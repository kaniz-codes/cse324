#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <iomanip>

using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet;
map<char, set<char>> followSet;
set<char> nonTerminals;
set<char> terminals;
char startSymbol;

void computeFirst(char c) {
    if (!firstSet[c].empty()) return;

    for (const string& prod : grammar[c]) {
        if (prod == "#") {
            firstSet[c].insert('#');
            continue;
        }

        for (size_t i = 0; i < prod.length(); ++i) {
            char nextChar = prod[i];

            if (!isupper(nextChar)) {
                firstSet[c].insert(nextChar);
                break;
            } else {
                computeFirst(nextChar);
                bool hasEpsilon = false;
                for (char f : firstSet[nextChar]) {
                    if (f == '#') hasEpsilon = true;
                    else firstSet[c].insert(f);
                }
                if (!hasEpsilon) break;
                if (i == prod.length() - 1) firstSet[c].insert('#');
            }
        }
    }
}

void computeFollow() {
    followSet[startSymbol].insert('$');

    bool changed = true;
    while (changed) {
        changed = false;
        for (char nt : nonTerminals) {
            for (const string& prod : grammar[nt]) {
                for (size_t i = 0; i < prod.length(); ++i) {
                    char c = prod[i];
                    if (isupper(c)) {
                        size_t oldSize = followSet[c].size();

                        if (i + 1 < prod.length()) {
                            char nextChar = prod[i + 1];
                            if (!isupper(nextChar)) {
                                followSet[c].insert(nextChar);
                            } else {
                                bool hasEpsilon = false;
                                for (char f : firstSet[nextChar]) {
                                    if (f == '#') hasEpsilon = true;
                                    else followSet[c].insert(f);
                                }
                                if (hasEpsilon) {
                                    for (char f : followSet[nt]) followSet[c].insert(f);
                                }
                            }
                        } else {
                            for (char f : followSet[nt]) followSet[c].insert(f);
                        }

                        if (followSet[c].size() != oldSize) changed = true;
                    }
                }
            }
        }
    }
}

int main() {
    int numProds;
    cout << "Enter number of productions: ";
    cin >> numProds;

    cout << "Enter productions:\n";
    for (int i = 0; i < numProds; ++i) {
        string prodLine;
        cin >> prodLine;

        char lhs = prodLine[0];
        string rhs = prodLine.substr(3);

        if (i == 0) startSymbol = lhs;

        grammar[lhs].push_back(rhs);
        nonTerminals.insert(lhs);

        for (char ch : rhs) {
            if (!isupper(ch) && ch != '#') terminals.insert(ch);
        }
    }
    terminals.insert('$');

    for (char nt : nonTerminals) computeFirst(nt);
    computeFollow();

    // First and Follow Output
    cout << "\nFIRST AND FOLLOW SETS\n";
    for (char nt : nonTerminals) {
        cout << "FIRST(" << nt << ")  = { ";
        for (char c : firstSet[nt]) cout << c << " ";
        cout << "}\n";

        cout << "FOLLOW(" << nt << ") = { ";
        for (char c : followSet[nt]) cout << c << " ";
        cout << "}\n\n";
    }

    map<char, map<char, string>> parsingTable;
    bool isLL1 = true;

    for (char nt : nonTerminals) {
        for (const string& prod : grammar[nt]) {
            set<char> firstRHS;
            if (prod == "#") {
                firstRHS.insert('#');
            } else {
                for (size_t i = 0; i < prod.length(); ++i) {
                    char nextChar = prod[i];
                    if (!isupper(nextChar)) {
                        firstRHS.insert(nextChar);
                        break;
                    } else {
                        bool hasEpsilon = false;
                        for (char f : firstSet[nextChar]) {
                            if (f == '#') hasEpsilon = true;
                            else firstRHS.insert(f);
                        }
                        if (!hasEpsilon) break;
                        if (i == prod.length() - 1) firstRHS.insert('#');
                    }
                }
            }

            for (char t : firstRHS) {
                if (t != '#') {
                    if (!parsingTable[nt][t].empty()) isLL1 = false;
                    parsingTable[nt][t] = prod;
                } else {
                    for (char f : followSet[nt]) {
                        if (!parsingTable[nt][f].empty()) isLL1 = false;
                        parsingTable[nt][f] =  "#";
                    }
                }
            }
        }
    }

    // LL(1) Parsing Table Output
    cout << "LL(1) PARSING TABLE\n";
    cout << left << setw(8) << "NT";
    for (char t : terminals) {
        cout << setw(12) << t;
    }
    cout << "\n" << string(8 + terminals.size() * 12, '-') << "\n";

    for (char nt : nonTerminals) {
        cout << setw(8) << nt;
        for (char t : terminals) {
            string entry = "-";
            if (!parsingTable[nt][t].empty()) {
                entry = string(1, nt) + "->" + parsingTable[nt][t];
            }
            cout << setw(12) << entry;
        }
        cout << "\n";
    }

    if (!isLL1) {
        cout << "\nGrammar is NOT LL(1) due to structural table conflicts!\n";
    } else {
        cout << "\nGrammar is successfully LL(1)!\n";
    }
    return 0;
}

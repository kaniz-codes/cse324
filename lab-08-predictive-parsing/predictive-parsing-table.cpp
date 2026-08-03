#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

// A production rule
struct Production {
    char nonTerminal;
    string production;
};

// Grammar and Parsing Table
vector<Production> grammar = {
    {'E', "eEx"},
    {'E', "aBc"},
    {'F', "fFy"},
    {'G', "gGz"}
};

map<char, set<char>> first;
map<char, set<char>> follow;
map<char, map<char, string>> parsingTable;

set<char> terminals;
set<char> nonTerminals = {'E', 'F', 'G', 'B'};

void computeTerminals() {
    for (const auto& prod : grammar) {
        for (char c : prod.production) {
            if (!isupper(c) && c != 'ε') {
                terminals.insert(c);
            }
        }
    }
    terminals.insert('$'); // End of input symbol
}

// Hardcoded FIRST sets for this mini-language
void computeFirstSets() {
    first['E'] = {'e', 'a'};
    first['F'] = {'f'};
    first['G'] = {'g'};
    first['B'] = {'b'}; // Assume rule: B -> b
}

// Hardcoded FOLLOW sets for this mini-language
void computeFollowSets() {
    follow['E'] = {'$', 'x', 'c'}; // '$' added for start symbol
    follow['F'] = {'y'};
    follow['G'] = {'z'};
    follow['B'] = {'c'};
}

// Build the parsing table
void buildParsingTable() {
    for (const auto& prod : grammar) {
        char lhs = prod.nonTerminal;
        string rhs = prod.production;

        char firstSymbol = rhs[0];
        if (isupper(firstSymbol)) {
            for (char f : first[firstSymbol]) {
                parsingTable[lhs][f] = rhs;
            }
        } else {
            parsingTable[lhs][firstSymbol] = rhs;
        }
    }
}

// Display the parsing table
void displayParsingTable() {
    cout << setw(10) << "NT/T";
    for (char t : terminals) {
        cout << setw(10) << t;
    }
    cout << endl;

    for (char nt : nonTerminals) {
        cout << setw(10) << nt;
        for (char t : terminals) {
            if (parsingTable[nt].count(t)) {
                cout << setw(10) << nt << "->" << parsingTable[nt][t];
            } else {
                cout << setw(10) << "";
            }
        }
        cout << endl;
    }
}

int main() {
    computeTerminals();
    computeFirstSets();
    computeFollowSets();
    buildParsingTable();

    cout << "Predictive Parsing Table:\n";
    displayParsingTable();

    return 0;
}
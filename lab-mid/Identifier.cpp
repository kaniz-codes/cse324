// Write a C/C++ program to recognize valid and invalid identifier.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string id;
    int valid = 1;

    cout << "Enter an identifier: ";
    cin >> id;

    if (!((id[0] >= 'A' && id[0] <= 'Z') ||
          (id[0] >= 'a' && id[0] <= 'z') ||
           id[0] == '_'))
    {
        valid = 0;
    }

    for (int i = 1; i < id.length(); i++)
    {
        if (!((id[i] >= 'A' && id[i] <= 'Z') ||
              (id[i] >= 'a' && id[i] <= 'z') ||
              (id[i] >= '0' && id[i] <= '9') ||
               id[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    if (valid == 1)
        cout << "Valid identifier";
    else
        cout << "Invalid identifier";

    return 0;
}
# Lab 01: Lexical Analysis Basics

This lab introduces the basic ideas of **lexical analysis**, the first phase of a compiler.  

## Learnt

In compiler design, lexical analysis is used to scan source code and identify meaningful tokens.  
This lab practices some beginner-level lexical analysis operations, including:

- Detecting comments
- Searching for keywords
- Reading input from the user
- Reading and writing files
- Processing text line by line



## Code Files

| File | Description |
|------|-------------|
| `01-ReadString.cpp` | Takes a string input and checks whether it is a comment. |
| `02-Exercise.cpp` | Writes sample text into a file, reads it line by line, and checks each line for comments. |
| `03-KeywordsSearch.cpp` | Checks whether a given word is a keyword. |
| `practice.cpp` | Practices basic file writing and reading in C++. |

---

## Problems

### P01: Check if the input string is a comment.

Example:

```txt
Input:
//This is a comment

Output:
This is a comment.

Input:
/*This is a comment*/

Output:
This is a comment.
```

<details>
<summary><kbd>View Solution Code</kbd></summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cout << "Enter a string: " << endl;
    getline(cin, a);

    int n = a.length();

    if ((a[0] == '/' && a[1] == '*') && (a[n - 1] == '/' && a[n - 2] == '*')) {
        cout << "This is a comment." << endl;
    }
    else if (a[0] == '/' && a[1] == '/') {
        cout << "This is a comment." << endl;
    }
    else {
        cout << "This is not a comment." << endl;
    }
}
```

</details>

### P02: Read a file and check if the texts are comment or not.

<details>
<summary>View Solution Code</summary>

```cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
//=========Write File===========

    ofstream myFile("text.txt");

    if(myFile.is_open())
    {
        myFile << "My name is Kaniz Fatema.\n";
        myFile << "//Kaniz Fatema.\n";
        myFile << "/*Kaniz Fatema.*/\n";

        myFile.close();
        cout<<"Mission successful!!"<<endl;
    }
    else
    {
        cout<<"Error: file not open"<<endl;
    }
//=========Read File===========

    ifstream inFile("text.txt");
    string line;

    if(!inFile.is_open())
    {
        cout<<"Error: Could not open"<<endl;
    }


    while(getline(inFile,line))
    {
        cout<<line<<endl;

        int n = line.length();

        if((line[0] == '/' && line[1] == '*') && (line[n-1] == '/' && line[n-2] == '*'))
        {
            cout << "This is a comment." <<endl;
        }
        else if((line[0] == '/' && line[1] == '/'))
        {
            cout << "This is a comment." <<endl;
        }

        else
        {
            cout << "This is not a comment." <<endl;
        }
    }

    inFile.close();

}

```

</details>

### P03: Check if the input string is a keyword.

The keyword search program checks whether the input word exists in a predefined keyword list.

Example:

```txt
Input:
int

Output:
this is a keyword.

Input:
abc

Output:
this is not a keyword.
```
<details>
<summary><kbd>View Solution Code</kbd></summary>>

```cpp
#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    cout << "Enter a string: " <<endl;
    cin >> a;

    string keywords[] = {"int", "float", "if", "else", "for", "while"};

    int n = sizeof(keywords) / sizeof(keywords[0]);

    bool found = false;
    for(int i=0; i<n; i++){
        if(a == keywords[i]){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"this is a keyword."<<endl;
    }
    else{
        cout<<"this is not a keyword."<<endl;
    }
}
```

</details>

### Self Practice: File Handling

The file handling programs use:

- `ofstream` to write data into a file
- `ifstream` to read data from a file
- `getline()` to process text line by line

A sample file named `text.txt` is created and used for testing comment detection.

<details>
<summary><kbd>View Solution Code</kbd></summary>

```cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream myFile("text.txt");

    if(myFile.is_open()){
        myFile << "My name is Kaniz Fatema.\n";
        myFile << "//Kaniz Fatema.\n";
        myFile << "/*Kaniz Fatema.*/\n";

        myFile.close();
        cout<<"Mission successful!!"<<endl;
    }
    else{
        cout<<"Error: file not open"<<endl;
    }

    ifstream inFile("text.txt");
    string line;

    if(!inFile.is_open()){
        cout<<"Error: Could not open"<<endl;
    }


    while(getline(inFile,line)){
        cout<<line<<endl;
    }

    inFile.close();
}

```

</details>


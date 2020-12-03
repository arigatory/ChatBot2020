#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

void to_lower(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main()
{
    cout << "Hello dear user, please ask your question!\n";
    string question; //user question
        while (question != "exit") {
            getline(cin, question);
            to_lower(question);


            regex hello = regex(".*hello.*");
            if (regex_match(question, hello))
            {
                cout << "Hello again my friend\n";
            }

            regex name = regex(".*what is your name.*");
            if (regex_match(question, name))
            {
                cout << "My name is Bot2020\n";
            }
            
        }
}


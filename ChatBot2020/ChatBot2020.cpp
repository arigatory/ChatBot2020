#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <map>
using namespace std;

void to_lower(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void bot(string text) {
    cout << "[BOT]: " << text << endl;
}

string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    to_lower(question);
    return question;
}

int main()
{
    cout << "Hello dear user, please ask your question!\n";
    string question; //user question

    map<string, string> database = {
        {"hello", "Oh, hello to you human"},
        {"how are you", "I'm good"},
        {"what are you doing", "Answering stupid questions"},
        {"what is your name","My name is Bot2020"},
        {"exit","Ok byeeee!"}
    };

        while (question != "exit") {
            question = user();
            bool isAnswerFound = false;
            for (auto entry : database)
            {
                regex pattern = regex(".*" + entry.first + ".*");
                if (regex_match(question, pattern))
                {
                    bot(entry.second);
                    isAnswerFound = true;
                }
            }
            if (!isAnswerFound)
            {
                bot("Sorry, I don't understand");
            }
        }
}


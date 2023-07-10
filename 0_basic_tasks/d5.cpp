#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, pair<string, bool>> database;

    string operation, login, password;
    while (cin >> operation >> login) {
        if (operation == "register") {
            cin >> password;
            if (database.count(login) > 0) {
                cout << "login already in use" << '\n';
            } else {
                database[login] = make_pair(password, false);
                cout << "account created" << '\n';
            }
        } else if (operation == "login") {
            cin >> password;
            if (database.count(login) == 0 || database[login].first != password) {
                cout << "wrong account info" << '\n';
            } else if (database[login].second) {
                std::cout << "already logged in" << '\n';
            } else {
                database[login].second = true;
                cout << "logged in" << '\n';
            }
        } else if (operation == "logout") {
            if (database.count(login) == 0 || !database[login].second) {
                cout << "incorrect operation" << '\n';
            } else {
                database[login].second = false;
                cout << "logged out" << '\n';
            }
        }
    }

    return 0;
}
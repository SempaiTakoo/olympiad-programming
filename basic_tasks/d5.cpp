#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10e5

using namespace std;

class account {
    public:
        string login;
        string password;
        bool isLogged;
};

void registration(vector<account>& data, account newacc) {
    for (vector<account>::iterator iter = data.begin(); iter != data.end(); ++iter) {
        if ((*iter).login == newacc.login) {
            cout << "login already in use\n";
            return;
        }
    }
    data.push_back(newacc);
    cout << "account created\n";
}

void authorization(vector<account>& data, account newacc) {
    for (vector<account>::iterator iter = data.begin(); iter != data.end(); ++iter) {
        if ((*iter).login != newacc.login)
            continue;
        if ((*iter).password != newacc.password) {
            cout << "wrong account info\n";
            return;
        }
        if ((*iter).isLogged) {
            cout << "already logged in\n";
            return;
        }
        (*iter).isLogged = true;
        cout << "logged in\n";
        return;
    }
    cout << "wrong account info\n";
}

void deauthorization(vector<account>& data, account newacc) {
    for (vector<account>::iterator iter = data.begin(); iter != data.end(); ++iter) {
        if ((*iter).login != newacc.login)
            continue;
        if ((*iter).isLogged) {
            (*iter).isLogged = false;
            cout << "logged out\n";
            return;
        }
        cout << "incorrect operation\n";
        return;
    }
    cout << "incorrect operation\n";
}

int main() {
    vector<account> data(MAX_SIZE);
    string command, login, password;
    while (cin >> command) {
        if (command == "register") {
            account newacc;
            cin >> login >> password;
            newacc.login = login;
            newacc.password = password;
            newacc.isLogged = false;
            registration(data, newacc);
        }
        if (command == "login") {
            account newacc;
            cin >> login >> password;
            newacc.login = login;
            newacc.password = password;
            newacc.isLogged = false;
            authorization(data, newacc);
        }
        if (command == "logout") {
            account newacc;
            cin >> login;
            newacc.login = login;
            deauthorization(data, newacc);
        }
    }
}
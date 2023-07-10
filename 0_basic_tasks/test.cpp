#include <iostream>
#include <string>
#include <set>

using namespace std;

class account {
    public:
        string login;
        string password;
};

bool operator== (account a, account b) {
    return a.login == b.login;
}
bool operator< (account a, account b) {
    return a.login < b.login;
}

int main() {
    set<account> accounts;
    account a1, a2;
    a1.login = "aaaa";
    a1.password = "123";
    a2.login = "aaab";
    a2.password = "321";
    accounts.insert(a2);
    accounts.insert(a1);
    for (set<account>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        cout << (*it).login << ' ' << (*it).password << '\n';
    }
}
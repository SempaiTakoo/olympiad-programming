#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

int main() {
    char ch;
    stack<ll> st;
    while (cin >> ch) {
        if (isdigit(ch)) {
            st.push(ch - '0');
            continue;
        }
        if (ch == '+') {
            ll a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b + a);
            continue;
        }
        if (ch == '-') {
            ll a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b - a);
            continue;
        }
        if (ch == '*') {
            ll a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b * a);
            continue;
        }
    }
    cout << st.top() << '\n';
}
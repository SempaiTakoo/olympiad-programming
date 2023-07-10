#include <iostream>
#include <set>

using namespace std;

void print_set(multiset<int> st) {
    cout << "Set: ";
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
}

int main() {
    set<int> st;
    st.insert(3);
    st.insert(4);
    st.insert(1);
    st.insert(6);

    int a = *st.begin();
    st.erase(st.begin());
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
    cout << a << '\n';
    return 0;
}
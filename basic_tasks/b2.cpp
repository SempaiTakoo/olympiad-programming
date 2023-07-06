#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x > 0 and y > 0) {
        std::cout << 1 << '\n';
    } else if (x < 0 and y > 0) {
        std::cout << 2 << '\n';
    } else if (x < 0 and y < 0) {
        std::cout << 3 << '\n';
    } else if (x > 0 and y < 0) {
        std::cout << 4 << '\n';
    }
}
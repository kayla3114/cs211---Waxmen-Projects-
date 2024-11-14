#include <iostream>
#include <cmath>

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || std::abs(c - i) == std::abs(q[c] - q[i])) {
            return false;
        }
    }
    return true;
}

void print(int q[], int solutions) {
    std::cout << "Solution " << solutions << ":";
    for (int i = 0; i < 8; i++) {
        std::cout << q[i] << " ";
    }
    std::cout << std::endl;
}

void find(int q[], int c, int& solutions) {
    if (c == 8) {
        print(q, ++solutions);
        return;
    }

    for (q[c] = 0; q[c] < 8; q[c]++) {
        if (ok(q, c)) {
            find(q, c + 1, solutions);
        }
    }
}

int main() {
    int q[8] = {};
    int solutions = 0;

    find(q, 0, solutions);

    return 0;
}

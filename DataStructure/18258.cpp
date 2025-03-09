#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::vector<int> vec;
    int front = 0;

    std::cin >> N;

    while (N--) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push") {
            int num;
            std::cin >> num;
            vec.push_back(num);
        }
        else if (cmd == "pop") {
            if (front == vec.size()) {
                std::cout << -1;
            }
            else {
                std::cout << vec[front];
                front++;
            }
            std::cout << '\n';
        }
        else if (cmd == "size") {
            std::cout << (vec.size() - front) << '\n';
        }
        else if (cmd == "empty") {
            std::cout << ((front == vec.size()) ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (front == vec.size())
                std::cout << -1;
            else
                std::cout << vec[front];
            std::cout << '\n';
        }
        else if (cmd == "back") {
            if (front == vec.size())
                std::cout << -1;
            else
                std::cout << vec.back();
            std::cout << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <deque>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        std::string func;
        std::cin >> func;

        int n;
        std::cin >> n;

        std::string arys;
        std::cin >> arys;

        std::deque<int> deque;
        int num = 0;
        bool is_num = false;
        for (char c : arys) {
            if (std::isdigit(c)) {
                is_num = true;
                num = num * 10 + (c - '0');
            }
            else {
                if (is_num) {
                    deque.push_back(num);
                    num = 0;
                    is_num = false;
                }
            }
        }

        bool is_reversed = false;
        bool is_error = false;
        for (char op : func) {
            if (op == 'R') {
                is_reversed = !is_reversed;
            }
            else {  
                if (deque.empty()) {
                    is_error = true;
                    break;
                }
                if (!is_reversed) 
                    deque.pop_front();
                else              
                    deque.pop_back();
            }
        }

        if (is_error) {
            std::cout << "error\n";
        }
        else {
            std::cout << '[';
            if (!is_reversed) {
                for (int i = 0; i < deque.size(); ++i) {
                    if (i) 
                        std::cout << ',';
                    std::cout << deque[i];
                }
            }
            else {
                for (int i = deque.size(); i-- > 0; ) {
                    if (i != deque.size() - 1) 
                        std::cout << ',';
                    std::cout << deque[i];
                }
            }
            std::cout << "]\n";
        }
    }
    return 0;
}

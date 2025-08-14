#include <iostream>
#include <deque>
#include <string>

// 가상의 언어인 AC의 연산 실행 결과를 구해야 함
// AC에는 R(뒤집기)와 D(버리기) 연산이 있음
// R은 배열의 수를 뒤집는 함수고, D는 첫 번째 수를 버리는 함수이며, 배열이 빈 상태에서 D를 연산하면 에러가 발생함
// 이 때, 각 연산들로 이루어진 함수 p를 진행한 뒤의 배열의 최종 상태를 출력하는 문제

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

        // 문자열 파싱 진행
        for (char c : arys) {
            // 숫자 문자인 경우 is_num 플래그를 활성화시키고 자릿수를 누적시켜 num 계산
            if (std::isdigit(c)) {
                is_num = true;
                num = num * 10 + (c - '0');
            }
            // 숫자가 아닌 경우 현재까지의 계산된 숫자를 deque에 삽입하고 num과 플래그 초기화
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

            // std::reverse는 O(N)이기 때문에 시간 초과가 발생할 수 있기 때문에 reverse 플래그로 연산을 진행함
            // R이 등장할 때마다 뒤집기 연산 토글
            if (op == 'R') {
                is_reversed = !is_reversed;
            }
            else {  
                // deque이 비어있는 상태에서 D 연산을 하면 에러 발생
                if (deque.empty()) {
                    is_error = true;
                    break;
                }
                // deque의 맨 앞의 원소 제거
                // 즉 원 상태라면 맨 앞의 문자를, 뒤집힌 상태라면 맨 뒤의 문자를 제거함
                if (!is_reversed) 
                    deque.pop_front();
                else              
                    deque.pop_back();
            }
        }

        // error 플래그가 true면 error 출력
        if (is_error) {
            std::cout << "error\n";
        }
        else {
            std::cout << '[';
            // 뒤집혀지지 않은 상태인 경우에는 순방향으로 출력
            if (!is_reversed) {
                for (int i = 0; i < deque.size(); ++i) {
                    if (i) 
                        std::cout << ',';
                    std::cout << deque[i];
                }
            }
            // 뒤집힌 경우에는 역방향으로 출력
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

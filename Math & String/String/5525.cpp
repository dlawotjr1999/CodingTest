#include <iostream>
#include <string>

// 'I'와 'O'가 교대로 나오는, (2^N - 1)개로 이루어진 문자열을 P_N이라고 할 때 주어진 문자열의 P_N의 갯수를 구하는 문제

int answer;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    int cnt = 0;

    for (int i = 1; i < M - 1;) {
        // "IOI"문자열인 경우 P_N에 해당하는 지 검토
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            cnt++;

            // P_N인 경우 answer 증가
            if (cnt == N) {
                answer++;
                
                // 중복 제거를 위해 cnt를 감소
                // 예를 들어, "IOIOI"(cnt = 2) 다음에 "OI"가 존재할 경우에도 cnt = 2를 유지해야 P_2로 검토할 수 있기 때문 
                cnt--; 
            }
            i += 2;
        }
        // "IOI" 문자열이 아닌 경우 cnt 초기화 후 다음 문자 검토
        else {
            cnt = 0;
            i++;
        }
    }

    std::cout << answer;
    return 0;
}

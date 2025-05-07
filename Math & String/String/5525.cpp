#include <iostream>
#include <string>

int answer;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    int cnt = 0;

    for (int i = 1; i < M - 1;) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            cnt++;
            if (cnt == N) {
                answer++;
                cnt--; 
            }
            i += 2;
        }
        else {
            cnt = 0;
            i++;
        }
    }

    std::cout << answer;
    return 0;
}

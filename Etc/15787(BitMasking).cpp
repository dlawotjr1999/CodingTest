#include <iostream>
#include <vector>
#include <set>

// 주어진 명령에 따라 기차의 상태를 조작하고, 마지막에는 기차 상태의 다양한 갯수를 구하는 문제
// 기차 상태를 비트마스크처럼 다루고, 명령을 처리한 후 고유한 기차 상태의 개수를 구해야 함
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    // 기차 상태를 저장할 2차원 벡터
    // vec[i][j]는 기차 i의 j번째 자리가 'True'이면 '1', 'False'이면 '0'을 의미
    std::vector<std::vector<bool>> vec(N, std::vector<bool>(20, false));

    int prompt[3];

    for (int i = 0; i < M; i++) {
        std::cin >> prompt[0] >> prompt[1];
        int train = prompt[1] - 1;  // 기차 번호는 1부터 시작하므로 0부터 시작하도록 -1 해줌

        if (prompt[0] == 1 || prompt[0] == 2)
            std::cin >> prompt[2];

        switch (prompt[0]) {
        case 1:
            vec[train][prompt[2] - 1] = true;
            break;

        case 2:
            vec[train][prompt[2] - 1] = false;
            break;

        case 3:
            for (int j = 19; j > 0; j--)
                vec[train][j] = vec[train][j - 1];
            vec[train][0] = false;
            break;

        case 4:
            for (int j = 0; j < 19; j++)
                vec[train][j] = vec[train][j + 1];
            vec[train][19] = false;
        }
    }

    // 기차 상태를 set에 넣어 중복된 상태를 제거
    std::set<std::vector<bool>> trains(vec.begin(), vec.end());
    std::cout << trains.size();

    return 0;
}

#include <iostream>
#include <map>
#include <vector> 

// 흔히 나오는 map과 vector를 활용하는 문제
// map에 값들을 입력하고, 두 번째로 입력한 값들이 map에서 몇 번 등장하는지 구현하는 문제

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::map<int, int> map;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        map[num]++;
    }

    std::cin >> M;
    std::vector<int> count(M, 0);

    for (int j = 0; j < M; j++) {
        int cnt;
        std::cin >> cnt;

        if (map.find(cnt) != map.end())
            count[j] = map[cnt];
        else
            continue;
    }

    for (int k = 0; k < count.size(); k++)
        std::cout << count[k] << " ";

    return 0;
}

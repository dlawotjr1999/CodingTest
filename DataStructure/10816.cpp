#include <iostream>
#include <map>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::map<int, int> map;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        map.emplace(num, 0);

        if (map.find(num) != map.end()) map[num]++;
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

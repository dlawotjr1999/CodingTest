#include <iostream>
#include <map>

// multimap 사용 문제
// multimap은 key에 따라 정렬이 되어 데이터가 저장됨
// 참고 : key 대신 value로 정렬하기(https://unluckyjung.github.io/cpp/2020/05/07/Sort_map_by_value/)

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N;
    std::multimap<int, std::string> map;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int age;
        std::string name;
        std::cin >> age >> name;
        map.emplace(age, name);
    }

    for (const std::pair<int, std::string>& entry : map)
        std::cout << entry.first << " " << entry.second << '\n';

    return 0;
}

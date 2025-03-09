#include <iostream>
#include <map>
#include <set>

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

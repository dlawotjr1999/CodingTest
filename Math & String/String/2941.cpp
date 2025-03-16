#include <iostream>
#include <string>
#include <vector>

// 문자열 치환 문제

int main() {
    std::vector<std::string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int idx;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < croatian.size(); i++)
    {
        while (1) {
            idx = str.find(croatian[i]);

            // string에서는 find로 값을 찾지 못하면 npos를 반환함
            if (idx == std::string::npos)
                break;
            str.replace(idx, croatian[i].length(), "#");
        }
    }
    std::cout << str.length();
}


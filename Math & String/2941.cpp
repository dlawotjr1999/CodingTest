#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int idx;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < croatian.size(); i++)
    {
        while (1) {
            idx = str.find(croatian[i]);
            if (idx == std::string::npos)
                break;
            str.replace(idx, croatian[i].length(), "#");
        }
    }
    std::cout << str.length();
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    for(int i = 0; i < (int)clothes.size(); ++i) {
        um[clothes[i][1]]++;
    }
    
    vector<pair<string, int>> vec(um.begin(), um.end());
    for(const auto& elm : um) {
        answer *= (elm.second + 1);
    }
    answer--;
    
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 1:1, 2:2, 3:2 4:1 5:2
// 1:4, 2:3, 3:1 

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> um;
    for(int t : tangerine) {
        um[t]++;
    }
    
    vector<pair<int, int>> vec(um.begin(), um.end());
    sort(vec.begin(), vec.end(), [](const auto& l, const auto& r) {
        return l.second > r.second;
    });
    
    for(auto elm : vec) {
        k -= elm.second;
        answer++;
        
        if(k <= 0)
            break;
    }

    return answer;
}
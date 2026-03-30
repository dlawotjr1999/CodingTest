#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = players.size();
    
    vector<int> expire(n + k + 1, 0);
    
    int active = 0;
    for(int i = 0; i < n; ++i) {
        active -= expire[i];
        
        int need = players[i] / m;
        
        if(need > active) {
            int add = need - active;
            answer += add;
            active += add;
            expire[i + k] += add;
        }
    }
    
    return answer;
}
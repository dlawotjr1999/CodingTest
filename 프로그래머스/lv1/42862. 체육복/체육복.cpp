#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<bool> borrowed(n + 1, false);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(size_t i = 0; i < lost.size(); ++i) {
        for(size_t j = 0; j < reserve.size(); ++j) {
            if(lost[i] == reserve[j]) {
                borrowed[lost[i]] = true;
                break;
            }
        }
    }
    
    for(size_t i = 0; i < lost.size(); ++i) {
        if(borrowed[lost[i]]) continue;
        
        bool isPossible = false;
        for(size_t j = 0; j < reserve.size(); ++j) {
            if(borrowed[reserve[j]])
                continue;
            
            if(reserve[j] == lost[i] - 1) {
                borrowed[lost[i] - 1] = true;
                isPossible = true;
                break;
            }

            else if(reserve[j] == lost[i] + 1) {
                borrowed[lost[i] + 1] = true;
                isPossible = true;
                break;
            }
        }
        
        if(!isPossible)
            answer--;
    }
    
    return answer;
}
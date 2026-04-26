#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    
    int idx = 0;
    int w = 0;
    
    while(idx < truck_weights.size()) {
        answer++;
        int cur = truck_weights[idx];
        
        if(bridge.size() == bridge_length) {
            w -= bridge.front();
            bridge.pop();
        }
        
        if(w + cur <= weight) {
            bridge.push(cur);
            w += cur;
            idx++;
        }
        else
            bridge.push(0);
    }
    answer += bridge_length;
    
    return answer;
}
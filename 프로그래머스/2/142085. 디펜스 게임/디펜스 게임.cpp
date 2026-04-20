#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    
    for(int i = 0; i < (int)enemy.size(); ++i) {
        n -= enemy[i];
        pq.push(enemy[i]);
        
        if(n < 0) {
            if(k == 0)
                return i;
            
            n += pq.top();
            pq.pop();  
            k--;
        }
    }
    
    return enemy.size();
}
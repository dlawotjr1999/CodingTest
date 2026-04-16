#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {    
    int answer = 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(const int s : scoville) {
        pq.push(1LL * s);
    }
    
    while(!pq.empty()) {
        if(pq.top() >= K) {
            return answer;
        }
        
        if(pq.size() < 2)
            return -1;
        
        long long s1 = pq.top();
        pq.pop();
    
        long long s2 = pq.top();
        pq.pop();
    
        long long res = s1 + (s2 * 2);
        pq.push(res);
        
        answer++;
    }
    
    return -1;
}
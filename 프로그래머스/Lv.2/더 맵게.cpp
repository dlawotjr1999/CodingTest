#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int& elm : scoville) 
        pq.push(elm);
    
    while(pq.size() >= 2 && pq.top() < K) {
        int least = pq.top();  pq.pop();
        int second_least = pq.top();   pq.pop();
        int sum_scoville = least + (2 * second_least);
        pq.push(sum_scoville);
        answer++;
    }
    
    if(pq.top() < K)
        return -1;
    
    return answer;
}
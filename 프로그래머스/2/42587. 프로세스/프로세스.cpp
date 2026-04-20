#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < (int)priorities.size(); ++i) {
        q.emplace(priorities[i], i);
        pq.push(priorities[i]);
    }
    
    // 2 1 3 2
    // 3 2 2 1
    
    while(!q.empty()) {   
        while(q.front().first != pq.top()) {
            q.emplace(q.front());
            q.pop();
        }
        
        if(q.front().second == location)
            return answer;
        
        q.pop(); pq.pop();
        answer++;
    }
    
    return -1;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int p : progresses) {
        q.emplace(100 - p);
    }
    
    int idx = 0;
    while(!q.empty()) {
        int cnt = 0;
        
        while(!q.empty() && q.front() <= 0) {
            cnt++;   
            idx++;
            q.pop();
        }
        if(cnt > 0)
            answer.push_back(cnt);
        
        // 한 타임에 speeds_i만큼 줄이기
        if(!q.empty()) {
            for(int i = idx; i < (int)speeds.size(); ++i) {
                q.push(q.front() - speeds[i]);
                q.pop();
            }
        }
    }
    
    return answer;
}
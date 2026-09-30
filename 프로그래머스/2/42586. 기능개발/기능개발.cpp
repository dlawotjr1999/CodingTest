#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < (int)progresses.size(); ++i) {
        q.emplace(progresses[i], speeds[i]);
    }
    
    while(!q.empty()) {
        for(int i = 0; i < (int)q.size(); ++i) {
            int progress = q.front().first;
            int speed = q.front().second;
            
            q.emplace(progress + speed, speed);
            q.pop();
        } 

        if(q.front().first >= 100) {
            int deploy = 0;
            
            while(!q.empty() && q.front().first >= 100) {
                deploy++;
                q.pop();
            }
            answer.push_back(deploy);
        }
    }
    
    return answer;
}
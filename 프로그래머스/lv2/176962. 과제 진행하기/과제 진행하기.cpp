#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct info {
    string name;
    int start_time;
    int duration;
};

int TimeToMinute(const string& str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    
    return h*60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<info> vec;
    stack<info> s;
    
    for(size_t i = 0; i < plans.size(); ++i) {
        vec.push_back({ plans[i][0], TimeToMinute(plans[i][1]), stoi(plans[i][2]) });
    }
    sort(vec.begin(), vec.end(), [](const auto& l, const auto& r) {
        return l.start_time < r.start_time;
    });
    
    for(size_t i = 0; i < vec.size() - 1; ++i) {
        info cur = vec[i];
        info next = vec[i + 1];
        
        int diff = next.start_time - cur.start_time;
        if(cur.duration <= diff) {
            answer.push_back(cur.name);
            
            int remain = diff - cur.duration;
            while(!s.empty() && remain > 0) {
                info top = s.top();
                s.pop();
                
                if(top.duration <= remain) {
                    remain -= top.duration;
                    answer.push_back(top.name);
                }
                else {
                    top.duration -= remain;
                    remain = 0;
                    s.push(top);
                }
            }
        }
        else {
            cur.duration -= diff;
            s.push(cur);
        }
    }
    answer.push_back(vec.back().name);
    
    while(!s.empty()) {
        answer.push_back(s.top().name);
        s.pop();
    }
    
    return answer;
}
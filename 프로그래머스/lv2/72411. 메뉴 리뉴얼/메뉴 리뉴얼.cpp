#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

void DFS(int idx, int cnt, string& choose, string& str, unordered_map<string, int>& um) {
    if(choose.length() >= cnt) {
        um[choose]++;
        return;
    }
    
    for(int i = idx; i < str.length(); ++i) {
        choose.push_back(str[i]);
        DFS(i + 1, cnt, choose, str, um);
        choose.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int c : course) {    
        unordered_map<string, int> um;
        
        for(int i = 0; i < (int)orders.size(); ++i) {
            string cur = orders[i];
            sort(cur.begin(), cur.end());
            
            string choose = "";
            DFS(0, c, choose, cur, um);
        }
        vector<pair<string, int>> temp(um.begin(), um.end());
        sort(temp.begin(), temp.end(), [](const auto& l, const auto& r) {
            return l.second > r.second;
        });
        
        if(!temp.empty()) {
            int max_val = temp[0].second;
            
            if(max_val > 1) {
                for(auto t : temp) {
                    if(t.second == max_val)
                        answer.push_back(t.first);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
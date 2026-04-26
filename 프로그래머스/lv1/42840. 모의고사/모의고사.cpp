#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX = 10000;
const vector<vector<int>> vec = {{ 1,2,3,4,5 }, { 2,1,2,3,2,4,2,5 }, { 3,3,1,1,2,2,4,4,5,5 }};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> info(3, vector<int>(MAX, 0));
    for(int i = 0; i < 3; ++i) {
        vector<int> cur = vec[i];
        
        for(int j = 0; j < MAX; j += (int)cur.size()) {
            for(int k = 0; k < (int)cur.size(); ++k) {
                info[i][j + k] = cur[k];
            }
        }
    }
    
    vector<pair<int, int>> temp;
    for(int i = 0; i < 3; ++i) {
        int cnt = 0;
        vector<int> cur = info[i];
        
        for(int j = 0; j < (int)answers.size(); ++j) {
            if(cur[j] == answers[j])
                cnt++;
        }
        temp.emplace_back(cnt, i + 1);
    }
    sort(temp.begin(), temp.end(), [](const pair<int,int>& l, const pair<int,int>& r) {
        return l.first > r.first;
    });
    
    answer.push_back(temp[0].second);
    if(temp[0].first == temp[1].first) 
        answer.push_back(temp[1].second);
    if(temp[0].first == temp[2].first) 
        answer.push_back(temp[2].second);
    
    sort(answer.begin(), answer.end());
    return answer;
}
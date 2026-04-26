#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<string> path;
vector<bool> used;
bool found = false;

void DFS(string cur, vector<vector<string>>& tickets, int cnt) {
    if(found)
        return;
    
    if(cnt == (int)tickets.size()) {
        answer = path;
        found = true;
        return;
    }
    
    for(int i = 0; i < (int)tickets.size(); ++i) {
        if(!used[i] && tickets[i][0] == cur) {
            path.push_back(tickets[i][1]);
            used[i] = true;
            DFS(tickets[i][1], tickets, cnt + 1);
            used[i] = false;
            path.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    used.resize(tickets.size(), false);
    
    path.push_back("ICN");
    DFS("ICN", tickets, 0);
    
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    unordered_map<string, bool> visited;
    queue<pair<string, int>> q;
    
    q.emplace(begin, 0);
    visited[begin] = true;
    
    while(!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();
        
        if(cur == target)
            return dist;
        
        for(string w : words) {
            int diff = 0;
            
            if(visited[w])
                continue;
            
            for(int i = 0; i < cur.length(); ++i) {
                if(cur[i] != w[i]) diff++;
            }
            
            if(diff == 1) {
                visited[w] = true;
                q.emplace(w, dist + 1);
            }
        }
    }
    
    return 0;
}
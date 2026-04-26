#include <string>
#include <vector>

using namespace std;

int n;
int answer;

vector<bool> visited;

void DFS(int cur, int idx, int cnt, vector<vector<int>> dungeons) {
    if(idx >= n) {
        answer = max(answer, cnt);
        return;
    }
    
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {           
            if(cur >= dungeons[i][0]) {
                visited[i] = true;
                DFS(cur - dungeons[i][1], idx + 1, cnt + 1, dungeons);
                visited[i] = false;
            }
            else
                DFS(cur, idx + 1, cnt, dungeons);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    visited.resize(n, false);
    
    DFS(k, 0, 0, dungeons);
    
    return answer;
}
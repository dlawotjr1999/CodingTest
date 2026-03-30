#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};

int R, C;
vector<vector<bool>> visited;

int BFS(int y, int x, const vector<vector<int>>& land, set<int>& cols) {
    queue<pair<int, int>> q;
    q.emplace(y, x);
    cols.insert(x);
    visited[y][x] = true;
    
    int cnt = 1;
    while(!q.empty()) {
        auto [cur_y, cur_x] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = cur_x + dir_x[i];
            int ny = cur_y + dir_y[i];
            
            if(nx < 0 || nx >= C || ny < 0 || ny >= R)
                continue;
            if(land[ny][nx] == 0)
                continue;
            if(visited[ny][nx])
                continue;
            
            q.emplace(ny, nx);
            visited[ny][nx] = true;
            
            if(!cols.count(nx))
                cols.insert(nx);
            cnt++;
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    R = land.size();
    C = land[0].size();
    visited.assign(R, vector<bool>(C, false));
    
    vector<int> col_sum(C, 0);
    for(int j = 0; j < C; ++j) {    
        for(int i = 0; i < R; ++i) {
            if(land[i][j] == 1 && !visited[i][j]) {
                set<int> columns;
                int s = BFS(i, j, land, columns);
                
                for(int col : columns)
                    col_sum[col] += s;       
            }
        }
    }
    
    for(int cur : col_sum)
        answer = max(answer, cur);
    
    return answer;
}
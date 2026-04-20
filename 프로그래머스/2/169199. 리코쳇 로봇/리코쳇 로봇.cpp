#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

int BFS(int y, int x, int n, int m, vector<string>& board) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    
    q.emplace(y, x);
    visited[y][x] = 0;
    
    while(!q.empty()) {
        auto [cur_y, cur_x] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = cur_x;
            int ny = cur_y;
            
            while(board[ny][nx] != 'D') {
                nx += dir_x[i];
                ny += dir_y[i];
                
                if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                    break;                
            }
            nx -= dir_x[i]; ny -= dir_y[i];
            
            if(visited[ny][nx] != -1)
                continue;
            visited[ny][nx] = visited[cur_y][cur_x] + 1;
            
            if(board[ny][nx] == 'G')
                return visited[ny][nx];
            
            q.emplace(ny, nx);
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 'R') {
                return BFS(i, j, n, m, board);
            }
        }
    }
}
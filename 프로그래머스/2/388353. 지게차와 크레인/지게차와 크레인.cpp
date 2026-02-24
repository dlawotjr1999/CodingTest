#include <string>
#include <vector>
#include <queue>

using namespace std;

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};

int R, C;

void Forklift(char cur, vector<string>& storage) {
    vector<pair<int, int>> points;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(!(i == 0 || i == R - 1 || j == 0 || j == C - 1))
                continue;
            if(storage[i][j] == cur)
                points.emplace_back(i, j);
            else if(storage[i][j] == ' ') {
                q.emplace(i, j);
                visited[i][j] = true;
                
                while(!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();
                    
                    for(int k = 0; k < 4; ++k) {
                        int nx = x + dir_x[k];
                        int ny = y + dir_y[k];
                        
                        if(nx < 0 || nx >= C || ny < 0 || ny >= R)
                            continue;
                        if(visited[ny][nx])
                            continue;
                        
                        if(storage[ny][nx] == ' ') {
                            visited[ny][nx] = true;
                            q.emplace(ny, nx);
                        }
                        else if(storage[ny][nx] == cur) {
                            visited[ny][nx] = true;
                            points.emplace_back(ny, nx);
                        }
                    }
                }
            }
        }
    }
    
    for(auto [p1, p2] : points) {
        storage[p1][p2] = ' ';
    }
}

void Crane(char cur, vector<string>& storage) {
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(storage[i][j] == cur)
                storage[i][j] = ' ';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    R = storage.size();
    C = storage[0].size();
    
    for(const string& cmd : requests) {
        if(cmd.length() == 1) {
            Forklift(cmd[0], storage);
        }
        else {
            Crane(cmd[0], storage);
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(storage[i][j] != ' ')
                cnt++;
        }
    }
    
    return cnt;
}
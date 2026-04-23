#include <vector>
#include <queue>

using namespace std;

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 1;
    
    while(!q.empty()) {
        auto [cur_y, cur_x] = q.front();
        q.pop();
        
        if(cur_y == n - 1 && cur_x == m - 1)
            return dist[cur_y][cur_x];
        
        for(int i = 0; i < 4; ++i) {
            int nx = cur_x + dir_x[i];
            int ny = cur_y + dir_y[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if(dist[ny][nx] > 0)
                continue;
            if(maps[ny][nx] == 0)
                continue;
            
            dist[ny][nx] = dist[cur_y][cur_x] + 1;
            q.emplace(ny, nx);
        }
    }
    
    
    return -1;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int r = park.size(), c = park[0].size();
    
    int cur_x = 0, cur_y = 0;
    for(int i = 0; i < r; ++i) {        
        for(int j = 0; j < c; ++j) {
            if(park[i][j] == 'S') { cur_x = j; cur_y = i; }
        }
    }
    
    for(int i = 0; i < (int)routes.size(); ++i) {
        char op = routes[i][0];
        int n = routes[i][2] - '0';
        
        int temp_x = cur_x, temp_y = cur_y;
        int dx = 0, dy = 0;
        
        if(op == 'N')
            dy = -1;
        else if(op == 'S')
            dy = 1;
        else if(op == 'W')
            dx = -1;
        else 
            dx = 1;
        
        bool isPossible = true;
        for(int j = 0; j < n; ++j) {
            temp_x += dx;
            temp_y += dy;
            
            if(temp_x < 0 || temp_x >= c || temp_y < 0 || temp_y >= r 
               || park[temp_y][temp_x] == 'X') 
                { isPossible = false; break;  }
        }
    
        if(isPossible) { cur_x = temp_x; cur_y = temp_y; }
    }
    
    answer = {cur_y, cur_x};
    return answer;
}
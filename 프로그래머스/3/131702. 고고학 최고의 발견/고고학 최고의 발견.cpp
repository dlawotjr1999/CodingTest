#include <string>
#include <vector>

using namespace std;

const int dir_x[5] = { 0,0,1,0,-1 };
const int dir_y[5] = { 0,-1,0,1,0 };

const int INF = 1e8;

int answer;
vector<vector<int>> first_rows;

void Rotate(vector<vector<int>>& board, int y, int x, int cnt) {
    int n = board.size();

    for (int d = 0; d < 5; ++d) {
        int ny = y + dir_y[d];
        int nx = x + dir_x[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;

        board[ny][nx] = (board[ny][nx] + cnt) % 4;
    }
}

int Calculate(const vector<int>& row, const vector<vector<int>>& clockHands) {
    int n = clockHands.size();
    vector<vector<int>> board = clockHands;
    
    int cnt = 0;
    
    for(int i = 0; i < n; ++i) {
        if(row[i] == 0)
            continue;
        Rotate(board, 0, i, row[i]);
        cnt += row[i];
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int up = board[i - 1][j];
            
            if(up != 0) {
                int need = (4 - up) % 4;
                Rotate(board, i, j, need);
                cnt += need;
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        if(board[n - 1][i] != 0)
            return INF;
    }
    
    return cnt;
}

void DFS(vector<int>& temp, const vector<vector<int>>& clockHands) {
    if(temp.size() >= clockHands.size()) {
        int num = Calculate(temp, clockHands);
        answer = min(answer, num);
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        temp.push_back(i);
        DFS(temp, clockHands);
        temp.pop_back();
    }
}

int solution(vector<vector<int>> clockHands) {
    int n = clockHands.size();
    answer = INF;
    
    vector<int> temp; 
    DFS(temp, clockHands);
    
    return answer;
}
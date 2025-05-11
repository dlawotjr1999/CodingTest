#include <string>
#include <vector>

using namespace std;

int N;
int answer;
vector<int> field;

bool Promising(int row) {
    for(int i = 0; i < row; i++) {
        if(field[row] == field[i] || row - i == abs(field[row] - field[i])) {
            return false;
        }
    }
    return true;
}

void DFS(int row) {
    if(row == N) {
        answer++;
        return;
    }
    
    for(int col = 0; col < N; col++) {
        field[row] = col;
        
        if(Promising(row)) {
            DFS(row+1);
        }    
    }
}

int solution(int n) {
    N = n;
    answer = 0;
    field.resize(n, 0);
    DFS(0);              
    return answer;
}
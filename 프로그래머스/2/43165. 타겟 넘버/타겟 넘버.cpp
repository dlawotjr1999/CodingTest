#include <string>
#include <vector>

using namespace std;

int answer;

void DFS(int idx, int cur, vector<int> numbers, int target) {
    if(idx >= (int)numbers.size()) {
        if(cur == target)
            answer++;
        return;
    }
    
    DFS(idx + 1, cur + numbers[idx], numbers, target);
    DFS(idx + 1, cur - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {   
    DFS(0, 0, numbers, target);
    
    return answer;
}
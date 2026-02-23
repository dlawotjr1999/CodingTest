#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    unordered_map<string, bool> visited;

    visited[words[0]] = true;
    int turn = 1, cur = 1;
    
    for(int i = 1; i < words.size(); ++i) {
        if(visited[words[i]] || words[i - 1].back() != words[i][0]) {
            answer = {cur + 1, turn};
            break;
        }
        
        visited[words[i]] = true;
        cur++;
        if(cur == n) {
            turn++; cur = 0;
        }
    }    
    
    return answer;
}
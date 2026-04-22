#include <string>
#include <vector>

using namespace std;

const int cost[3][3] = { {1,1,1}, {5,1,1}, {25,5,1} };
int answer = 1e8;

// 0 : 0 1 2 3 4
// 1 : 5 6 7 8 9

void DFS(vector<int>& vec, int num, vector<int>& picks, const vector<string>& minerals) {
    if(num == 0 || vec.size() * 5 >= minerals.size()) {
        int temp = 0;
        
        for(int i = 0; i < (int)vec.size(); ++i) {
            int cur = vec[i];
            
            for(int j = i * 5; j < i * 5 + 5 && j < (int)minerals.size(); ++j) {
                int mineral = 0;
                
                if(minerals[j] == "diamond")
                    mineral = 0;
                else if(minerals[j] == "iron")
                    mineral = 1;
                else
                    mineral = 2;
                
                temp += cost[cur][mineral];
            }
        }
        
        answer = min(answer, temp);
        return;
    }
    
    for(int i = 0; i < (int)picks.size(); ++i) {
        if(picks[i] == 0)
            continue;
        picks[i]--;
        vec.push_back(i);
        DFS(vec, num - 1, picks, minerals);
        vec.pop_back();
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {    
    int num = 0;
    for(int p : picks)
        num += p;
    
    vector<int> vec;
    DFS(vec, num, picks, minerals);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

const int MAX = 100;

int N;
int answer;

vector<bool> selected;
vector<bool> infected;
vector<pair<int, int>> graph[MAX + 1];

int DFS(int start, int type) {
    infected[start] = true;
    int cnt = 0;
    
    for(auto next : graph[start]) {
        if(!infected[next.first] && next.second == type) {
            infected[next.first] = true;
            cnt += (1 + DFS(next.first, type));
        }
    }
    
    return cnt;
}

void Permutation(vector<int>& vec, int k, int infection) {
    if(vec.size() == k) {
        infected.assign(N + 1, false);
        infected[infection] = true;
        
        int cnt = 1;
        
        for(int type : vec) {
            vector<int> current;
            
            for (int i = 1; i <= N; ++i) {
                if (infected[i]) 
                    current.push_back(i);
            }
            
            for(int c : current) {
                cnt += DFS(c, type);
            }
        }
        
        answer = max(answer, cnt);
        return;
    }

    for(int i = 1; i <= 3; ++i) {
        vec.push_back(i);
        Permutation(vec, k, infection);
        vec.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N = n;
    answer = -1;
    
    // 그래프 초기화
    for(vector<int> edge : edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);    
        graph[edge[1]].emplace_back(edge[0], edge[2]);    
    }    
    selected.assign(4, false);
    
    // 경우의 수 탐색
    vector<int> vec;
    Permutation(vec, k, infection);
    
    // 다시 비우기
    for(int i = 0; i <= MAX; ++i) {
       graph[i].clear();
    }
    selected.clear();
    
    return answer;
}
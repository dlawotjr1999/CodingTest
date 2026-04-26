#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    // 생성 노드, 도넛 그래프, 막대 그래프. 8자 그래프
    int n = 0, g1 = 0, g2 = 0, g3 = 0;
    
    vector<int> answer;
    
    int max_node = -1;
    for(auto& e : edges) {
        max_node = max({max_node, e[0], e[1]});
    }

    vector<int> in(max_node + 1, 0);
    vector<int> out(max_node + 1, 0);
    
    for (auto &e : edges) {
        int a = e[0], b = e[1];
        out[a]++;
        in[b]++;
    }

    for (int v = 1; v <= max_node; v++) {
        if(in[v] + out[v] == 0)
            continue;
        
        if (in[v] == 0 && out[v] >= 2) 
            n = v;
        if (out[v] == 0) 
            g2++;
        if (in[v] >= 2 && out[v] == 2) 
            g3++;
    }
    
    g1 = out[n] - g2 - g3;
    answer = {n, g1, g2, g3};
    return answer;
}
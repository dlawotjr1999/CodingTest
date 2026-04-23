#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> combs;

void DFS(int remain, int idx, vector<int>& temp) {
    if(remain <= 0) {
        combs.push_back(temp);
        return;
    }
    
    for(int i = idx; i < temp.size(); ++i) {
        temp[i]++;
        DFS(remain - 1, i, temp);
        temp[i]--;
    }
}

int Calculate(vector<int>& comb, vector<vector<int>>& reqs) {
    priority_queue<int, vector<int>, greater<int>> pq[comb.size()];
    int result = 0;  
    
    for(int i = 1; i < comb.size(); ++i){
        for(int j = 0; j < comb[i]; ++j) 
            pq[i].push(0);
    }
    
    for(auto req : reqs) {
        int arrive = req[0];
        int duration = req[1];
        int num = req[2];
        
        int top = pq[num].top();
        pq[num].pop();
        
        if(top < arrive) {
            pq[num].push(arrive + duration);
        }
        else if(top == arrive) {
            pq[num].push(top + duration);
        }
        else {
            result += (top - arrive);
            pq[num].push(top + duration);
        }
    }
    
    return result;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 1e8;
    
    vector<int> temp(k + 1, 1);
    DFS(n - k, 1, temp);
    
    for(auto comb : combs) {
        answer = min(answer, Calculate(comb, reqs));
    }
    
    return answer;
}
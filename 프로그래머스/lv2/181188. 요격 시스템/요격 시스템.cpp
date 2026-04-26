#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& l, vector<int>& r) {
    return l[1] < r[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), comp);
    
    int e = 0;
    for(int i = 0; i < targets.size(); ++i) {
        if(e <= targets[i][0]) {
            answer++;
            e = targets[i][1];
        }    
    }
    
    return answer;
}
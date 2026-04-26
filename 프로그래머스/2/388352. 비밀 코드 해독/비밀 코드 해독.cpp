#include <string>
#include <vector>

using namespace std;

int answer;

bool isValid(vector<int>& nums, vector<vector<int>>& q, vector<int>& ans) {
    for(int i = 0; i < (int)q.size(); ++i) {
        vector<int> cur = q[i];
        int cnt = 0;
        
        for(int c : cur) {
            for(int n: nums)
                if(c == n)
                    cnt++;
        }
        
        if(cnt != ans[i]) return false;    
    }
    
    return true;
}

void DFS(int start, int n, vector<int>& nums, vector<vector<int>>& q, vector<int>& ans) {
    if((int)nums.size() == 5) {
        if(isValid(nums, q, ans))
            answer++;
        return;
    }
    
    for(int i = start; i <= n; ++i) {
        nums.push_back(i);
        DFS(i + 1, n, nums, q, ans);
        nums.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {    
    answer = 0;
    vector<int> nums;
    DFS(1, n, nums, q, ans);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void check(int pwd, vector<vector<int>> q, vector<int> ans) {
    for(int i  = 0; i < q.size(); i++) {
        int compare = 0, cnt = 0;
        for(int bit : q[i]) 
            compare += (1 << bit-1);
        cnt = __builtin_popcount(pwd & compare);
        if(cnt != ans[i]) 
            return;
    }
    answer++;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int temp = 0;
    
    for(int i = 1; i <= n - 4; i++) {
         for(int ii = i + 1; ii <= n - 3; ii++) {
             for(int iii = ii + 1; iii <= n - 2; iii++) {
                for(int iv = iii + 1; iv <= n - 1; iv++) {
                    for(int v = iv + 1; v <= n; v++) {
                        temp = (1 << (i - 1) | 1 << (ii - 1) | 1 << (iii - 1) | 1 << (iv - 1) | 
                                1 << (v - 1));    
                        check(temp, q, ans);
                    }
                }                      
            }        
        }
    }
    return answer;
}
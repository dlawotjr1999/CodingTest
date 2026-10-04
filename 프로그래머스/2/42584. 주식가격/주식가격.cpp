#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();

    vector<int> answer(n);
    stack<int> s;  

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && prices[s.top()] >= prices[i]) 
            s.pop();

        if (s.empty()) 
            answer[i] = n - 1 - i;
        else 
            answer[i] = s.top() - i;
        s.push(i);
    }

    return answer;
}
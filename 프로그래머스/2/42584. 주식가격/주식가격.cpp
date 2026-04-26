#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < (int)prices.size(); ++i) {
        int cur = 0;
        
        for(int j = i + 1; j < (int)prices.size(); ++j) {
            cur++;
            
            if(prices[i] > prices[j])
                break;
        }
        
        answer.push_back(cur);
    }
    
    return answer;
}
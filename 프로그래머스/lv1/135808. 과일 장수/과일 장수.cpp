#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int N = score.size() / m;
    
    sort(score.begin(), score.end(), greater<int>());
    vector<vector<int>> apples(N + 1);
    
    for(int i = 0; i < score.size(); ++i) 
        apples[i / m].push_back(score[i]);
    
    int answer = 0;
    for(const auto& apple : apples) {
        if(apple.size() == m) {
            answer += (apple.back() * m);
        }
    }
    
    return answer;
}
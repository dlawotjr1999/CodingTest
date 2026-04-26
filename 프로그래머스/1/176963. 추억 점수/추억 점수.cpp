#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < name.size(); ++i) {
        m[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); ++i) {
        vector<string> cur = photo[i];
        int score = 0;
        
        for(int j = 0; j < cur.size(); ++j) {
            if(m[cur[j]] != 0) {
                score += m[cur[j]];
            }
        }
        answer.push_back(score);
    }
    
    return answer;
    
    
    
    
}
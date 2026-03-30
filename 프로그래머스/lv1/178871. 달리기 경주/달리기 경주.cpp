#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    vector<string> answer = players;
    
    for(int i = 0; i < players.size(); ++i) {
        m[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); ++i) {
        int loc = m[callings[i]];
        
        m[answer[loc - 1]]++;
        m[callings[i]]--;
        
        string tmp = answer[loc];
        answer[loc] = answer[loc - 1];
        answer[loc - 1] = tmp;
    }
    
    return answer;
}
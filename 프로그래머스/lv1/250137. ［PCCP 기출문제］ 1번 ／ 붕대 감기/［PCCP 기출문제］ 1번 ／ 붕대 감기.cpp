#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int last = attacks[attacks.size() - 1][0];
    int cur_health = health;
    
    unordered_map<int, int> attack_info;
    for(int i = 0; i < attacks.size(); ++i) {
        attack_info[attacks[i][0]] = attacks[i][1];    
    }
    
    int duration = 0;
    
    for(int t = 0; t <= last; ++t) {
        if(attack_info[t] != 0) {
            cur_health -= attack_info[t];  
            duration = 0;
            
            if(cur_health <= 0) {
                cur_health = -1;
                break;
            }
            continue;
        }
            
        cur_health += bandage[1];
        cur_health = min(cur_health, health); 
        duration++;
            
        if(duration == bandage[0]) {
            cur_health += bandage[2];  
            cur_health = min(cur_health, health); 
            duration = 0;
        }
    }    
    
    answer = cur_health;
    return answer;
}
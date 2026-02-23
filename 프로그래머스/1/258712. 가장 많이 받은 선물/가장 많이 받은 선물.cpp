#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int N = friends.size();
    
    unordered_map<string, int> um;
    for(int i = 0; i < N; ++i) {
        um[friends[i]] = i;
    }
    
    vector<vector<int>> info(N, vector<int>(N, 0));
    vector<int> give(N, 0); vector<int> take(N, 0); vector<int> index(N, 0);
    
    for(int i = 0; i < gifts.size(); ++i) {
        string s1 = "", s2 = "";
        
        string cur = "";
        for(int j = 0; j < (int)gifts[i].length(); ++j) {
            if(gifts[i][j] != ' ') 
                cur += gifts[i][j];
            else {
                s1 = cur; cur = "";
            }
        }
        s2 = cur;
        
        info[um[s1]][um[s2]]++;
        give[um[s1]]++;
        take[um[s2]]++;
    }
    
    for(int i = 0; i < N; ++i)
        index[i] = give[i] - take[i];
    
    vector<int> next_gifts(N, 0);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i == j) continue;
            
            if(info[i][j] > info[j][i])
                next_gifts[i]++;
             else if (info[i][j] == info[j][i] && index[i] > index[j]) 
                 next_gifts[i]++;
        }
    }
    
    answer = *max_element(next_gifts.begin(), next_gifts.end());
    return answer;
}
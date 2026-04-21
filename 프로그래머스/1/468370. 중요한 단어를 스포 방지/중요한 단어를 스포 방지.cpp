#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.length();
    int answer = 0;
    
    unordered_map<string, int> strToExist;
    vector<bool> isMasked(n, false);
    
    for(int i = 0; i < (int)spoiler_ranges.size(); ++i) {
        int l = spoiler_ranges[i][0], r = spoiler_ranges[i][1];
        
        for(int j = l; j <= r; ++j) 
            isMasked[j] = true;
    }
    
    string words = "";
    bool isMask = false;
    for(int i = 0; i < message.length(); ++i) {
        if(message[i] == ' ') {
            if(!words.empty() && !isMask)
                strToExist[words]++;
            words = "";
            isMask = false;
            continue;
        }
        if(isMasked[i])
            isMask = true;
        else
            words.push_back(message[i]);
    }
    if(!words.empty() && !isMask)
        strToExist[words]++;
    
    for(int i = 0; i < (int)spoiler_ranges.size(); ++i) {
        int l = spoiler_ranges[i][0], r = spoiler_ranges[i][1];
        
        if(message[l] == ' ') l++;
        if(message[r] == ' ') r--;
        
        while(l >= 0 && message[l] != ' ') l--;
        while(r < n && message[r] != ' ') r++;
        
        if(l > r) continue;
        
        string cur = "";
        for(int i = l + 1; i < r; ++i) {
            cur += message[i];
        }

        string cur_str = "";
        for(int i = 0; i < cur.length(); ++i) {
            if(cur[i]  == ' ') {    
                if(!cur_str.empty() && strToExist[cur_str] == 0) {
                    answer++;
                    strToExist[cur_str]++;
                }
                cur_str = "";
            }
            else 
                cur_str += cur[i];
        }
        if(!cur_str.empty() && strToExist[cur_str] == 0) {
            answer++;
            strToExist[cur_str]++;
        }
    }
    
    return answer;
}
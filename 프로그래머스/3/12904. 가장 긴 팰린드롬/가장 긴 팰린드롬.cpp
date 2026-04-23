#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int len = s.length();
    int answer=1;
    
    for(int i = 0; i < len; ++i) {
        int cur_len = 0;
        int l = 0, r = 0;
        
        l = i - 1; r = i + 1;
        cur_len = 1;
        
        while(l >= 0 && r < len) {
            if(s[l] == s[r]) {
                cur_len += 2;
                l--; r++;
            }
            else {
                break;
            }      
        }
        answer = max(answer, cur_len);

        l = i; r = i + 1;
        cur_len = 0;
        
        while(l >= 0 && r < len) {
            if(s[l] == s[r]) {
                cur_len += 2;
                l--; r++;
            }
            else {
                break;
            }      
        }
        answer = max(answer, cur_len);
    }

    return answer;
}
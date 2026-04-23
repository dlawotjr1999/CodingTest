#include <string>
#include <vector>

using namespace std;

// 8255
// 8

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0) {
        int mod = storey % 10;
        int next = (storey / 10) % 10;
        
        if(mod > 5) {
            answer += (10 - mod);
            storey += 10;
        }   
        else if(mod == 5) {
            if(next >= 5) {
                answer += 5;
                storey += 10;
            }
            else
                answer += 5;
        }
        else {
            answer += mod;
        }
        
        storey /= 10;
    }
    
    return answer;
}
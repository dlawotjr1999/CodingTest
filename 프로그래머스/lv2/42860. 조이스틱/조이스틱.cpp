#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int n = name.length();
    int answer = 0;

    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }
    
    int move = n - 1;
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        
        while(next < n && name[next] == 'A')
            next++;
        
        int c1 = i * 2 + (n - next);
        int c2 = 2 * (n - next) + i;
        move = min({ move, c1, c2 });
    }
    answer += move;
    
    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int area = brown + yellow;
    int a, b;
    
    for(int i = 1; i <= area; ++i) {
        if(area % i == 0) {
            int cur_x = i;
            int cur_y = area / i;
            int inner = (cur_x - 2) * (cur_y - 2);    
            
            if(inner == yellow) {
                a = max(cur_x, cur_y);
                b = min(cur_x, cur_y);
                break;
            }

        }
    }
    
    answer.push_back(a);
    answer.push_back(b);
    
    return answer;
}
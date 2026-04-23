#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int len = 1;
    
    for(size_t i = 0; i < signals.size(); ++i) {
        int g = signals[i][0];
        int y = signals[i][1];
        int r = signals[i][2];
        
        len *= (g + y + r);
    }
    
    vector<int> vec(len + 1, 0);
    for(size_t i = 0; i < signals.size(); ++i) {
        int g = signals[i][0];
        int y = signals[i][1];
        int r = signals[i][2];
        
        int offset = (g + y + r);
        
        for(int j = 1; j <= len; j += offset) {
            for(int k = 0; k < y; ++k) {
                vec[g + j + k]++;
            }
        }
    }
    
     for (int i = 1; i <= len; ++i) {
            if (vec[i] == (int)signals.size()) {
                return i;
            }
        }
    
    return -1;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int r = park.size(), c = park[0].size();
    sort(mats.begin(), mats.end());
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            
            if(park[i][j] == "-1") {
                bool isPossible = true;
                
                for(int mat : mats) {
                    for(int mat_r = 0; mat_r < mat; ++mat_r) {
                        for(int mat_c = 0; mat_c < mat; ++mat_c) {
                            int nr = i + mat_r;
                            int nc = j + mat_c;
                            
                            if(nr < 0 || nr >= r || nc < 0 || nc >= c ||
                              park[nr][nc] != "-1") {
                                isPossible = false;
                                break;
                            }
                        }
                        if(!isPossible) 
                            break;
                    }    
                    if(isPossible) 
                        answer = max(answer, mat);
                    else
                        break;
                }
            }
        }
    }
    
    return answer;
}
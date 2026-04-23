#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<pair<int, int>> coords;
    
    for(int i = 0; i < (int)wallpaper.size(); ++i) {
        for(int j = 0; j < (int)wallpaper[i].size(); ++j) {
            if(wallpaper[i][j] == '#') {
                coords.emplace_back(i, j);
            }
        }
    }
    
    sort(coords.begin(), coords.end());
    int min_y = coords[0].first, max_y = coords.back().first + 1;
    
    sort(coords.begin(), coords.end(), [](const auto& l, const auto& r) {
        return l.second < r.second;
    });
    int min_x = coords[0].second, max_x = coords.back().second + 1;
    
    return { min_y, min_x, max_y, max_x };
}
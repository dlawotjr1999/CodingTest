#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
        return l.second > r.second;
    }
};

pair<int, int> ToTime(vector<string>& cur) {
    vector<int> vec;
    
    for(string& s : cur) {
        int hh = stoi(s.substr(0, 2));
        int mm = stoi(s.substr(3, 2));
        
        vec.push_back(hh * 60 + mm);
    }
    
    pair<int, int> t = { vec[0], vec[1] };
    return t;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> book_time_nums;
    
    for(vector<string> t : book_time) {
        book_time_nums.push_back(ToTime(t));    
    }
    sort(book_time_nums.begin(), book_time_nums.end());
    for(auto t : book_time_nums) {
        cout << t.first << '-' << t.second << ' ';
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;    
    for(int i = 0; i < (int)book_time_nums.size(); ++i) {
        if(!pq.empty()) {            
            if(book_time_nums[i].first >= pq.top().second + 10)
                pq.pop();
        }
        pq.emplace(book_time_nums[i]);
    }
    
    return pq.size();
}
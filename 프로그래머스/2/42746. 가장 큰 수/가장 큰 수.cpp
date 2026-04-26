#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> vec;
    for(int num : numbers) {
        string cur = to_string(num);
        vec.push_back(cur);
    }
    sort(vec.begin(), vec.end(), [](const string& l, const string& r) {
        return l + r > r + l;
    });
    
    for(string s : vec)
        answer += s;
    if(answer[0] == '0')
        return "0";
    
    return answer;
}
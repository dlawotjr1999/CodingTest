#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) { 
    unordered_map<string, bool> numToExist;
    for(string num : phone_book)
        numToExist[num] = true;
    
    for(int i = 0; i < (int)phone_book.size(); ++i) {
        string cur = phone_book[i];
        
        for(int j = 1; j < cur.length(); ++j) {
            string temp = cur.substr(0, j);
            if(numToExist[temp])
                return false;
        }
    }
    
    return true;
}
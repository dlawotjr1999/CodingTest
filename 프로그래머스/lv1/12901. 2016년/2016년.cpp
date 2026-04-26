#include <string>
#include <vector>

using namespace std;

int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
string days[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    
    int to_days = 0;
    for(int i = 0; i < (a - 1); ++i) {
        to_days += month[i];
    }
    to_days += b;
    
    answer = days[to_days % 7];
    return answer;
}
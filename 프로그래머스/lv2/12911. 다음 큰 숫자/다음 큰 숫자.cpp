#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string bin = "";
    
    while(n > 0) {
        bin += '0' + (n % 2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    bin = "0" + bin;
    
    int idx = 0;
    for(int i = bin.length() - 1; i >= 1; --i) {
        if(bin[i - 1] < bin[i]) {
            idx = i - 1;
            swap(bin[i - 1], bin[i]);
            break;
        }
    }
    sort(bin.begin() + idx + 1, bin.end());
    
    int cur = 1;
    for(int i = bin.length() - 1; i >= 0; --i) {
        answer += cur * (bin[i] - '0');
        cur *= 2;
    }
    
    return answer;
}
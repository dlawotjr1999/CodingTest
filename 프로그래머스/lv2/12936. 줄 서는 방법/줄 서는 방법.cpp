#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> numbers;
    vector<int> answer;
    
    long long fact = 1;
    for(int i = 1; i <= n; ++i) {
        numbers.push_back(i);
        fact *= i;
    }

    k--;
    for(int i = n; i >= 1; --i) {
        fact /= i;
        int idx = k / fact;
        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);
        k %= fact;
    }
    
    
    
    return answer;
}
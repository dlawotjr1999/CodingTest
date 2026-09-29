#include <string>
#include <vector>

using namespace std;

const int MAX = 10000000;

// 들어가는 값 : 본인을 제외한 가장 큰 약수
vector<int> solution(long long begin, long long end) {
    int s = end - begin + 1;
    vector<int> answer(s, 1);

    for(long long num = begin; num <= end; ++num) {
        int idx = num - begin;

        if(num == 1) {
            answer[idx] = 0;
            continue;
        }

        for(long long j = 2; j * j <= num; ++j) {
            if(num % j != 0)
                continue;
            
            if(num / j <= MAX) {
                answer[idx] = num / j;
                break;
            }
            answer[idx] = (int)j;
        }
    }

    return answer;
}
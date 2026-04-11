#include <string>
#include <vector>

using namespace std;

long long answer;

int distLimit;
int splitLimit;

void DFS(long long cur_leaf, long long remain_dist, long long cur_split) {
    if(cur_split > splitLimit)
        return;
    
    answer = max(answer, cur_leaf);
    
    if(cur_leaf > remain_dist) {
        if(cur_split * 3 <= splitLimit) {
            answer = max(answer, cur_leaf + remain_dist * 2);
        }
        if(cur_split * 2 <= splitLimit) {
            answer = max(answer, cur_leaf + remain_dist);
        }
        return;
    }
    
    DFS(cur_leaf * 2, remain_dist - cur_leaf, cur_split * 2);
    DFS(cur_leaf * 3, remain_dist - cur_leaf, cur_split * 3);
}

int solution(int dist_limit, int split_limit) {
    distLimit = dist_limit;
    splitLimit = split_limit;
    
    DFS(1, dist_limit, 1);
    
    return answer;
}
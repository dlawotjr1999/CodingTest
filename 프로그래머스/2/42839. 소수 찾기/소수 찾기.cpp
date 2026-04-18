#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> primes(10000000, true);
vector<bool> checked(10000000, false);
int answer;

void SieveOfEratosthenes(vector<bool>& primes) {
    for(int i = 2; i * i < 10000000; ++i) {
        for(int j = i * i; j < 10000000; j += i) {
            primes[j] = false;
        }
    }
}

void DFS(int len, string& cur, const string& nums, vector<bool>& visited) {
    if((int)cur.size() == len) {
        int n = stoi(cur);
        
        if(!checked[n] && primes[n]) {
            checked[n] = true;
            answer++;
        }
        
        return;
    }
    
    for(int i = 0; i < nums.length(); ++i) {
        if(visited[i])
            continue;
        
        visited[i] = true;
        cur.push_back(nums[i]);
        DFS(len, cur, nums, visited);  
        cur.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    primes[0] = primes[1] = false;
    SieveOfEratosthenes(primes);
    
    for(int len = 1; len <= numbers.length(); ++len) {
        string cur = "";
        vector<bool> visited(len);
        
        DFS(len, cur, numbers, visited);
    }
    
    return answer;
}
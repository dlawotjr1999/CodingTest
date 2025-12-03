#include <iostream>
#include <vector>

int freq[3001];

int main() {
    int N, d, k, c;
    std::cin >> N >> d >> k >> c;

    std::vector<int> sushi(N);
    for (int i = 0; i < N; ++i)
        std::cin >> sushi[i];

    int cnt = 0; 
    for (int i = 0; i < k; ++i) {
        if (freq[sushi[i]] == 0)
            cnt++;
        freq[sushi[i]]++;
    }

    int answer = cnt;
    if (freq[c] == 0) 
        answer++;
    
    for (int i = 1; i < N; ++i) {
        int left = sushi[i - 1];                 
        int right = sushi[(i + k - 1) % N];        

        freq[left]--;
        if (freq[left] == 0) 
            cnt--;

        if (freq[right] == 0) 
            cnt++;
        freq[right]++;

        int current = cnt;
        if (freq[c] == 0) 
            current++;

        answer = std::max(answer, current);
    }

    std::cout << answer;
    return 0;
}
#include <iostream>
#include <vector>

// 초밥의 종류를 번호로 표현하는 회전 초밥 음식점에서 행사를 진행하고 있으며, 그 행사는 아래와 같이 이루어짐
// 1. 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공
// 2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공함
// 3. 만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공함
// 이 때, 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값을 구하는 문제

// 현재 윈도우에 초밥 x가 몇 개 있는지 저장하는 배열
int freq[3001];

int main() {
    int N, d, k, c;
    std::cin >> N >> d >> k >> c;

    std::vector<int> sushi(N);
    for (int i = 0; i < N; ++i)
        std::cin >> sushi[i];

    // 한 윈도우에 있는 초밥들의 종류의 갯수와 각 초밥들의 빈도 계산 
    int cnt = 0; 
    for (int i = 0; i < k; ++i) {
        if (freq[sushi[i]] == 0)
            cnt++;
        freq[sushi[i]]++;
    }

    // 쿠폰 번호에 해당하는 초밥이 윈도우 내에 없으면 종류 수 증가
    int answer = cnt;
    if (freq[c] == 0) 
        answer++;
    
    // 윈도우 순회
    for (int i = 1; i < N; ++i) {
        int left = sushi[i - 1];                 
        int right = sushi[(i + k - 1) % N];        

        // 이전 윈도우의 맨 앞 초밥 제거
        // 제거 후 0개가 되면 종류 감소
        freq[left]--;
        if (freq[left] == 0) 
            cnt--;

        // 새로 포함될 초밥 확인
        // 새로운 종류의 초밥일 시 종류 증가
        if (freq[right] == 0) 
            cnt++;
        freq[right]++;

        // 현재 윈도우에 있는 초밥의 종류의 수를 저장
        // 쿠폰 번호에 해당하는 초밥의 빈도가 0이면 종류 증가
        int current = cnt;
        if (freq[c] == 0) 
            current++;

        answer = std::max(answer, current);
    }

    std::cout << answer;
    return 0;
}
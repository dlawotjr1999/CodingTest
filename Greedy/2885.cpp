#include <iostream>

// 상근이가 K개의 초콜릿 조각을 먹기 위해 초콜릿을 쪼개는 문제
// 주어진 초콜릿은 2의 제곱 갯수로 이루어진 막대 초콜릿이며, 오로지 가운데로만 쪼갤 수 있음
// 이 때 몇 번 쪼개야 K개를 만들 수 있는지와 사야하는 최소 초콜릿 크기를 구하는 문제

int main() {
    int K;
    std::cin >> K;

    int size = 1;   // 초콜릿의 크기
    int piece = 0;  // 나누어진 초콜릿 조각 수들의 합
    int cut = 0;    // 초콜릿을 자른 횟수

    // 초콜릿의 크기는 K보다 큰 2의 제곱수들 중 가장 작은 수여야 함
    while (K > size) {
        size *= 2;
    }

    // 초콜릿을 자른 횟수를 구하기
    // 기존에 잘려져 있던 조각수(piece)와 한 번 더 잘랐을 때의 수(temp)의 합이 K인 경우 종료
    // 그 합이 K보다 작으면 piece에 추가
    // K보다 크든 작든 자르는 연산은 진행되어야 함
    if (size != K) {
        int temp = size / 2;
        cut++;

        while (piece + temp != K) {
            if (piece + temp < K)
                piece += temp;
            temp /= 2;
            cut++;
        }

        // different solution
        /* 
        int temp = size;
        
        while (K % temp != 0) {
            temp /= 2;
            cnt++;
        }
        */
    }

    std::cout << size << " " << cut << std::endl;

    return 0;
}

#include <bits/stdc++.h>

// 어떤 문자들이 주어질 때 그 단어를 이루는 알파벳들로 만들 수 있는 단어들이 사전순으로 정렬되어 있음
// 이때,  주어진 단어 다음에 나오는 단어를 찾는 문제
// 참고 : https://howudong.tistory.com/192

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string str;
		std::cin >> str;
		
		// 문자열의 끝에서부터 비교 탐색 시작
		// 역순 탐색 시 오름차순이 깨지는 부분을 탐색
		// 즉, 이 루프문으로 구하는 것은 교환될 위치 idx
		int idx = str.length() - 2;
		while (idx >= 0 && str[idx] >= str[idx + 1]) 
			idx--;

		// 문자열의 처음까지 탐색했을 때 
		// 이 때는 주어진 알파벳으로 만든 문자열 조합 중 가장 뒤쪽에 있으므로 그대로 출력
		if (idx < 0) {
			std::cout << str << '\n';
			continue;
		}

		// 위치 idx의 문자(x)를 기준으로 끝에서부터 x보다 큰 문자의 위치 탐색
		// x보다 큰 문자와 교환을 해야 사전순으로 다음에 위치하기 때문
		// idx 뒤에 있는 문자들은 내림차순을 만족하기 때문에, 끝에서부터 탐색했을 때 처음 조건을 만족하는 위치가 str[j] <= str[idx]를 만족하는 가장 작은 문자
		// 즉, 이 루프문으로 구하는 것은 교환될 위치 j
		int j = str.length() - 1;
		while (str[j] <= str[idx])
			j--;

		// idx와 j를 swap
		std::swap(str[idx], str[j]);

		// (idx+1)번째 위치부터 문자열의 끝까지 정렬 수행
		std::sort(str.begin() + idx + 1, str.end());
		std::cout << str << '\n';
	}

	return 0;
}
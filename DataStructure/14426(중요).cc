#include <iostream>
#include <memory>

// 문자열 집합 S에서 부분 집합 S에 포함되어 있는 문자열 중 적어도 하나의 접두사인 것의 개수를 구하는 문제

// 참고 : https://ko.wikipedia.org/wiki/%ED%8A%B8%EB%9D%BC%EC%9D%B4_(%EC%BB%B4%ED%93%A8%ED%8C%85)

int answer;

// Trie 구현
struct Trie {
	std::unique_ptr<Trie> Node[26];

	void insert(const std::string& s, int idx) {
		if (idx == s.size())
			return;
		int cur = s[idx] - 'a';
		if (Node[cur] == nullptr)
			Node[cur] = std::make_unique<Trie>();
		Node[cur]->insert(s, idx + 1);
	}

	bool find(const std::string& s, int idx) {
		if (idx == s.size())
			return true;
		int cur = s[idx] - 'a';
		if (Node[cur] == nullptr)
			return false;
		return Node[cur]->find(s, idx + 1);
	}
};

int main() {
	int N, M;
	std::cin >> N >> M;

	Trie root;

	// 입력된 문자열들을 Trie에 삽입
	for (int i = 0; i < N; i++) {
		std::string str;  std::cin >> str;
		root.insert(str, 0);
	}
	
	// 각 접두어들을 Trie 내에서 탐색
	for (int i = 0; i < M; i++) {
		std::string prefix;  std::cin >> prefix;
		if (root.find(prefix, 0)) 
			answer++;
	}

	std::cout << answer;
	return 0;
}
#include <iostream>
#include <memory>

int answer;

struct Trie {
	std::unique_ptr<Trie> Node[26];

	Trie() = default;

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
	for (int i = 0; i < N; i++) {
		std::string str;  std::cin >> str;
		root.insert(str, 0);
	}
	
	for (int i = 0; i < M; i++) {
		std::string str;  std::cin >> str;
		if (root.find(str, 0)) 
			answer++;
	}

	std::cout << answer;
	return 0;
}
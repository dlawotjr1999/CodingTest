#include <iostream>
#include <vector>

// 단순 트리 순회 문제
// 기본 알고리즘 중 하나이므로 기억해둬야 함

struct node {
	char c;
	node* left;
	node* right;
};

// 전위 순회
void Preorder(node* n) {
	std::cout << n->c;
	if (n->left != nullptr) Preorder(n->left);
	if (n->right != nullptr) Preorder(n->right);
}

// 중위 순회
void Inorder(node* n) {
	if (n->left != nullptr) Inorder(n->left);
	std::cout << n->c;
	if (n->right != nullptr) Inorder(n->right);
}

// 후위 순회
void Postorder(node* n) {
	if (n->left != nullptr) Postorder(n->left);
	if (n->right != nullptr) Postorder(n->right);
	std::cout << n->c;
}

int main() {
	int N;
	std::vector<node> vec(26);
	node* n;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		char left, right, root;
		std::cin >> root >> left >> right;

		vec[root - 'A'].c = root;
		if (left != '.') vec[root - 'A'].left = &vec[left - 'A'];
		if (right != '.') vec[root - 'A'].right = &vec[right - 'A'];
	}

	// 항상 A가 루트 노드임
	Preorder(&vec[0]);
	std::cout << '\n';
	Inorder(&vec[0]);
	std::cout << '\n';
	Postorder(&vec[0]);
}
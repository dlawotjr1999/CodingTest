#include <iostream>
#include <vector>

struct node {
	char c;
	node* left;
	node* right;
};

void Preorder(node* n) {
	std::cout << n->c;
	if (n->left != nullptr) Preorder(n->left);
	if (n->right != nullptr) Preorder(n->right);
}

void Inorder(node* n) {
	if (n->left != nullptr) Inorder(n->left);
	std::cout << n->c;
	if (n->right != nullptr) Inorder(n->right);
}

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
	Preorder(&vec[0]);
	std::cout << '\n';
	Inorder(&vec[0]);
	std::cout << '\n';
	Postorder(&vec[0]);
}
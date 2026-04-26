#include <bits/stdc++.h>

int N, M, K;
std::vector<long long> vec;
std::vector<long long> segment_tree;

long long CalculateSum(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return segment_tree[node];

	int mid = (start + end) / 2;
	long long left_sum = CalculateSum(node * 2, start, mid, left, right);
	long long right_sum = CalculateSum(node * 2 + 1, mid + 1, end, left, right);

	return left_sum + right_sum;
}

void UpdateValue(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end)
		return;
	segment_tree[node] = segment_tree[node] + diff;

	if (start != end) {
		int mid = (start + end) / 2;
		UpdateValue(node * 2, start, mid, idx, diff);
		UpdateValue(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

long long InitTree(int node, int start, int end) {
	if (start == end)
		return segment_tree[node] = vec[start];

	int mid = (start + end) / 2;
	long long left = InitTree(node * 2, start, mid);
	long long right = InitTree(node * 2 + 1, mid + 1, end);
	segment_tree[node] = left + right;

	return segment_tree[node];
}

int main() {
	std::cin >> N >> M >> K;

	vec.resize(N);
	segment_tree.resize(N * 4);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	InitTree(1, 0, N - 1);


	for(int i = 0; i < M + K; ++i) {
		long long a, b, c;
		std::cin >> a >> b >> c;

		if (a == 1) {
			long long temp = vec[b - 1];
			vec[b - 1] = c;
			long long diff = c - temp;

			UpdateValue(1, 0, N - 1, b - 1, diff);
		}
		else {
			std::cout << CalculateSum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}
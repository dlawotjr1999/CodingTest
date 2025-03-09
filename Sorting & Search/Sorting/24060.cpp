#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#pragma warning(disable : 4996)

int N, K, cnt;
int result = -1;
int* A;
int* tmp;

void merge(int* A, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
	}
	while (i <= q) tmp[t++] = A[i++];
	while (j <= r) tmp[t++] = A[j++];
	i = p;
	t = 1;
	while (i <= r) {
		A[i++] = tmp[t++];
		cnt++;
		if (cnt == K) {
			result = A[i - 1];
			break;
		}
	}
}

void merge_sort(int* A, int p, int r) {
	if (p < r) {
		int q = (int)((p + r) / 2);
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {

	std::cin >> N >> K;
	A = new int[N + 1];
	tmp = new int[N + 1];

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	merge_sort(A, 0, N - 1);
	std::cout << result;

	delete[] A;
	delete[] tmp;
}

//외부 코드 참고
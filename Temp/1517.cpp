#include <iostream>
#include <vector>

std::vector<int> vec;
std::vector<int> temp;

int N;
long long result;

void mergeSort(int start, int end) {
	if (end - start < 1)
		return;

	int mid = start + (end - start) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);

	for (int i = start; i <= end; i++)
		temp[i] = vec[i];

	int k = start;
	int idx1 = start;
	int idx2 = mid + 1;

	while (idx1 <= mid && idx2 <= end) {
		if (temp[idx1] > temp[idx2]) {
			vec[k] = temp[idx2];
			result = result + idx2 - k;
			k++;
			idx2++;
		}
		else {
			vec[k] = temp[idx1];
			k++;
			idx1++;
		}
	}

	while (idx1 <= mid) {
		vec[k] = temp[idx1];
		k++;
		idx1++;
	}
	while (idx2 <= end) {
		vec[k] = temp[idx2];
		k++;
		idx2++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	vec.resize(N + 1, 0);
	temp.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
		std::cin >> vec[i];

	mergeSort(1, N);
	std::cout << result;

	return 0;
}
#include <bits/stdc++.h>

int N;
int answer;

std::vector<int> beads;
std::vector<bool> selected;

void DFS(int size, int energy) {
	if (size == 2) {
		answer = std::max(answer, energy);
		return;
	}

	for (int i = 1; i < N - 1; ++i) {
		int cur_energy = 0;

		if (!selected[i]) {
			selected[i] = true;
			
			int l = i - 1, r = i + 1;
			while (l >= 0 && selected[l]) l--;
			while (r < N && selected[r]) r++;

			cur_energy = (beads[l] * beads[r]);
			DFS(size - 1, energy + cur_energy);

			selected[i] = false;
		}
	}
}

int main() {
	std::cin >> N;
	beads.resize(N, 0);
	selected.resize(N, false);

	for (int i = 0; i < N; ++i) {
		std::cin >> beads[i];
	}

	DFS(N, 0);
	std::cout << answer;
}
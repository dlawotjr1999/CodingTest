#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	auto CCW = [](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
		ll result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
		if (result < 0) {
			return -1;
		}
		else if (result > 0) {
			return 1;
		}
		return 0;
	};

	auto IsOverlap = [](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) -> bool {
		if (std::min(x1, x2) <= std::max(x3, x4) && std::min(x3, x4) <= std::max(x1, x2)
			&& std::min(y1, y2) <= std::max(y3, y4) && std::min(y3, y4) <= std::max(y1, y2)) {
			return true;
		}
		return false;
	};

	auto IsCross = [&](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) -> bool {
		int abc = CCW(x1, y1, x2, y2, x3, y3);
		int abd = CCW(x1, y1, x2, y2, x4, y4);
		int cda = CCW(x3, y3, x4, y4, x1, y1);
		int cdb = CCW(x3, y3, x4, y4, x2, y2);

		if (abc * abd == 0 && cda * cdb == 0) {
			return IsOverlap(x1, y1, x2, y2, x3, y3, x4, y4);
		}
		else if (abc * abd <= 0 && cda * cdb <= 0) {
			return true;
		}
		return false;
	};

	bool cross = IsCross(x1, y1, x2, y2, x3, y3, x4, y4);
	std::cout << cross ? 1 : 0;

	return 0;
}
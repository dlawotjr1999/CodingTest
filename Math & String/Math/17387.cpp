#include <iostream>
#include <cmath>

// 2차원 좌표계에 두 선분이 있을 때 두 선분의 교차 여부를 구하는 문제
// 한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차하는 것으로 취급함

typedef long long ll;

int main() {
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	// CCW Algorithm
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

	// 두 선분이 모두 일직선인 경우 교차 여부를 확인하는 함수
	// 한 선분의 min 값이 다른 선분의 max값보다 작은 경우에 선분은 겹친다고 볼 수 있음
	// 엄밀히 말해서, "구간 A의 시작 <= 구간 B의 끝" 그리고 "구간 B의 시작 <= 구간 A의 끝" 두 가지를 모두 만족해야 함 
	auto IsOverlap = [](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) -> bool {
		if (std::min(x1, x2) <= std::max(x3, x4) && std::min(x3, x4) <= std::max(x1, x2)
			&& std::min(y1, y2) <= std::max(y3, y4) && std::min(y3, y4) <= std::max(y1, y2)) {
			return true;
		}
		return false;
	};

	// 선분 ab, cd가 있을 때 두 선분의 교차 여부는, 한 선분을 기준으로 다른 선분의 한 점과의 CCW를 구함으로써 알 수 있음
	// 두 CCW 값의 곱이 음수이면 두 선분은 교차한다고 볼 수 있음
	// 만약 두 선분이 겹친다면(= 두 ccw 값이 모두 0이면) 겹침 여부를 판단해야 함
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
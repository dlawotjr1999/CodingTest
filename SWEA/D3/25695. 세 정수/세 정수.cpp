#include <iostream>

using namespace std;

int main() {
	int T;	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int X, Y, Z;
		cin >> X >> Y >> Z;

		if (X == Y && Y == Z && Z == X)
			cout << X << " " << X << " " << X;
		else if (X == Z && Y < Z)
			cout << X << " " << Y << " " << Y;
		else if(X == Y && Z < X)
			cout << Z << " " << Y << " " << Z;
		else if (Y == Z && X < Y)
			cout << X << " " << X << " " << Y;
		else
			cout << "-1 -1 -1";
		cout << '\n';
	}
}
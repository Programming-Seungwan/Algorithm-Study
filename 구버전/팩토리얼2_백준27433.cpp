#include <iostream>
using namespace std;

int Recursion(int x, long long ans);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	Recursion(N, 1);

	return 0;
}

int Recursion(int x, long long ans) {
	if (x == 0) { cout << ans; return 0; }
	
	ans *= x;
	Recursion(x - 1, ans);
	
	return 0;
}

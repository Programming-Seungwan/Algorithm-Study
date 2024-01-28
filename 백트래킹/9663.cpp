#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 0;
int col[16];

bool check(int row) {
	for (int i = 0; i < row; i++) {
		// 같은 열이나 대각선 상에 퀸이 놓여있으면 false 
		if (col[row] == col[i] || abs(col[row] - col[i]) == row-i) {
			return false;
		}
	}
	return true;
}

void func(int row) {
	if (row == n) { // N개의 행까지 온 경우, 가능한 경우의 수 증가 
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		col[row] = i;

		if (check(row)) {
			func(row + 1);
		}


	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	func(0);
	cout << ans;
    
    return 0;
	
}


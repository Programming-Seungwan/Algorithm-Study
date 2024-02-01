#include <iostream>
using namespace std;
#define MX 101

long long DP[MX]; //오버플로우 주의...

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;

    //초기값 설정 
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;

	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 6; j <= n; j++) {
			if (DP[j] != 0) continue; //이미 값이 있으면 패스 
			DP[j] = DP[j - 1] + DP[j - 5];
		}
		cout << DP[n] << "\n";
	}
	
	return 0;
}

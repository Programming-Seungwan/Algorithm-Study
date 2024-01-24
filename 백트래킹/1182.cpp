#include <iostream>
#include <vector>

using namespace std;

int n, s;
int nums[22];
int ans = 0;

// 매개변수로는 비교할 숫자를 검색하기 위한 index.
// 해당 원소가 포함/불포함을 가정하기 위한 act.
// 그 원소들의 합을 계산해 부분 수열의 합 S와 비교하기 위한 total을 받는다.
void func(int index, bool act, int sum) {
	if (index == n) return;

	if (act) {
		sum += nums[index];
		if (sum == s) ans++;
	}

	index++;

	func(index, true, sum);
	func(index, false, sum);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	func(0, true, 0);
	func(0, false, 0);

	cout << ans << "\n";
	
	
	return 0;
}



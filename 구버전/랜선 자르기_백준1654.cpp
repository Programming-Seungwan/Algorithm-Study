#include <iostream>
#include <vector>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> v;

	int K, N;
	cin >> K >> N;

	long long sum=0;
	for (int i = 0; i < K; i++) {
		long long n;
		cin >> n;
		sum += n;
		v.push_back(n);
	}

	long long start = 1;
	int end = sum / N;
	//end를 sum/N으로 한 이유...
	//sum/N 이상의 숫자들로 이용해 구하면 N보다 작게 나온다

	int mx = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long len = 0;
		for (int i = 0; i < v.size(); i++) {
			long long n = v[i] / mid;
			len += n;
		}

		if (len < N) {
			end = mid - 1;
		}
		else  {
			start = mid + 1;
			if (mx < mid) mx = mid;
		}
	}

	cout << mx << "\n";
	return 0;

}

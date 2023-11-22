#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001]; //누적 합 배열 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;
	cin >> N >> K;
	
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[i] = arr[i-1] + num; //누적 합 배열 
	}

	//입력값들이 모두 양수인 경우엔 answer를 굳이 -99999로 할 필요가 없다.
	//그러나 입력값에 음수가 포함하고 있으면 answer을 가능한 제일 작은 값으로 설정해야 한다. 
	int answer = -99999;
	for (int i = K; i <= N; i++) {
		//answer와 구간합을 비교 -> 둘 중 더 큰 값을 answer로 대입. 
		answer = max(answer, arr[i] - arr[i - K]);
	}
	
	cout << answer << "\n";
	return 0;
	
}

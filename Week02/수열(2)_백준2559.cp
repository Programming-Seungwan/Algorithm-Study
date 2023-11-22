//투 포인터 방식 + 슬라이딩 방식

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	for (int i = 0; i < K; i++) {
		answer += arr[i];
	}

	//포인터 초기 설정 
	int start = 1;
	int end = K - 1;

	//그룹에 속한 데이터들의 합 
	int nums = answer - arr[0]; 

	while (start <= N - K) {
		if (end >= N) end = N - 1;

		if (end - start + 1 == K) { //그룹의 넓이가 k개인 경우 
			answer = max(answer, nums);
		}

		if ((end - start + 1) < K) { //그룹의 넓이가 k보다 작은 경우 
			end++; //end 포인터 증가 
			nums += arr[end];
		}
		else{  //그룹의 넓이가 k보다 크거나 같을 경우 
			nums -= arr[start]; 
			start++;
		}
	}
	cout <<  answer << "\n";
	

	return 0;
}

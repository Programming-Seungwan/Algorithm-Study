#include <bits/stdc++.h>

using namespace std;
#define MX 10001

int n,m;
vector<int> truth; //진실을 아는 사람들 
int party[51][51]; //각 파티에 참여한 사람들 정보 저장 
int arr[51]; 

int answer = 0;


int Find(int num) {
    if (arr[num] == num) return num;
    return arr[num] = Find(arr[num]);
}

void Union(int index, int cnt) {

    int min_ele = 1e9;
    for (int i = 1; i <= cnt; i++) { //각 파티별로 최솟값 구하기 
        if (min_ele > Find(party[index][i])) min_ele = Find(party[index][i]);
    }

    //전체 사람들 중 파티에 참여한 사람들과 같은 번호를 같고 있는 경우... min_ele로 업데이트 
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= n; j++) {
            int id = party[index][i];
            if (Find(id) == arr[j]) arr[j] = min_ele;
        }
    }
}

void AbleToGo(int index) {
    for (auto t : truth) {

        for (int i = 1; i <= n; i++) {
                int id = party[index][i];
                if (id == 0) break; 
                if (Find(id) == Find(t)) { //진실을 아는 사람들도 index 파티에 참여한 경우 
                    return;
                }
        }

    }
    
    answer++; //참여할 수 있는 파티 증가 
}


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    int t;
    cin >> t;

    truth.resize(t);
    for (int i = 0; i < t; i++) {
        cin >> truth[i];
    }

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        for (int j = 1; j <= x; j++) {
            cin >> party[i][j];
        }

        Union(i, x);
    }

    for (int i = 1; i <= m; i++) {
        AbleToGo(i);
    }


    cout << answer;


    
    return 0;
}

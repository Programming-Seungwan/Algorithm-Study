/*백준 9372번 상근이의 여행
적은 종류의 비행기를 타고 모든 국가들을 여행하도록.
상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다.

상근이가 모든 국가를 여행하기 위해 타야 하는 비행기 종류의 최소 개수를 출력한다.

??? 그냥 n-1 아냐?? 
*/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; //국가의 수 (2 ≤ N ≤ 1000)
        int m;
        cin>>n>>m;

        int list[10000][2]; //비행기의 종류 (1 ≤ M ≤ 10000)

        for(int i=0; i<m; i++){
            for(int j=0; j<2; j++){
                cin>>list[i][j];
            }

        }

        cout<<n-1<<endl;
    }

}
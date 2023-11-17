/*2023_11_17(금)
백준 2960 에라토스테네스의 체

N, K가 주어졌을 때, K번째 지우는 수
*/
#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    bool list[1001]={false,};

    for(int i=2; i<=n; i++){
        for (int j = i; j<=n; j+=i) {
            if(list[j]){
                continue;
            }else{
                list[j]=1;
                k--;
            }
            if(k==0){
                cout<<j<<endl;
                break;
            }
        }
        if(k==0){
            break;
        }
    }
}
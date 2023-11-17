/*백준 2839번 설탕배달
    Nkg 가지고 나갈건데 최대한 적은 봉지 >> 최적화 문제 >> DP 
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int list[5001];

    //basecase
    list[0]=n;
    list[1]=n;
    list[2]=n;
    list[3]=1;
    list[4]=n;
    list[5]=1;

    //recursive step
    for(int i=6;i<=n;i++){
        int tmp_3 = list[i-3];
        int tmp_5 = list[i-5];

        //둘 중 최솟값
        if(tmp_3<tmp_5){
            list[i]=tmp_3+1;
        }else{
            list[i]=tmp_5+1;
        }
    }

    if(list[n]>=n){
        cout<<-1<<endl;
    }else{
        cout<<list[n]<<endl;
    }





}
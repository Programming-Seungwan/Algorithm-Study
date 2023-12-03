/*3273 두수의합
2023.12.3(일)

1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //입력받기
    int list[100000];

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    
    int x;
    cin>>x;

    sort(list,list+n);

    int cnt=0;

    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            int ret = list[i]+list[j];
            if(ret>x){
                break;
            }
            if(x==ret){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;

}
/*2023.11.30(목)
백준 9252_LCS2

부분 수열이 되는 수열 중 가장 긴 것을 찾아라
문자열은 알파벳 대문자로만, 최대 1000글자

하........문자열은 마지막 공백까지 +1......이거떔에 또 고생했네......
*/

#define MAX_SIZE 1000

#include <iostream>
#include <stack>
using namespace std;

int char_size(char a[]){
    int cnt=0;
    while(a[cnt]){
        cnt++;
    }
    return cnt;
}

int M[MAX_SIZE+1][MAX_SIZE+1]; //최대 갯수 기록
int generate_note[MAX_SIZE+1][MAX_SIZE+1];

int LCS(char v1[],char v2[], int m, int n){
    //basecase
    for(int i=0;i<m;i++){
        M[i][0]=0;
    }
    for(int i=0;i<n;i++){
        M[0][i]=0;
    }
    
    //recursive step
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v1[i]==v2[j]){//같은경우
                M[i+1][j+1] = M[i][j]+1;
                generate_note[i+1][j+1]=1;
            }
            else{//다른경우 둘 중 큰값
                if(M[i][j+1]>M[i+1][j]){
                    M[i+1][j+1] = M[i][j+1];
                    generate_note[i+1][j+1]=2;
                }
                else{
                    M[i+1][j+1] = M[i+1][j];
                    generate_note[i+1][j+1]=3;
                }

            }
        }
    }
    
    return M[m][n];
    
}

void generate(char v2[],int m,int n){
    stack<char> stack;
    while(n && m){
        switch (generate_note[m][n])
        {
        case 1: //같은 경우
            stack.push(v2[n-1]);
            m--;
            n--;
            continue;
        case 2: //다른경우 1
            m--;
            continue;
        case 3: //다른경우 2
            n--;
            continue;
        }
    }  

    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
}


int main(){
    char v1[1001];
    char v2[1001];
    cin>>v1>>v2;

    int v1_m = char_size(v1);
    int v2_n = char_size(v2);

    int ret = LCS(v1,v2,v1_m,v2_n);
    cout<<ret<<endl;
    if(ret){
         generate(v2,v1_m,v2_n);
    }
    
   

}
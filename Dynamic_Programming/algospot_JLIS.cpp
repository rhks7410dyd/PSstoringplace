#include <iostream>
#include <cstring>
#define endl '\n'
#define INF 987654321
#define SIZE 101

using namespace std;

int n,m;
int DP[SIZE][SIZE];
int A[SIZE];
int B[SIZE];

void Solve();
void Input();
int get_JLIS(int ai,int bi);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    for(int i = 0 ; i < c ; i++){
        Solve();
    }

    return 0;
}

void Solve(){
    Input();

    int ans = get_JLIS(0,0)-2;

    cout << ans << endl;
    return;
}

void Input(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> B[i];
    }

    A[0] = -2147483648;
    B[0] = -2147483648;
    memset(&DP[0][0],-1,sizeof(DP));
}

int get_JLIS(int ai,int bi){
    int& ret = DP[ai][bi];

    if(ret == -1){
        ret = 2;
        int x = max(A[ai],B[bi]);
        for(int i = ai ; i <= n ; i++){
            if(x < A[i])    ret = max(ret,get_JLIS(i,bi)+1);
        }
        for(int i = bi ; i <= m ; i++){
            if(x < B[i])    ret = max(ret,get_JLIS(ai,i)+1);
        }
    }
    return ret;
}

/*
https://lipcoder.tistory.com/50
두번째 방법에서 두가지 배열을 사용한 것을 응용해서 풀면됨
*/
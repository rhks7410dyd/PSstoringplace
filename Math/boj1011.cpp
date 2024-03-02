#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

const int INF = 987654321;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        int a,b,ans,n;
        cin >> a >> b;
        int distance = b-a;
        n = b-a;
        long long k = 1;
        while(k*k <= n)  k++;
        k--;

        n -= k*k;
        ans = 2*k-1;
        if(n)  ans += n/k + 1;

        cout << ans << endl;
    }
    return 0;
}

/*
메모리 초과가 뜸
계단 형식으로 만들어지기 때문에 추적이 가능함.
1+2+3...+k+k-1+...+2+1 == k*(k-1) + k == k*k
k*k <= n < (k+1)^2
*/

/*
int get_path(int n, int bef_dis);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        int a,b;
        cin >> a >> b;
        cout << 1 + get_path(b-a-1,1) << endl;
    }
    return 0;
}

int get_path(int n, int bef_dis){
    if(n == 1){
        if(bef_dis <= 2){
            return 1;
        }
        else{
            return INF;
        }
    }

    int ret = INF;

    if((long long)2*n < bef_dis*(bef_dis-1)){
        return ret;
    }

    for(int now_dis = bef_dis-1 ; now_dis < bef_dis+2 ; now_dis++){
        if(now_dis == 0)    continue;
        ret = min(ret,get_path(n-now_dis,now_dis)+1);
    }

    return ret;
}
*/
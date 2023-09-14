//경우를 나눠줘야할듯(dp를 다차원 배열로 변경)
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
#define SIZE 101

using namespace std;

bool other_schedule[SIZE];
int dp[SIZE];
int N,M,Coupon = 0;

int Solve(int idx);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    cin >> N >> M;

    int t;
    for(int i = 0 ; i < M ; i++){
        cin >> t;
        other_schedule[t] = true;
    }

    fill(&dp[0],&dp[101],INF);

    int ans = Solve(1);

    cout << ans << '\n';

    return 0;
}

/*
1) 못가는 날이다
사지 않는다
3일권을 산다
5일권을 산다
2) 가는 날이다
쿠폰을 쓴다
1일권을 산다
3일권을 산다(idx <= N - 2)
5일권을 산다(idx <= N - 4)
*/
int Solve(int idx){
    if(idx > N){
        return 0;
    }

    int& ret = dp[idx];
    if(ret != INF) return ret;

    if(other_schedule[idx]){
        ret = min(ret,Solve(idx+1));
    }
    else{
        if(Coupon > 2){
            Coupon -= 3;
            ret = min(ret,Solve(idx+1));
            Coupon += 3;
        }

        ret = min(ret,Solve(idx+1)+10000);
    }

    if(idx < N-1){
        Coupon++;
        ret = min(ret,Solve(idx+3)+25000);
        Coupon--;
    }
    if(idx < N-3){
        Coupon += 2;
        ret = min(ret,Solve(idx+5)+37000);
        Coupon -= 2;
    }

    cout << "ln81 ret : " << ret << " idx " << idx << endl;
    return ret;
}
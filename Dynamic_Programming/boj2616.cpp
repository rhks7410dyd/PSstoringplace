#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n,small_num;
int pep_num[50001];
int dp[50001][3];

int get_dp(int idx,int train_num);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> pep_num[i];

        pep_num[i] += pep_num[i-1];
    }
    cin >> small_num;

    memset(&dp[0][0],-1,sizeof(dp));

    get_dp(1,3);

    cout << dp[1][2] << endl;
    return 0;
}

int get_dp(int idx,int train_num){
    if(n - idx + 1 < train_num * small_num)   return -1;

    if(train_num == 0)  return 0;

    int ret = dp[idx][train_num-1];

    if(ret != -1)   return ret;

    ret = max(ret,get_dp(idx+1,train_num));
    ret = max(ret,get_dp(idx+small_num,train_num-1)+(pep_num[idx+small_num-1]-pep_num[idx-1]));
    //위의 줄 표현이 살짝 아쉽긴 함. 너무 가독성이 떨어짐

    return ret;
}
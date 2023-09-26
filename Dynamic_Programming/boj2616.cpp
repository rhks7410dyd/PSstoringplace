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

    //continue code. . .

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> pep_num[i];

        pep_num[i] += pep_num[i-1];
    }
    cin >> small_num;

    memset(&dp[0][0],-1,sizeof(dp));

    get_dp(small_num,2);

    cout << dp[small_num][2] << endl;
    return 0;
}
//왜 예제가 195가 나올까...
int get_dp(int idx,int train_num){
    if(idx > n)    return 0;

    int& ret = dp[idx][train_num];
    if(ret != -1)   return ret;
    if(train_num == 0)  return ret = 0;
    
    ret = max(ret,get_dp(idx+small_num,train_num-1)+pep_num[idx]-pep_num[idx-small_num]);
    ret = max(ret,get_dp(idx+1,train_num));

    return ret;
}
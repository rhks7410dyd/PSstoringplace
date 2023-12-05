#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

const int SIZE = 1000;

int sum,n,score; // 총 점수
int card_list[SIZE];
int dp[SIZE][SIZE];

void Solve();
void Input();
int recursive(int l,int r,bool geunwoo_turn);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        Solve();
    }
    return 0;
}

void Solve(){
    memset(&dp[0][0],-1,sizeof(dp));
    Input();

    int ans = recursive(0,n-1,true);

    cout << ans << endl;
}

void Input(){
    sum = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> card_list[i];
        sum += card_list[i];
    }
}
//
int recursive(int l,int r,bool geunwoo_turn){
    if(l == r){
        return geunwoo_turn ? card_list[l] : 0;
    }

    int& ret = dp[l][r];
    if(ret != -1)   return ret;

    ret = recursive(l+1,r,!geunwoo_turn) < recursive(l,r+1,!geunwoo_turn) ?  : recursive(l,r+1,!geunwoo_turn);

    int left_choice ;
    if(geunwoo_turn){
        
    }

    return ret;
}
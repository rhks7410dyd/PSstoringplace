#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

const int SIZE = 50;
const int INF = 987654321;

int sum,n,score; // 총 점수
int card_list[SIZE];
int dp[2][SIZE][SIZE];

void Solve();
void Input();
int recursive(int l,int r,bool hyeonwoo_turn);

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
    fill(&dp[0][0][0],&dp[1][SIZE-1][SIZE],INF);
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
int recursive(int l,int r,bool hyeonwoo_turn){
    if(l > r){
        return 0;
    }

    int& ret = dp[hyeonwoo_turn][l][r];
    if(ret != INF)   return ret;

    ret = 0;

    if(hyeonwoo_turn){
        ret = max(recursive(l+1,r,false)+card_list[l],recursive(l,r-1,false)+card_list[r]);
        if(r-l>=1){
            ret = max(ret,recursive(l+2,r,false));
            ret = max(ret,recursive(l,r-2,false));
        }   
    }
    else{
        ret = min(recursive(l+1,r,true)-card_list[l],recursive(l,r-1,true)-card_list[r]);
        if(r-l >= 1){
            ret = min(ret,recursive(l+2,r,true));
            ret = min(ret,recursive(l,r-2,true));
        }
    }

    return ret;
}   
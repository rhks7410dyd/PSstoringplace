/*
마지막에 찾는 과정만 못함
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define endl '\n'
#define SIZE 100 + 1
#define INF 987654321

using namespace std;

int n,w;
int dp[SIZE][1001];
vector<string> ans_list;
vector<string> name_list;
vector<pair<int,int>> v;

void Solve();
void Input();
void get_ans_list(int cap,int idx);
int rec(int cap,int idx);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    for(int i = 0 ; i < C ; i++){
        Solve();
    }

    return 0;
}

void Solve(){
    memset(&dp[0][0],-1,sizeof(dp));
    ans_list.clear();
    name_list.clear();
    v.clear();

    Input();

    int ans = rec(w,0);
    
    // dp[w][i] == dp[w][i+1] 스킵 했다는 의미
    // dp[w][i] != dp[w][i+1] 얘를 선택했을 때 최적화된 수라는 의미

    get_ans_list(w,0);

    cout << ans << ' ' << ans_list.size() << endl;
    for(int i = 0 ; i < ans_list.size() ; i++){
        cout << ans_list[i] << endl;
    }

    /*
    for(int i = 0 ; i <= w ; i++){
        for(int j = 0 ; j <  n ; j++){
            cout << dp[j][i] << '\t';
        }
        cout << endl;
    }*/
}

void Input(){
    cin >> n >> w;
    string name;
    int a,b;
    for(int i = 0 ; i < n ; i++){
        cin >> name >> a >> b;
        name_list.push_back(name);
        v.push_back({a,b});
    }
}

int rec(int cap,int idx){
    int& ret = dp[idx][cap];
    if(ret != -1)   return ret;

    if(idx == n)    return ret = 0;

    auto now = v[idx];
    if(now.first > cap) ret = rec(cap,idx+1);
    else    ret = max(rec(cap,idx+1),now.second + rec(cap-now.first,idx+1));

    return ret;
}

void get_ans_list(int cap,int idx){
    if(idx == n-1){
        if(cap >= v[idx].first) ans_list.push_back(name_list[idx]);
    }
    else{
        if(dp[idx][cap] == dp[idx+1][cap]){
            get_ans_list(cap,idx+1);
        }
        else{
            ans_list.push_back(name_list[idx]);
            get_ans_list(cap-v[idx].first,idx+1);
        }
    }
}
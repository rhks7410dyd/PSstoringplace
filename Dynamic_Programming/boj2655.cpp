#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl '\n'
#define SIZE 101
#define INF 987654321

using namespace std;

int n;
int dp[SIZE][SIZE];
vector<pair<pair<int,int>,pair<int,int>>> v;
vector<int> ans_list;

void Solve();
void Input();
void get_list();
int DP(int index,int before);
void printvector();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();

    sort(v.begin(),v.end(),greater<>());

    memset(&dp[0][0],-1,sizeof(dp));

    DP(1,0);
    
    get_list();

    printvector();
}

void get_list(){
    int x = 1,y=0;
    while(x > y && x<n){
        if(dp[x][y] == dp[x+1][y])  x++;
        else{
            ans_list.push_back(v[x].second.second);
            y = x;
            x++;
        }
    }

    if(x==n && dp[n][y] != 0){
        ans_list.push_back(v[x].second.second);
    }
}

void printvector(){
    auto v = ans_list;
    cout << v.size() << endl;
    for(int i = v.size()-1 ; i >= 0 ; i--){
        cout << v[i] << endl;
    }
    cout << '\n';
}

void Input(){
    cin >> n;
    int a,b,c;
    v.push_back({{INF,INF},{INF,INF}});
    for(int i = 1 ; i <= n ; i++){
        cin >> a >> b >> c;
        v.push_back({{a,c},{b,i}});
    }
}

int DP(int index,int before){
    int& ret = dp[index][before];
    if(ret != -1)   return ret;

    auto now = v[index];
    auto before_info = v[before].first;
    if(index == n){
        if(!before || (now.first.first < before_info.first && now.first.second < before_info.second))  return ret = now.second.first;
        else    return ret = 0;
    }

    if(!before){
        ret = max(ret,DP(index+1,before));
        ret = max(ret,DP(index+1,index)+now.second.first);
    }

    if(now.first.first < before_info.first && now.first.second < before_info.second){
        ret = max(ret,DP(index+1,index)+now.second.first);
    }
    ret = max(ret,DP(index+1,before));

    return ret;
}
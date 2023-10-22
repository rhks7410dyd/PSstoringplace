#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
#define SIZE 100 + 1

using namespace std;

int n,w;
int dp[SIZE][1001];
map<string,int> m;
vector<pair<int,int>> v;

void Solve();
void Input();

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
    Input();

    //``
}

void Input(){
    cin >> n >> w;
    string name;
    int a,b;
    for(int i = 0 ; i < n ; i++){
        cin >> name >> a >> b;
        m[name] = i;
        v.push_back({a,b});
    }
}
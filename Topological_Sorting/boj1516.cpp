#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 987654321
#define SIZE 501

using namespace std;

int n;
int val[SIZE];
int ans[SIZE];
vector<int> v[SIZE];
queue<pair<int,int>> q;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n;

    int t;
    for(int i = 1 ; i <= n ; i++){
        v[i].push_back(0);
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> t;
        val[i] = t;
        while(true){
            cin >> t;
            if(t == -1)     break;
            v[t].push_back(i);
            v[t][0]++;
        }
    }

    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        if(v[i][0] == 0)    q.push({i,0});
    }

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        ans[now.first] = now.second + val[now.first];
        ////////////////////////////
    }

    return 0;
}
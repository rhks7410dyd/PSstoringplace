#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 987654321
#define SIZE 501

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int val[SIZE];
    int ans[SIZE];
    int latest_time[SIZE];
    vector<int> v[SIZE];

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
            v[i][0]++;
        }
    }

    queue<pair<int,int>> q;
    for(int i = 1 ; i <= n ; i++){
        if(v[i][0] == 0)    q.push({i,0});
    }

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        ans[now.first] = now.second + val[now.first];
        for(int i = 1 ; i < v[now.first].size() ; i++){
            int next = v[now.first][i];
            v[next][0]--;
            latest_time[next] = latest_time[next] > ans[now.first] ? latest_time[next] : ans[now.first];
            if(latest_time[next] == 0)  latest_time[next] = ans[now.first];
            if(v[next][0] == 0){
                q.push({next,latest_time[next]});
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
#define INF 987654321

using namespace std;

vector<int> v[10001];
int n,m;

int BFS(int start){
    int ret = 0;

    queue<int> q;
    q.push(start);
    bool visit[10001];
    memset(&visit[0],0,sizeof(visit));
    visit[start] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for (int i = 0 ; i < v[now].size(); i++){
          if(!visit[v[now][i]]){
            visit[v[now][i]] = true;
            ret++;
            q.push(v[now][i]);
          }
        }
    }

    return ret;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> m;
    int a,b;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }

    vector<int> ans_list;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        //continue code...
        int ret = BFS(i);
        if(ret == ans){
            ans_list.push_back(i);
        }
        else if(ret > ans){
            ans = ret;
            ans_list.clear();
            ans_list.push_back(i);
        }
    }

    for (int i=0; i< ans_list.size(); i++)
    {
      cout << ans_list[i] << ' ';
    }
    cout << endl;

    return 0;
}
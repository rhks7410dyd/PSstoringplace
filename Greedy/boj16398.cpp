#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
#define SIZE 1001

using namespace std;

int n;
int uni[SIZE];
int map[SIZE][SIZE];
void Input();
void Solve();
long long get_MST();
int get_root(int a);
int merge_root(int a,int b);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();
    long long ans = get_MST();
    cout << ans << endl;
    return;
}

void Input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
}

long long get_MST(){
    long long ans = 0;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i = 0 ; i < n ; i++){
        uni[i] = i;
        for(int j = i+1 ; j < n ; j++){
            pq.push({-map[i][j],{i,j}});
        }
    }

    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();

        if(get_root(now.second.first) == get_root(now.second.second))   continue;

        ans -= now.first;

        merge_root(now.second.first,now.second.second);
    }
    return ans;
}

int get_root(int a){
    if(uni[a] == a) return a;
    else    return uni[a] = get_root(uni[a]);
}

int merge_root(int a,int b){
    a = get_root(a);
    b = get_root(b);
    if(a > b){
        uni[a] = b;
    }
    else{
        uni[b] = a;
    }

    return uni[a];
}
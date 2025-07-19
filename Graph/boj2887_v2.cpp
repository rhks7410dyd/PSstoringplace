#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

#define endl '\n'
#define INF 987654321
#define SIZE 100001

using namespace std;

struct Edge{
    int n1,n2,len;

    Edge() : n1(0), n2(0), len(0) {}
    Edge(int _n1, int _n2, int _len) : n1(_n1), n2(_n2), len(_len) {}

    bool operator<(const Edge& other) const {
        if(len != other.len)    return len > other.len;
        if(n1 != other.n1)  return n1 > other.n1;
        return n2 > other.n2;
    }
};

vector<pair<int,int>> x_pos;
vector<pair<int,int>> y_pos;
vector<pair<int,int>> z_pos;
//vector<array<int,3>> input;
priority_queue<Edge> edges;

int Union_set[SIZE];

int find_union(int a){
    if(a == Union_set[a])   return a;
    return Union_set[a] = find_union(Union_set[a]);
}

void Union(int a,int b){
    a = find_union(a);
    b = find_union(b);
    if(a < b)   Union_set[b] = a;
    else    Union_set[a] = b;
}

bool is_Union(int a,int b){
    a = find_union(a);
    b = find_union(b);
    return a==b;
}

void remove_useless_node();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x,y,z;
        cin >> x >> y >> z;
        //input.push_back({x,y,z});
        x_pos.emplace_back(x,i);
        y_pos.emplace_back(y,i);
        z_pos.emplace_back(z,i);

        Union_set[i] = i;
    }

    sort(x_pos.begin(),x_pos.end());
    sort(y_pos.begin(),y_pos.end());
    sort(z_pos.begin(),z_pos.end());
    
    for(int i = 0 ; i < n-1 ; i++){
        edges.emplace(x_pos[i].second,x_pos[i+1].second,abs(x_pos[i].first-x_pos[i+1].first));
        edges.emplace(y_pos[i].second,y_pos[i+1].second,abs(y_pos[i].first-y_pos[i+1].first));
        edges.emplace(z_pos[i].second,z_pos[i+1].second,abs(z_pos[i].first-z_pos[i+1].first));
    }
    
    int ans = 0;

    while(edges.empty() == false){
        Edge now = edges.top();
        if(is_Union(now.n1,now.n2)){
            edges.pop();
        }
        else{
            Union(now.n1,now.n2);
            ans += now.len;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define endl '\n'
#define INF 1987654321

using namespace std;

int n,m,now_pos;
vector<pair<int,int>> reverse_run_section;

void Solve();
void Input();
long long get_ans();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();

    long long ans = get_ans();

    cout << ans << endl;
}

void Input(){
    cin >> n >> m;

    int a,b;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        if(a > b)   reverse_run_section.push_back({b,a});
    }

    sort(reverse_run_section.begin(),reverse_run_section.end());
}

long long get_ans(){
    int v_size = reverse_run_section.size();
    
    long long ret = 0;
    int i = 1;
    int start = reverse_run_section[0].first,end = reverse_run_section[0].second;
    while(i < v_size){
        if(end >= reverse_run_section[i].first){
            end = max(end,reverse_run_section[i].second);
        }
        else{
            ret += 2*(end - start);
            start = reverse_run_section[i].first;    end = reverse_run_section[i].second;
        }
        i++;
    }

    ret += m + 2*(end - start);

    return ret;
}

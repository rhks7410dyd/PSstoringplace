#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

int n,m;
double R;

vector<int> flagpole;
vector<int> pile;

void Input();
int get_pos(double h);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Input();

    double best = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int now_base = pile[j] - pile[i];
            double best_height = 2*R/now_base;
            int best_pos = get_pos(best_height);

            if(best_pos == -1)  continue;

            best = max(best,(double)now_base * flagpole[best_pos]);
        }
    }

    if(best == 0)   cout << -1 << endl;
    else    cout << best/2 << endl;

    return 0;
}

void Input(){
    cin >> n >> m >> R;
    int t;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        pile.push_back(t);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> t;
        flagepole.push_back(t);
    }

    sort(pile.begin(),pile.end());
    sort(flagpole.begin(),flagpole.end());
}

int get_pos(double h){
    int s = 0, e = m;
    int mid;
    while(s < e){
        mid = (s+e)/2;
        if(h - flagpole[mid] <= 0.5) return mid;
        if(h - flagpole[mid] < 0)   e = m;
        else    s = m + 1;
    }

    if(e == 0)  return -1;
    if(s == e)  return m-1;

    return mid;
}
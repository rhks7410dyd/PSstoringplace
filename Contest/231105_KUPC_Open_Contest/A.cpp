#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,now,best=-1,best_num=0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        char t,bef = '0';
        now = 0;
        string input;
        cin >> input;
        for(int j = 0 ; j < m ; j++){
            t = input[j];
            if(t != bef){
                bef = t;
                if(t == '1')    now++;
            }
        }

        if(now > best){
            best = now;
            best_num = 1;
        }
        if(now == best) best_num++;
    }

    cout << best << ' ' << best_num << endl;

    return 0;
}
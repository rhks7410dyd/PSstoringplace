#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
vector<int> v(1000,0);
bool use[1000];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.begin()+n);

    int t = 0,ans = 0;
    for(int c = 0 ; c < 2 ; c++){
        t = 0;
        for(int i = 0 ; i < n ; i++){
            if((!t || t < v[i]) && !use[i]){
                t = v[i];
                ans++;
                use[i] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
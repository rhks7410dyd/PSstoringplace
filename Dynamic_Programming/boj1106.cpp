#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define SIZE 1001

using namespace std;

int dp[SIZE];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<pair<int,int>> input;
    vector<pair<double,int>> eff;

    int c,n;
    cin >> c >> n;
    
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        input.emplace_back(a, b);
        eff.emplace_back((double)b/a,i);
    }

    

    return 0;
}
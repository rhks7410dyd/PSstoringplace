#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    map<string,int> input;
    int n,m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        //continue code...
        string temp;
        cin >> temp;
        input[temp] = 1;
    }

    int cnt = 0;

    for(int i = 0 ; i < m ; i++){
        //continue code...
        string temp;
        cin >> temp;
        if(input[temp] == 1)    cnt++;
    }

    cout << cnt << endl;

    return 0;
}
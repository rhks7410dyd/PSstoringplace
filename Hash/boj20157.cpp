#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int getgcd(int a,int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int n,x,y;
    cin >> n;
    map<pair<int,int>,int> cnt;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> x >> y;
        if(x == 0){
            y = y/abs(y);
        }
        else if(y == 0){
            x = x/abs(x);
        }
        else{
            int GCD = getgcd(abs(x),abs(y));
            x = x/GCD;  y = y/GCD;
        }
        cnt[make_pair(x,y)]++;
    }

    int max = 0;
    for(auto c : cnt){
        max = max < c.second ? c.second : max; 
    }

    cout << max << endl;

    return 0;
}
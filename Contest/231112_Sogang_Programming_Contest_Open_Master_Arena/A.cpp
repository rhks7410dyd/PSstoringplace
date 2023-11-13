#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int T;
int input[200000][2];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for(int i = 0 ; i < T ; i++){
        cin >> input[i][0] >> input[i][1];
    }

    int ans = 0;
    int b_l,b_r;
    for(int i = 0 ; i < T ; i++){
        if(i != 0){
            if(b_l == input[i][0] && b_l != 0)  ans++;
            if(b_r == input[i][1] && b_r != 0)  ans++;
        }

        b_l = input[i][0];  b_r = input[i][1];

        if(input[i][0] == input[i][1] && input[i][0] != 0)  ans++;
    }

    cout << ans << endl;

    return 0;
}
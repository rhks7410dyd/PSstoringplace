#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int input[9];

    for(int i = 0 ; i < 9 ; i++){
        //continue code...
        cin >> input[i];
    }

    int ans=0;

    for(int i = 1 ; i < 7 ; i++){
        //continue code...
        ans += input[i]/input[7];
        (input[i]%input[7]) ? (ans += 1) : (ans += 0);
    }

    cout << ans << endl << input[0]/input[8] << ' ' << input[0]%input[8];

    return 0;
}
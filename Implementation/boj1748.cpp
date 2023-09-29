#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int n;
    cin >> n;

    int ans =0;
    int digit=10,pl = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i < digit)   ans += pl;
        else if(i == digit){
            pl++;
            ans += pl;
            digit*=10;
        }
    }

    cout << ans << endl;
    
    return 0;
}
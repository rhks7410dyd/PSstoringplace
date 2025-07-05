#include <iostream>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,cnt=0;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        //continue code...
        int a,b;
        cin >> a >> b;
        if(a < b)   cnt++;
    }

    cout << cnt << endl;

    return 0;
}
#include <iostream>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        int n;
        cin >> n;
        if(n%4){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}
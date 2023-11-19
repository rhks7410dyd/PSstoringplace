#include <iostream>
#define endl '\n'

using namespace std;

void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        Solve();
    }
    return 0;
}

void Solve(){
    Input();
}
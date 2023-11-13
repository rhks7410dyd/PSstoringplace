#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

long long x,y;

long long get_coprime_with_x(long long a);
void Solve();


int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> x >> y;

    Solve();

    return 0;
}

void Solve(){
    for(int i = 2 ; i <= x ; i++){
        long long temp = get_coprime_with_x(i);

        if(temp != 1){
            //
        }
    }
}
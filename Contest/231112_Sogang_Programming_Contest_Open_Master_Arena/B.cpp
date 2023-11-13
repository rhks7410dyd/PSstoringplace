#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int ans[200000];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    int dis = 0;
    for(int i = 0 ; i < N/2 ; i++){
        int n1 = 2*i+2;
        int n2 = 2*i+1;
        ans[i] = n2;
        ans[N-1-i] = n1;
    }

    if(N%2 == 1){
        ans[N/2] = N;
    }

    for(int i = 0 ; i < N ; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
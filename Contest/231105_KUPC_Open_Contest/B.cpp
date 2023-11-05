#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    
    cin >> n;

    if(n%2) cout << "Goose\n";
    else    cout << "Duck\n";

    return 0;
}
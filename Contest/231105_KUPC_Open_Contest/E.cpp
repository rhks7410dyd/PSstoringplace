#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int alphabet[26];

int n;
string s;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> s;

    for(int i = 0 ; i < n ; i++){
        if(n%2 && i == n/2) continue;
        alphabet[s[i]-'a']++;
    }

    for(int i = 0 ; i < 26 ; i++){
        if(alphabet[i]%2){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
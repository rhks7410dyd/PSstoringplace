#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321
#define SIZE 501

using namespace std;

int n;
int val[SIZE];
vector<int> v[SIZE];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n;

    int t;
    for(int i = 1 ; i <= n ; i++){
        cin >> t;
        val[i] = t;
        v[i].push_back(0);
        while(true){
            cin >> t;
            if(t == -1)     break;
            v[i].push_back(t);
        }
    }

    int ans = 0;

    

    return 0;
}
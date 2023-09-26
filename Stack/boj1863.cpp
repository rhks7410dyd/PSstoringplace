#include <iostream>
#include <stack>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
stack<int> s1;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n;

    int x,y,ans = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        if(s1.empty() || s1.top() < y){
            s1.push(y);
        }
        else{
            while(!s1.empty() && s1.top() > y){
                ans++;
                s1.pop();
            }
            
            if(s1.empty() || y != s1.top())   s1.push(y);
        }
    }
    y = 0;
    while(!s1.empty() && s1.top() > y){
        ans++;
        s1.pop();
    }

    cout << ans << endl;

    return 0;
}
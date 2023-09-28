/*
    k가 남은 경우는 무조건 뒤에서부터 뺴주면 되는가?
    k가 남았다는 것은 지금 스택안이 완벽하게 내림차순 순으로 정리가 되어있다는 의미.
    즉, 제일 뒤에서부터 빼도 무방
*/
#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
#define INF 987654321

using namespace std;

int n,k;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> k;

    string input;
    cin >> input;

    stack<int> s;

    for(int i = 0 ; i < n ; i++){
        int now = input[i] - '0';
        if(!k || s.empty() || s.top() >= now)  s.push(now);
        else{
            while(k && !s.empty() && s.top() < now){
                s.pop();
                k--;
            }
            s.push(now);
        }
    }

    if(k > 0){
        for(int i = 0 ; i < k ; i++){
            s.pop();
        }
    }

    string ans = "";
    while(!s.empty()){
        ans += s.top() + '0';
        s.pop();
    }

    for(int i = ans.size() - 1 ; i >= 0 ; i--){
        cout << ans[i];
    }

    return 0;
}
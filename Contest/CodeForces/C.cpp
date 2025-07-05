#include <iostream>
#include <string>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //cout << "start\n";
    int C;
    cin >> C;
    
    int input[200001];
    int min_info[200001];
    min_info[0] = INF;
    int max_info[200002];
    
    while(C--){
        //continue code. . .
        int n;
        cin >> n;
        max_info[n+1] = -1;
        for(int i = 1 ; i <= n ; i++){
            //continue code...
            cin >> input[i];
            if(min_info[i-1] > input[i]) min_info[i] = input[i];
            else    min_info[i] = min_info[i-1];
        }
        
        for(int i = n ; i >= 1 ; i--){
            //continue code...
            if(max_info[i+1] < input[i]) max_info[i] = input[i];
            else    max_info[i] = max_info[i+1];
        }

        string ans = "";
        for(int i = 1 ; i <= n ; i++){
            //continue code...
            if(input[i] == max_info[i] || input[i] == min_info[i]) ans = ans + "1";
            else    ans = ans + "0";
        }
        
        cout << ans << endl;
    }
    return 0;
}

/*
1. 가장 큰 수와 작은 수는 무조건 된다
2. 양쪽 끝은 무조건 가능하다.
3. 양쪽 끝 중 한곳에 갈 수 있는가?
13 11 10 12 20
11 10 12 20
11 20
11

왼쪽 애들보다도 더 크거나, 오른쪽 애들보다도 더 작거나

*/
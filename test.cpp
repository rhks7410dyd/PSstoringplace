#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int x,y;

int Rev(int n){
    if(n == 1000)    return 1;
    
    int ret = 0;
    if(n/100 > 0){
        ret += n/100;
        ret += ((n/10)%10)*10;
        ret += (n%10)*100;
    }
    else if(n/10 > 0){
        ret += n/10;
        ret += (n%10)*10;
    }
    else{
        ret = n;
    }
    
    return ret;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> x >> y;
    int ans = Rev(Rev(x)+Rev(y));
    
    cout << ans << endl;

    return 0;
}
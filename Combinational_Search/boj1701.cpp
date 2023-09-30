#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

string input;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> input;
    int Size = input.size(),ans = 0,temp,s1,s2;
    for(int i = 0 ; i < Size - ans - 1 ; i++){
        for(int j = i+1 ; j < Size ; j++){
            s1 = i;
            s2 = j;
            temp = 0;
            while(input[s1++] == input[s2++]){
                temp++;
            }
            ans = max(ans,temp);
        }
    }

    cout << ans << endl;
    return 0;
}
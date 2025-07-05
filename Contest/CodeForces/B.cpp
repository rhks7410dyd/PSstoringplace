#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        int n,j,k;
        cin >> n >> j >> k;

        int temp,max_str = -1;
        vector<int> input;
        for(int i = 0 ; i < n ; i++){
            //continue code...
            cin >> temp;
            if(temp > max_str)  max_str = temp;
            input.push_back(temp);
        }

        if(k == 1){
            if(input[j-1] == max_str) cout << "YES\n";
            else    cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
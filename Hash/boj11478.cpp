#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;

    cin >> input;

    map<string,int> substrs;

    int n = input.length();
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            string sub = input.substr(j - i, i);
            substrs[sub] = 1;
        }
    }

    cout << substrs.size() << endl;
}
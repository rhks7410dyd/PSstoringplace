#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
map<char,int> m1;

int pow(int num,int exponent){
    int ret = 1;
    for(int i = 0 ; i < exponent ; i++){
        ret *=num;
    }

    return ret;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> N;
    string input;

    for(int i = 0 ; i < 26 ; i++){
        m1[i+'A'] = 0;
    }

    for(int i = 0 ; i < N ; i++){
        cin >> input;
        for(int j = 0 ; j < input.size() ; j++){
            m1[input[j]] += pow(10,input.size()-j-1);
        }
    }

    for(auto t : m1){
        v.push_back(t.second);
    }

    sort(v.begin(),v.end(),greater<>());

    int ans=0;

    for(int i = 0 ; i < v.size() ; i++){
        ans += (9-i)*v[i];
    }

    cout << ans << '\n';

    return 0;
}
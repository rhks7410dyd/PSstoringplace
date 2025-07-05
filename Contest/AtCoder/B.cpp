#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    string s,t;

    cin >> s >> t;

    bool condition_check = true;
    
    for(int i = 1 ; i < s.size() ; i++){
        //continue code...
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(t.find(s[i-1]) >= t.size()){
                condition_check = false;
                break;
            }        
        }
    }

    cout << (condition_check ? "Yes" : "No") << endl;
    return 0;
}
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

vector<char> v;
int L,C;

void backtracking(int c,bool use_gather,int use_char_bit);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;

    for(int i = 0 ; i < C ; i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    backtracking(0,false,0);

    return 0;
}

void backtracking(int c,bool use_gather,int use_char_bit){
    if(c == C){
        for(int i = 0 ; i < C ; i++){
            if(use_char_bit & 1<<i){
                cout << v[i];
            }
        }
        cout << endl;
        return;
    }

    if(v[c])

    bool have_gather = true;
    if(!use_gather){
        have_gather=false;
        for(int i = c ; i < C ; i++){
            if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'){
                have_gather=true;
                break;
            }
        }
    }

    if(have_gather){
        backtracking(c+1,use_gather,use_char_bit);

        backtracking(c+1,)
    }
}
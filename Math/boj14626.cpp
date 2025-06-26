#include <iostream>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input;
    cin >> input;
    
    int weight[2] = {1,3};
    int ans = 0;
    if(input[12] == '*'){
        for(int i = 0 ; i < 12 ; i++){
            ans += weight[i%2]*(input[i]-'0');
            ans %= 10;
        }
        cout << (10 - ans)%10 << endl;
    }
    else{
        int star_weight;
        for(int i = 0 ; i < 12 ; i++){
            if(input[i] != '*'){
                ans += weight[i%2]*(input[i]-'0');
                ans %= 10;
            }
            else{
                star_weight = weight[i%2];
            }
        }
        int mark = input[12] - '0';
        for(int i = 0 ; i < 10 ; i++){
            if((ans+i*star_weight)%10 == (10-mark)%10){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    
    
    return 0;
}
#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int get_prime_factor(int num);

const int Size = 10e5 + 1;
bool eratoth[Size];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    eratoth[1] = true;
    for(int i = 2 ; i < Size ; i++){
        int temp = i*2;
        while(temp < Size){
            eratoth[temp] = true;
            temp += i;
        }
    }

    int a,b,ans=0;
    cin >> a >> b;

    for(int i = a ; i <= b ; i++){
        int num = get_prime_factor(i);
        if(!eratoth[num]) ans++;
    }

    cout << ans << endl;

    return 0;
}

int get_prime_factor(int num){
    int ret = 0;
    for(int i = 2 ; i <= num ; i++){
        if(eratoth[i])  continue;
        while(num%i == 0){
            ret++;
            num/=i;
        }
    }
    return ret;
}
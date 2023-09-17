//계산해야됨
#include <iostream>
#define endl '\n'

using namespace std;

long long n;
int q,k;

long long get_dis(long long x,long long y); 
int get_lev(long long a);
void calcul_lev();

long long lev[52];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> k >> q;

    calcul_lev();
    
    for(int i = 1 ; i < 51 ; i++){
        cout << lev[i] << endl;
    }

    long long x,y;
    for(int i = 0 ; i < q ; i++){
        cin >> x >> y;

        long long ans = get_dis(x,y);

        cout << ans << '\n';
    }

    return 0;
}

long long get_dis(long long x,long long y){
    
    return 0;
}

void calcul_lev(){
    long long t = 1;
    long long end = t;
    int i = 1;
    while(end < n){
        lev[i++] = end;
        t *= k;
        end += t;
    }
    lev[i] = n;
}

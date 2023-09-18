#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

long long n;
int q,k;

long long get_dis(long long x,long long y);
long long find_root(long long n);
int get_lev(long long a);
void calcul_lev();

long long lev[55];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> k >> q;

    long long x,y;

    if(k==1){
        for(int i = 0 ; i < q ; i++){
            cin >> x >> y;
            cout << abs(x-y) << '\n';
        }
        return 0;
    }

    calcul_lev();
    for(int i = 0 ; i < q ; i++){
        cin >> x >> y;

        int ans = get_dis(x,y);

        cout << ans << '\n';
    }

    return 0;
}

long long get_dis(long long x,long long y){
    if(x > y){
        long long temp = x;
        x = y;
        y = temp;
    }

    int ret = 0;
    int x_lev = get_lev(x);
    int y_lev = get_lev(y);
    
    //cout << "ln49 x & x_lev : " << x << ' ' << x_lev << " y & y_lev : " << y << ' ' << y_lev << endl;

    while(x_lev != y_lev){
        y = find_root(y);
        y_lev--;
        ret++;
    }

    while(x != y){
        x = find_root(x);
        y = find_root(y);

        //cout << "ln61 x & y : " << x << ' ' << y << endl;

        ret+=2;
    }

    return ret;
}

void calcul_lev(){
    long long t = 1;
    long long end = 1;
    int i = 2;
    lev[1] = 1 ;
    while(end < n){
        lev[i++] = end+1;
        t *= k;
        end += t;
    }
    lev[i] = n+1;
}

int get_lev(long long a){
    int i=1;
    while(true){
        if(lev[i+1] > a && lev[i] <= a ){
            return i;
        }
        i++;
    }
    return 0;
}

long long find_root(long long n){
    int Lev = get_lev(n);
    long long first_node = lev[Lev];
    return (n-first_node)/k + lev[Lev-1];
}

#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h,m,s;
    cin >> h >> m >> s;
    int t;
    cin >> t;
    h += t/3600;
    t %= 3600;
    m += t/60;
    t %= 60;
    s += t;

    m += s/60;
    s %= 60;
    h += m/60;
    m %= 60;
    h %= 24;

    cout << h << ' ' << m << ' ' << s << endl;

    return 0;
}
#include <iostream>
#include <string>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    string A,B,C;
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << endl << stoi(A+B) - stoi(C) << endl;
    return 0;
}
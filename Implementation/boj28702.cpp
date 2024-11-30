#include <iostream>
#include <string>
#define endl '\n'
#define INF 987654321

using namespace std;

bool is_fizzbuzz(string a);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    string a,b,c;
    cin >> a >> b >> c;

    int result;

    if(!is_fizzbuzz(a)){
        result = stoi(a)+3;
    } else if(!is_fizzbuzz(b)){
        result = stoi(b)+2;
    } else{
        result = stoi(c)+1;
    }

    if(result%15 == 0){
        cout << "FizzBuzz" << endl;
        return 0;
    } else if(result%5 == 0){
        cout << "Buzz" << endl;
        return 0;
    } else if(result%3 == 0){
        cout << "Fizz" << endl;
        return 0;
    } else{
        cout << result << endl;
        return 0;        
    }

    return 0;
}

bool is_fizzbuzz(string a){
    if(a == "Buzz" || a == "Fizz" || a == "FizzBuzz")   return true;
    return false;
}
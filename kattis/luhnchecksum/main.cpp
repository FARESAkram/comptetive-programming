#include<iostream>
#include<string>

using namespace std;

char transform(char x){
    int double_num = (x - '0') * 2;
    if ( double_num < 10 ){
        return double_num + '0';
    }
    int sum_digits = (double_num / 10) + (double_num % 10);
    while(sum_digits > 10 ){
        int sum_digits_new = (sum_digits / 10) + (sum_digits % 10);
        sum_digits = sum_digits_new;
    }
    return sum_digits + '0';
}

bool solve(string s){
    int n = s.length(), sum = 0;
    for(int i = n - 1, j = 1 ; i >= 0; i--, j ++ ){
        if ( j % 2 == 1 ){
            sum += s[i] - '0';
        } else {
            sum += transform(s[i]) - '0';
        }
    }
    return sum % 10 == 0;
}

int main(){
    string s;
    int T;
    bool is_valid = false;
    cin >> T;

    while(T--){
        cin >> s;
        is_valid = solve(s);
        if ( is_valid ){
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }
}
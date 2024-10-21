#include <iostream>

using namespace std;

bool isPalindrome(string s){
    int left = 0, right = s.length() - 1;
    while(left < right){
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    int largestPalindrome = -1;
    for (int i = 100 ; i <= 999 ; i ++ ){
        for ( int j = 100 ; j <= 999 ; j ++ ){
            int num = i * j;
            string str = to_string(num);
            if(isPalindrome(str) && num > largestPalindrome){
                largestPalindrome = num;
            }
        }
    }
    cout << largestPalindrome << endl;
    return 0;
}
#include<iostream>
using namespace std;
bool isPalindrome(string s){
    if(s.length()==0)
        return true;
    int left = 0,right=s.length()-1;
    while(left<right){
        if(s[left]!=s[right])
            return false;
        left++,right--;
    }
    return true;
}
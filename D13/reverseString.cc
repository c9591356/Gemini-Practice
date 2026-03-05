#include <string>
using namespace std;

void reverseString(string& s){
    if(s.length()==0)
        return;
    int left=0;
    int right=s.length()-1;
    while (left<right)
    {
        swap(s[left],s[right]);
        left++;
        right--;
    }
    
    
};
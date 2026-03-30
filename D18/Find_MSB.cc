#include<iostream>
using namespace std;
int find_msb_position(unsigned int n) {
    if (n == 0) return -1;
    int pos = 0;
    // 你的實作邏輯
    while(n>0){
        n>>1;
        pos++;
    }
    return pos-1;
}
int main(){
    cout<<find_msb_position(100)<<endl;
}
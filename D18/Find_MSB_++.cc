#include<iostream>
using namespace std;
int find_msb_position(unsigned int n) {
    if (n == 0) return -1;
    int pos = 0;
    // 你的實作邏輯
    int cut = 16;
    while(cut>0)
    {
        /* code */
        if (n >> cut) { 
            pos += cut;   // 既然前 16 bits 有值，MSB 至少在 16 以上！
            n >>= cut;    // 把 n 往右推 16 格，我們接下來只要看這剩下的 16 bits 就好
        }
        
        cut=cut>>1;
    }
    
    return pos;
}
int main(){
    cout<<find_msb_position(100)<<endl;
}
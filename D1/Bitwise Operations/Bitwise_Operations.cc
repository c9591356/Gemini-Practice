#include<iostream>
#include <bitset>
using namespace std;
void set_bit(bitset<16> &n,int i){
    bitset<16> x(1);
    x = x<< i;
    n=n | x;
    cout<<n<<endl;
}
void Clear_Bit(bitset<16> &n,int i){
    bitset<16> x(1);
    
    
    n=n & ~(x<<i);
    cout<<n<<endl;
}
void toggle_bit(bitset<16> &n,int i){
    bitset<16> x(1);
     n=n ^(x<<i);
    cout<<n<<endl;
}
int main(){
    int n,i;
    cin>>n;
    bitset<16> b(n);
    cout<<b<<endl;
    cout<<"set_bit:"<<endl;
    cin>>i;
    set_bit(b,i);
    cout<<"Clear_Bit:"<<endl;
    cin>>i;
    Clear_Bit(b,i);
    cout<<"toggle_bit:"<<endl;
    cin>>i;
    toggle_bit(b,i);
    system("pause");
    return 0;
}
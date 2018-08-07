//C++递归实现
#include <iostream>

using namespace std;

void move(char x, char z);
void hanoi(int n, char x, char y, char z);  //由柱x借柱y移到柱z

int main()
{
    int n;
    cin>>n;
    hanoi(n,'a','b','c');

    return 0;
}

void move(char x, char z){
    static int i;
    i++;
    cout<<i<<":"<<x<<"->"<<z<<endl;
}

void hanoi(int n, char x, char y, char z){
    if(n==1) move(x,z);
    else{
        hanoi(n-1, x, z, y);
        move(x,z);
        hanoi(n-1, y, x, z);
    }
}
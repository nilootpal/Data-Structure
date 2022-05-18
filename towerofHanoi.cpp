#include <iostream>
using namespace std;

void towerOfHanoi(int n, char x, char y, char z){
    if(n>=1){
        towerOfHanoi(n-1,x,z,y);
        cout<<"move top disk from tower "<<x<<" to top of tower "<<y<<endl;
        towerOfHanoi(n-1,z,y,x);
    }
}

int main(){
    int n = 21;
    char x = 'x', y = 'y', z = 'z';

    towerOfHanoi(n, x, y, z);

    return 0;
}
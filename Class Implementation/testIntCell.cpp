#include <iostream>
#include "IntCell.h"

using namespace std;

int main(){
    IntCell *m;

    m = new IntCell;
    m->write(5);
    cout<<m->read()<<endl;
    delete m;
    return 0;

    // IntCell m;
    // m.write(5);

    // // IntCell obj4( );

    // IntCell obj1; // Zero parameter constructor, same as before
    // IntCell obj2( 12 ); // One parameter constructor, same as before
    // // IntCell obj4( );

    // cout<<"Cell Contents: "<<m.read()<<endl<<obj1.read();
    // return 0 ;
}
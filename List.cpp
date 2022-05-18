#include <iostream>
#include <vector>

using namespace std;

template <typename Container>

void removeEveryOtherItem ( Container & lst ){
    auto itr = lst.begin();

    while( itr != lst.end()){
        itr = lst.erase(itr);
        itr += (itr != lst.end()) ? 1 : 0;
    }
} 

int main(){
    return 0;
}
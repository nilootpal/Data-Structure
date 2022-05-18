#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

template <typename Object>

class Vector {
    public: 
        explicit Vector( int initSize = 0 ) : theSize( initSize ), theCapacity( initSize + SPARE_CAPACITY ){
            objects = new Object[ theCapacity ];
        }

        Vector(const Vector & rhs) : theSize( rhs.theSize ), theCapacity( rhs. theCapacity ), objects( nullptr ){
            objects = new Object[ theCapacity ];
            for( int i = 0; i < theSize; ++i ){
                objects[i] = rhs.objects[i];
            }
        }

        Vector & operator= (const Vector & rhs){
            Vector copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        ~Vector(){
            delete [] objects;
        }

        Vector(const Vector && rhs) : theSize( rhs.theSize ), theCapacity( rhs. theCapacity ), objects( rhs.objects ){
            rhs.theSize = 0;
            rhs.theCapacity = 0;
            rhs.objects = nullptr;
        }

        Vector & operator= (const Vector && rhs){
            std::swap( theSize, rhs.theSize );
            std::swap( theCapacity, rhs.theCapacity );
            std::swap( objects, rhs.objects );

            return *this;
        }

        void resize( int newSize ){
            if(newSize > theCapacity){
                reserve( newSize * 2 );
            }
            theSize = newSize;
        }

        void reserve( int newCapacity ){
            if(newCapacity < theSize){
                return;
            }
            Object *newArray = new Object[newCapacity];

            for(int k = 0; k < theSize; ++k){
                newArray[ k ] = std::move( objects[ k ] );
            }

            theCapacity = newCapacity;
            std::swap( objects, newArray );
            delete [] newArray;
        }

        Object & operator[] (int index){
            return objects[index];
        }

        const Object & operator[] (int index) const{
            return objects[index];
        }

        int size() const{
            return theSize;
        }

        bool isEmpty() const{
            return size() == 0;
        }

        int capacity() const{
            return theCapacity;
        }

        void push_back( const Object & x ){
            if(theSize == theCapacity)
                resize(2*theCapacity+1);
            objects[theSize++] = x;
        }

        void push_back( const Object && x ){
            if(theSize == theCapacity)
                resize(2*theCapacity+1);
            objects[theSize++] = std::move(x);
        }

        void pop_back(){
            --theSize;
        }

        const Object & back() const{
            return objects[theSize-1];
        }

        typedef Object * iterator;
        typedef const Object * const_iterator;

        iterator begin(){
            return &objects[0];
        }
        
        const_iterator begin() const{
            return &objects[0];
        }

        iterator end( ){
            return &objects[ size( ) ];
        }

        const_iterator end( ) const{
            return &objects[ size( ) ];
        }

        static const int SPARE_CAPACITY = 16;


    private:
        int theSize, theCapacity; 
        Object objects;
};

int main(){
    return 0;
}
#include <iostream>
using namespace std;

class IntCell 
{
    public:
        explicit IntCell( int initialValue = 0 )
        { storedValue = new int( initialValue ); }

        ~IntCell( ) // Destructor
        { delete storedValue; }

        IntCell( const IntCell & rhs ) // Copy constructor
        { storedValue = new int( *rhs.storedValue ); }

        IntCell( IntCell && rhs ) : storedValue( rhs.storedValue ) // Move constructor
        { rhs.storedValue = nullptr; }

        IntCell & operator= ( const IntCell & rhs ) // Copy assignment
        {
            if( this != &rhs )
                *storedValue = *rhs.storedValue;
            return *this;
        }

        IntCell & operator= ( IntCell && rhs ) // Move assignment
        {
            std::swap( storedValue, rhs.storedValue );
            return *this;
        }

        int read( ) const
        { return *storedValue; }
        void write( int x )
        { *storedValue = x; }

    private:
        int *storedValue;
};

int main(){
    IntCell a(2);
    IntCell b = a;
    IntCell c;

    c = b;
    a.write( 4 );
    cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;

    return 0;
}
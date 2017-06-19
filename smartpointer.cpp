// Compile: g++ smartpointer.cpp -o hello

/*
	SmartPointer functions identically to a regular pointer, but provides automatic memory management
	by keeping track of references to the pointer object.
*/

using std::cout;

template <class T> 
class SmartPointer {

public:
	SmartPointer( T* obj )
	{
		smartPtr = obj;
		count = ( int* ) malloc( sizeof( int ) );
		count = 1;
	}

	// Creates new reference to existing object
	SmartPointer( SmartPointer<T> *sPtr )
	{
		smartPtr = sPtr.smartPtr;
		count = sPtr.count;
		( *count )++;
	}

	// TODO: Override equals operator

	~SmartPointer( SmartPointer<T> sPtr )
	{
		( *count )--;
		if ( *count == 0 )
		{
			delete smartPtr;
			free( count );
		}
	}

	T GetValue()
	{
		return *smartPtr;
	}

protected:
	// The object and the count must be pointers to correctly track count when an object has several smart pointers
	T * smartPtr;
	int * count; 

};
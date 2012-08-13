#include <iostream>
#include "MetaFunctionHeader.hpp"
#include <boost/type_traits/is_same.hpp>
using namespace boost;
using namespace std;

int main()
{
    typedef int* array[] ;
    typedef float* brrby[];
    if( is_same<replace_type<array,int,float>::type,brrby>::value )
    {
        cout<<"test ok"<<endl;
    }
    return 0;
}

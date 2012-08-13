#include <iostream>

#include <boost/type_traits/is_same.hpp>
using namespace std;

///! Metafunction is some class can be used like bellow
///! meta_func< type >::xxx_type
///! We can use metafunction to get xxx_type assocate with type

///! Name : add_const_ref<T>
///! 如果T是一个引用类型，则返回一个T&，否则返回T const &
template <typename T>
struct add_const_ref
{
    typedef T const &type;
};
template <typename T>
struct add_const_ref<T&>
{
    typedef T& type;
};

template <typename T>
struct add_const
{
    typedef T const type;
};
template <typename T>
struct add_const<T&>
{
    typedef T& type;
};
template <typename T>
struct add_const<T*>
{
    typedef T* const type;
};
template <typename T>
struct add_const<T const>
{
    typedef T const type;
};
    template <typename c>
    class test
    {
        public:
        typedef typename c::type type;
    };
int main()
{
    if(
        boost::is_same<add_const_ref<int>::type,int const&>::value &&
        boost::is_same<add_const_ref<int&>::type,int &>::value  &&
        boost::is_same<add_const_ref<int*>::type,int* const &>::value &&
        boost::is_same<add_const_ref<int*&>::type,int* &>::value    &&
        boost::is_same<test< add_const_ref<bool> >::type,bool const &>::value
       )
    {
        cout<< "test: add_const_ref : success"<<endl;
    }
    else
    {
        cout<< "test: add_const_ref : faild"<<endl;
    }
    //下面这个是类似boost库中的add_const，规则参考boost库
    if( boost::is_same<add_const<float>::type,float const>::value)
    {
        cout<<"const int is same"<<endl;
    }

    return 0;
}

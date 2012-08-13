#ifndef METAFUNCTIONHEADER_HPP_INCLUDED
#define METAFUNCTIONHEADER_HPP_INCLUDED

//用到继承的技巧

///! MetaFunction Header file
template <typename c, typename x,typename y>
struct replace_type_d
{
    typedef c type;
};

template <typename c, typename x, typename y>
struct replace_type : public replace_type_d<c,x,y>
{
};

template <typename x, typename y>
struct replace_type<x,x,y>
{
    typedef y type;
};



template <typename c, typename x, typename y>
struct replace_type_d<c*,x,y>
{
    typedef typename replace_type<c,x,y>::type* type;
};

template <typename c, typename x, typename y>
struct replace_type_d<c* [],x,y>
{
    typedef typename replace_type<c*,x,y>::type type[];
};

template <typename c, typename x, typename y>
struct replace_type_d<c [],x,y>
{
    typedef typename replace_type<c,x,y>::type type[];
};

#endif // METAFUNCTIONHEADER_HPP_INCLUDED

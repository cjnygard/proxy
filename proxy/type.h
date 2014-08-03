//**********************************************************BEGINDOC
//
// Copyright (c) 1999  Spatial Software Solutions, Inc.
//
//!LIBRARY: Services
//
//!CLASS: Type
//: template class to perform ref/type tricks
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_TYPE
#define INC_TYPE

////////////////////////////////////////////////////////////////////
//- Includes


////////////////////////////////////////////////////////////////////
//- Class Definition


#if RHCB_CANT_OVERLOAD_ON_CONSTNESS
template <typename T>
struct Type
{
    typedef T const_ref;  // VC++ does not support reference typedef
    typedef T ref;  // VC++ does not support reference typedef
    typedef T type;
};
#else
template <typename T>
struct Type
{
    typedef const T& const_ref;
    typedef T& ref;
    typedef T  type;
};

template <typename T>
struct Type<T&>
{
    typedef T& const_ref;
    typedef T& ref;
    typedef T& type;
};
#endif

template <>
struct Type<void>:public Type<int>
{};

#endif // INC_TYPE


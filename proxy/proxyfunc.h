//**********************************************************BEGINDOC
//
// Copyright (c) 1999    Spatial Software Solutions, Inc.
//
//!LIBRARY: GTK
//
//!CLASS: ProxyFunc
//: accessor for member functions
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_PROXYFUNC
#define INC_PROXYFUNC

////////////////////////////////////////////////////////////////////
//- Includes

#ifndef INC_PROXYBASE
#include "proxybase.h"
#endif // INC_PROXYBASE


////////////////////////////////////////////////////////////////////
//- Class Definition


//: accessor for member functions
template <class T, class D>
class ProxyFunc : public ProxyBase<D> {

public:

    //- Types

    typedef typename ProxyBase<D>::value_type value_type;
    typedef typename ProxyBase<D>::result_type result_type;
    typedef typename ProxyBase<D>::const_ref_type const_ref_type;
    typedef typename ProxyBase<D>::type type;
    typedef T class_type;
    typedef  result_type (class_type::*GetFunc)() const;
    typedef void (class_type::*ConstSetFunc)(const_ref_type);
    typedef void (class_type::*SetFunc)(type);

    //- Constants

    //: Constructor
    ProxyFunc(class_type* obj, GetFunc get, SetFunc set) :
        ProxyBase<value_type>(),
        _obj(obj),
        _get(get),
        _set(set),
        _constSet(NULL)
        {}

    ProxyFunc(class_type* obj, GetFunc get, ConstSetFunc set) :
        ProxyBase<value_type>(),
        _obj(obj),
        _get(get),
        _set(NULL),
        _constSet(set)
        {}

    //: virtual Constructor 
    virtual ProxyBase<value_type>* Clone() const 
        { return new ProxyFunc<class_type,value_type>(*this); }

    //- default Copy Constructor

    //- default Destructor

    //- default Assignment Operator

    //- Proxy & Mutator/Modifier Pairs

    //- Services

    //: Get the value of the element
    result_type Value() const 
        { return (_obj->*(_get))(); }
    //: Set the value of the element
    void Value(const_ref_type val) 
        { 
            if(_set) (_obj->*(_set))(val); 
            else  (_obj->*(_constSet))(val); 
        }

    //- Function Operators

    //- Access Operators

    //- Comparison Operators

    //- Math Operators

    //- Cast Operators

    //- Test Routines

    //- Friend Functions

private:

    //- Types

    //- Constants

    class_type* _obj;
    GetFunc _get;
    SetFunc _set;
    ConstSetFunc _constSet;

    //- Variables

    //- Routines
};


#endif // INC_PROXYFUNC


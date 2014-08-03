//**********************************************************BEGINDOC
//
// Copyright (c) 1999  Spatial Software Solutions, Inc.
//
//!LIBRARY: Proxy
//
//!CLASS: ProxyBase
//: encapsulate anonymous access
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_PROXYBASE
#define INC_PROXYBASE

////////////////////////////////////////////////////////////////////
//- Includes

#ifndef INC_TYPE
#include "type.h"
#endif // INC_TYPE

////////////////////////////////////////////////////////////////////
//- Class Definition


//: encapsulate memberwise access
template <class T>
class ProxyBase {

public:

    //- Types

    typedef T value_type;
    typedef typename Type<T>::const_ref const_ref_type;
    typedef typename Type<T>::const_ref result_type;
    typedef typename Type<T>::ref ref_type;
    typedef typename Type<T>::type type;

    //- Constants

    //- default Constructor
    //- default Copy Constructor

    //: virtual Constructor
    virtual ProxyBase* Clone() const = 0;

    //: Destructor
    virtual ~ProxyBase() {};

    //- default Assignment Operator

    //- Proxy & Mutator/Modifier Pairs

    //- Services

    //: Get the value of the element
    virtual result_type Value() const = 0;
    //: Set the value of the element
    virtual void Value(const_ref_type val) = 0;

    //- Function Operators

    result_type operator()() const { return Value(); }
    void operator()(const_ref_type val) { Value(val); }

    //- Access Operators

    //- Comparison Operators

    //- Math Operators

    //- Cast Operators

    //- Test Routines

    //- Friend Functions

private:

    //- Types

    //- Constants

    //- Variables

    //- Routines

};

#endif // INC_PROXYBASE


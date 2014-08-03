//**********************************************************BEGINDOC
//
// Copyright (c) 1999  Spatial Software Solutions, Inc.
//
//!LIBRARY: 
//
//!CLASS: ProxyVal
//: accessor for member data fields
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_PROXYVAL
#define INC_PROXYVAL

////////////////////////////////////////////////////////////////////
//- Includes

#ifndef INC_PROXYBASE
#include "proxybase.h"
#endif // INC_PROXYBASE

////////////////////////////////////////////////////////////////////
//- Class Definition


//: accessor for member data fields
template <class T>
class ProxyVal : public ProxyBase<T> {

public:

    //- Types

    typedef typename ProxyBase<T>::value_type value_type;
    typedef typename ProxyBase<T>::const_ref_type const_ref_type;
    typedef typename ProxyBase<T>::result_type result_type;

    //- Constants

    //: Constructor
    ProxyVal(value_type* obj) :
        ProxyBase<value_type>(),
        _obj(obj)
        {}

    //: virtual Constructor 
    virtual ProxyBase<value_type>* Clone() const 
        { return new ProxyVal<value_type>(*this); }

    //- default Copy Constructor

    //- default Destructor

    //- default Assignment Operator

    //- Proxy & Mutator/Modifier Pairs

    //- Services

    //: Get the value of the element
    //: Get the value of the element
    result_type Value() const { return *this->_obj; }
    //: Set the value of the element
    void Value(const_ref_type val) { *this->_obj = val; }

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

    //- Variables

    value_type* _obj;

    //- Routines

};

#endif // INC_PROXYOBJ



//**********************************************************BEGINDOC
//
// Copyright (c) 1999  Spatial Software Solutions, Inc.
//
//!LIBRARY: 
//
//!CLASS: ProxyObj
//: accessor for member data fields
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_PROXYOBJ
#define INC_PROXYOBJ

////////////////////////////////////////////////////////////////////
//- Includes

#ifndef INC_PROXYBASE
#include "proxybase.h"
#endif // INC_PROXYBASE

////////////////////////////////////////////////////////////////////
//- Class Definition


//: accessor for member data fields
template <class T, class D>
class ProxyObj : public ProxyBase<D> {

public:

    //- Types

    typedef typename ProxyBase<D>::value_type value_type;
    typedef typename ProxyBase<D>::result_type result_type;
    typedef typename ProxyBase<D>::const_ref_type const_ref_type;
    typedef T class_type;
    typedef value_type class_type::* DataMember;

    //- Constants

    //: Constructor
    ProxyObj(class_type* obj,  const DataMember& member) :
        ProxyBase<value_type>(),
        _obj(obj),
        _member(member)
        {}

    //: virtual Constructor 
    virtual ProxyBase<value_type>* Clone() const 
        { return new ProxyObj<class_type,value_type>(*this); }

    //- default Copy Constructor

    //- default Destructor

    //- default Assignment Operator

    //- Proxy & Mutator/Modifier Pairs

    //- Services

    void Object(class_type* obj) { _obj = obj; }
    const class_type* Object() const { return _obj; }

    //: Get the value of the element
    result_type Value() const { return _obj->*_member; }
    //: Set the value of the element
    void Value(const_ref_type val) { _obj->*_member = val; }

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

    class_type* _obj;
    DataMember _member;

    //- Routines

};

#endif // INC_PROXYOBJ



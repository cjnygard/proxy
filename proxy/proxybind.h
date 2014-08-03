//**********************************************************BEGINDOC
//
// Copyright (c) 1999  Spatial Software Solutions, Inc.
//
//!LIBRARY: Proxy
//
//!CLASS: ProxyBind
//: binders for using accessor with iterator algorithms
//
// $RCSfile$ $Revision$ $Date$
//
//************************************************************ENDDOC

#ifndef INC_PROXYBIND
#define INC_PROXYBIND

////////////////////////////////////////////////////////////////////
//- Includes

#include <functional>

template <typename ACC, typename Op>
struct ProxyBinder {
    ProxyBinder(const ACC& acc, const Op& op) :
        _acc(acc),
        _op(op)
        {}
    void operator()() const {
        _acc.Value(_op(_acc.Value()));
    }
private:
    ACC _acc;
    Op _op;
};

template <typename ACC, typename Op>
struct ProxyTransform {
    ProxyTransform(const ACC& acc, const Op& op) :
        _acc(acc),
        _op(op)
        {}
    typename Op::result_type operator()() const {
        return _op(_acc.Value());
    }
private:
    ACC _acc;
    Op _op;
};


#endif // INC_PROXYBIND

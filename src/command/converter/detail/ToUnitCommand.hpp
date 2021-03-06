#pragma once 

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>


#include <QVariant>
#include <QVariantMap>

namespace Xeth{


template<size_t unit>
class ToUnitCommand
{
    public:
        QVariant operator()(const QVariant &);
};



}

#include "ToUnitCommand.ipp"

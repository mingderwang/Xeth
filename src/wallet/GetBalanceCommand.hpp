#pragma once

#include "ethrpc/Provider.hpp"
#include "ethrpc/Wallet.hpp"

#include <QString>
#include <QVariant>

#include <boost/multiprecision/cpp_dec_float.hpp>

namespace Xeth{


class GetBalanceCommand
{
    public:

        GetBalanceCommand(Ethereum::Connector::Provider &);

        QVariant operator()(const QString &);
        QVariant operator()(const char *);


    private:
        Ethereum::Connector::Wallet _wallet;
};


}

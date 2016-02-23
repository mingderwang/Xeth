#pragma once

#include <string>

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

#include <boost/lexical_cast.hpp>

#include "detail/LevelDbStore.hpp"
#include "detail/NumericKeyComparator.hpp"
#include "types/TransactionCategory.hpp"
#include "types/BigInt.hpp"
#include "types/StealthKey.hpp"


namespace Xeth{


class TransactionDataSerializer : public DataSerializer<QJsonObject>
{
    public:
        QJsonObject operator()(const char *, const char *) const;
        bool operator()(int, const char *, QJsonObject &) const;

        using DataSerializer::operator(); //for serialization
};




typedef LevelDbStore<QJsonObject, TransactionDataSerializer, int, Xeth::KeySerializer<int>, NumericKeyComparator<int> > TransactionDataStore;
typedef LevelDbStore<int> TransactionIndexStore;



class TransactionStore : public QObject
{

    Q_OBJECT

    public:
        typedef TransactionDataStore::Iterator Iterator;
        typedef TransactionDataStore::ReverseIterator ReverseIterator;
        typedef TransactionDataStore::DataType DataType;


    public:
        TransactionStore();
        TransactionStore(const std::string &path);

        void open(const std::string &);
        bool openNoThrow(const std::string &);

        bool insert
        (
            const TransactionCategory &category,
            const std::string &hash,
            const std::string &from,
            const std::string &to,
            const BigInt &amount,
            time_t timestamp
        );
        
        bool insert
        (
            const TransactionCategory &category,
            const std::string &hash,
            const std::string &from,
            const std::string &to,
            const Ethereum::Stealth::Address &stealth,
            const BigInt &amount,
            time_t timestamp
        );


        bool insert(const QJsonObject &);

        QJsonObject get(const char *hash) const;
        Iterator begin() const;
        Iterator end() const;
        Iterator at(int , bool reverse=false) const;
        ReverseIterator rbegin() const;
        ReverseIterator rend() const;

    signals:
        void NewItem(const QJsonObject &) const;

    private:
        int getNextIndex();

    private:
        TransactionDataStore _dataStore;
        TransactionIndexStore _indexStore;
        int _lastIndex;

};


}

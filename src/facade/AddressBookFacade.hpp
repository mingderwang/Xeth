#pragma once

#include <QObject>

#include "database/DataBase.hpp"

#include "command/addressbook/AddContactCommand.hpp"
#include "command/addressbook/EditContactCommand.hpp"
#include "command/addressbook/ListContactsCommand.hpp"
#include "command/addressbook/RemoveContactCommand.hpp"
#include "command/addressbook/RenameConactCommand.hpp"

#include "Invoker.hpp"


namespace Xeth{

class AddressBookFacade : public QObject
{
    Q_OBJECT

    public:
        AddressBookFacade(DataBase &, Notifier &);


    public slots:
        QVariant addContact(const QVariantMap &);
        QVariant editContact(const QVariantMap &);
        QVariant renameContact(const QVariantMap &);
        QVariant listContacts();
        QVariant removeContact(const QString &);


    private:
        DataBase &_database;
        Invoker _invoker;

};


}
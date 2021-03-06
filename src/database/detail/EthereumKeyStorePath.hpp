#pragma once 

#include <string>
#include <boost/filesystem.hpp>

#include "ethrpc/transport/Path.hpp"

#include "conf/Settings.hpp"


namespace Xeth{


class EthereumKeyStorePath
{
    public:
        EthereumKeyStorePath();
        EthereumKeyStorePath(const Settings &);
        EthereumKeyStorePath(const std::string &);

        const std::string & toString() const;

        static std::string GetDefaultPath(bool testnet=false);

    private:
        static std::string MakePath(const std::string &);
        static std::string MakePath(boost::filesystem::path &);

    private:
        std::string _path;
};



}

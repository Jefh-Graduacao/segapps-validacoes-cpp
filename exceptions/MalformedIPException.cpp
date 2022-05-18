#include <string>
#include <sstream>

class MalformedIPException
{
    std::string malformedIP;

public:
    MalformedIPException(std::string malformedIP)
    {
        this->malformedIP = malformedIP;
    }

    std::string message()
    {
        std::stringstream stringStream;
        std::string malformedIp =
            this->malformedIP.empty() ? "string vazia" : this->malformedIP;

        stringStream << "O valor informado (" << malformedIp << ") não está no formato correto para um endereço IPv6";
        return stringStream.str();
    }
};
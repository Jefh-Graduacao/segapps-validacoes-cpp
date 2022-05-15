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
        stringStream << "O valor informado (" << this->malformedIP << ") não está no formato correto para um endereço IPv6";
        return stringStream.str();
    }
};
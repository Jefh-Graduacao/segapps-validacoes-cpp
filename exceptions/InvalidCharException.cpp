#include <string>
#include <sstream>

class InvalidCharException
{
    std::string invalidChars;

public:
    InvalidCharException(std::string invalidChars)
    {
        this->invalidChars = invalidChars;
    }

    std::string message()
    {
        std::stringstream stringStream;

        bool pluralize = this->invalidChars.size() > 1;

        std::string prefix = pluralize ? "Os caracteres informados " : "O caracter informado ";
        std::string suffix = pluralize ? " não são caracteres válidos" : " não é um caracter válido";

        stringStream << prefix << "(" << this->invalidChars << ")" << suffix << " para um endereço IPv6";
        return stringStream.str();
    }
};
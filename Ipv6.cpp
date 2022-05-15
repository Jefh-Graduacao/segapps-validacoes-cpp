#include <string>
#include <regex>
#include "exceptions/MalformedIPException.cpp"
#include "exceptions/InvalidCharException.cpp"

class Ipv6
{
    std::string value;

public:
    Ipv6(std::string value)
    {
        this->value = "";

        this->validate(value);

        this->value = value;
    }

    std::string getValue()
    {
        return this->value;
    }

private:
    // Desativação do construtor de cópia e operator de atribuição
    Ipv6(const Ipv6 &objeto);
    Ipv6 &operator=(const Ipv6 &objeto);

    static void validate(std::string value)
    {
        if (value.empty())
        {
            throw MalformedIPException(value);
        }

        validateIPv6Format(value);
        validateInvalidChars(value);
    }

    static void validateIPv6Format(std::string value)
    {
        std::regex formatRegex("^([\\w]{4}:){7}([\\w]{4})$");
        if (!std::regex_match(value, formatRegex))
        {
            throw MalformedIPException(value);
        }
    }

    static void validateInvalidChars(std::string value)
    {
        std::regex formatRegex("^([a-fA-F0-9]{4}:){7}([a-fA-F0-9]{4})$");
        std::regex validCharRegex("[a-fA-F0-9:]");

        if (!std::regex_match(value, formatRegex))
        {
            // aqui precisamos encontrar o caracter inválido
            std::stringstream invalidChars;
            for (std::string::iterator it = value.begin(); it != value.end(); ++it)
            {
                char character = *it;

                if (std::regex_match(std::string(1, character), validCharRegex))
                    continue;

                invalidChars << character;
            }

            throw InvalidCharException(invalidChars.str());
        }
    }
};
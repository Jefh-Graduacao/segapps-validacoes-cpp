#include <string>

class Emptyinputexception
{
public:
    std::string message()
    {
        return "Entrada vazia.";
    }

private:
    Emptyinputexception(const Emptyinputexception &objeto);
    Emptyinputexception &operator=(const Emptyinputexception &objeto);
};
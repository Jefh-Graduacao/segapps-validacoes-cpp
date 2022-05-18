#include <iostream>
#include <string>
#include "Ipv6.cpp"

int main(int argc, const char *argv[])
{
    const std::string probemPrefix = "Falha ao validar o endereço, veja mais detalhes abaixo.";

    if (argc < 2)
    {
        std::cout << "Informe um IPV6 como argumento do programa" << std::endl;
        return 1;
    }

    std::string entradaUsuario = argv[1];

    Ipv6 *ipv6;
    try
    {
        ipv6 = new Ipv6(entradaUsuario);

        std::cout << ipv6->getValue() << " é um IPv6 válido!" << std::endl;

        delete ipv6;
        ipv6 = NULL;
    }
    catch (MalformedIPException malformedIpExc)
    {
        std::cout << probemPrefix << std::endl
                  << std::endl
                  << malformedIpExc.message() << std::endl;
        ipv6 = NULL;
    }
    catch (InvalidCharException invalidCharExc)
    {
        std::cout << probemPrefix << std::endl
                  << std::endl
                  << invalidCharExc.message() << std::endl;
        ipv6 = NULL;
    }
    catch (...)
    {
        std::cout << "Ocorreu algum problema..." << std::endl;
        ipv6 = NULL;
    }

    std::cout << std::endl
              << "Fim do programa" << std::endl;
}
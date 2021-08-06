#ifndef _HPP_ESTRUTURA_DINAMICA
#define _HPP_ESTRUTURA_DINAMICA

#include <string>

using namespace std;

struct DadosObjeto
{
    char tipo;
    string descricao;
};

struct DadosPessoa
{
    string nomePessoa;
    char sexo;
    string cpf;
    int idade;
    bool pcd;
    bool gestante;
};

struct DadosTransportadora
{
    string nomeTransportadora;
    string cnpj;
    char tipo;
};

#endif /// _HPP_ESTRUTURA_DINAMICA
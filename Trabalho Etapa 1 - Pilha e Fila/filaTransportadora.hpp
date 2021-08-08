#ifndef _HPP_FILA2_DINAMICA
#define _HPP_FILA2_DINAMICA

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "estruturas.hpp"

typedef DadosTransportadora DadoNoFilaTransportadora;

struct NoFilaTransportadora
{
    DadoNoFilaTransportadora dado; /// Informacao do nó
    NoFilaTransportadora *prox; /// Proximo elemento da fila
};

struct FilaTransportadora
{
    NoFilaTransportadora *inicio;
    NoFilaTransportadora *fim;

    FilaTransportadora() { /// Construtor. Usado para inicializar os dados das variaveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};

/// Inicializacao dos dados da fila
void inicializaFTransportadora(FilaTransportadora *f)
{
    /// Define nulo para o ininio e o fim da fila
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaFTransportadora(FilaTransportadora *f)
{
    if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}

/// Enqueue
bool enfileiraFTransportadora(FilaTransportadora *f, DadoNoFilaTransportadora dado)
{
    NoFilaTransportadora *novo = new NoFilaTransportadora();
    if (!novo) /// Nao conseguiu alocar memoria (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

/// Dequeue
bool desenfileiraFTransportadora(FilaTransportadora *f, DadoNoFilaTransportadora *dado)
{
    /// Se nao estiver vazia, retira valor
    if (f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado; /// Pega o dado armazenado no primeiro no
        NoFilaTransportadora *apagar = f->inicio; /// Guarda o primeiro no em uma variavel auxiliar
        f->inicio = f->inicio->prox; /// Atualiza o inicio da fila
        delete apagar; /// Libera a memoria

        if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;

        return true;
    } else
        return false;
}

/// Peek
bool espiaFTransportadora(FilaTransportadora* f, DadoNoFilaTransportadora *dado)
{
    if (f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado;
        return true;
    }
    else
        return false;
}

/// Show
void mostraFTransportadora(FilaTransportadora *f)
{
    cout << "Fila: ";

    if(f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        cout << "[";

        NoFilaTransportadora *no = f->inicio;
        while (no) /// Faça enquanto (no != NULL)
        {
            cout << "{" << no->dado.nomeTransportadora;
            cout << ", " << no->dado.cnpj;
            cout << ", " << no->dado.tipo << "}";
            no = no->prox;

            if(no) /// Verifica se o proximo no nao e nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl << endl;
    } else
        cout << "Fila vazia.\n\n";
}

/// Retorna true se o valor existe na fila
/// Retorna false se o valor nao existe na fila
/*bool buscaFPessoa(FilaPessoa *f, DadoNoFilaPessoa valor)
{
    NoFilaPessoa *no = f->inicio;
    while (no) /// Faca enquanto (no != NULL)
    {
        if(no->dado == valor)
            return true;

        no = no->prox;
    }

    return false;
}*/

void destroiFTransportadora(FilaTransportadora *f)
{
    NoFilaTransportadora *no = f->inicio;
    while (no) /// Faca enquanto (no != NULL)
    {
        NoFilaTransportadora *apagar = no; /// Guarda o no em uma variavel auxiliar

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

/// Mostra o primeiro elemento da fila
void primeiraTransportadoraF(FilaTransportadora *f)
{
    cout << f->inicio->dado.nomeTransportadora << endl;
}

#endif /// _HPP_FILA2_DINAMICA
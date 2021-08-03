#ifndef _HPP_FILA1_DINAMICA
#define _HPP_FILA1_DINAMICA

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "estruturas.hpp"

typedef DadosPessoa DadoNoFilaPessoa;

struct NoFilaPessoa
{
    DadoNoFilaPessoa dado; /// Informacao do nó
    NoFilaPessoa *prox; /// Proximo elemento da fila
};

struct FilaPessoa
{
    NoFilaPessoa *inicio;
    NoFilaPessoa *fim;

    FilaPessoa() { /// Construtor. Usado para inicializar os dados das variaveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};

/// Inicializacao dos dados da fila
void inicializaFPessoa(FilaPessoa *f)
{
    /// Define nulo para o ininio e o fim da fila
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaFPessoa(FilaPessoa *f)
{
    if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}

/// Enqueue
bool enfileiraFPessoa(FilaPessoa *f, DadoNoFilaPessoa dado)
{
    NoFilaPessoa *novo = new NoFilaPessoa();
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
bool desenfileiraFPessoa(FilaPessoa *f, DadoNoFilaPessoa *dado)
{
    /// Se nao estiver vazia, retira valor
    if (f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado; /// Pega o dado armazenado no primeiro no
        NoFilaPessoa *apagar = f->inicio; /// Guarda o primeiro no em uma variavel auxiliar
        f->inicio = f->inicio->prox; /// Atualiza o inicio da fila
        delete apagar; /// Libera a memoria

        if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;

        return true;
    } else
        return false;
}

/// Peek
bool espiaFPessoa(FilaPessoa* f, DadoNoFilaPessoa *dado)
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
void mostraFPessoa(FilaPessoa *f)
{
    cout << "Fila: ";

    if(f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        cout << "[";

        NoFilaPessoa *no = f->inicio;
        while (no) /// Faça enquanto (no != NULL)
        {
            cout << "{" << no->dado.nomePessoa;
            cout << ", " << no->dado.sexo;
            cout << ", " << no->dado.cpf;
            cout << ", " << no->dado.idade;
            cout << ", " << no->dado.pcd;
            cout << ", " << no->dado.gestante << "}";
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

void destroiFPessoa(FilaPessoa *f)
{
    NoFilaPessoa *no = f->inicio;
    while (no) /// Faca enquanto (no != NULL)
    {
        NoFilaPessoa *apagar = no; /// Guarda o no em uma variavel auxiliar

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif /// _HPP_FILA1_DINAMICA
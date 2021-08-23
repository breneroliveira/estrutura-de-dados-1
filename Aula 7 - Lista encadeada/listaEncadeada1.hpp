#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

#include <iostream>

using namespace std;

typedef int DadoNoLista;

struct No
{
    DadoNoLista dado;
    struct No *prox;
};

void inicializaL(No **lista)
{
    *lista = nullptr;
}

bool vaziaL(No **lista)
{
    if(! (*lista))
        return true;
    else
        return false;
}

/// Excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

/// Insere no inicio da lista
bool insereL(No **lista, DadoNoLista valor)
{

    No *novo = new No(); /// Aloca memoria para o no
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "L:{";
    while(n) /// Enquanto n nao for NULL fica no laco
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}\n\n";
}

/// Remover um valor especifico da lista
bool removeL(No **lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = *lista;
    /// Fica no laco enquanto tiver elementos na lista
    /// e nao encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// Pode sair do laco sem encontrar o valor (atual==NULL)
    /// Se encontrar >>> atual tem o endereco do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// Se atual e NULL >> nao encontrou
        return false;
    if (!anterior) /// Se anterior e igual a NULL
    {
        /// O elemento a ser excluido esta no inicio da lista
        *lista = atual->prox;
    }
    else   /// Elemento esta no meio ou no fim
    {
        anterior->prox = atual->prox;
    }
    /// Libera a memoria do elemento
    delete(atual);
    return true;
}

No* buscaL(No **lista, DadoNoLista valor)
{
    No *n = *lista;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(No **lista, DadoNoLista valor, int posicao)
{
    No *anterior = NULL;
    No *atual = *lista;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; /// Significa que nao encontrou a posicao

    No *novo = new No();
    novo->dado = valor;
    if (!anterior) /// Primeira posicao
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    return true;
}

#endif // _HPP_LISTA_DINAMICA
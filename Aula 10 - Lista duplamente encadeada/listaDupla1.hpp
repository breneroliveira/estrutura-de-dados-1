#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA

#include <iostream>

#include "animal.hpp"

using namespace std;

typedef Animal DadoNoLista;

struct No {
    DadoNoLista dado;
    No *prox;
    No *ant;

    No() { /// Construtor 
        dado.codigo = 0;
        dado.idade = 0;
        dado.peso = 0;
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista {
    No *inicio;
    No *fim;
    int tamanho;

    Lista() { /// Construtor
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }

    ~Lista() { /// Desconstrutor /// Quando chame delete (ponteiro)
        //cout << "\n executando o desconstrutor....\n";
        No *n = inicio;

        while(n) {
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};

/// Quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n) {
    // cout << n
    return os << "[" << n->dado.codigo << ", " << n->dado.idade << ", " << n->dado.peso << "]";
}

/// Quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l) {
    No *n = l->inicio;

    while(n) {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }

    return os;
}

bool vaziaL(Lista *lista) {
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostrarInversoL(Lista *lista) {
    No *n = lista->fim;

    cout << "L[" << lista->tamanho << "]:{";
    while(n) {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}

/// Insere no inicio da lista
bool insereInicioL(Lista *lista, DadoNoLista valor) {
    No *novo = new No();

    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; /// Se o novo no sera adicionado no inicio da lista, o ponteiro *ant do primeiro no sempre e nulo
    novo->prox = lista->inicio;

    if (!lista->fim) /// Lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

No* buscaL(Lista *lista, DadoNoLista valor) {
    No *n = lista->inicio;

    while(n) {
        if (n->dado.codigo == valor.codigo)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removerNoL(Lista *lista, No *no) { /// Remove do inicio (eu acho)
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) { /// Se anterior e igual a NULL, o elemento a ser excluido esta no inicio da lista
        lista->inicio = no->prox;
        if (!lista->inicio) /// Lista ficou vazia?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    } else { /// Elemento esta no meio ou no fim
        no->ant->prox = no->prox;
        if (!no->prox) /// Se for retirado ultimo da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;
    }

    /// Libera a memoria do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

bool removeL(Lista *lista, DadoNoLista valor) { /// Remove um valor indicado
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

void mostraDescritorL(Lista *lista) {
    cout << "Descritor [" << lista->tamanho << ", " << lista->inicio << ", " << lista->fim << "]" << endl << endl;
}

#endif /// _HPP_LISTA_DUPLA
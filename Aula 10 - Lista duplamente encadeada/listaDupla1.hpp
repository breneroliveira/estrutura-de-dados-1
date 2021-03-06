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

No* buscaL(Lista *lista, int code) { /// Busca o animal pelo codigo
    No *n = lista->inicio;

    while(n) {
        if (n->dado.codigo == code)
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

bool removeL(Lista *lista, int code) { /// Remove um valor indicado (por codigo)
    No* no = buscaL(lista, code);

    if(!no)
        return false;

    if(no->dado.codigo == code)
        removerNoL(lista, no);

    return true;
}

void mostraDescritorL(Lista *lista) {
    string verifica = "NULL";

    if(vaziaL(lista))
        cout << "Descritor [" << 0 << ", " << verifica << ", " << verifica << "]" << endl << endl;
    else
        cout << "Descritor [" << lista->tamanho << ", " << lista->inicio << ", " << lista->fim << "]" << endl << endl;
}

void acessaTresUltimos(Lista *lista) {
    string verifica = "NULL";

    cout << "Tres ultimos [";

    if(lista->fim)
        cout << lista->fim << ", ";
    else if(lista->fim == nullptr)
        cout << verifica << ", ";

    if(lista->fim->ant)
        cout << lista->fim->ant << ", ";
    else if(lista->fim->ant == nullptr)
        cout << verifica << ", ";

    if(lista->fim->ant->ant)
        cout << lista->fim->ant->ant << "]\n";
    else if(lista->fim->ant->ant == nullptr)
        cout << verifica << "]\n";
}

void separaPorPeso(Lista *lista) {
    No *n = lista->inicio;
    
    Lista *listaMenor50 = new Lista();
    Lista *listaMaior50 = new Lista();

    if(vaziaL(lista)) {
        cout << "N??o ha animais na lista" << endl;
    } else {
        while(n) {
            if(n->dado.peso < 50)
                insereInicioL(listaMenor50, n->dado);
            else if(n->dado.peso > 50)
                insereInicioL(listaMaior50, n->dado);
            n = n->prox;
        }
    }

    cout << "\nAnimais (menos de 50Kg) [" << listaMenor50->tamanho << "]:{" << listaMenor50 << "}" << endl;
    cout << "\nAnimais (mais de 50Kg) [" << listaMaior50->tamanho << "]:{" << listaMaior50 << "}" << endl;
}

bool insereFinalL(Lista *lista, DadoNoLista valor) {
    No *novo = new No();

    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = lista->fim;
    novo->prox = nullptr;

    if (!lista->inicio) /// Lista vazia?
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

bool removeInicioL(Lista *lista) {
    No* no = lista->inicio;

    if(!no)
        return false;

    if(lista->inicio)
        removerNoL(lista, no);

    return true;
}

bool removeUltimoL(Lista *lista) {
    No* no = lista->fim;

    if(!no)
        return false;

    if(lista->fim)
        removerNoL(lista, no);

    return true;
}

#endif /// _HPP_LISTA_DUPLA
#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <iostream>

using namespace std;

struct Funcionario 
{
    int codigo;
    string nome;
    int idade;
    float salario;
};

typedef Funcionario DadoNoLista;

struct No
{
    DadoNoLista dado;
    struct No *prox;

    No() { /// Construtor
        dado.codigo = 0;
        dado.nome = "";
        dado.idade = 0;
        dado.salario = 0;
        prox = nullptr;
    }
};

struct Lista {
    No *inicio;
    No *fim;

    int tamanho;

    Lista() /// Construtor
    {
        /// cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
    ~Lista() /// Desconstrutor /// Quando chame delete (ponteiro)
    {
        /// cout << "\n executando o desconstrutor....\n";
        No *n = inicio;
        while(n)
        {
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};

/// Quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n;
    return os << "[" << n->dado.codigo << ", " << n->dado.nome << ", " << n->dado.idade << ", " << n->dado.salario << "]";
}

/// Quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    return os;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

/// Insere no inicio da lista
bool insereInicioL(Lista *lista, DadoNoLista valor)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}

bool insereFinalL(Lista *lista, DadoNoLista valor) {
    No *novo = new No();

    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(!lista->inicio)
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

/*bool removeL(Lista *lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    /// Fica no laco enquanto tiver elementos na lista
    /// E nao encontrar o valor procurado
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
        lista->inicio = atual->prox;
        if (!lista->inicio) /// Lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else /// Elemento esta no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox) /// Se for retirado ultimo da lista
            lista->fim = anterior;
    }
    /// Libera a memoria do elemento
    lista->tamanho--;

    delete(atual);
    return true;
}*/

No* buscaLCodigo(Lista *lista, DadoNoLista valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == valor.codigo)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(Lista *lista, DadoNoLista valor, int posicao)
{
    No *anterior = NULL;
    No *atual = lista->inicio;

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
    if(!anterior) /// Inclusao no inicio da lista
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;

        if (!lista->fim)
            lista->fim = lista->inicio;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;

        if (!novo->prox) /// O no adicionado esta no final da lista?
            lista->fim = novo;
    }

    lista->tamanho++;

    return true;
}

void mostraDescritorL(Lista *lista) {
    cout << "Descritor [" << lista->tamanho << ", " << lista->inicio << ", " << lista->fim << "]" << endl << endl;
}

#endif /// _HPP_LISTA_DESCRITOR
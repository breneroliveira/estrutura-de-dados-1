#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> /// Biblioteca usada para formatar a impressao da pilha

struct No
{
    int dado; /// Informacao do no
    No *prox; /// Proximo elemento da pilha
};

struct Pilha
{
    No *topo;

    Pilha(){ /// Construtor. Usado para inicializar os dados das variaveis da struct
        topo = nullptr;
    }
};

/// Inicializacao dos dados da pilha
void inicializaP(Pilha *p)
{
    p->topo = nullptr; /// Define nulo para o topo da pilha
}

bool vaziaP(Pilha *p)
{
    if (!p->topo) /// (p->topo == NULL)
        return true;
    else
        return false;
}

/// Push
bool empilhar(Pilha *p, int dado)
{
    No *novo =  new No(); /// Cria um novo nó
    if (!novo) /// Sistema não conseguiu alocar a memoria
        return false;

    novo->dado = dado; /// Armazena a informacao no no
    novo->prox = p->topo; /// O proximo elemento do no criado sera o ultimo elemento da pilha
    p->topo = novo; /// Atualiza o topo da pilha para o no criado
    return true;
}

/// Pop
bool desempilhar(Pilha *p, int *dado)
{
    /// Se nao estiver vazia, retira valor
    if (!vaziaP(p))
    {
        *dado = p->topo->dado; /// Pega o dado armazenado no no do topo
        No *apagar = p->topo; /// Guarda o nó do topo em uma variavel auxiliar
        p->topo = p->topo->prox; /// Atualiza o topo para o proximo elemento
        delete apagar;  /// Libera a memoria
        return true;
    }
    else
        return false;
}

/// Peek
bool espiar(Pilha* p, int *dado)
{
    if (p->topo)
    {
        *dado = p->topo->dado;
        return true;
    }
    else
        return false;
}

void mostrar(Pilha *p)
{
    cout << "PILHA: " << endl;

    if(!vaziaP(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "No" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        No *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

/// Retorna true se o valor existe na pilha
/// Retorna false se o valor nao existe na pilha
bool buscar(Pilha *p, int dado)
{
    No *no = p->topo;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}

void desalocar(Pilha *p)
{
    int dado;
    while(!vaziaP(p))
        desempilhar(p, &dado);
}

#endif /// _HPP_PILHA
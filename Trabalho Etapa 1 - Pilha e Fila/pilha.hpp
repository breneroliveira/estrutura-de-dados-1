#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include "estruturas.hpp"

#include <iomanip> /// Biblioteca usada para formatar a impressao da pilha
#include <iostream>

using namespace std;

/// Ler os dados do objeto quando inserir na pilha
struct No
{
    DadosObjeto objeto; /// Informacao do no
    DadosPessoa pessoa; 
    No *prox; /// Proximo elemento da pilha
};

struct Pilha
{
    No *topo;

    Pilha() { /// Construtor. Usado para inicializar os dados das variaveis da struct
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
bool empilhar(Pilha *p, DadosPessoa pessoa, DadosObjeto objeto)
{
    No *novo =  new No(); /// Cria um novo nó
    if (!novo) /// Sistema não conseguiu alocar a memoria
        return false;

    novo->pessoa.nomePessoa = pessoa.nomePessoa; /// Armazena a informacao no no da pessoa
    novo->pessoa.sexo = pessoa.sexo;
    novo->pessoa.cpf = pessoa.cpf;
    novo->pessoa.idade = pessoa.idade;
    novo->pessoa.pcd = pessoa.pcd;
    novo->pessoa.gestante = pessoa.gestante;

    novo->objeto.tipo = objeto.tipo; /// Armazena a informacao no no da pessoa
    novo->objeto.descricao = objeto.descricao;

    novo->prox = p->topo; /// O proximo elemento do no criado sera o ultimo elemento da pilha
    p->topo = novo; /// Atualiza o topo da pilha para o no criado
    return true;
}

/// Pop
bool desempilhar(Pilha *p, DadosPessoa *pessoa, DadosObjeto *objeto)
{
    /// Se nao estiver vazia, retira valor
    if (!vaziaP(p))
    {
        *pessoa = p->topo->pessoa; /// Pega o dado armazenado no no do topo
        *objeto = p->topo->objeto; /// Pega o dado armazenado no no do topo
        No *apagar = p->topo; /// Guarda o nó do topo em uma variavel auxiliar
        p->topo = p->topo->prox; /// Atualiza o topo para o proximo elemento
        delete apagar;  /// Libera a memoria
        
        return true;
    }
    else
        return false;
}

void mostrar(Pilha *p)
{
    cout << endl;
    if(!vaziaP(p))
    {
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(11) << "No" << " | ";
        cout << setfill(' ') << std::setw(9) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(14) << "Nome" << " | ";
        cout << setfill(' ') << std::setw(2) << "Sexo" << " | ";
        cout << setfill(' ') << std::setw(12) << "CPF" << " | ";
        cout << setfill(' ') << std::setw(1) << "Idade" << " | ";
        cout << setfill(' ') << std::setw(1) << "PcD" << " | ";
        cout << setfill(' ') << std::setw(1) << "Gestante" << " | ";
        cout << setfill(' ') << std::setw(1) << "Objeto" << " | ";
        cout << setfill(' ') << std::setw(13) << "Descricao" << " | " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        No *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(11) << no << " | ";
            cout << setfill(' ') << std::setw(9) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->pessoa.nomePessoa << " | ";
            cout << setfill(' ') << std::setw(4) << no->pessoa.sexo << " | ";
            cout << setfill(' ') << std::setw(12) << no->pessoa.cpf << " | ";
            cout << setfill(' ') << std::setw(5) << no->pessoa.idade << " | ";
            cout << setfill(' ') << std::setw(3) << no->pessoa.pcd << " | ";
            cout << setfill(' ') << std::setw(9) << no->pessoa.gestante << " | ";
            cout << setfill(' ') << std::setw(6) << no->objeto.tipo << " | ";
            cout << setfill(' ') << std::setw(12) << no->objeto.descricao << " | " << endl;
            cout << "------------------------------------------------------------------------------------------------------------------" << endl;
            no = no->prox;
        }
        cout << endl;
    } else
        cout << "A pilha esta vazia." << endl << endl;
}

int tamanhoPilha(Pilha *p) {
    int contElementos = 0;

    No *no = p->topo;

    while(no != NULL) {
        contElementos++;
        no = no->prox;
    }
    
    return contElementos;
}

void mostraPEquipamentos(Pilha *p)
{
    DadosPessoa auxPessoa;
    DadosObjeto auxObjeto;

    Pilha auxPilhaEquipamento;

    cout << "Equipamentos na ordem em que foram doados: " << endl;

    while(!vaziaP(p)) {
        desempilhar(p, &auxPessoa, &auxObjeto);
        empilhar(&auxPilhaEquipamento, auxPessoa, auxObjeto);
    }

    mostrar(&auxPilhaEquipamento);

    while(!vaziaP(&auxPilhaEquipamento)) {
        desempilhar(&auxPilhaEquipamento, &auxPessoa, &auxObjeto);
        empilhar(p, auxPessoa, auxObjeto);
    }
}

void mostraPLivro(Pilha *p)
{
    DadosPessoa auxPessoa;
    DadosObjeto auxObjeto;

    Pilha auxPilhaLivro;

    cout << "Livros na ordem em que foram doados: " << endl;

    while(!vaziaP(p)) {
        desempilhar(p, &auxPessoa, &auxObjeto);
        empilhar(&auxPilhaLivro, auxPessoa, auxObjeto);
    }

    mostrar(&auxPilhaLivro);

    while(!vaziaP(&auxPilhaLivro)) {
        desempilhar(&auxPilhaLivro, &auxPessoa, &auxObjeto);
        empilhar(p, auxPessoa, auxObjeto);
    }
}

bool pilhaCPF(Pilha *p, DadosPessoa pessoa) {
    No *novo =  new No(); /// Cria um novo no
    if (!novo) /// Sistema não conseguiu alocar a memoria
        return false;

    novo->pessoa.cpf = pessoa.cpf;

    novo->prox = p->topo; /// O proximo elemento do no criado sera o ultimo elemento da pilha
    p->topo = novo; /// Atualiza o topo da pilha para o no criado
    return true;
}

int busca(Pilha *p, DadosPessoa pessoa, string cpfBuscado)
{
    int contCPF = 0;
    No *no = p->topo;

    while (no != NULL)
    {
        if(no->pessoa.cpf == cpfBuscado)
            contCPF++;

        no = no->prox;
    }

    return contCPF;
}

#endif /// _HPP_PILHA
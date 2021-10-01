#ifndef _HPP_LISTA
#define _HPP_LISTA

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/// Pre-declaracao da struct Usuario
struct Usuario;

struct No {
    Usuario *dado; /// Referencia do usuario, evita duplicar dados entre as lista de amigos e a lista de usuarios da rede
    No *prox;

    No() {
        dado = nullptr;
        prox = nullptr;
    }
};

struct Lista {
    No* inicio;
    No* fim;
    int tamanho;

    Lista() { /// Inicializa a lista
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
    ~Lista() { /// Destroi a lista
        No *n = inicio;

        while(n) {
            No *aux = n;
            n = n->prox;

            delete aux; /// Apaga apenas o no, "Usuario *dado" ainda permanece alocado
        }

        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
};

/// Alocar memoria para criar um usuario: Usuario* usr = new  Usuario(1, 20, 0, "Joao");"
struct Usuario {
    int ID;
    int idade;
    int sexo;
    std::string nome;
    Lista *amigos; /// Lista de amigos

    Usuario(int id, int ida, int sx, string nm) {
        ID = id;
        idade = ida;
        sexo = sx;
        nome =  nm;
        amigos = new Lista();
    }

    Usuario() {
        ID = 0;
        idade = 0;
        sexo = 0;
        nome =  "";
        amigos = nullptr;
    }

    ~Usuario() {
        if(amigos)
            delete amigos;
        amigos = nullptr;

        ID = 0;
        idade = 0;
        sexo = 0;
        nome =  "";
        amigos = nullptr;
    }
};

/// Quando cout receber uma struct No
ostream& operator << (ostream& os, const No *n) {
    /// cout << n;
    return os << n->dado->nome << " (" << n->dado->ID << ")";
}
/*ostream& operator << (ostream& os, const No *n) {
    /// cout << n;
    return os << "[" << n->dado->ID << ", " << n->dado->nome << ", " << n->dado->idade << ", " << n->dado->sexo << "]";
}*/

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

No *buscaL(Lista *lista, int id) {
    No *n = lista->inicio;

    while(n) {
        if (n->dado->ID == id)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool vaziaL(Lista *lista) {
    if(!(lista->inicio))
        return true;
    else
        return false;
}

No *buscaIDRepetido(Lista *lista, Usuario *valor) {
    No *n = lista->inicio;

    while(n) {
        if (n->dado->ID == valor->ID)
            return n;

        n = n->prox;
    }

    return nullptr;
}

/// Insere ordenado na lista
bool addUsuario(Lista *lista, Usuario *valor) {
    No *aux;
    No *novo = new No();
    
    if(!novo)
        return false;

    novo->dado = valor;

    if(!buscaIDRepetido(lista, valor)) {
        if(lista->inicio == nullptr) {
            novo->prox = nullptr;
            lista->inicio = novo;
            lista->fim = novo;
        } else if(novo->dado->ID < lista->inicio->dado->ID) {
            novo->prox = lista->inicio;
            lista->inicio = novo;
        } else {
            aux = lista->inicio;

            while(aux->prox && novo->dado->ID > aux->prox->dado->ID) {
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
            
            if(!novo->prox)
                lista->fim = novo;
        }
        
        lista->tamanho++;
    } else
        return false;

    return true;
}

void imprimirUsuarios(Lista *lista, ostream *escreve) {
    No *n = lista->inicio;

    if(!n) {
        *escreve << "Nao ha usuarios na rede." << endl;
        (*escreve).flush();
    } else {
        *escreve << "Usuarios da rede: ";
        (*escreve).flush();
        while(n) {
            *escreve << n->dado->nome << " (" << n->dado->ID << ")";
            (*escreve).flush();
            
            if((lista->fim->dado) != n->dado) {
                *escreve << ", ";
                (*escreve).flush();
            } else {
                *escreve << "\n";
                (*escreve).flush();
            }
            
            n = n->prox;
        }
    }
}

void imprimirAmigos(Lista *lista, ostream *escreve, int id) {
    No *n;

    if(buscaL(lista, id)) 
        n = buscaL(lista, id)->dado->amigos->inicio;

    if(!buscaL(lista, id)) {
        *escreve << "\nErro ao imprimir amigos do usuario com ID " << id << ". O usuario nao existe." << endl;
        (*escreve).flush();
    } else {
        *escreve << "Amigos de " << buscaL(lista, id)->dado->nome << " (" << buscaL(lista, id)->dado->ID << "): ";
        (*escreve).flush();
        while(n) {
            *escreve << n->dado->nome << " (" << n->dado->ID << ")";
            (*escreve).flush();
            
            if((buscaL(lista, id)->dado->amigos->fim->dado->ID) != n->dado->ID) {
                *escreve << ", ";
                (*escreve).flush();
            } else {
                *escreve << "\n";
                (*escreve).flush();
            }
            n = n->prox;
        }
    }
}

bool removeL(Lista *lista, Usuario *valor) {
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
}

bool removerAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    if(buscaL(listaUsuariosRede, ID1) == buscaL(listaUsuariosRede, ID2))
        return false;

    if(!buscaL(listaUsuariosRede, ID1) || !buscaL(listaUsuariosRede, ID2))
        return false;

    if(!removeL(buscaL(listaUsuariosRede, ID1)->dado->amigos, buscaL(listaUsuariosRede, ID2)->dado) || 
       !removeL(buscaL(listaUsuariosRede, ID2)->dado->amigos, buscaL(listaUsuariosRede, ID1)->dado))
        return false;

    return true;
}

bool removerTodasAmizades(Lista *lista, Usuario *usuario) {
    No *n = buscaL(lista, usuario->ID);
    No *amigo = n->dado->amigos->inicio;

    if(!n)
        return false;

    while(amigo) {
        removerAmigo(lista, n->dado->ID, amigo->dado->ID);
        amigo = amigo->prox;
    }

    return true;
}

void mostraDescritorL(Lista *lista) {
    string verifica = "NULL";

    if(vaziaL(lista))
        cout << "Descritor [" << 0 << ", " << verifica << ", " << verifica << "]" << endl;
    else
        cout << "Descritor [" << lista->tamanho << ", " << lista->inicio << ", " << lista->fim << "]" << endl;
}

#endif /// _HPP_LISTA
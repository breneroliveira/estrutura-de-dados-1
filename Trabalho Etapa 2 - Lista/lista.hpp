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

    while (n) {
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
    *escreve << "Usuarios da rede: " << lista << endl;
    
    //escreve.close();
}

/*void imprimirAmigos(Lista *lista) {
    ofstream escreve("saida.txt", ios::app);

    if(escreve.is_open())
        escreve << "L_Amigos [" << lista->tamanho << "]:{" << lista << "}" << endl;
}*/

void mostraDescritorL(Lista *lista) {
    string verifica = "NULL";

    if(vaziaL(lista))
        cout << "Descritor [" << 0 << ", " << verifica << ", " << verifica << "]" << endl;
    else
        cout << "Descritor [" << lista->tamanho << ", " << lista->inicio << ", " << lista->fim << "]" << endl;
}

#endif /// _HPP_LISTA
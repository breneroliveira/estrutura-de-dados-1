#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "lista.hpp"

//char elementoArquivo[80];
//ifstream leitura;

void addAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    /// Buscar usuario 1, passando por parametro (listaUsuariosRede, ID1)

    /// Buscar usuario 2, passando por parametro (listaUsuariosRede, ID2)


    /// insereL(usuario1->amigos, usuario2);
    /// insereL(usuario2->amigos, usuario1);
}

void removerAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    /// Buscar usuario 1, passando por parametro (listaUsuariosRede, ID1)

    /// Buscar usuario 2, passando por parametro (listaUsuariosRede, ID2)


    /// removeL(usuario1->amigos, usuario2); /// remove o no
    /// removeL(usuario2->amigos, usuario1); /// remove o no
}

void removerUsuarioRede(Lista * listaUsuariosRede, int ID1) {
    /// Buscar usuario 1, passando por parametro (listaUsuariosRede, ID1)

    /// Se Fernanda sera removida, a amizada entre Fernanda e Pedro deve ser removida primeiro!
    /// removerTotasAmizades(usuario1);


    /// removeL(listaUsuariosRede, usuario1); /// remove o no
    /// delete usuario1; /// desaloca o usuario
}

void removerTodosUsariosRede(Lista * listaUsuariosRede) {
    /// Chamar "removerUsuarioRede" para todos os usuarios da rede
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Usuario *novoUsr = nullptr;
    Lista *listaUsuariosRede = new Lista();

    string elementoArquivo, codigo;

    ifstream leitura;
    leitura.open("entrada.txt", ios::in);

    ofstream escreve("saida.txt", ios::out);

    /// Adicionando usuarios
    if(leitura.is_open() && escreve.is_open()) {
        while(!leitura.eof()) {
            leitura >> codigo;
            
            if(codigo == "addUsuario") {
                int ID;
                int idade;
                int sexo;
                string nome;

                leitura >> ID;
                leitura >> idade;
                leitura >> sexo;
                leitura >> nome;

                Usuario *novo = new Usuario(ID, idade, sexo, nome);

                if(addUsuario(listaUsuariosRede, novo))
                    escreve << "O usuário " << nome << " (" << ID << ") foi adicionado na rede." << endl;
                else
                    escreve << "Erro ao adicionar o usuário " << nome << " (" << ID << "). O ID " << ID << " já existe." << endl;
            } else if(codigo == "imprimirUsuario") {
                imprimirUsuario(listaUsuariosRede);
            } else if(codigo.at(0) == '#') {
                getline(leitura, elementoArquivo);
            }
        }
    } else
        cout << "Erro ao abrir o arquivo." << endl;

    leitura.close();

    mostraDescritorL(listaUsuariosRede);

    /// Removendo amigo
    //removerAmigo(listaUsuariosRede,  4, 10);

    /// Removendo usuario da rede
    //removerUsuarioRede(listaUsuariosRede, 10);

    //removerTodosUsariosRede(listaUsuariosRede);

    delete listaUsuariosRede;

    return EXIT_SUCCESS;
}
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "lista.hpp"

bool addAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    /// Buscar usuario 1, passando por parametro (listaUsuariosRede, ID1)
    No *user1 = buscaL(listaUsuariosRede, ID1);

    /// Buscar usuario 2, passando por parametro (listaUsuariosRede, ID2)
    No *user2 = buscaL(listaUsuariosRede, ID2);

    if(user1 == user2)
        return false;

    if(!user1 || !user2)
        return false;

    /// insereL(usuario1->amigos, usuario2);
    //addUsuario(user1->dado->amigos, user2->dado);
    /// insereL(usuario2->amigos, usuario1);
    //addUsuario(user2->dado->amigos, user1->dado);

    if(!addUsuario(user1->dado->amigos, user2->dado) || !addUsuario(user2->dado->amigos, user1->dado))
        return false;

    return true;
}

/*bool removerAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    /// Buscar usuario 1, passando por parametro (listaUsuariosRede, ID1)
    No *user1 = buscaL(listaUsuariosRede, ID1);

    /// Buscar usuario 2, passando por parametro (listaUsuariosRede, ID2)
    No *user2 = buscaL(listaUsuariosRede, ID2);

    if(!user1 || !user2)
        return false;


    /// removeL(usuario1->amigos, usuario2); /// remove o no
    /// removeL(usuario2->amigos, usuario1); /// remove o no

    if(!removeL(user1->dado->amigos, user2->dado) || !removeL(user2->dado->amigos, user1->dado))
        return false;
}*/

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

    //Usuario *novoUsr = nullptr;
    Lista *listaUsuariosRede = new Lista();
    //No *listaAmigos = new No();

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

                if(addUsuario(listaUsuariosRede, novo)) {
                    escreve << "O usuario " << nome << " (" << ID << ") foi adicionado na rede." << endl;
                    escreve.flush();
                } else {
                    escreve << "Erro ao adicionar o usuario " << nome << " (" << ID << "). O ID " << ID << " ja existe." << endl;
                    escreve.flush();
                }
            } else if(codigo == "addAmigo") {
                int IDAmigo1, IDAmigo2;

                leitura >> IDAmigo1;
                leitura >> IDAmigo2;

                if(addAmigo(listaUsuariosRede, IDAmigo1, IDAmigo2)) {
                    No *amigoBuscado1 = buscaL(listaUsuariosRede, IDAmigo1);
                    No *amigoBuscado2 = buscaL(listaUsuariosRede, IDAmigo2);

                    escreve << "Os usuarios " << amigoBuscado1->dado->nome << " (" << amigoBuscado1->dado->ID << ") e " << amigoBuscado2->dado->nome << " (" << amigoBuscado2->dado->ID << ") se tornaram amigos." << endl;
                    escreve.flush();
                } else {
                    escreve << "Erro ao criar amizade dos usuários com IDs " << IDAmigo1 << " e " << IDAmigo2 <<"." << endl;
                    escreve.flush();
                }
            } else if(codigo == "imprimirUsuarios") {
                imprimirUsuarios(listaUsuariosRede, &escreve);
            } else if(codigo == "imprimirAmigos") {
                int IDAmigoBuscado;

                leitura >> IDAmigoBuscado;

                imprimirAmigos(listaUsuariosRede, &escreve, IDAmigoBuscado);
            } else if(codigo.at(0) == '#') {
                getline(leitura, elementoArquivo);
            }
        }
    } else
        cout << "Erro ao abrir o arquivo." << endl;

    leitura.close();
    escreve.close();

    mostraDescritorL(listaUsuariosRede);
    cout << "Usuarios da rede: " << listaUsuariosRede->tamanho << "]:{" << listaUsuariosRede << "}" << endl;

    /// Removendo amigo
    //removerAmigo(listaUsuariosRede,  4, 10);

    /// Removendo usuario da rede
    //removerUsuarioRede(listaUsuariosRede, 10);

    //removerTodosUsariosRede(listaUsuariosRede);

    delete listaUsuariosRede;

    return EXIT_SUCCESS;
}
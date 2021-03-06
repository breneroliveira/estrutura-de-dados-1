#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "lista.hpp"

bool addAmigo(Lista * listaUsuariosRede, int ID1, int ID2) {
    if(buscaL(listaUsuariosRede, ID1) == buscaL(listaUsuariosRede, ID2))
        return false;

    if(!buscaL(listaUsuariosRede, ID1) || !buscaL(listaUsuariosRede, ID2))
        return false;

    if(!addUsuario(buscaL(listaUsuariosRede, ID1)->dado->amigos, buscaL(listaUsuariosRede, ID2)->dado) || 
       !addUsuario(buscaL(listaUsuariosRede, ID2)->dado->amigos, buscaL(listaUsuariosRede, ID1)->dado))
        return false;

    return true;
}

bool removerUsuarioRede(Lista * listaUsuariosRede, int ID1) {    
    if(!buscaL(listaUsuariosRede, ID1))
        return false;

    if(!removerTodasAmizades(listaUsuariosRede, buscaL(listaUsuariosRede, ID1)->dado))
        return false;

    Usuario *user = buscaL(listaUsuariosRede, ID1)->dado;

    if(removeL(listaUsuariosRede, buscaL(listaUsuariosRede, ID1)->dado))
        delete(user);
    else
        return false;

    return true;
}

void removerTodosUsariosRede(Lista * listaUsuariosRede) {
    No *n = listaUsuariosRede->inicio;

    if(!n)
        return;

    while(n) {
        removerUsuarioRede(listaUsuariosRede, n->dado->ID);
        n = n->prox;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

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
                    escreve << "Erro ao criar amizade dos usuarios com IDs " << IDAmigo1 << " e " << IDAmigo2 <<"." << endl;
                    escreve.flush();
                }
            } else if(codigo == "imprimirUsuarios") {
                imprimirUsuarios(listaUsuariosRede, &escreve);
            } else if(codigo == "imprimirAmigos") {
                int IDAmigoBuscado;

                leitura >> IDAmigoBuscado;

                imprimirAmigos(listaUsuariosRede, &escreve, IDAmigoBuscado);
            } else if(codigo == "removerAmigo") {
                int IDAmigoRemover1, IDAmigoRemover2;

                leitura >> IDAmigoRemover1;
                leitura >> IDAmigoRemover2;

                if(removerAmigo(listaUsuariosRede, IDAmigoRemover1, IDAmigoRemover2)) {
                    No *amigoRemovido1 = buscaL(listaUsuariosRede, IDAmigoRemover1);
                    No *amigoRemovido2 = buscaL(listaUsuariosRede, IDAmigoRemover2);

                    escreve << "Os usuarios " << amigoRemovido1->dado->nome << " (" << amigoRemovido1->dado->ID << ") e " << amigoRemovido2->dado->nome << " (" << amigoRemovido2->dado->ID << ") nao sao mais amigos." << endl;
                    escreve.flush();
                } else {
                    escreve << "Erro ao remover a amizade. Nao existe amizade entre os usuarios com IDs " << IDAmigoRemover1 << " e " << IDAmigoRemover2 <<"." << endl;
                    escreve.flush();
                }
            } else if(codigo == "removerUsuario") {
                int IDUsuarioRemover;

                leitura >> IDUsuarioRemover;

                if(buscaL(listaUsuariosRede, IDUsuarioRemover)) {
                    No *usuarioRemovido = buscaL(listaUsuariosRede, IDUsuarioRemover);

                    escreve << "O usuario " << usuarioRemovido->dado->nome << " (" << usuarioRemovido->dado->ID << ") foi excluido da rede." << endl;
                    escreve.flush();
                    
                    removerUsuarioRede(listaUsuariosRede, IDUsuarioRemover);
                } else {
                    escreve << "Erro ao excluir o usuario com ID " << IDUsuarioRemover << ". O usuario nao existe." << endl;
                    escreve.flush();
                }
            } else if(codigo == "removerTodosUsariosRede") {
                removerTodosUsariosRede(listaUsuariosRede);
            } else if(codigo == "imprimirMediaIdadeAmigos") {
                int IDUsuarioMedia;

                leitura >> IDUsuarioMedia;

                imprimirMediaIdadeAmigos(listaUsuariosRede, IDUsuarioMedia, &escreve);
            } else if(codigo == "imprimirAmigosEmComum") {
                int IDAmigoComum1, IDAmigoComum2, sexo;

                leitura >> IDAmigoComum1;
                leitura >> IDAmigoComum2;
                leitura >> sexo;

                imprimirAmigosEmComum(listaUsuariosRede, IDAmigoComum1, IDAmigoComum2, sexo, &escreve);
            } else if(codigo.at(0) == '#') {
                getline(leitura, elementoArquivo);
            }
        }

        cout << "O programa foi executado, verifique o arquivo 'saida.txt'." << endl;
    } else
        cout << "Erro ao abrir o arquivo." << endl;

    leitura.close();
    escreve.close();

    removerTodosUsariosRede(listaUsuariosRede);

    delete listaUsuariosRede;

    return EXIT_SUCCESS;
}
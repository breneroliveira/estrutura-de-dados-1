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
                    escreve << "Erro ao remover a amizade. Não existe amizade entre os usuários com IDs " << IDAmigoRemover1 << " e " << IDAmigoRemover2 <<"." << endl;
                    escreve.flush();
                }
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
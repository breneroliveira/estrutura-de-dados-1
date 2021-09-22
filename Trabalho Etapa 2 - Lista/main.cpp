#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "lista.hpp"

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

    /// Adicionando usuarios
    novoUsr = new Usuario(4, 20, 0, "Joao"); /// id, idade, sexo, nome

    /// insereL(listaUsuariosRede, novoUsr); /// Insere na lista o ponteiro para o usuario

    novoUsr = new Usuario(10, 30, 1, "Fernanda"); //id, idade, sexo, nome
    /// insereL(listaUsuariosRede, novoUsr); /// Insere na lista o ponteiro para o usuario

    ///Mostra lista
    mostraDescritorL(listaUsuariosRede); /// Mostra os descritores (tamanho, inicio e fim)
    cout << "L_Usuarios [" << listaUsuariosRede->tamanho << "]:{" << listaUsuariosRede << "}" << endl;  /// Mostra a lista

    /// Adicionando amigo
    addAmigo(listaUsuariosRede, 4, 10);

    /// Removendo amigo
    removerAmigo(listaUsuariosRede,  4, 10);

    /// Removendo usuario da rede
    removerUsuarioRede(listaUsuariosRede, 10);

    removerTodosUsariosRede(listaUsuariosRede);

    delete listaUsuariosRede;
    return EXIT_SUCCESS;
}
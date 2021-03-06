#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip>

struct Pilha {
    int topo;
    int base;
    int tam;
    char *dados;

    Pilha(){
        tam = 0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

void inicializa(Pilha *p, int tam){
    p->base = -1;
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new char[tam];

}

bool vazia(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

bool empilhar(Pilha *p, char valor){
    if (p->topo == (p->tam - 1)){
        return false;
    }
    else {
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

bool desempilhar(Pilha *p, char *valor){
    if (p->topo == -1){
        return false;
    }
    else {
        *valor = p->dados[p->topo];
        p->topo--;
        return true;
    }
}

void mostrar(Pilha *p)
{

    if (p->dados == NULL) /// retorna se a pilha n?o foi inicializada
        return;

    cout << "PILHA :" << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(!vazia(p))
    {
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}

#endif /// _HPP_PILHA

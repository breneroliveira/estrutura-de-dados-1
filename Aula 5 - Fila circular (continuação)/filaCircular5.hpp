#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> /// Biblioteca usada para formatar a impress�o da fila

struct Fila
{
    int tam; /// Tamanho do vetor de dados
    int total; /// Total de elementos armazenados na fila
    int inicio; /// Ponteiro para o elemento armazenado no inicio da fila
    int fim; /// Ponteiro para o fim da fila (posi��o do vetor onde ser� armazenado o pr�ximo elemento)
    char *dados; /// Ponteiro para o vetor que ser� alocado para armazenar os dados

    Fila() /// Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam = 0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

void inicializaF(Fila *f, int tam) /// Inicializa��o da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new char[tam]; /// Aloca mem�ria para vetor
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(f->dados) /// f->dados != NULL
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}

bool vaziaF(Fila *f) /// Fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f) /// Fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

/// Enqueue
bool enfileiraF(Fila *f, char valor) /// Incluir valor na fila
{
    if (!f->dados || cheiaF(f)) /// Retorna false se a fila n�o foi inicializada ou se cheia
        return false;

    /// Inserir no final da fila
    f->dados[f->fim] = valor;

    /// Incrementa a quantidade de elementos armazenados na fila
    f->total++;

    /// Avan�a o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0; /// Circular

    return true;
}

/// Dequeue
bool desenfileiraF(Fila *f, char *valor)  /// Retirar da fila
{
    if (!f->dados || vaziaF(f)) /// Retorna false se a fila n�o foi inicializada ou se vazia
        return false;

    /// Remover do inicio da fila
    *valor = f->dados[f->inicio];

    /// Diminui a quantidade de elementos armazenados na fila
    f->total--;

    /// Avan�a o ponteiro in�cio
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0; /// Circular

    return true;
}

/// Peek
bool espiarF(Fila *f, char *valor) /// Peek
{
    if (!f->dados || vaziaF(f))  /// Retorna false se a fila n�o foi inicializada ou se vazia
        return false;

    *valor = f->dados[f->inicio];

    return true;
}

void mostraF(Fila *f)
{
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";


    if (!f->dados)  /// Retorna se a fila n�o foi inicializada
        return;

    if (!vaziaF(f))
    {
        int idx = f->inicio;
        cout << "[";
        for(int i = 0; i < f->total; i++)
        {
            cout << f->dados[idx];

            if(i < f->total-1)
                cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0; /// Circular
        }
        cout << "]\n";
    }else
        cout << "Fila vazia!\n";
}

void mostraVetorDadosF(Fila *f)
{
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total;
    cout << ", I = " << f->inicio << ", F = " <<  f->fim << "} -> ";


    if (!f->dados) /// Retorna se a fila n�o foi inicializada
        return;

    /// A quantidade de dados armazenados na fila pode ser menor que o tamanho do vetor de dados "f->dados"
    /// Assim, o vetor de dados "f->dados" pode conter posi��es livres quando a fila n�o est� cheia.
    /// O vetor "dadosFila[f->tam]" foi usado para determinar se uma posi��o i do vetor f->dados est� livre ou n�o
    bool dadosFila[f->tam];

    /// Inicializa o vetor, indicando que que todos as posi��es do vetor est�o livres, ou seja, fila vazia
    for(int i = 0; i < f->tam; i++)
        dadosFila[i] = false;

    /// Atribui TRUE para cada posi��o do vetor de dados que armazena um valor da fila
    int idx = f->inicio;
    for(int i = 0; i < f->total; i++) /// FOR percorrendo f->inicio at� f->fim
    {
        dadosFila[idx] = true;
        idx++;
        if(idx >= f->tam)
            idx = 0; /// Circular
    }

    /// Imprimir o vetor, colocando "-" para posi��es livres
    cout << "[";
    for(int i = 0; i < f->tam; i++)
    {
        /// Para cada posi��o n�o nula do vetor de dados, imprimir o valor do dado
        if(dadosFila[i])
            cout << f->dados[i];
        else
            cout << "-";

        if(i < f->tam-1)
            cout << ", ";
    }
    cout << "]\n";
}

#endif /// _HPP_FILA

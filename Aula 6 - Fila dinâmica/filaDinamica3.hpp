#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA

typedef int DadoNoFila;

struct NoFila
{
    DadoNoFila dado; /// Informacao do nó
    NoFila *prox; /// Proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila() { /// Construtor. Usado para inicializar os dados das variaveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};

/// Inicializacao dos dados da fila
void inicializaF(Fila *f)
{
    /// Define nulo para o ininio e o fim da fila
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaF(Fila *f)
{
    if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}

/// Enqueue
bool enfileiraF(Fila *f, DadoNoFila dado)
{
    NoFila *novo = new NoFila();
    if (!novo) /// Nao conseguiu alocar memoria (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

/// Dequeue
bool desenfileiraF(Fila *f, DadoNoFila *dado)
{
    /// Se nao estiver vazia, retira valor
    if (f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado; /// Pega o dado armazenado no primeiro no
        NoFila *apagar = f->inicio; /// Guarda o primeiro no em uma variavel auxiliar
        f->inicio = f->inicio->prox; /// Atualiza o inicio da fila
        delete apagar; /// Libera a memoria

        if (!f->inicio) /// Verifica se a fila esta vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;

        return true;
    } else
        return false;
}

/// Peek
bool espiaF(Fila* f, DadoNoFila *dado)
{
    if (f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado;
        return true;
    }
    else
        return false;
}

/// Show
void mostraF(Fila *f)
{
    cout << "Fila: ";

    if(f->inicio) /// Verifica se a fila nao esta vazia, ou seja, (f->inicio != NULL)
    {
        cout << "[";

        NoFila *no = f->inicio;
        while (no) /// Faça enquanto (no != NULL)
        {
            cout << no->dado;
            no = no->prox;

            if(no) /// Verifica se o proximo no nao e nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl << endl;
    } else
        cout << "Fila vazia.\n\n";
}

/// Retorna true se o valor existe na fila
/// Retorna false se o valor nao existe na fila
bool buscaF(Fila *f, DadoNoFila dado)
{
    NoFila *no = f->inicio;
    while (no) /// Faca enquanto (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(Fila *f)
{
    NoFila *no = f->inicio;
    while (no) /// Faca enquanto (no != NULL)
    {
        NoFila *apagar = no; /// Guarda o no em uma variavel auxiliar

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

void concatenaF (Fila *f1, Fila *f2, Fila *fConcatenada) {
    if(vaziaF(f1) && vaziaF(f2))
        cout << "Fila A e fila B estao vazias." << endl << endl;
    else {
        NoFila *no1 = f1->inicio;
        NoFila *no2 = f2->inicio;
        destroiF(fConcatenada);
        while(no1)        
        {
            enfileiraF(fConcatenada, no1->dado);
            no1 = no1->prox;
        }
        while(no2)        
        {
            enfileiraF(fConcatenada, no2->dado);
            no2 = no2->prox;
        }
        mostraF(fConcatenada);
    }
}

#endif /// _HPP_FILA_DINAMICA
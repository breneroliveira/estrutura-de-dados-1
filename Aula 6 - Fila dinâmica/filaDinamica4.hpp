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

void separaF(int n, Fila *f1, Fila *f2) {
    Fila fAux;
    int aux = 0;

    if(vaziaF(f1))
        cout << "\nFila 1 esta vazia." << endl << endl;
    else if(!buscaF(f1, n))
        cout << "\nO numero " << n << " nao consta na fila 1." << endl << endl;
    else {
        while(!vaziaF(f1)) {
            desenfileiraF(f1, &aux);
            enfileiraF(&fAux, aux);
            if(aux == n) {
                while(!vaziaF(f1)) {
                    desenfileiraF(f1, &aux);
                    enfileiraF(f2, aux);
                }
            }
        } 
        while(!vaziaF(&fAux)) {
            desenfileiraF(&fAux, &aux);
            enfileiraF(f1, aux);
        }
    }
}

#endif /// _HPP_FILA_DINAMICA
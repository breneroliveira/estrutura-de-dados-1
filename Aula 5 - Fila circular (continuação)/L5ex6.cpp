#include <iostream>
#include <fstream>

using namespace std;

#include "filaCircular6.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;

    float numero;
    int menu;
    bool controle = false;
    char x[100];
    float aux, soma = 0;

    inicializaF(&f1, 8);

    ofstream escreve("revisa.txt", ios::out);
    ifstream leitura;

    do {
        cout << "***************** MENU ******************" << endl;
        cout << "*                                       *" << endl;
        cout << "* 1. Incluir na fila                    *" << endl;
        cout << "* 2. Mostrar a fila                     *" << endl;
        cout << "* 3. Remover da fila                    *" << endl;
        cout << "* 4. Mostrar dados do arquivo e a soma  *" << endl;
        cout << "* 5. Sair                               *" << endl;
        cout << "*                                       *" << endl;
        cout << "*****************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 1:
                system("cls");

                cout << "Insira um numero: ";
                cin >> numero;

                while (numero > 50)
                {
                    system("cls");
                    cout << "Nao sao permitidos maiores que 50." << endl << endl;
                    system("pause");
                    system("cls");

                    cout << "Insira um numero menor que 50: ";
                    cin >> numero;
                }

                if(enfileiraF(&f1, numero))
                    cout << "\nNumero inserido." << endl << endl;
                else
                    cout << "\nFila cheia." << endl << endl;

                break;

            case 2:
                system("cls");

                mostraF(&f1);
                
                break;

            case 3:
                system("cls");

                if(desenfileiraF(&f1, &numero)) {
                    cout << "Numero " << numero << " removido." << endl << endl;

                    ofstream escreve("revisa.txt", ios::app);

                    if(escreve.is_open()) {
                        escreve << "\n" << numero;

                        escreve.close();
                    }
                } else
                    cout << "Fila vazia." << endl << endl;

                break;

            case 4:
                system("cls");

                leitura.open("revisa.txt", ios::in);

                if(leitura.is_open()) {
                    cout << "Arquivo aberto." << endl << endl;

                    soma = 0;

                    while(leitura.getline(x, sizeof(x), '\n')) {
                        cout << x << " ";
                        aux = atof(x);
                        soma += aux;
                    }
                } else
                    cout << "Erro ao abrir o arquivo." << endl;

                leitura.close();

                cout << "\n\nSoma dos valores do arquivo: " << soma << endl << endl;

                break;

            case 5:
                system("cls");

                cout << "Programa encerrado." << endl << endl;

                break;

            default:
                system("cls");

                cout << "Opcao invalida." << endl << endl;

                break;
        }

        system("pause");
        system("cls");

    } while(menu != 5);

    //ofstream escreve("revisa.txt", ios::trunc);
    //escreve.close();
}
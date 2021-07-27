#include <iostream>

using namespace std;

#include "filaDinamica2.hpp"
#include "pilhaDinamica2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Pilha p1;
    int valor;
    int menu;

    /// Não precisamos definir o tamanho da fila
    inicializaF(&f1);

    do {
        cout << "***************** MENU ******************" << endl;
        cout << "*                                       *" << endl;
        cout << "* 1. Incluir na fila                    *" << endl;
        cout << "* 2. Remover da fila                    *" << endl;
        cout << "* 3. Mostrar fila                       *" << endl;
        cout << "* 4. Inverter fila                      *" << endl;
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
                cin >> valor;

                if(enfileiraF(&f1, valor))
                    cout << "\nNumero inserido." << endl << endl;
                else
                    cout << "\nFila cheia." << endl << endl;

                break;

            case 2:
                system("cls");

                if(desenfileiraF(&f1, &valor)) {
                    cout << "Numero " << valor << " removido." << endl << endl;
                } else
                    cout << "Fila vazia." << endl << endl;
                
                break;

            case 3:
                system("cls");

                mostraF(&f1);

                break;

            /*case 4:
                system("cls");

                

                break;*/

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

    return EXIT_SUCCESS;

} /// Final do main

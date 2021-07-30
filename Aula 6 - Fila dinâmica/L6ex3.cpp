#include <iostream>

using namespace std;

#include "filaDinamica3.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2, fConcatenada;
    int valorF1, valorF2;
    int menu;

    do {
        cout << "***************** MENU ******************" << endl;
        cout << "*                                       *" << endl;
        cout << "* 1. Incluir na fila 1                  *" << endl;
        cout << "* 2. Incluir da fila 2                  *" << endl;
        cout << "* 3. Mostrar filas 1 e 2                *" << endl;
        cout << "* 4. Mostrar filas concatenadas         *" << endl;
        cout << "* 5. Sair                               *" << endl;
        cout << "*                                       *" << endl;
        cout << "*****************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 1:
                system("cls");

                cout << "Insira um valor na fila 1: ";
                cin >> valorF1;

                if(enfileiraF(&f1, valorF1))
                    cout << "\nNumero " << valorF1 << " inserido na fila 1." << endl << endl;

                break;

            case 2:
                system("cls");

                cout << "Insira um valor na fila 2: ";
                cin >> valorF2;

                if(enfileiraF(&f2, valorF2))
                    cout << "\nNumero " << valorF2 <<  " inserido na fila 2." << endl << endl;

                break;

            case 3:
                system("cls");

                cout << "*** FILA 1 ***" << endl;
                mostraF(&f1);

                cout << "*** FILA 2 ***" << endl;
                mostraF(&f2);

                break;

            case 4:
                system("cls");

                cout << "*** FILA CONCATENADA ***" << endl;
                concatenaF(&f1, &f2, &fConcatenada);

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

    return EXIT_SUCCESS;
}
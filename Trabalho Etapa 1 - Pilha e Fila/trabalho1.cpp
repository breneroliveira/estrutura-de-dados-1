#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//#include "pilha.hpp"
#include "filaPessoa.hpp"
#include "filaTransportadora.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    FilaPessoa fDoaPrioritaria, fDoaNaoPrioritaria;
    FilaTransportadora fRetiraPrioritaria, fRetiraNaoPrioritaria;
    //Pilha pLivro, pEquipamento;

    DadosObjeto objeto;
    DadosPessoa pessoa;
    DadosTransportadora transportadora;

    int auxPcd;

    char menu;

    do {
        cout << "******************* MENU *********************" << endl;
        cout << "*                                            *" << endl;
        cout << "* a) Incluir pessoa na fila de doacao;       *" << endl;
        cout << "* n) Encerrar programa.                      *" << endl;
        cout << "*                                            *" << endl;
        cout << "**********************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

            case 'a':
                system("cls");

                cout << "********** Inclusao de pessoa **********" << endl;
                cout << "Nome: ";
                getline(cin, pessoa.nomePessoa);
                fflush(stdin);

                cout << "Sexo: ";
                cin >> pessoa.sexo;
                fflush(stdin);

                cout << "CPF: ";
                cin >> pessoa.cpf;
                fflush(stdin);

                cout << "Idade: ";
                cin >> pessoa.idade;
                fflush(stdin);

                cout << "Pessoa com deficiencia (1 = sim/0 = nao): ";
                //cin >> pessoa.pcd;
                cin >> auxPcd;
                fflush(stdin);

                while(auxPcd != 1 && auxPcd != 0) {
                    cout << "Digite 1 para 'sim' ou 0 para 'nao': ";
                    //cin >> pessoa.pcd;
                    cin >> auxPcd;
                    fflush(stdin);
                }

                pessoa.pcd = auxPcd;

                cout << "Gestante: ";
                cin >> pessoa.gestante;
                fflush(stdin);

                if(enfileiraFPessoa(&fDoaPrioritaria, pessoa))
                    cout << "\nDados de " << pessoa.nomePessoa << " inseridos na fila 1." << endl << endl;

                mostraFPessoa(&fDoaPrioritaria);

                break;

            /*case 2:
                system("cls");

                cout << "Insira um numero: ";
                cin >> nInt;

                separaF(nInt, &f1, &f2);

                break;

            case 3:
                system("cls");

                cout << "*** FILA 1 ***" << endl;
                mostraF(&f1);

                cout << "*** FILA 2 ***" << endl;
                mostraF(&f2);

                break;*/

            case 'n':
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

    } while(menu != 'n');

    return EXIT_SUCCESS;
}
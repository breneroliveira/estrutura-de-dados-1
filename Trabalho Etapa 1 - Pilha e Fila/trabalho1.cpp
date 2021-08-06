#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "pilha.hpp"
#include "filaPessoa.hpp"
#include "filaTransportadora.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    FilaPessoa fDoaPrioritaria, fDoaNaoPrioritaria;
    FilaTransportadora fRetiraPrioritaria, fRetiraNaoPrioritaria;
    Pilha pLivro, pEquipamento;

    DadosObjeto objeto;
    DadosPessoa pessoa;
    DadosTransportadora transportadora;

    ofstream escreve("doacao.txt", ios::out);

    stringstream sso;
    string teste;

    char menu;

    do {
        cout << "******************* MENU *********************" << endl;
        cout << "*                                            *" << endl;
        cout << "* a) Incluir pessoa na fila de doacao;       *" << endl;
        cout << "* b) Incluir empresa na fila de retirada;    *" << endl;
        cout << "* c) Atender uma pessoa da fila;             *" << endl;
        cout << "* d) Atender uma empresa da fila;            *" << endl;
        cout << "* n) Encerrar programa.                      *" << endl;
        cout << "* z) Mostra tudo.                            *" << endl;
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

                pessoa.sexo = toupper(pessoa.sexo);

                cout << "CPF: ";
                cin >> pessoa.cpf;
                fflush(stdin);

                cout << "Idade: ";
                cin >> pessoa.idade;
                fflush(stdin);

                cout << "Pessoa com deficiencia (1 = sim/0 = nao): ";
                cin >> pessoa.pcd;
                fflush(stdin);

                cout << "Gestante (1 = sim/0 = nao): ";
                cin >> pessoa.gestante;
                fflush(stdin);

                if(pessoa.gestante == true || pessoa.pcd == true || pessoa.idade > 65) {
                    if(enfileiraFPessoa(&fDoaPrioritaria, pessoa))
                        cout << "\nDados de " << pessoa.nomePessoa << " inseridos na fila prioritaria." << endl << endl;
                } else {
                    if(enfileiraFPessoa(&fDoaNaoPrioritaria, pessoa))
                        cout << "\nDados de " << pessoa.nomePessoa << " inseridos na fila nao prioritaria." << endl << endl;
                }

                break;

            case 'b':
                system("cls");

                cout << "********** Inclusao de transportadora **********" << endl;
                cout << "Nome: ";
                getline(cin, transportadora.nomeTransportadora);
                fflush(stdin);

                cout << "CNPJ: ";
                cin >> transportadora.cnpj;
                fflush(stdin);

                cout << "Tipo: ";
                cin >> transportadora.tipo;
                fflush(stdin);

                transportadora.tipo = toupper(transportadora.tipo);

                if(transportadora.tipo == 'L') {
                    if(enfileiraFTransportadora(&fRetiraPrioritaria, transportadora))
                        cout << "\nDados de " << transportadora.nomeTransportadora << " inseridos na fila prioritaria." << endl << endl;
                } else if(transportadora.tipo == 'E') {
                    if(enfileiraFTransportadora(&fRetiraNaoPrioritaria, transportadora))
                        cout << "\nDados de " << transportadora.nomeTransportadora << " inseridos na fila nao prioritaria." << endl << endl;
                }

                break;

            case 'c':
                system("cls");

                cout << "********** Atendimento a pessoa **********" << endl;
                if(!vaziaFPessoa(&fDoaPrioritaria)) {
                    cout << "Pessoa sendo atendida: ";
                    primeiraPessoaF(&fDoaPrioritaria);

                    cout << "Objeto doado (l = ivro/e = equipamento): ";
                    cin >> objeto.tipo;
                    fflush(stdin);

                    objeto.tipo = toupper(objeto.tipo);

                    cout << "Descricao: ";
                    getline(cin, objeto.descricao);
                    fflush(stdin);

                    desenfileiraFPessoa(&fDoaPrioritaria, &pessoa);

                    ofstream escreve("doacao.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\nAdicionada a ficha." << endl;
                        escreve << "\n# " << pessoa.nomePessoa << " # " << pessoa.sexo << " # " << pessoa.cpf <<  " # " << pessoa.idade << " # " << pessoa.pcd << " # " << pessoa.gestante << " # " << objeto.tipo << " # " << objeto.descricao;

                        escreve.close();
                    } else
                        cout << "Erro ao abrir o arquivo." << endl;

                    //sso << pessoa.idade;
                    //sso >> teste;

                    if(objeto.tipo == 'L')
                        empilhar(&pLivro, pessoa, objeto);
                    else if(objeto.tipo == 'E')
                        empilhar(&pEquipamento, pessoa, objeto);

                    cout << "\nA pessoa " << pessoa.nomePessoa << " foi retirada da fila prioritaria." << endl << endl;
                } else if(!vaziaFPessoa(&fDoaNaoPrioritaria) && vaziaFPessoa(&fDoaPrioritaria)) {
                    cout << "Pessoa sendo atendida: ";
                    primeiraPessoaF(&fDoaNaoPrioritaria);

                    cout << "Objeto doado (l = ivro/e = equipamento): ";
                    cin >> objeto.tipo;
                    fflush(stdin);

                    objeto.tipo = toupper(objeto.tipo);

                    cout << "Descricao: ";
                    getline(cin, objeto.descricao);
                    fflush(stdin);

                    desenfileiraFPessoa(&fDoaNaoPrioritaria, &pessoa);

                    ofstream escreve("doacao.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\nAdicionada a ficha." << endl;
                        escreve << "\n# " << pessoa.nomePessoa << " # " << pessoa.sexo << " # " << pessoa.cpf <<  " # " << pessoa.idade << " # " << pessoa.pcd << " # " << pessoa.gestante << " # " << objeto.tipo << " # " << objeto.descricao;

                        escreve.close();
                    } else
                        cout << "Erro ao abrir o arquivo." << endl;

                    if(objeto.tipo == 'L')
                        empilhar(&pLivro, pessoa, objeto);
                    else if(objeto.tipo == 'E')
                        empilhar(&pEquipamento, pessoa, objeto);

                    cout << "\nA pessoa " << pessoa.nomePessoa << " foi retirada da fila nao prioritaria." << endl << endl;
                } else if(vaziaFPessoa(&fDoaPrioritaria) && vaziaFPessoa(&fDoaNaoPrioritaria))
                    cout << "\nAmbas as filas estao vazias." << endl << endl;

                break;

            case 'd':
                system("cls");

                cout << "********** Atendimento a transportadora **********" << endl;
                if(!vaziaFTransportadora(&fRetiraPrioritaria)) {
                    desenfileiraFTransportadora(&fRetiraPrioritaria, &transportadora);
                    cout << "A transportadora " << transportadora.nomeTransportadora << " foi retirada da fila prioritaria." << endl << endl;
                } else if(!vaziaFTransportadora(&fRetiraNaoPrioritaria) && vaziaFTransportadora(&fRetiraPrioritaria)) {
                    desenfileiraFTransportadora(&fRetiraNaoPrioritaria, &transportadora);
                    cout << "A transportadora " << transportadora.nomeTransportadora << " foi retirada da fila nao prioritaria." << endl << endl;
                } else
                    cout << "Ambas as filas estao vazias." << endl << endl;

                break;

            case 'z':
                system("cls");

                cout << "Fila de PESSOA PRIORITARIA: ";
                mostraFPessoa(&fDoaPrioritaria);

                cout << "Fila de PESSOA NAO PRIORITARIA: ";
                mostraFPessoa(&fDoaNaoPrioritaria);

                cout << "Fila de TRANSPORTADORA PRIORITARIA: ";
                mostraFTransportadora(&fRetiraPrioritaria);

                cout << "Fila de TRANSPORTADORA NAO PRIORITARIA: ";
                mostraFTransportadora(&fRetiraNaoPrioritaria);

                cout << "Pilha de doacao de LIVROS: ";
                mostrar(&pLivro);

                cout << "Pilha de doacao de EQUIPAMENTOS: ";
                mostrar(&pEquipamento);

                break;

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
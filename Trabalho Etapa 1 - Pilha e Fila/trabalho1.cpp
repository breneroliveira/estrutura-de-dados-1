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

    ofstream escreveDoa("doacao.txt", ios::out);
    ofstream escreveRetira("retiradas.txt", ios::out);

    int qtdObjetosRetirados = 0;

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

                cout << "Sexo (m = masculino/f = feminino): ";
                cin >> pessoa.sexo;
                fflush(stdin);

                pessoa.sexo = toupper(pessoa.sexo);

                while(pessoa.sexo != 'M' && pessoa.sexo !='F') {
                    cout << "Insira o sexo novamente (m = masculino/f = feminino): ";
                    cin >> pessoa.sexo;
                    fflush(stdin);

                    pessoa.sexo = toupper(pessoa.sexo);
                }

                cout << "CPF (complete apenas com números): ";
                getline(cin, pessoa.cpf);
                fflush(stdin);

                while(pessoa.cpf.size() != 11) {
                    cout << "Insira o CPF novamente (o CPF contem 11 digitos): ";
                    getline(cin, pessoa.cpf);
                    fflush(stdin);
                }

                cout << "Idade: ";
                cin >> pessoa.idade;
                fflush(stdin);

                while(pessoa.idade < 1) {
                    cout << "Insira a Idade novamente (a idade precisa ser maior que 1): ";
                    cin >> pessoa.idade;
                    fflush(stdin);
                }
                
                cout << "Pessoa com deficiencia (1 = sim/0 = nao): ";
                cin >> pessoa.pcd;
                fflush(stdin);

                while(pessoa.pcd != 1 && pessoa.pcd != 0) {
                    cout << "Informe se é PcD novamente (1 = sim/0 = nao): ";
                    cin >> pessoa.pcd;
                    fflush(stdin);
                }
                
                cout << "Gestante (1 = sim/0 = nao): ";
                cin >> pessoa.gestante;
                fflush(stdin);

                while(pessoa.gestante != 1 && pessoa.gestante != 0) {
                    cout << "Informe se é gestante novamente (1 = sim/0 = nao): ";
                    cin >> pessoa.gestante;
                    fflush(stdin);
                }

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

                cout << "CNPJ (complete apenas com numeros): ";
                getline(cin, transportadora.cnpj);
                fflush(stdin);

                while(transportadora.cnpj.size() != 12) {
                    cout << "Insira o CNPJ novamente (o CNPJ contem 12 digitos): ";
                    getline(cin, transportadora.cnpj);
                    fflush(stdin);
                }

                cout << "Tipo de objeto transportado (l = Livro/e = Equipamento): ";
                cin >> transportadora.tipo;
                fflush(stdin);

                transportadora.tipo = toupper(transportadora.tipo);

                while(transportadora.tipo != 'L' && transportadora.tipo != 'E') {
                    cout << "Insira o tipo de objeto transportado novamente (l = Livro/e = Equipamento): ";
                    cin >> transportadora.tipo;
                    fflush(stdin);

                    transportadora.tipo = toupper(transportadora.tipo);
                }

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

                    cout << "Objeto doado (l = Livro/e = Equipamento): ";
                    cin >> objeto.tipo;
                    fflush(stdin);

                    objeto.tipo = toupper(objeto.tipo);

                    while(objeto.tipo != 'L' && objeto.tipo != 'E') {
                        cout << "Insira o objeto doado novamente (l = Livro/e = Equipamento): ";
                        cin >> objeto.tipo;
                        fflush(stdin);

                        objeto.tipo = toupper(objeto.tipo);
                    }

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

                    cout << "Objeto doado (l = Livro/e = Equipamento): ";
                    cin >> objeto.tipo;
                    fflush(stdin);

                    objeto.tipo = toupper(objeto.tipo);

                    while(objeto.tipo != 'L' && objeto.tipo != 'E') {
                        cout << "Insira o objeto doado novamente (l = Livro/e = Equipamento): ";
                        cin >> objeto.tipo;
                        fflush(stdin);

                        objeto.tipo = toupper(objeto.tipo);
                    }

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
                    cout << "Transportadora sendo atendida: ";
                    primeiraTransportadoraF(&fRetiraPrioritaria);

                    cout << "Quantidade de objetos que serão retirados: ";
                    cin >> qtdObjetosRetirados;

                    cout << "Tipo de carga (l = Livro/e = Equipamento): ";
                    cin >> objeto.tipo;

                    objeto.tipo = toupper(objeto.tipo);

                    while(objeto.tipo != 'L' && objeto.tipo != 'E') {
                        cout << "Insira o tipo de carga novamente (l = Livro/e = Equipamento): ";
                        cin >> objeto.tipo;
                        fflush(stdin);

                        objeto.tipo = toupper(objeto.tipo);
                    }

                    desenfileiraFTransportadora(&fRetiraPrioritaria, &transportadora);

                    ofstream escreve("retiradas.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\nAdicionada a ficha." << endl;
                        escreve << "\n# " << transportadora.nomeTransportadora << " # " << transportadora.cnpj << " # " << transportadora.tipo <<  " # " << objeto.tipo << " # " << objeto.descricao;

                        escreve.close();
                    } else
                        cout << "Erro ao abrir o arquivo." << endl;

                    if(objeto.tipo == 'L')
                        desempilhar(&pLivro, &pessoa, &objeto);
                    else if(objeto.tipo == 'E')
                        desempilhar(&pEquipamento, &pessoa, &objeto);

                    cout << "\nA transportadora " << transportadora.nomeTransportadora << " foi retirada da fila prioritaria." << endl << endl;
                } else if(!vaziaFTransportadora(&fRetiraNaoPrioritaria) && vaziaFTransportadora(&fRetiraPrioritaria)) {
                    cout << "Transportadora sendo atendida: ";
                    primeiraTransportadoraF(&fRetiraPrioritaria);

                    cout << "Quantidade de objetos que serão retirados: ";
                    cin >> qtdObjetosRetirados;

                    cout << "Tipo de carga (l = Livro/e = Equipamento): ";
                    cin >> objeto.tipo;

                    objeto.tipo = toupper(objeto.tipo);

                    while(objeto.tipo != 'L' && objeto.tipo != 'E') {
                        cout << "Insira o tipo de carga novamente (l = Livro/e = Equipamento): ";
                        cin >> objeto.tipo;
                        fflush(stdin);

                        objeto.tipo = toupper(objeto.tipo);
                    }

                    desenfileiraFTransportadora(&fRetiraPrioritaria, &transportadora);

                    ofstream escreve("retiradas.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\nAdicionada a ficha." << endl;
                        escreve << "\n# " << transportadora.nomeTransportadora << " # " << transportadora.cnpj << " # " << transportadora.tipo <<  " # " << objeto.tipo << " # " << objeto.descricao;

                        escreve.close();
                    } else
                        cout << "Erro ao abrir o arquivo." << endl;

                    if(objeto.tipo == 'L')
                        desempilhar(&pLivro, &pessoa, &objeto);
                    else if(objeto.tipo == 'E')
                        desempilhar(&pEquipamento, &pessoa, &objeto);

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
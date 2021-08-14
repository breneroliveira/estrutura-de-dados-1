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

    ofstream escreveDoa("doacao.txt", ios::out);
    ofstream escreveRetira("retiradas.txt", ios::out);

    Pilha pLivro, pEquipamento, pApenasCPF;
    FilaPessoa fDoaPrioritaria, fDoaNaoPrioritaria;
    FilaTransportadora fRetiraPrioritaria, fRetiraNaoPrioritaria;

    DadosObjeto objeto;
    DadosPessoa pessoa;
    DadosTransportadora transportadora;

    char auxPcd, auxGestante;
    char elementoArquivo;

    int qtdObjetosRetirados = 0, contRetirada = 0, auxQtdElementos = 0;
    int totalPessoas = 0, sexoFeminino = 0, sexoMasculino = 0, pessoaPcd = 0, mulherGravida = 0;
    int totalEmpresas = 0, entregaLivro = 0, entregaEquipamento = 0;

    int contPrioridade = 0, totalDoadores = 0;

    float somaIdade = 0;
    float idadeMedia = 0;

    string procuraCPF;

    ifstream leitura;

    char menu;

    do {
        cout << "**************************************************** MENU ****************************************************" << endl;
        cout << "*                                                                                                            *" << endl;
        cout << "* a) Incluir pessoa na fila de doacao;                                                                       *" << endl;
        cout << "* b) Incluir empresa na fila de retirada;                                                                    *" << endl;
        cout << "* c) Atender uma pessoa da fila;                                                                             *" << endl;
        cout << "* d) Atender uma empresa da fila;                                                                            *" << endl;
        cout << "* e) Listar todas as pessoas das filas;                                                                      *" << endl;
        cout << "* f) Listar todas as empresas das filas;                                                                     *" << endl;
        cout << "* g) Listar informacoes sobre as filas de pessoas de forma unificada;                                        *" << endl;
        cout << "* h) Listar informacoes sobre as filas de empresas de forma unificada;                                       *" << endl;
        cout << "* i) Listar o estoque de equipamentos na ordem em que eles foram doados;                                     *" << endl;
        cout << "* j) Listar o estoque de livros na ordem em que eles foram doados;                                           *" << endl;
        cout << "* k) Listar as doacoes recebidas pela ONG, o numero de doadores prioritarios e a idade media dos doadores;   *" << endl;
        cout << "* l) Verificar o numero de doacoes realizadas por um determinado CPF;                                        *" << endl;
        cout << "* m) Listar todas as retiradas realizadas;                                                                   *" << endl;
        cout << "* n) Encerrar programa.                                                                                      *" << endl;
        cout << "* z) Mostra tudo.                                                                                            *" << endl;
        cout << "*                                                                                                            *" << endl;
        cout << "**************************************************************************************************************" << endl << endl;

        cout << "Escolha uma opcao: ";
        cin >> menu;
        fflush(stdin);

        menu = tolower(menu);

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

                cout << "CPF (complete apenas com numeros): ";
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
                cin >> auxPcd;
                fflush(stdin);

                while(auxPcd != '1' && auxPcd != '0') {
                    cout << "Informe se e PcD novamente (1 = sim/0 = nao): ";
                    cin >> auxPcd;
                    fflush(stdin);
                }

                if(auxPcd == '1')
                    pessoa.pcd = true;
                else if(auxPcd == '0')
                    pessoa.pcd = false;
                
                cout << "Gestante (1 = sim/0 = nao): ";
                cin >> auxGestante;
                fflush(stdin);

                while(auxGestante != '1' && auxGestante != '0') {
                    cout << "Informe se e gestante novamente (1 = sim/0 = nao): ";
                    cin >> auxGestante;
                    fflush(stdin);
                }

                if(pessoa.sexo == 'M') {
                    sexoMasculino++;
                    pessoa.gestante = false;
                } else {
                    sexoFeminino++;
                    if(auxGestante == '1')
                        pessoa.gestante = true;
                    else if(auxGestante == '0')
                        pessoa.gestante = false;
                }

                if(pessoa.sexo == 'M' && auxGestante == '1')
                    cout << "\nApenas pessoas do sexo feminino podem constar como gestantes no sistema." << endl;

                if(pessoa.gestante == true || pessoa.pcd == true || pessoa.idade > 65) {
                    if(enfileiraFPessoa(&fDoaPrioritaria, pessoa)) {
                        cout << "\nPessoa de nome " << pessoa.nomePessoa << " inserida na fila de doacao prioritaria." << endl << endl;
                        totalPessoas++;

                        if(pessoa.pcd == true)
                            pessoaPcd++;

                        if(pessoa.gestante == true)
                            mulherGravida++;
                    }
                } else {
                    if(enfileiraFPessoa(&fDoaNaoPrioritaria, pessoa)) {
                        cout << "\nPessoa de nome " << pessoa.nomePessoa << " inserida na fila de doacao nao prioritaria." << endl << endl;
                        totalPessoas++;
                    }
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
                    if(enfileiraFTransportadora(&fRetiraPrioritaria, transportadora)) {
                        cout << "\nTransportadora de nome " << transportadora.nomeTransportadora << " inserida na fila de retirada prioritaria." << endl << endl;
                        totalEmpresas++;
                        entregaLivro++;
                    }
                } else if(transportadora.tipo == 'E') {
                    if(enfileiraFTransportadora(&fRetiraNaoPrioritaria, transportadora)) {
                        cout << "\nTransportadora de nome " << transportadora.nomeTransportadora << " inserida na fila de retirada nao prioritaria." << endl << endl;
                        totalEmpresas++;
                        entregaEquipamento++;
                    }
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

                    while(objeto.descricao.empty()) {
                        cout << "E necessario inserir uma descricao: ";
                        getline(cin, objeto.descricao);
                        fflush(stdin);
                    }

                    desenfileiraFPessoa(&fDoaPrioritaria, &pessoa);
                    pilhaCPF(&pApenasCPF, pessoa);

                    contPrioridade++;

                    totalDoadores++;

                    somaIdade = somaIdade + pessoa.idade;

                    totalPessoas--;

                    if(pessoa.sexo == 'F')
                        sexoFeminino--;
                    else
                        sexoMasculino--;

                    if(pessoa.pcd == true)
                        pessoaPcd--;

                    if(pessoa.gestante == true)
                        mulherGravida--;

                    ofstream escreve("doacao.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\n" << objeto.descricao << " adicionado a ficha de doacao." << endl;
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

                    cout << "\nA pessoa de nome " << pessoa.nomePessoa << " foi atendida (retirada da fila prioritaria)." << endl << endl;
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

                    while(objeto.descricao.empty()) {
                        cout << "E necessario inserir uma descricao: ";
                        getline(cin, objeto.descricao);
                        fflush(stdin);
                    }

                    desenfileiraFPessoa(&fDoaNaoPrioritaria, &pessoa);
                    pilhaCPF(&pApenasCPF, pessoa);

                    totalDoadores++;

                    somaIdade = somaIdade + pessoa.idade;

                    totalPessoas--;

                    if(pessoa.sexo == 'F')
                        sexoFeminino--;
                    else
                        sexoMasculino--;

                    ofstream escreve("doacao.txt", ios::app);

                    if(escreve.is_open()) {
                        cout << "\n" << objeto.descricao << " adicionado a ficha de doacao." << endl;
                        escreve << "\n# " << pessoa.nomePessoa << " # " << pessoa.sexo << " # " << pessoa.cpf <<  " # " << pessoa.idade << " # " << pessoa.pcd << " # " << pessoa.gestante << " # " << objeto.tipo << " # " << objeto.descricao;

                        escreve.close();
                    } else
                        cout << "Erro ao abrir o arquivo." << endl;

                    if(objeto.tipo == 'L')
                        empilhar(&pLivro, pessoa, objeto);
                    else if(objeto.tipo == 'E')
                        empilhar(&pEquipamento, pessoa, objeto);

                    cout << "\nA pessoa de nome " << pessoa.nomePessoa << " foi atendida (retirada da fila nao prioritaria)." << endl << endl;
                } else if(vaziaFPessoa(&fDoaPrioritaria) && vaziaFPessoa(&fDoaNaoPrioritaria))
                    cout << "\nAmbas as filas estao vazias." << endl << endl;

                break;

            case 'd':
                system("cls");

                cout << "********** Atendimento a transportadora **********" << endl;
                if(!vaziaFTransportadora(&fRetiraPrioritaria)) {
                    cout << "Transportadora sendo atendida: ";
                    primeiraTransportadoraF(&fRetiraPrioritaria);

                    if(vaziaP(&pLivro)) {
                        cout << "\nNao ha livros para serem retirados." << endl;
                        desenfileiraFTransportadora(&fRetiraPrioritaria, &transportadora);
                        cout << "\nA transportadora de nome " << transportadora.nomeTransportadora << " foi despachada (retirada da fila prioritaria)." << endl << endl;
                        totalEmpresas--;
                        entregaLivro--;
                        break;
                    }

                    cout << "Quantidade de objetos que serao retirados: ";
                    cin >> qtdObjetosRetirados;

                    while(qtdObjetosRetirados > tamanhoPilha(&pLivro) || qtdObjetosRetirados == 0) {
                        cout << "Insira uma quantia valida (ha " << tamanhoPilha(&pLivro) << " objetos na pilha dos livros): ";
                        cin >> qtdObjetosRetirados;
                    }

                    contRetirada = 0;

                    desenfileiraFTransportadora(&fRetiraPrioritaria, &transportadora);
                    totalEmpresas--;
                    entregaLivro--;

                    while(contRetirada < qtdObjetosRetirados) {
                        desempilhar(&pLivro, &pessoa, &objeto);

                        ofstream escreve("retiradas.txt", ios::app);

                        if(escreve.is_open()) {
                            cout << "\n" << objeto.descricao << " adicionado a ficha de retirada." << endl;
                            escreve << "\n# " << transportadora.nomeTransportadora << " # " << transportadora.cnpj << " # " << transportadora.tipo <<  " # " << objeto.tipo << " # " << objeto.descricao;

                            escreve.close();
                        } else
                            cout << "Erro ao abrir o arquivo." << endl;
                        contRetirada++;
                    }
                    cout << "\nA transportadora de nome " << transportadora.nomeTransportadora << " foi despachada (retirada da fila prioritaria)." << endl << endl;
                } else if(!vaziaFTransportadora(&fRetiraNaoPrioritaria) && vaziaFTransportadora(&fRetiraPrioritaria)) {
                    cout << "Transportadora sendo atendida: ";
                    primeiraTransportadoraF(&fRetiraNaoPrioritaria);

                    if(vaziaP(&pEquipamento)) {
                        cout << "\nNao ha equipamentos para serem retirados." << endl;
                        desenfileiraFTransportadora(&fRetiraNaoPrioritaria, &transportadora);
                        cout << "\nA transportadora de nome " << transportadora.nomeTransportadora << " foi despachada (retirada da fila nao prioritaria)." << endl << endl;
                        totalEmpresas--;
                        entregaEquipamento--;
                        break;
                    }

                    cout << "Quantidade de objetos que serao retirados: ";
                    cin >> qtdObjetosRetirados;

                    while(qtdObjetosRetirados > tamanhoPilha(&pEquipamento) || qtdObjetosRetirados == 0) {
                        cout << "Insira uma quantia valida (ha " << tamanhoPilha(&pEquipamento) << " objetos na pilha dos equipamentos): ";
                        cin >> qtdObjetosRetirados;
                    }

                    contRetirada = 0;

                    desenfileiraFTransportadora(&fRetiraNaoPrioritaria, &transportadora);
                    totalEmpresas--;
                    entregaEquipamento--;

                    while(contRetirada < qtdObjetosRetirados) {
                        desempilhar(&pEquipamento, &pessoa, &objeto);

                        ofstream escreve("retiradas.txt", ios::app);

                        if(escreve.is_open()) {
                            cout << "\n" << objeto.descricao << " adicionado a ficha de retirada." << endl;
                            escreve << "\n# " << transportadora.nomeTransportadora << " # " << transportadora.cnpj << " # " << transportadora.tipo <<  " # " << objeto.tipo << " # " << objeto.descricao;

                            escreve.close();
                        } else
                            cout << "Erro ao abrir o arquivo." << endl;
                        contRetirada++;
                    }
                    cout << "\nA transportadora de nome " << transportadora.nomeTransportadora << " foi despachada (retirada da fila nao prioritaria)." << endl << endl;
                } else
                    cout << "\nAmbas as filas estao vazias." << endl << endl;

                break;

            case 'e':
                system("cls");

                cout << "Fila de pessoas prioritarias: ";
                mostraFPessoa(&fDoaPrioritaria);

                cout << "Fila de pessoas nao prioritarias: ";
                mostraFPessoa(&fDoaNaoPrioritaria);
                
                break;

            case 'f':
                system("cls");

                cout << "Fila de transportadoras prioritarias: ";
                mostraFTransportadora(&fRetiraPrioritaria);

                cout << "Fila de transportadoras nao prioritarias: ";
                mostraFTransportadora(&fRetiraNaoPrioritaria);
                
                break;

            case 'g':
                system("cls");

                cout << "********** Contagem das pessoas de forma unificada **********" << endl;
                cout << "Total de pessoas: " << totalPessoas << endl;
                cout << "Pessoas do sexo feminino: " << sexoFeminino << endl;
                cout << "Pessoas do sexo masculino: " << sexoMasculino << endl;
                cout << "Pessoas com deficiencia: " << pessoaPcd << endl;
                cout << "Mulheres gravidas: " << mulherGravida << endl << endl;
                
                break;

            case 'h':
                system("cls");

                cout << "********** Contagem das empresas de forma unificada **********" << endl;
                cout << "Total de empresas: " << totalEmpresas << endl;
                cout << "Empresas especializadas na entrega de livros: " << entregaLivro << endl;
                cout << "Empresas especializadas na entrega de equipamentos: " << entregaEquipamento << endl << endl;
                
                break;

            case 'i':
                system("cls");

                mostraPEquipamentos(&pEquipamento);
                
                break;

            case 'j':
                system("cls");

                mostraPLivro(&pLivro);
                
                break;

            case 'k':
                system("cls");

                leitura.open("doacao.txt", ios::in);

                if(leitura.is_open()) {
                    cout << "Arquivo aberto." << endl;

                    while(leitura.get(elementoArquivo))
                        cout << elementoArquivo;
                } else
                    cout << "Erro ao abrir o arquivo." << endl;

                leitura.close();

                cout << "\n\nPessoas prioritarias que realizaram doacoes: " << contPrioridade << endl;
                idadeMedia = somaIdade / totalDoadores;

                if(somaIdade == 0 && totalDoadores == 0)
                    idadeMedia = 0;

                cout << "Idade media dos doadores: " << idadeMedia << endl << endl;
                
                break;

            case 'l':
                system("cls");

                cout << "********** Buscar CPF **********" << endl;
                cout << "Insira o CPF desejado: ";
                getline(cin, procuraCPF);
                fflush(stdin);

                while(procuraCPF.size() != 11) {
                    cout << "Insira o CPF novamente (o CPF contem 11 digitos): ";
                    getline(cin, procuraCPF);
                    fflush(stdin);
                }

                cout << "\nQuantidade de doacoes realizadas: " << busca(&pApenasCPF, pessoa, procuraCPF) << endl << endl;
                
                break;

            case 'm':
                system("cls");

                leitura.open("retiradas.txt", ios::in);

                if(leitura.is_open()) {
                    cout << "Arquivo aberto." << endl;

                    while(leitura.get(elementoArquivo))
                        cout << elementoArquivo;
                } else
                    cout << "Erro ao abrir o arquivo." << endl;

                leitura.close();

                cout << endl << endl;
                
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
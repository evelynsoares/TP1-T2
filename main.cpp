#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <stdexcept>
#include <vector>
#include "dominios.hpp"
#include "entidades.hpp"
#include "controladora.hpp"

using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Criar Viagem\n";
    cout << "2. Ler Viagem\n";
    cout << "3. Atualizar Viagem\n";
    cout << "4. Excluir Viagem\n";
    cout << "5. Listar Viagens\n\n";
    cout << "6. Criar Destino\n";
    cout << "7. Ler Destino\n";
    cout << "8. Atualizar Destino\n";
    cout << "9. Excluir Destino\n";
    cout << "10. Listar Destinos\n\n";
    /*cout << "11. Criar Hospedagem\n";
    cout << "12. Ler Hospedagem\n";
    cout << "13. Atualizar Hospedagem\n";
    cout << "14. Excluir Hospedagem\n";
    cout << "15. Listar Hospedagens\n\n";
    cout << "16. Criar Atividade\n";
    cout << "17. Ler Atividade\n";
    cout << "18. Atualizar Atividade\n";
    cout << "19. Excluir Atividade\n";
    cout << "20. Listar Atividades\n\n";*/
    cout << "0. Sair\n";
    cout << "==========================\n";
    cout << "Escolha uma opcao: ";
}

string gerarCodigoAleatorio() {
    const string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    const int tamanhoCodigo = 6;
    string codigo;

    srand(time(0));

    for (int i = 0; i < tamanhoCodigo; ++i) {
        int indice = rand() % valid.size(); 
        codigo += valid[indice]; 
    }

    return codigo;
}

int main() {
    // Inicializa a interface da conta
    LNControladoraConta servicoConta;
    CntrIUControladoraConta controladoraConta(&servicoConta);

    string codigoContaStr, senhaContaStr;
    codigoContaStr = gerarCodigoAleatorio();
    Codigo codigoConta(codigoContaStr);

    cout << "Ola! Esse sistema facilita um planejamento de viagens! Para comecar..." << endl;

    // Loop ate que a senha seja valida, garantindo autenticacao
    while (true) { 
        cout << "Digite a senha da conta, a senha deve ter 5 numeros: ";
        cin >> senhaContaStr;

        try {
            Senha senhaConta(stoi(senhaContaStr));
            if (senhaConta.senhaValida()) {
                Conta novaConta(codigoConta, senhaConta); 
                controladoraConta.criarConta(novaConta);
                cout << "Codigo da conta: " << novaConta.getCodigo().getCodigo() << endl;
                cout << "Usuario autenticado!" << endl;
                break; 
            }
        } catch (const invalid_argument& e) {
            cerr << "Erro: Senha invalida. Digite apenas numeros inteiros." << endl;
        } catch (const out_of_range& e) {
            cerr << "Erro: Senha muito longa. Digite um numero de 5 caracteres." << endl;
        }
    }

    // Inicializa a interface de viagem, destino, hospedagem e atividades
    LNCntrViagem servicoViagem; 
    CntrIUViagem controladoraViagem(&servicoViagem);
    LNCntrDestino servicoDestino;
    CntrIUDestino controladoraDestino(&servicoDestino);

    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        switch (opcao) {
            case 1: { // Criar Viagem
                string nomeViagemStr;
                int avaliacaoViagemNota;
                cout << "Digite o nome da viagem: ";
                cin.ignore();
                getline(cin, nomeViagemStr);
                cout << "Digite a avaliacao da viagem (0-5): ";
                cin >> avaliacaoViagemNota;
                
                string tmp;
                cout << "Digite o destino da viagem (caso não exista, aperte enter e crie um. Esta operação fecha a criação de viagem): ";
                cin >> tmp;
                if(tmp == ""){
                    break;
                }
                Codigo destinoViagem(tmp);

                string codigoViagemStr = gerarCodigoAleatorio();

                Codigo codigoViagem(codigoViagemStr);
                Nome nomeViagem(nomeViagemStr);
                Avaliacao avaliacaoViagem(avaliacaoViagemNota);
                Codigo codigoConta(codigoContaStr); // Codigo da conta atual

                // Cria a viagem
                Viagem viagem(codigoViagem, nomeViagem, avaliacaoViagem, codigoConta);
                controladoraViagem.criarViagem(viagem);
                break;
            }
            case 2: { // Ler Viagem
                string codigoViagemLidaStr;
                cout << "Digite o codigo da viagem que deseja ler: ";
                cin >> codigoViagemLidaStr;
                try {
                    Viagem viagemLida = controladoraViagem.lerViagem(Codigo(codigoViagemLidaStr));
                    cout << "Viagem lida: " << viagemLida.getNome().getNome()
                        << " - Avaliacao: " << viagemLida.getAvaliacao().getNota() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: { // Atualizar Viagem
                string codigoViagemAtualizarStr;
                cout << "Digite o codigo da viagem que deseja atualizar: ";
                cin >> codigoViagemAtualizarStr;

                string novoNomeViagemStr;
                double novaAvaliacaoViagemNota;
                cout << "Digite o novo nome da viagem: ";
                cin.ignore();
                getline(cin, novoNomeViagemStr);
                cout << "Digite a nova avaliacao da viagem (0-5): ";
                cin >> novaAvaliacaoViagemNota;

                string tmp;

                cout << "Digite o novo código de destino (deixar esse parametro em branco fechara o prompt): ";
                cin >> tmp;
                if(tmp == ""){
                    break;
                }
                Codigo novoDestino(tmp);

                Codigo codigoViagemAtualizar(codigoViagemAtualizarStr);
                Nome novoNomeViagem(novoNomeViagemStr);
                Avaliacao novaAvaliacaoViagem(novaAvaliacaoViagemNota);
                Codigo codigoConta(codigoContaStr); 

                Viagem viagemAtualizada(codigoViagemAtualizar, novoNomeViagem, novaAvaliacaoViagem, codigoConta);
                controladoraViagem.atualizarViagem(viagemAtualizada);
                break;
            }
            case 4: { // Excluir Viagem
                string codigoViagemExcluirStr;
                cout << "Digite o codigo da viagem que deseja excluir: ";
                cin >> codigoViagemExcluirStr;
                if (controladoraViagem.excluirViagem(Codigo(codigoViagemExcluirStr))) {
                    cout << "Viagem excluida com sucesso!\n";
                } else {
                    cout << "Falha ao excluir viagem!\n";
                }
                break;
            }
            case 5: { // Listar Viagens
                vector<Viagem> viagens = controladoraViagem.listarViagens();

                cout << "\nListando todas as viagens:\n";
                if (viagens.empty()) {
                    cout << "Nenhuma viagem cadastrada.\n";
                } else {
                    for (const auto& viagem : viagens) {
                        cout << "Viagem: " << viagem.getNome().getNome() << ", Avaliacao: " << viagem.getAvaliacao().getNota() << ", Codigo: " << viagem.getCodigo().getCodigo() << endl;
                    }
                }
                break;
            }
            case 6: { // Criar Destino
                string codigoViagemAssDestinoStr;
                cout << "Digite o codigo da viagem associada ao destino que deseja criar: " << endl;
                cin >> codigoViagemAssDestinoStr;

                // Verifica se a viagem existe
                try {
                    Codigo codigoViagemAssDestino(codigoViagemAssDestinoStr);

                    Viagem viagemAssociada = controladoraViagem.lerViagem(Codigo(codigoViagemAssDestino));
                    cout << "Viagem encontrada: " << viagemAssociada.getNome().getNome() << endl;

                    string nomeDestinoStr;
                    cout << "Digite o nome do destino: ";
                    cin.ignore(); 
                    getline(cin, nomeDestinoStr);

                    string codigoDestinoStr = gerarCodigoAleatorio();
                    Codigo codigoDestino(codigoDestinoStr);
                    Nome nomeDestino(nomeDestinoStr);

                    int diaInicio, mesInicio, anoInicio;
                    cout << "Digite a data de inicio (DD MM AA): ";
                    cin >> diaInicio >> mesInicio >> anoInicio;

                    Data dataInicio(diaInicio, mesInicio, anoInicio); 

                    int diaTermino, mesTermino, anoTermino;
                    cout << "Digite a data de termino (DD MM AA): ";
                    cin >> diaTermino >> mesTermino >> anoTermino;

                    Data dataTermino(diaTermino, mesTermino, anoTermino);

                    int avaliacaoDestinoNota;
                    cout << "Digite a avaliacao do destino (0-5): ";
                    cin >> avaliacaoDestinoNota;

                    Avaliacao avaliacaoDestino(avaliacaoDestinoNota);

                    Destino destino(&codigoDestino, &nomeDestino, &dataInicio, &dataTermino, &avaliacaoDestino, &codigoViagemAssDestino);
                    controladoraDestino.criarDestino(destino);
                    } catch (const runtime_error& e) {
                    cout << "Erro, nao foi possivel adicionar um destino: " << e.what() << endl;
                }
                break;
            }
            case 7: { // Ler Destino
                string codigoDestinoStr;
                cout << "Digite o codigo do destino que deseja ler: ";
                cin >> codigoDestinoStr;
                try {
                    Destino destinoLido = controladoraDestino.lerDestino(Codigo(codigoDestinoStr));
                    cout << "Codigo: " << destinoLido.getCodigo().getCodigo()
                              << ", Nome: " << destinoLido.getNome().getNome()
                              << ", Data de Inicio: " << destinoLido.getDataDeInicio().getData()
                              << ", Data de Termino: " << destinoLido.getDataDeTermino().getData()
                              << ", Avaliacao: " << destinoLido.getAvaliacao().getNota() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 8: { // Atualizar Destino
                string codigoDestinoStr;
                cout << "Digite o codigo do destino que deseja atualizar: ";
                cin >> codigoDestinoStr;

                try {
                    Destino destinoParaAtualizar = controladoraDestino.lerDestino(Codigo(codigoDestinoStr));

                    string novoNomeDestinoStr;
                    cout << "Digite o novo nome do destino: ";
                    cin.ignore();
                    getline(cin, novoNomeDestinoStr);

                    int novoDiaInicio, novoMesInicio, novoAnoInicio;
                    cout << "Digite a nova data de inicio (DD MM AA): ";
                    cin >> novoDiaInicio >> novoMesInicio >> novoAnoInicio;
                    Data novaDataInicio(novoDiaInicio, novoMesInicio, novoAnoInicio);
                    
                    int novoDiaTermino, novoMesTermino, novoAnoTermino;
                    cout << "Digite a nova data de termino (DD MM AA): ";
                    cin >> novoDiaTermino >> novoMesTermino >> novoAnoTermino;
                    Data novaDataTermino(novoDiaTermino, novoMesTermino, novoAnoTermino);
                    
                    int novaAvaliacaoDestinoNota;
                    cout << "Digite a nova avaliacao do destino (0-5): ";
                    cin >> novaAvaliacaoDestinoNota;
                    
                    controladoraDestino.atualizarDestino(destinoParaAtualizar);
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 9: { // Excluir Destino
                string codigoDestinoStr;
                cout << "Digite o codigo do destino que deseja excluir: ";
                cin >> codigoDestinoStr;
                if (controladoraDestino.excluirDestino(Codigo(codigoDestinoStr))) {
                    cout << "Destino excluido com sucesso!\n";
                } else {
                    cout << "Falha ao excluir destino!\n";
                }
                break;
            }
            case 10: { // Listar Destinos 
                vector<Destino> destinos = controladoraDestino.listarDestinos();

                cout << "\nListando todos os destinos:\n";
                if (destinos.empty()) {
                    cout << "Nenhum destino cadastrado.\n";
                } else {
                    for (const auto& destino : destinos) {
                        cout << "Codigo: " << destino.getCodigo().getCodigo()
                                  << ", Nome: " << destino.getNome().getNome()
                                  << ", Data de Inicio: " << destino.getDataDeInicio().getData()
                                  << ", Data de Termino: " << destino.getDataDeTermino().getData()
                                  << ", Avaliacao: " << destino.getAvaliacao().getNota() << endl;
                    }
                }
                break;
            }
            case 11: { // Adicionar Hospedagem
                // cout << "Funcionalidade de adicionar hospedagem ainda nao implementada.\n";
                string hosp;
                cout << "Digite o código do destino da hospedagem: ";
                cin >> hosp;

                break;
            }
            case 12: { // Ler Hospedagem
                cout << "Funcionalidade de ler hospedagem ainda nao implementada.\n";
                break;
            }
            case 13: { // Atualizar Hospedagem
                cout << "Funcionalidade de atualizar hospedagem ainda nao implementada.\n";
                break;
            }
            case 14: { // Excluir Hospedagem
                cout << "Funcionalidade de excluir hospedagem ainda nao implementada.\n";
                break;
            }
            case 15: { // Listar Hospedagem
                cout << "Funcionalidade de listar hospedagens ainda nao implementada.\n";
                break;
            }
            case 16: { // Adicionar Atividade
                cout << "Funcionalidade de adicionar atividade ainda nao implementada.\n";
                break;
            }
            case 17: { // Ler Atividade
                cout << "Funcionalidade de ler atividade ainda nao implementada.\n";
                break;
            }
            case 18: { // Atualizar Atividade
                cout << "Funcionalidade de atualizar atividade ainda nao implementada.\n";
                break;
            }
            case 19: { // Excluir Atividade
                cout << "Funcionalidade de excluir atividade ainda nao implementada.\n";
                break;
            }
            case 20: { // Listar Atividades
                cout << "Funcionalidade de listar atividades ainda nao implementada.\n";
                break;
            }
            case 0: { // Sair
                cout << "Saindo...\n";
                break;
            }
            default: {
                cout << "Opcao invalida! Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}

#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "dominios.hpp"
#include "testes.hpp"
#include "entidades.hpp"
#include "controladora.hpp"

using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Criar Viagem\n";
    cout << "2. Ler Viagem\n";
    cout << "3. Atualizar Viagem\n";
    cout << "4. Excluir Viagem\n";
    cout << "5. Listar Viagens\n";
    cout << "6. Adicionar Destino\n";
    cout << "7. Adicionar Hospedagem\n";
    cout << "8. Adicionar Atividade\n";
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
    //Inicializa a interface da conta
    LNControladoraConta servicoConta;
    CntrIUControladoraConta controladoraConta(&servicoConta);

    //Cria uma conta nova
    string codigoContaStr, senhaContaStr;
    codigoContaStr = gerarCodigoAleatorio();
    cout << "Digite a senha da conta: ";
    cin >> senhaContaStr;

    Codigo codigoConta(codigoContaStr);
    Senha senhaConta(stoi(senhaContaStr)); 
    Conta novaConta(&codigoConta, &senhaConta);

    controladoraConta.criarConta(novaConta);

    cout << "Codigo da conta: " << novaConta.getCodigo().getCodigo() << endl;
    cout << "Usuario autenticado!" << endl;

    //Apos autenticacao
    //Inicializa a interface de viagem, destino, hospedagem e atividades
    LNCntrViagem servicoViagem; 
    CntrIUViagem controladoraViagem(&servicoViagem);

    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: { // Criar Viagem
                string nomeViagemStr;
                double avaliacaoViagemNota;
                cout << "Digite o nome da viagem: ";
                cin.ignore();
                getline(cin, nomeViagemStr);
                cout << "Digite a avaliacao da viagem: ";
                cin >> avaliacaoViagemNota;

                string codigoViagemStr = gerarCodigoAleatorio();
                cout << "Codigo gerado para a viagem: " << codigoViagemStr << endl;

                Codigo codigoViagem(codigoViagemStr);
                Nome nomeViagem(nomeViagemStr);
                Avaliacao avaliacaoViagem(avaliacaoViagemNota);
                
                Viagem viagem(&codigoViagem, &nomeViagem, &avaliacaoViagem);
                controladoraViagem.criarViagem(viagem); 
                cout << "Viagem criada com sucesso!\n";
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
                cout << "Digite a nova avaliacao da viagem: ";
                cin >> novaAvaliacaoViagemNota;

                Codigo codigoViagemAtualizar(codigoViagemAtualizarStr);
                Nome novoNomeViagem(novoNomeViagemStr);
                Avaliacao novaAvaliacaoViagem(novaAvaliacaoViagemNota);
                Viagem viagemAtualizada(&codigoViagemAtualizar, &novoNomeViagem, &novaAvaliacaoViagem);
                controladoraViagem.atualizarViagem(viagemAtualizada);
                cout << "Viagem atualizada com sucesso!\n";
                break;
            }
            case 4: { // Excluir Viagem -> nao funciona direito
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
                cout << "\nListando todas as viagens:\n";
                vector<Viagem> viagens = controladoraViagem.listarViagens();
                for (const auto& v : viagens) {
                    cout << "Viagem: " << v.getNome().getNome() << ", Avaliacao: " << v.getAvaliacao().getNota() << ", Codigo: " << v.getCodigo().getCodigo() << endl;
                }
                break;
            }
            case 6: { // Adicionar Destino
                cout << "Funcionalidade de adicionar destino ainda nao implementada.\n";
                break;
            }
            case 7: { // Adicionar Hospedagem
                cout << "Funcionalidade de adicionar hospedagem ainda nao implementada.\n";
                break;
            }
            case 8: { // Adicionar Atividade
                cout << "Funcionalidade de adicionar atividade ainda nao implementada.\n";
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
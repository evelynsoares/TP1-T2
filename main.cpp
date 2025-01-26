#include <iostream>
#include "dominios.hpp"
#include "testes.hpp"
#include "entidades.hpp"
#include "controladora.hpp"

using namespace std;

int main() {
    
    LNControladoraConta servicoConta;
    CntrIUControladoraConta controladoraConta(&servicoConta);

    // nova conta
    Codigo codigoConta("CT3768");
    Senha senhaConta(67890);
    Conta novaConta(&codigoConta, &senhaConta);

    controladoraConta.criarConta(novaConta);

    LNCntrViagem servicoViagem; 
    CntrIUViagem controladoraViagem(&servicoViagem);


    Codigo codigoViagem("V123as");
    Nome nomeViagem("Viagem para Paris");
    Avaliacao avaliacaoViagem(4.5);
    
    Viagem viagem(&codigoViagem, &nomeViagem, &avaliacaoViagem);

    cout << "Digite o nome da viagem: " << endl;
    //cin >> nomeViagem->setNome();

    
    viagem.setNome(nomeViagem); 


    controladoraViagem.criarViagem(viagem);

    vector<Viagem> viagens = controladoraViagem.listarViagens();
    for (const auto& v : viagens) {
        cout << "Viagem: " << v.getNome().getNome() << ", Avaliacao: " << v.getAvaliacao().getNota() << endl;
    }

    try {
        Viagem viagemLida = controladoraViagem.lerViagem(Codigo("V123as"));
        cout << "Viagem lida: " << viagemLida.getNome().getNome()
            << " - Avaliacao: " << viagemLida.getAvaliacao().getNota() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    Nome novoNomeViagem("Viagem para Londres");
    Avaliacao novaAvaliacaoViagem(5.0);
    Viagem viagemAtualizada(&codigoViagem, &novoNomeViagem, &novaAvaliacaoViagem);
    controladoraViagem.atualizarViagem(viagemAtualizada);

    try {
        Viagem viagemAtualizadaLida = controladoraViagem.lerViagem(Codigo("V123as"));
        cout << "Viagem atualizada: " << viagemAtualizadaLida.getNome().getNome()
            << " - Avaliacao: " << viagemAtualizadaLida.getAvaliacao().getNota() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    if (controladoraViagem.excluirViagem(Codigo("V123as"))) {
        cout << "Viagem excluida com sucesso!" << endl;
    }

    return 0;
}

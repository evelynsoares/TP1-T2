#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED
#include "entidades.hpp"
#include "dominios.hpp"

#include <vector>
//#include <stack>

using namespace std;

//Conta
static vector<Conta> bancoDeContas;

class IUControladoraConta {
public:
    virtual void criarConta(const Conta& conta) = 0;
    virtual ~IUControladoraConta() {}
};

class ILNControladoraConta {
public:
    virtual bool criarConta(const Conta& conta) = 0;
    virtual ~ILNControladoraConta() {}
};

class CntrIUControladoraConta : public IUControladoraConta {
private:
    ILNControladoraConta* cntrLNConta;
public:
    CntrIUControladoraConta(ILNControladoraConta* cntrLNConta) : cntrLNConta(cntrLNConta) {}

    void criarConta(const Conta& conta) override {
        if (cntrLNConta->criarConta(conta)) {
            cout << "Conta criada com sucesso!" << endl;
        } else {
            cout << "Falha ao criar conta!" << endl;
        }
    }
};

class LNControladoraConta : public ILNControladoraConta {
private:
    vector<Conta> bancoDeContas;
public:
    bool criarConta(const Conta& conta) override {
        bancoDeContas.push_back(conta);
        return true;
    }

    vector<Conta>& getBancoDeContas() {
        return bancoDeContas;
    }
};


//Viagem
class IUViagem {
public:
    virtual void criarViagem(const Viagem& viagem) = 0;
    virtual Viagem lerViagem(Codigo codigo) = 0;
    virtual void atualizarViagem(Viagem& viagem) = 0;
    virtual bool excluirViagem(Codigo codigo) = 0;
    virtual vector<Viagem> listarViagens() = 0;
    virtual ~IUViagem() {}
};

class ILNViagem {
public:
    virtual bool criarViagem(const Viagem& viagem) = 0;
    virtual Viagem lerViagem(Codigo codigo) = 0;
    virtual bool atualizarViagem(Viagem& viagem) = 0;
    virtual bool excluirViagem(Codigo codigo) = 0;
    virtual vector<Viagem> listarViagens() = 0;
    virtual ~ILNViagem() {}
};

class CntrIUViagem : public IUViagem {
private:
    ILNViagem* cntrLNViajem;

public:
    CntrIUViagem(ILNViagem* cntrLNViajem) : cntrLNViajem(cntrLNViajem) {}

    void criarViagem(const Viagem& viagem) override {
        cntrLNViajem->criarViagem(viagem);
    }

    Viagem lerViagem(Codigo codigo) {
        return cntrLNViajem->lerViagem(codigo);
    }

    void atualizarViagem(Viagem& viagem) override {
        cntrLNViajem->atualizarViagem(viagem);
    }

    bool excluirViagem(Codigo codigo) override {
        return cntrLNViajem->excluirViagem(codigo);
    }

    vector<Viagem> listarViagens() override {
        return cntrLNViajem->listarViagens();
    }
};


class LNCntrViagem : public ILNViagem {
private:
    vector<Viagem> bancoDeViagens;

public:
    bool criarViagem(const Viagem& viagem) override {
        bancoDeViagens.push_back(viagem); // Adiciona a viagem ao final do vetor
        cout << "Viagem criada com sucesso! Codigo: " << viagem.getCodigo().getCodigo() << endl;
        return true;
    }

    Viagem lerViagem(Codigo codigo) override {
        for (const auto& viagem : bancoDeViagens) { // Itera sobre o vetor???
            if (viagem.getCodigo().getCodigo() == codigo.getCodigo()) {
                return viagem; 
            }
        }
        throw runtime_error("Viagem nao encontrada."); 
    }

    bool atualizarViagem(Viagem& viagem) override {
        for (auto& v : bancoDeViagens) { 
            if (v.getCodigo().getCodigo() == viagem.getCodigo().getCodigo()) {
                v.setNome(viagem.getNome());
                v.setAvaliacao(viagem.getAvaliacao());
                cout << "Viagem atualizada com sucesso!" << endl;
                return true;
            }
        }
        return false; 
    }

    bool excluirViagem(Codigo codigo) override {
        for (auto it = bancoDeViagens.begin(); it != bancoDeViagens.end(); ++it) { 
            if (it->getCodigo().getCodigo() == codigo.getCodigo()) {
                bancoDeViagens.erase(it); // Remove a viagem do vetor
                cout << "Viagem excluida com sucesso!" << endl;
                return true;
            }
        }
        return false; 
    }

    vector<Viagem> listarViagens() override {
        return bancoDeViagens; // Retorna o vetor diretamente
    }
};


//Destino
class IUDestino {
public:
    virtual void criarDestino(const Destino& destino) = 0;
    virtual Destino lerDestino(Codigo codigo) = 0;
    virtual void atualizarDestino(Destino& destino) = 0;
    virtual bool excluirDestino(Codigo codigo) = 0;
    virtual vector<Destino> listarDestinos() = 0;
    virtual ~IUDestino() {}
};

//Interface de logica pra destino
class ILNDestino {
public:
    virtual bool criarDestino(const Destino& destino) = 0;
    virtual Destino lerDestino(Codigo codigo) = 0;
    virtual bool atualizarDestino(Destino& destino) = 0;
    virtual bool excluirDestino(Codigo codigo) = 0;
    virtual vector<Destino> listarDestinos() = 0;
    virtual ~ILNDestino() {}
};

class CntrIUDestino : public IUDestino {
private:
    ILNDestino* cntrLNDestino;

public:
    CntrIUDestino(ILNDestino* cntrLNDestino) : cntrLNDestino(cntrLNDestino) {}

    void criarDestino(const Destino& destino) override {
        cntrLNDestino->criarDestino(destino);
    }

    Destino lerDestino(Codigo codigo) override {
        return cntrLNDestino->lerDestino(codigo);
    }

    void atualizarDestino(Destino& destino) override {
        cntrLNDestino->atualizarDestino(destino);
    }

    bool excluirDestino(Codigo codigo) override {
        return cntrLNDestino->excluirDestino(codigo);
    }

    vector<Destino> listarDestinos() override {
        return cntrLNDestino->listarDestinos();
    }
};

class LNCntrDestino : public ILNDestino {
private:
    vector<Destino> bancoDeDestinos;

public:
    bool criarDestino(const Destino& destino) override {
        bancoDeDestinos.push_back(destino);
        cout << "Destino criado com sucesso! Codigo: " << destino.getCodigo().getCodigo() << endl;
        return true;
    }

    Destino lerDestino(Codigo codigo) override {
        for (const auto& destino : bancoDeDestinos) {
            if (destino.getCodigo().getCodigo() == codigo.getCodigo()) {
                return destino;
            }
        }
        throw runtime_error("Destino nao encontrado.");
    }

    bool atualizarDestino(Destino& destino) override {
        for (auto& d : bancoDeDestinos) {
            if (d.getCodigo().getCodigo() == destino.getCodigo().getCodigo()) {
                d = destino; // Atualiza o destino diretamente
                cout << "Destino atualizado com sucesso!" << endl;
                return true;
            }
        }
        return false;
    }

    bool excluirDestino(Codigo codigo) override {
        for (auto it = bancoDeDestinos.begin(); it != bancoDeDestinos.end(); ++it) {
            if (it->getCodigo().getCodigo() == codigo.getCodigo()) {
                bancoDeDestinos.erase(it);
                cout << "Destino excluido com sucesso!" << endl;
                return true;
            }
        }
        return false;
    }

    vector<Destino> listarDestinos() override {
        return bancoDeDestinos;
    }
};
#endif // CONTROLADORA_HPP_INCLUDED

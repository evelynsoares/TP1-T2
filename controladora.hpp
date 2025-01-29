#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED
#include "entidades.hpp"
#include "dominios.hpp"

#include <vector>
#include <stack>

using namespace std;

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
public:
    bool criarConta(const Conta& conta) override {
        bancoDeContas.push_back(conta);
        return true;
    }
};


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
    stack<Viagem> bancoDeViagens; 

public:
    bool criarViagem(const Viagem& viagem) override {
        bancoDeViagens.push(viagem); 
        cout << "Viagem criada com sucesso! Codigo: " << viagem.getCodigo().getCodigo() << endl;
        return true;
    }

    Viagem lerViagem(Codigo codigo) override {
        stack<Viagem> tempStack = bancoDeViagens; 
        while (!tempStack.empty()) {
            Viagem v = tempStack.top();
            if (v.getCodigo().getCodigo() == codigo.getCodigo()) {
                return v;
            }
            tempStack.pop();
        }
        throw runtime_error("Viagem nao encontrada.");
    }

    bool atualizarViagem(Viagem& viagem) override {
        stack<Viagem> tempStack;
        bool encontrada = false;

        while (!bancoDeViagens.empty()) {
            Viagem v = bancoDeViagens.top();
            bancoDeViagens.pop();
            if (v.getCodigo().getCodigo() == viagem.getCodigo().getCodigo()) {
                v.setNome(viagem.getNome());
                v.setAvaliacao(viagem.getAvaliacao());
                encontrada = true;
            }
            tempStack.push(v); 
        }

        while (!tempStack.empty()) {
            bancoDeViagens.push(tempStack.top());
            tempStack.pop();
        }

        if (encontrada) {
            cout << "Viagem atualizada com sucesso!" << endl;
            return true;
        } else {
            return false;
        }
    }

    bool excluirViagem(Codigo codigo) override {
        stack<Viagem> tempStack;
        bool encontrada = false;

        while (!bancoDeViagens.empty()) {
            Viagem v = bancoDeViagens.top();
            bancoDeViagens.pop();
            if (v.getCodigo().getCodigo() == codigo.getCodigo()) {
                encontrada = true;
                cout << "Viagem excluida com sucesso!" << endl;
                break; 
            }
            tempStack.push(v); 
        }

        while (!tempStack.empty()) {
            bancoDeViagens.push(tempStack.top());
            tempStack.pop();
        }

        return encontrada;
    }

    vector<Viagem> listarViagens() override {
        vector<Viagem> viagens;
        stack<Viagem> tempStack = bancoDeViagens; 

        while (!tempStack.empty()) {
            viagens.push_back(tempStack.top());
            tempStack.pop();
        }

        reverse(viagens.begin(), viagens.end());

        return viagens;
    }
};

#endif // CONTROLADORA_HPP_INCLUDED

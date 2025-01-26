#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED
#include "entidades.hpp"
#include "dominios.hpp"

#include <vector>

using namespace std;

static vector<Conta> bancoDeContas;
static vector<Viagem> bancoDeViagens;

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

class ILNViajem {
public:
    virtual bool criarViagem(const Viagem& viagem) = 0;
    virtual Viagem lerViagem(Codigo codigo) = 0;
    virtual bool atualizarViagem(Viagem& viagem) = 0;
    virtual bool excluirViagem(Codigo codigo) = 0;
    virtual vector<Viagem> listarViagens() = 0;
    virtual ~ILNViajem() {}
};

class CntrIUViagem : public IUViagem {
private:
    ILNViajem* cntrLNViajem;

public:
    CntrIUViagem(ILNViajem* cntrLNViajem) : cntrLNViajem(cntrLNViajem) {}

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
        cntrLNViajem->excluirViagem(codigo);
    }

    vector<Viagem> listarViagens() override {
        return cntrLNViajem->listarViagens();
    }
};

class LNCntrViagem : public ILNViajem {
private:
    vector<Viagem> bancoDeViagens;

public:
    bool criarViagem(const Viagem& viagem) override {
        bancoDeViagens.push_back(viagem);
        cout << "Viagem criada com sucesso!" << endl;
        return true;
    }

    Viagem lerViagem(Codigo codigo) override {
        for (const auto& v : bancoDeViagens) {
            if (v.getCodigo().getCodigo() == codigo.getCodigo()) {
                return v;
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
                bancoDeViagens.erase(it);
                cout << "Viagem excluida com sucesso!" << endl;
                return true;
            }
        }
        return false;
    }

    vector<Viagem> listarViagens() override {
        return bancoDeViagens;
    }
};


#endif // CONTROLADORA_HPP_INCLUDED

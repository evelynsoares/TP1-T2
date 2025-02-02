#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"
#include <vector>

using namespace std;

///
///  A Classe Conta refere-se a conta de um possível usuário
/// Ela possui Nome, Senha, Código, e Viagem
/// @see Nome
/// @see Senha
/// @see Codigo
/// @see Viagem
/// @author 170102785
///
class Conta {
private:
    Codigo codigo;
    Senha senha;
    Codigo viagem;

public:
    Conta() = default;

    Conta(const Codigo& codigo, const Senha& senha) 
        : codigo(codigo), senha(senha), viagem(Codigo()) {}

    Conta(const Codigo& codigo, const Senha& senha, const Codigo& viagem) 
        : codigo(codigo), senha(senha), viagem(viagem) {}

    Senha getSenha() const { return senha; }
    Codigo getCodigo() const { return codigo; }
    Codigo getViagem() const { return viagem; }

    void setSenha(const Senha& novaSenha) { senha = novaSenha; }
    void setCodigo(const Codigo& novoCodigo) { codigo = novoCodigo; }
    void setViagem(const Codigo& codViagem) { viagem = codViagem; }
};

///
/// A classe viagem refere-se a viagens dentro do sistema
/// ela possui código, nome e avaliação
/// @see Codigo
/// @see Nome
/// @see Avaliacao
/// @see Conta
///

class Viagem {
private:
    Codigo codigo;
    Nome nome;
    Avaliacao avaliacao;
    Codigo contaAssociada;

public:
    Viagem(const Codigo& codigo, const Nome& nome, const Avaliacao& avaliacao, const Codigo& contaAssociada)
        : codigo(codigo), nome(nome), avaliacao(avaliacao), contaAssociada(contaAssociada) {}

    Viagem() = default;

    Codigo getCodigo() const { return codigo; }
    Nome getNome() const { return nome; }
    Avaliacao getAvaliacao() const { return avaliacao; }
    Codigo getContaAssociada() const { return contaAssociada; }

    void setCodigo(const Codigo& novoCodigo) { codigo = novoCodigo; }
    void setNome(const Nome& novoNome) { nome = novoNome; }
    void setAvaliacao(const Avaliacao& novaAvaliacao) { avaliacao = novaAvaliacao; }
};


///
/// Destino refere-se a destinos dentro do sistema
/// possui Codigo, Nome, duas datas (Inicio e termino), avaliação, viagens, atividade e hospedagem.
/// @see Codigo
/// @see Nome
/// @see Data
/// @see Avaliacao
/// @see Viagem
/// @see Atividade
/// @see Hospedagem
///
class Destino {
private:
    Codigo* codigo;
    Nome* nome;
    Data* dataDeInicio;
    Data* dataDeTermino;
    Avaliacao* avaliacao;
    vector<Codigo> viagens;
    vector<Codigo> atividades;
    Codigo* hospedagem[1];
    Codigo* viagem;

public:

    Destino(Codigo* codigo, Nome* nome, Data* dataDeInicio, Data* dataDeTermino, Avaliacao* avaliacao, Codigo* viagem){
        this->codigo = codigo;
        this->nome = nome;
        this->dataDeInicio = dataDeInicio;
        this->dataDeTermino = dataDeTermino;
        this->avaliacao = avaliacao;
        this->viagens = {};
        this->atividades = {};
        this->viagem = viagem;
    }


    Codigo getCodigo() const { return *codigo;}
    Nome getNome() const { return *nome; }
    Data getDataDeInicio() const { return *dataDeInicio; }
    Data getDataDeTermino() const { return *dataDeTermino;}
    Avaliacao getAvaliacao() const { return *avaliacao;}
    vector<Codigo> getViagens() const { return viagens;}
    vector<Codigo> getAtividade() const { return atividades;}
    Codigo* getHospedagem() const { return *hospedagem;}

    void setCodigo( const Codigo& novoCodigo) { *codigo = novoCodigo; }
    void setNome( const Nome& novoNome) { *nome = novoNome; }
    void setDataDeInicio( const Data& novaDataDeInicio) { *dataDeInicio = novaDataDeInicio;}
    void setDataDeTermino( const Data& novaDataDeTermino) { *dataDeTermino = novaDataDeTermino;}
    void setAvaliacao ( const Avaliacao& novaAvaliacao ) { *avaliacao = novaAvaliacao;}
    void addViagem (Codigo codViagem) { viagens.push_back(codViagem);}
    void remViagem (Codigo codViagem) {viagens.erase(remove(viagens.begin(), viagens.end(), codViagem), viagens.end());}
    void addAtividade (Codigo codAtividade) { atividades.push_back(codAtividade);}
    void remAtividade (Codigo codAtividade) {atividades.erase(remove(atividades.begin(), atividades.end(), codAtividade), atividades.end());}
    void setHospedagem (Codigo codHospedagem) { hospedagem[0] = &codHospedagem;}
    void remHospedagem () { hospedagem[0] = {};}

};

///
/// Hospedagem refere-se a uma hospedagem no sistema
/// possui código, nome, diaria (Dinheiro) e avaliação
/// @see Codigo
/// @see Nome
/// @see Dinheiro
/// @see Avaliacao
///
class Hospedagem {
private:
    Codigo* codigo;
    Nome* nome;
///
/// @param diaria @see Dinheiro
///
    Dinheiro* diaria;
    Avaliacao* avaliacao;
    Codigo* destino;

public:
    Hospedagem(Nome* nome, Codigo* codigo, Dinheiro* diaria, Avaliacao* avaliacao, Codigo* destino){
        this->nome = nome;
        this->codigo = codigo;
        this->diaria = diaria;
        this->avaliacao = avaliacao;
        this->destino = destino;
    }

    Codigo getCodigo() const { return *codigo;}
    Nome getNome() const { return *nome; }
    Dinheiro getDiaria() const { return *diaria; }
    Avaliacao getAvaliacao() const { return *avaliacao;}
    Codigo getDestino() const { return *destino;}

    void setCodigo( const Codigo& novoCodigo) { *codigo = novoCodigo; }
    void setNome( const Nome& novoNome) { *nome = novoNome; }
    void setDiaria( const Dinheiro& novaDiaria) { *diaria = novaDiaria; }
    void setAvaliacao( const Avaliacao& novaAvaliacao) { *avaliacao = novaAvaliacao; }
    void setDestino (const Codigo& codDestino) { *destino = codDestino;}

};

///
/// Classe Atividade refere-se a atividades no sistema
/// possui Codigo, nome, data, horario, duração, preço(Dinheiro), avaliação e destinos
/// @see Codigo
/// @see Nome
/// @see Dinheiro
/// @see Duracao
/// @see Horario
/// @see Avaliacao
/// @see Destino
///
class Atividade {
private:
    Codigo*codigo;
    Nome* nome;
    Data* data;
    Horario* horario;
    Duracao* duracao;
    Dinheiro* preco;
    Avaliacao* avaliacao;
    vector<Codigo> destinos;

public:
    Atividade(Codigo* codigo, Nome* nome, Data* data, Horario* horario, Duracao* duracao, Dinheiro* preco, Avaliacao* avaliacao){
        this->codigo = codigo;
        this->nome = nome;
        this->data = data;
        this->horario = horario;
        this->duracao = duracao;
        this->preco = preco;
        this->avaliacao = avaliacao;
        this->destinos = {};
    }

    Codigo getCodigo() const { return *codigo;}
    Nome getNome() const { return *nome; }
    Data getData() const { return *data; }
    Horario getHorario() const { return *horario; }
    Duracao getDuracao() const { return *duracao; }
    Dinheiro getPreco() const { return *preco; }
    Avaliacao getAvaliacao() const { return *avaliacao; }
    vector<Codigo> getDestinos() const { return destinos;}

    void setCodigo(const Codigo& novoCodigo) { *codigo = novoCodigo;}
    void setNome(const Nome& novoNome) { *nome = novoNome;}
    void setData(const Data& novaData) { *data = novaData;}
    void setHorario(const Horario& novoHorario) { *horario = novoHorario; }
    void setDuracao(const Duracao& novaDuracao) { *duracao = novaDuracao; }
    void setPreco(const Dinheiro& novoPreco) { *preco = novoPreco; }
    void setAvaliacao(const Avaliacao& novaAvaliacao)  { *avaliacao = novaAvaliacao; }
    void addDestino (Codigo codDestino) { destinos.push_back(codDestino);}
    void remDestino (Codigo codDestino) {destinos.erase(remove(destinos.begin(), destinos.end(), codDestino), destinos.end());}
};

#endif // ENTIDADES_HPP_INCLUDED

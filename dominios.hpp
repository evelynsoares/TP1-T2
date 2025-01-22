#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;

///
/// A classe código se refere a chave primária de uma viagem
///
class Codigo {
///
/// @param codigo string de 6 caracteres (letras ou digitos)
///
private:
    string codigo;
///
/// @param validar
///
    bool validar(string);

public:
    Codigo(string);
    void setCodigo(string c);
    string getCodigo();
};

///
/// Avaliação possui uma nota de 0 a 5
///
class Avaliacao {
///
/// @param nota digito 0,1,2,3,4 ou 5
///
private:
    int nota;
    bool validar(int);
public:
    Avaliacao(int n);
    void setNota(int n);
    int getNota();
};

///
/// A classe Data refere-se a data temporal (dia/mês/ano)
///
class Data {
private:
///
/// @param DD Dia (1 - 31, conforme mês adequado)
/// @param MM Mês ( 1 - 12)
/// @param AA Ano (apenas os dois últimos digitos de um ano, 00 - 99)
///
    int DD, MM, AA;
    bool validar(int, int, int);
public:
    Data(int d, int m, int a);
    void setData(int d, int m, int a);
    string getData();
};

///
/// Dinheiro refere-se ao valor de uma atividade ou hospedagem no sistema
///
class Dinheiro {
///
/// @param valor ( 00,00 - 200.000,00)
///
private:
    double valor;
    bool validar(double);
public:
    Dinheiro(double);
    void setValor(double v);
    double getValor();
};

///
/// Duração de alguma atividade em dias
///
class Duracao {
///
/// @param tempo quantidade de dias de uma atividade (0 - 360))
///
private:
    int tempo;
    bool validar(int);
public:
    Duracao(int);
    void setDuracao(int t);
    int getDuracao();
};

///
/// A Classe Horário denota o horário de alguma atividade do sistema
///
class Horario {
///
/// @param HH Horas (00 - 23)
/// @param MM Minutos (00 - 59)
///
private:
    int HH, MM;
    bool validar(int, int);
public:
    Horario(int h, int m);
    void setHorario(int h, int m);
    string getHorario();
};

///
/// Nome de uma viagem, destino, ativididade ou hospedagem.
///
class Nome {
///
/// @param nome texto com até 30 caracteres.
///
private:
    char nome[30];
    bool validar(char *);
public:
    Nome(char *);
    void setNome(char *n);
    string getNome();
};

///
/// Senha para o acesso de uma conta.
///
class Senha {
///
/// @param senha Cinco digitos, sem digito duplicado ou em ordem crescente/decrescente.
///
private:
    unsigned int senha;
    bool validar(unsigned int);
public:
    Senha(unsigned int);
    void setSenha(unsigned int s);
    unsigned int getSenha();
};
#endif // DOMINIOS_HPP_INCLUDED

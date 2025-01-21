#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

#include <stdexcept>

#include "dominios.hpp"

using namespace std;


class TUAvaliacao {
    private:
        const static int VALOR_VALIDO =  5 ;
        const static int VALOR_INVALIDO = -1;
        const static int VALOR_INVALIDO2 = 6;
        const static int VALOR_INVALIDO3 = 1000;
        int estado;
        Avaliacao *avaliacao;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};
/*
class TUCodigo {
    private:
        const  string VALOR_VALIDO =  "Az�301" ;
        const  string VALOR_INVALIDO = "1234567";
        const  string VALOR_INVALIDO2 = "ab";
        const  string VALOR_INVALIDO3 = "!567)";
        int estado;
        Codigo *codigo;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


class TUData {
    private:
        const  int VALOR_VALIDO[3] =  {29, 2, 2024} ;
        const  int VALOR_INVALIDO[3] = {31, 4, 2020};
        const  int VALOR_INVALIDO2[3] = {29, 2, 1900};
        const  int VALOR_INVALIDO3[3] = {29, 2, 2023};
        Data *data;
        int estado;


        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


class TUDinheiro {
    private:
        const  double VALOR_VALIDO = 1000.55;
        const  double VALOR_INVALIDO = 200001;
        const  double VALOR_INVALIDO2 = -55.;
        Dinheiro *dinheiro;
        int estado;
        void setUp();
        void tearDown();

        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUDuracao {
    private:
        const static int VALOR_VALIDO = 220;
        const static int VALOR_INVALIDO = 361;
        Duracao *duracao;
        int estado;
        void setUp();
        void tearDown();

        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


class TUHorario {
    private:
        const  int VALOR_VALIDO[2] = {22, 32};
        const  int VALOR_INVALIDO[2] = {24, 00};
        Horario *horario;
        int estado;
        void setUp();
        void tearDown();

        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUNome {
    private:
        const  char VALOR_VALIDO[30] = "nao sei o que escrever";
        const  char VALOR_INVALIDO[30] = "12345678901234";
        Nome *nome;
        int estado;
        void setUp();
        void tearDown();

        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUSenha {
    private:
        const static char VALOR_VALIDO =  86259;
        const static char VALOR_INVALIDO = 12345;
        const static char VALOR_INVALIDO2 = 54321;
        const static char VALOR_INVALIDO3 = 862590;
        const static char VALOR_INVALIDO4 = 86258;
        Senha *senha;
        int estado;
        void setUp();
        void tearDown();

        void testarCenarioValorValido();
        void testerCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};
*/
#endif // TESTES_HPP_INCLUDED

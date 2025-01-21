#include <iostream>
#include "dominios.hpp"
//#include "testes.hpp"
//#include "entidades.hpp"

using namespace std;

int main() {

    Avaliacao *aval = new Avaliacao(3);
    cout << "Nota inicial: " << aval->getNota() << endl;
    aval->setNota(9); // pega erro
    aval->setNota(-2); // pega erro
    aval->setNota(5);
    cout << "Nota final: " << aval->getNota() << endl;
    delete aval;

    Codigo *cod = new Codigo("CT2314");
    cod->setCodigo("fbgri743932"); // pega erro
    cod->setCodigo("%4t5g"); // pega erro
    cod->setCodigo("ABC"); // pega erro
    cod->setCodigo("AVFG12");
    cout << "Codigo: " << cod->getCodigo() << endl;
    delete cod;

    return 0;
}

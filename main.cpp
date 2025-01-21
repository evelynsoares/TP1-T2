#include <iostream>
#include "dominios.hpp"
#include "testes.hpp"
#include "entidades.hpp"

using namespace std;

int main() {

    Avaliacao *aval = new Avaliacao(3); //se colocar nota invalida aqui o codigo roda ok
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

    Data *data = new Data(1, 1, 2025);
    cout << "Data inicial: " << data->getData() << endl;
    data->setData(34, 9, 2015); // pega erro
    data->setData(12, 13, 2004); // pega erro
    data->setData(12, 12, 19191); // era pra pega erro? idk
    data->setData(21, 1, 2025);
    cout << "Data final: " << data->getData() << endl;
    delete data;

    Dinheiro *din = new Dinheiro(109.9);
    cout << "Valor inicial: " << din->getValor() << endl;
    din->setValor(300000); // pega erro
    din->setValor(-9302); // pega erro
    din->setValor(73824.2);
    cout << "Valor: " << din->getValor() << endl;
    delete din;

    Duracao *temp = new Duracao(30);
    cout << "Tempo inicial: " << temp->getDuracao() << endl;
    temp->setDuracao(39.8); // pega erro
    temp->setDuracao(-9302); // pega erro
    temp->setDuracao(90);
    cout << "Duracao: " << temp->getDuracao() << endl;
    delete temp;


    Horario *horario = new Horario(10, 30);
    cout << "Horario inicial: " << horario->getHorario() << endl;
    horario->setHorario(23, 99);
    horario->setHorario(99, 2);
    horario->setHorario(7, 45);
    cout << "Horário atualizado: " << horario->getHorario() << endl;

    return 0;
}

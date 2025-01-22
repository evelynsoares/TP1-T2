#include "dominios.hpp"
#include <stdexcept>

using namespace std;

bool Codigo::validar(string codigo){
    string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"; // Caracteres validos.
    if(codigo.length() != 6 ){
        return false;
    }
    for(int i = 0; i < codigo.length(); i++){ //->> WARNING
        bool flag = false;
        for(int j = 0; j < valid.length(); j++){ // isso roda no máximo 6*63 vezes no total (codigo.length() = 6). ---> WARNING
            if(codigo[i] == valid[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false; // Se loopar em todos e flag
        }
    }
    return true;
}

Codigo::Codigo(string c){
    try {
        if(validar(c)){
        this->codigo = c;
        } else {
            throw invalid_argument(c);
        }
    } catch (invalid_argument& e) {
        cout << "Erro, codigo invalido: " << e.what() << endl;
    }

}

void Codigo::setCodigo(string c) {
    try{
        if(validar(c)){
            this->codigo = c;
        } else {
            throw invalid_argument(c);
        }
    } catch (invalid_argument& e) {
        cout << "Erro, codigo invalido: " << e.what() << endl;
    }
}

string Codigo::getCodigo() {
    return codigo;
}

//170102785
bool Avaliacao::validar(int nota){
    if(nota < 0 || nota > 5){
        return false;
    }
    return true;
}

Avaliacao::Avaliacao(int n) {
    try {
        if (validar(n)) {
            this->nota = n;
        } else {
            throw invalid_argument(to_string(n));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, nota invalida: " << e.what() << endl;
    }
}

void Avaliacao::setNota(int n) {
    try {
        if (validar(n)) {
            this->nota = n;
        } else {
            throw invalid_argument(to_string(n));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, nota invalida: " << e.what() << endl;
    }
}

int Avaliacao::getNota() {
    return nota;
}

bool Data::validar(int DD, int MM, int AA) {
    if (DD < 1 || DD > 31 || MM > 12 || MM < 1 ||
        (DD > 30 && ((MM % 2 == 0 && MM < 8) || (MM % 2 == 1 && MM > 7))) ||
        (MM == 2 && ((AA % 4 == 0 && DD > 29) || (AA % 4 != 0 && DD > 28)))) {
        return false;
    }
    return true;
}

Data::Data(int DD, int MM, int AA) {
    try {
        if (validar(DD, MM, AA)) {
            this->DD = DD;
            this->MM = MM;
            this->AA = AA;
        } else {
            string aux = to_string(DD) + "-" + to_string(MM) + "-" + to_string(AA);
            throw invalid_argument(aux);
        }
    } catch (invalid_argument& e) {
        cout << "Erro, data invalida: " << e.what() << endl;
    }
}

void Data::setData(int d, int m, int a) {
    try {
        if (validar(d, m, a)) {
            DD = d;
            MM = m;
            AA = a;
        } else {
            string aux = to_string(d) + "-" + to_string(m) + "-" + to_string(a);
            throw invalid_argument(aux);
        }
    } catch (invalid_argument& e) {
        cout << "Erro, data invalida: " << e.what() << endl;
    }
}

string Data::getData() {
    return to_string(DD) + "-" + to_string(MM) + "-" + to_string(AA);
}

bool Dinheiro::validar(double m) {
    return !(m > 200000 || m < 0);
}

Dinheiro::Dinheiro(double valor) {
    try {
        if (validar(valor)) {
            this->valor = valor;
        } else {
            throw invalid_argument(to_string(valor));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, valor invalido: " << e.what() << endl;
    }
}

void Dinheiro::setValor(double v) {
    try {
        if (validar(v)) {
            this->valor = v;
        } else {
            throw invalid_argument(to_string(v));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, valor invalido: " << e.what() << endl;
    }
}

double Dinheiro::getValor() {
    return valor;
}

bool Duracao::validar(int d) {
    return !(d > 360 || d < 0);
}

Duracao::Duracao(int t) {
    try {
        if (validar(t)) {
            this->tempo = t;
        } else {
            throw invalid_argument(to_string(t));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, tempo invalido: " << e.what() << endl;
    }
}

void Duracao::setDuracao(int t) {
    try {
        if (validar(t)) {
            this->tempo = t;
        } else {
            throw invalid_argument(to_string(t));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, tempo invalido: " << e.what() << endl;
    }
}

int Duracao::getDuracao() {
    return tempo;
}

bool Horario::validar(int HH, int MM) {
    return !(HH > 23 || HH < 0 || MM > 59 || MM < 0);
}

void Horario::setHorario(int h, int m) {
    try {
        if(validar(h, m)){
           this->HH = h;
           this->MM = m;
        }
        else {
            throw invalid_argument(to_string(h) + ":" + to_string(m));
        }
    } catch (invalid_argument& e){
        cout << "Erro, horario invalido: " << e.what() << endl;

    }
}

string Horario::getHorario() {
    string formatHH = (HH < 10 ? "0" : "") + to_string(HH);
    string formatMM = (MM < 10 ? "0" : "") + to_string(MM);
    return formatHH + ":" + formatMM;
}

Horario::Horario(int HH, int MM) {
    try {
        if (validar(HH, MM)) {
            this->HH = HH;
            this->MM = MM;
        }
        else {
            throw invalid_argument(to_string(HH) + ":" + to_string(MM));
        }
    } catch (invalid_argument& e){
        cout << "Erro, horario invalido: " << e.what() << endl;
    }
}
bool Nome::validar(char* nome) {
    size_t length = strlen(nome);
    if (length == 0 || length > 30) {
        return false;
    }
    for (size_t i = 0; i < length; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false;
        }
    }
    return true;
}

void Nome::setNome(char *n) {
   try {
        if (validar(n)) {
            strncpy(this->nome, n, 30);
            this->nome[29] = '\0';
        } else {
            throw invalid_argument(string(n));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, nome invalido: " << e.what() << endl;
    }
}

string Nome::getNome() {
    return string(nome);
}

Nome::Nome(char* nome) {
    try {
        if (validar(nome)) {
            strncpy(this->nome, nome, 30);
            this->nome[29] = '\0';
        } else {
            throw invalid_argument(string(nome));
        }
    } catch (invalid_argument& e) {
        cout << "Erro, nome invalido: " << e.what() << endl;
        this->nome[0] = '\0';  // esvaziar a string
    }
}

bool Senha::validar(unsigned int senha) {
    string senha_str = to_string(senha);
    int counter_d = 1, counter_c = 1, counter_unicos = 1; //comecar no 1 para comparar com o digito anterior

    if (senha_str.length() != 5) {
        return false;
    }

    for(size_t i = 1; i < senha_str.length(); ++i){
        if (senha_str[i] == senha_str[i-1]){
            counter_unicos++;
        }
    }
    if (counter_unicos == 5) return false;

    //checa se a senha esta crescendo ou decrescendo
    for (size_t i = 1; i < senha_str.length(); ++i) {
        if (senha_str[i] < senha_str[i-1]) {
            counter_d++;
        } else if (senha_str[i] == senha_str[i+1]) {
            counter_c++;
        }
    }

    if (counter_c == 5 || counter_d == 5) {
        return false;
    }
    return true;
}

Senha::Senha(unsigned int s) {
    try {
        if (validar(s)) {
            this->senha = s;
        } else {
            throw invalid_argument(to_string(s));
        }
    } catch (invalid_argument& e) {
        cout << "Erro: Senha invalida: " << e.what() << endl;
        this->senha = 0;  // Set to default value on error
    }
}

void Senha::setSenha(unsigned int s) {
    try {
        if (validar(s)) {
            this->senha = s;
        } else {
            throw invalid_argument(to_string(s));
        }
    } catch (invalid_argument& e) {
        cout << "Erro: Senha invalida: " << e.what() << endl;
    }
}

unsigned int Senha::getSenha() {
    return senha;
}

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
    if(validar(c)){
        this->codigo = c;
    } else {
        throw invalid_argument(c);
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

Avaliacao::Avaliacao(int n) { //metodo construtor precisa ser inicializado com input valido
    if (validar(n)) {
        this->nota = n;
    } else {
        throw invalid_argument(to_string(n));
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



/*

bool Data::validar(int DD, int MM, int AA){
    if(DD < 1 || DD > 31 || MM > 12 || MM < 1 || (DD > 30 && ((MM%2 == 0 && MM < 8) || (MM%2 && MM > 7))) || (AA%4 == 0 && MM == 2 && DD > 29)){
        return false;
    }
    return true;
}

bool Dinheiro::validar(double m){
    if(m > 200000 || m < 0){
        return false;
    }
    return true;
}

bool Duracao::validar(int d){
    if(d > 360 || d < 0){
        return false;
    }
    return true;
}

bool Horario::validar(int HH, int MM) {
    if (HH > 23 || MM > 59) {
        return false;
    }
    return true;
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

bool Senha::validar(unsigned int senha) {
    string senha_str = to_string(senha);
    int counter_d = 1, counter_c = 1; //comecar no 1 para comparar com o digito anterior

    if (senha_str.length() != 5) {
        return false;
    }

    set<char> dig_unicos; //checa se todos os digitos sao unicos
    for (char c : senha_str) {
        if (!isdigit(c) || dig_unicos.count(c) > 0) {
            return false;
        }
        dig_unicos.insert(c);
    }
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




void Data::setData(int d, int m, int a) {
    if (validar(d, m, a)) {
        DD = d;
        MM = m;
        AA = a;
    }
}

Data Data::getData(int &d, int &m, int &a) {
    d = DD;
    m = MM;
    a = AA;
    return *this; // retorna o objeto
}

Data::Data(int DD, int MM, int AA){
    try{
        if(validar(DD, MM, AA)){
            this->DD = DD;
            this->MM = MM;
            this->AA = AA;
        } else {
            string aux = to_string(DD) + "-" + to_string(MM) + "-" + to_string(AA);
            throw aux;
        }
    } catch (string aux) {
        cout << "Erro: Data invalida. Valor entrado: " << aux << endl;
    }
}

// 170102785
void Dinheiro::setValor(double v) {
    if (validar(v)) {
        valor = v;
    }
}

double Dinheiro::getValor() {
    return valor;
}

Dinheiro::Dinheiro(double valor){
    try {
        if (validar(valor)){
            this->valor = valor;
        }
        else {
            throw valor;
        }
    } catch (double valor) {
        cout << "Erro: Dinheiro invalido. Valor entrado: " << valor << endl;
    }
}

// 170102785
void Duracao::setDuracao(int t) {
    if (validar(t)) {
        tempo = t;
    }
}

int Duracao::getDuracao() {
    return tempo;
}

Duracao::Duracao(int tempo){
    try {
        if (validar(tempo)){
            this->tempo = tempo;
        }
        else {
            throw tempo;
        }
    }
    catch (int tempo){
        cout << "Erro: Duracao invalida. Valor entrado: " << tempo << endl;
    }
}

void Horario::setHora(int h) {
    if (validar(h, MM)) {
        HH = h;
    }
}

void Horario::setMinuto(int m) {
    if (validar(HH, m)) {
        MM = m;
    }
}

Horario Horario::getHorario(int &h, int &m) {
    h = HH;
    m = MM;
    return *this;
}

Horario::Horario(int HH, int MM) {
    try {
        if (validar(HH, MM)) {
            this->HH = HH;
            this->MM = MM;
        } else {
            string aux = to_string(HH) + ":" + to_string(MM);
            throw aux;
        }
    } catch (string aux) {
        cout << "Erro: Horario invalido. Valor entrado: " << aux << endl;
    }
}
void Nome::setNome(char *n) {
    if (validar(n)) {
        strncpy(nome, n, 30);
        nome[29] = '\0';  // Assegura que o nome seja uma string terminada em '\0'
    }
}

string Nome::getNome(char *n) {
    strcpy(n, nome);  // Copia o conteúdo de 'nome' para o ponteiro 'n'
    return string(n);  // Retorna o nome como string
}

Nome::Nome(char* nome) {
    try {
        if (validar(nome)) {
            strncpy(this->nome, nome, 30);
            this->nome[29] = '\0';
        } else {
            throw string(nome);
        }
    } catch (string aux) {
        cout << "Erro: Nome invalido. Valor entrado: " << aux << endl;
    }
}

void Senha::setSenha(unsigned int s) {
    if (validar(s)) {
        senha = s;
    }
}

unsigned int Senha::getSenha() {
    return senha;
}
Senha::Senha(unsigned int senha) {
    try {
        if (validar(senha)) {
            this->senha = senha;
        } else {
            throw senha;
        }
    } catch (unsigned int senha) {
        cout << "Erro: Senha invalida. Valor entrado: " << senha << endl;
    }
}
*/

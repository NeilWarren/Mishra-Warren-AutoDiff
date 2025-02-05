
#ifndef MISHRA_WARREN_AUTODIFF_TOKEN_H
#define MISHRA_WARREN_AUTODIFF_TOKEN_H

#include <utility>

#include "../sys.h"
using namespace std;

class Token {

public:

    token_type type;
    string operation;
    double num_val;
    map<string, double> derivs;
    Token *l_c = nullptr;
    Token *r_c = nullptr;
    int precedence;
    char first_char;
    string var_name;

    Token(char t, token_type type, int precedence=0, double n_val=0.0,  string op="none"){
        this->first_char = t;
        this->num_val = n_val;
        this->type = type;
        this->precedence = precedence;
        this->operation = move(op);

    }
    Token(char t, token_type type, double n_val,  map<string, double> d){
        this->first_char = t;
        this->num_val = n_val;
        this->type = type;
        this->precedence = 0;
        this->operation = "none";
        this->derivs = std::move(d);

    }

    void set_func_type(std::string f){
        this->operation = move(f);
    }

    void set_var_name(std::string var) {
        this->var_name = var;
    }
    void set_lc(Token* t){
        this->l_c = t;
    }
    void set_rc(Token* t){
        this->r_c = t;
    }
    void set_n_val(double v){
        this->num_val = v;
    }

};


#endif //MISHRA_WARREN_AUTODIFF_TOKEN_H

/**
 * @file Request.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Request.h"

using namespace std;

/**
 * @brief Construct a new Request:: Request object
 * Construtor default
 */
Request::Request(){
    tipo = "";
    data = {};
}

/**
 * @brief Construct a new Request:: Request object
 * Construtor parametrizado
 * @param tipo Tipo de pedido
 * @param data Vetor com a informação do pedido
 */
Request::Request(string tipo, vector<string> data){
    this->tipo = tipo;
    this->data = data;
}

/**
 * @brief 
 * Setter do objeto tipo
 * @param s 
 */
void Request::setTipo(string s){
    tipo = s;
}

/**
 * @brief 
 * Setter do objeto data
 * @param s 
 */
void Request::setData(vector<string> s){
    data = s;
}

/**
 * @brief 
 * Getter do tipo de pedido
 * @return string 
 */
string Request::get_Tipo(){
    return tipo;
}

/**
 * @brief 
 * Getter da informação do pedido
 * @return vector<string> 
 */
vector<string> Request::get_Data(){
    return data;
}
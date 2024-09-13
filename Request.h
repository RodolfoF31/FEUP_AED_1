/**
 * @file Request.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef REQUEST_H
#define REQUEST_H

#include <vector>
#include <string>

using namespace std;

class Request{
    private:
        string tipo;
        vector<string> data;

    public:
        /**
         * @brief Construct a new Request object
         * Construtor default
         */
        Request();
        /**
         * @brief Construct a new Request object
         * Construtor parametrizado
         * @param tipo Tipo de pedido
         * @param data Vetor com a informação do pedido
         */
        Request(string tipo, vector<string> data);

        /**
         * @brief Setter do objeto tipo
         * 
         * @param s 
         */
        void setTipo(string s);
        /**
         * @brief Setter do objeto data
         * 
         * @param s 
         */
        void setData(vector<string> s);

        /**
         * @brief Gett do objeto tipo
         * 
         * @return string 
         */
        string get_Tipo();
        /**
         * @brief Getter do objeto data
         * 
         * @return vector<string> 
         */
        vector<string> get_Data();


};


#endif
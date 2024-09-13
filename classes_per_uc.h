/**
 * @file classes_per_uc.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CLASSES_PER_UC
#define CLASSES_PER_UC

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


class classes_per_uc{
    private:
        string UcCode;
        string ClassCode;
        int size;
    public:
        /**
         * @brief
         * Construtor default
         */
        classes_per_uc();
        /**
         * @brief
         * Construtor parametrizado
         * @param UcCode 
         * @param ClassCode 
         * @param size 
         */
        classes_per_uc(string UcCode, string ClassCode, int size);

        /**
         * @brief
         * Setter do objeto UcCode
         * @param s 
         */
        void setUcCode(string s);
        /**
         * @brief
         * Setter do objeto ClassCode
         * @param s 
         */
        void setClassCode(string s);
        /**
         * @brief
         * Setter do objeto Size
         * @param s 
         */
        void setSize(int s);
        
        /**
         * @brief
         * Setter do objeto UcCode
         * @return string 
         */
        string get_UcCode();
        /**
         * @brief
         * Setter do objeto ClassCode
         * @return string 
         */
        string get_ClassCode();
        /**
         * @brief
         * Setter do objeto Size
         * @return int 
         */
        int get_Size();
};

#endif
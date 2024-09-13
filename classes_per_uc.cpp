/**
 * @file classes_per_uc.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "classes_per_uc.h"

using namespace std;

/**
 * @brief
 * Construtor default
 */
classes_per_uc::classes_per_uc(){
    UcCode = "";
    ClassCode = "";
    size = 0;
}

/**
 * @brief
 * Construtor parametrizado
 * @param UcCode 
 * @param ClassCode 
 * @param size 
 */
classes_per_uc::classes_per_uc(string UcCode, string ClassCode, int size){
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
    this->size = size;
}

/**
 * @brief 
 * Setter do objeto UcCode
 * @param s 
 */
void classes_per_uc::setUcCode(string s){
    UcCode = s;
}
/**
 * @brief 
 * Setter do objeto ClassCode
 * @param s 
 */
void classes_per_uc::setClassCode(string s){
    ClassCode = s;
}
/**
 * @brief 
 * Setter do objeto size
 * @param s 
 */
void classes_per_uc::setSize(int s){
    size = s;
}
/**
 * @brief 
 * Setter do objeto UcCode
 * @return string 
 */
string classes_per_uc::get_UcCode(){
    return UcCode;
}
/**
 * @brief 
 * Setter do objeto ClassCode
 * @return string 
 */
string classes_per_uc::get_ClassCode(){
    return ClassCode;
}
/**
 * @brief 
 * Setter do objeto size
 * @return int 
 */
int classes_per_uc::get_Size(){
    return size;
}
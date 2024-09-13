/**
 * @file func_auxiliares.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Student.h"
#include "classes.h"
#include "Classes.cpp"
#include "Student.cpp"
#include "classes_per_uc.h"
#include "classes_per_uc.cpp"

using namespace std;


/**
 * @brief 
 * Comparador para ordenar estrutura linear de forma crescente através da variável float StartHour
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool FloatComparator(classes p1, classes p2){

    return (p1.get_StartHour() < p2.get_StartHour());

}

/**
 * @brief 
 * Comparador para ordenar estrutura linear de forma crescente através da variável string StudentCode
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool StudentNumberComparator(Student p1, Student p2){

    int p1_ = stoi(p1.get_StudentCode());
    int p2_ = stoi(p2.get_StudentCode());

    return (p1_ < p2_);

}

/**
 * @brief 
 * Comparador para ordenar estrutura linear de forma crescente através da variável string StudentName
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool NameComparator(Student p1, Student p2){

    return (p1.get_StudentName() < p2.get_StudentName());

}

/**
 * @brief 
 * Comparador para ordenar estrutura linear de forma crescente através da variável int Size
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool NumberofStudentsComparator(classes_per_uc p1, classes_per_uc p2){

    return (p1.get_Size() < p2.get_Size());

}


/**
 * @brief 
 * Retorna uma string que representa as horas. Exemplo: 9.5 -> 9:30
 * @param number Hora a que começa uma aula
 * @return string 
 */
string time(float number){
    
    if (floor(number) == number){
        int n = static_cast<int>(number);
        string finaltime = to_string(n) + ":00";
        return finaltime;
    }
    else{
        string finaltime = "";
        int hours = floor(number);
        int minutes = (number - hours) * 60;
        finaltime = to_string(hours) + ":" + to_string(minutes);
        return finaltime;
    }
}
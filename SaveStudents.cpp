/**
 * @file SaveStudents.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"

using namespace std;

/**
 * @brief 
 * Retorna um set do tipo class Student com todos os estudantes, definidos pelo seu número UP e nome.
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro
 * @return set<Student> 
 */
set<Student> savestudents(){
    Student astudent_;
    set<Student> aset_;

    ifstream savestudents;
    savestudents.open("students_classes.csv");

    string line;
    getline(savestudents, line); // Passar primeira linha á frente

    while(getline(savestudents, line)){
        string temp;

        stringstream input(line);

        getline(input, temp, ',');
        astudent_.setStudentCode(temp);
        getline(input, temp, ',');
        astudent_.setStudentName(temp);
        getline(input, temp, ',');
        astudent_.setUcCode__(temp);
        getline(input, temp, ',');
        astudent_.setClassCode__(temp);
        aset_.insert(astudent_);
    }
    return aset_;
}

/**
 * @brief 
 * Retorna um set do tipo class Student com todos os estudantes, definidos pelo seu número UP e nome.
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro
 * @return vector<Student> 
 */
vector<Student> savestudents2(){
    Student astudent_;
    vector<Student> avector_;

    ifstream savestudents;
    savestudents.open("students_classes.csv");

    string line;
    getline(savestudents, line); // Passar primeira linha á frente

    while(getline(savestudents, line)){
        string temp;

        stringstream input(line);

        getline(input, temp, ',');
        astudent_.setStudentCode(temp);
        getline(input, temp, ',');
        astudent_.setStudentName(temp);
        getline(input, temp, ',');
        astudent_.setUcCode__(temp);
        getline(input, temp, ',');
        astudent_.setClassCode__(temp);
        avector_.push_back(astudent_);
    }
    return avector_;
}

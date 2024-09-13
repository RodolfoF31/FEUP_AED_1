/**
 * @file Student.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Student.h"

using namespace std;

/**
 * @brief Construct a new Student:: Student object
 * Construtor default
 */
Student::Student(){
    StudentCode = "";
    StudentName = "";
    UcCode = "";
    ClassCode = "";
}

/**
 * @brief Construct a new Student:: Student object
 * Construtor parametrizado 
 * @param StudentCode 
 * @param StudentName 
 * @param UcCode 
 * @param ClassCode 
 */
Student::Student(string StudentCode, string StudentName, string UcCode, string ClassCode){
    this->StudentCode = StudentCode;
    this->StudentName = StudentName;
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
}

/**
 * @brief 
 * Setter do objeto StudentCode
 * @param s 
 */
void Student::setStudentCode(string s){
    StudentCode = s;
}

/**
 * @brief 
 * Setter do objeto StudentName
 * @param s 
 */
void Student::setStudentName(string s){
    StudentName = s;
}

/**
 * @brief 
 * Setter do objeto UcCode
 * @param s 
 */
void Student::setUcCode__(string s){
    UcCode = s;
}

/**
 * @brief 
 * Setter do objeto ClassCode
 * @param s 
 */
void Student::setClassCode__(string s){
    ClassCode = s;
}

/**
 * @brief 
 * Getter do objeto StudentCode
 * @return string 
 */
string Student::get_StudentCode(){
    return StudentCode;
}

/**
 * @brief 
 * Getter do objeto StudentName
 * @return string 
 */
string Student::get_StudentName(){
    return StudentName;
}

/**
 * @brief 
 * Getter do objeto UcCode
 * @return string 
 */
string Student::get_UcCode(){
    return UcCode;
}

/**
 * @brief 
 * Getter do objeto ClassCode
 * @return string 
 */
string Student::get_ClassCode(){
    return ClassCode;
}
/**
 * @brief 
 * Operator overloader
 * @param p1 
 * @return true 
 * @return false 
 */
bool Student::operator<(const Student& p1) const{
    return StudentName < p1.StudentName;
}
/**
 * @brief 
 * Operator overloader
 * @param p1 
 * @return true 
 * @return false 
 */
bool Student::operator==(const Student& p1) const{
    return ((StudentCode == p1.StudentCode) && (UcCode == p1.UcCode));
}
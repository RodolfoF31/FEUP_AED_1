/**
 * @file Student.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;


class Student{
    private:
        string StudentCode;
        string StudentName;
        string UcCode;
        string ClassCode;
    public:
        /**
         * @brief Construct a new Student object
         * Construtor default
         */
        Student();
        /**
         * @brief Construct a new Student object
         * Construtor parametrizado
         * @param StudentCode 
         * @param StudentName 
         * @param UcCode 
         * @param ClassCode 
         */
        Student(string StudentCode, string StudentName, string UcCode, string ClassCode);

        /**
         * @brief 
         * Setter do objeto StudentCode
         * @param s 
         */
        void setStudentCode(string s);
        /**
         * @brief 
         * Setter do objeto StudentName
         * @param s 
         */
        void setStudentName(string s);
        /**
         * @brief
         * Setter do objeto UcCode
         * @param s 
         */
        void setUcCode__(string s);
        /**
         * @brief
         * Setter do objeto ClassCode
         * @param s 
         */
        void setClassCode__(string s);
        /**
         * @brief
         * Getter do objeto StudentCode
         * @return string 
         */
        string get_StudentCode();
        /**
         * @brief
         * Getter do objeto StudentName
         * @return string 
         */
        string get_StudentName();
        /**
         * @brief
         * Getter do objeto UcCode
         * @return string 
         */
        string get_UcCode();
        /**
         * @brief
         * Getter do objeto ClassCode
         * @return string 
         */
        string get_ClassCode();
        
        /**
         * @brief 
         * Operator overloader
         * @param p1 
         * @return true 
         * @return false 
         */
        bool operator<(const Student& p1) const;
        /**
         * @brief 
         * Operator overloader
         * @param p1 
         * @return true 
         * @return false 
         */
        bool operator==(const Student& p1) const;
};


#endif
/**
 * @file classes.h
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


class classes{
    private:
        string UcCode;
        string ClassCode;
        string Weekday;
        float StartHour;
        float Duration;
        string Type;
    public:
        /**
         * @brief
         * Construtor default
         */
        classes();
        /**
         * @brief
         * Construtor parametrizado
         * @param UcCode 
         * @param ClassCode 
         * @param Weekday 
         * @param StartHour 
         * @param Duration 
         * @param Type 
         */
        classes(string UcCode, string ClassCode, string Weekday, float StartHour, float Duration, string Type);

        /**
         * @brief
         * Setter do objeto ClassCode
         * @param s 
         */
    	void setClassCode_(string s);
        /**
         * @brief
         * Setter do objeto UcCode
         * @param s 
         */
        void setUcCode_(string s);
        /**
         * @brief
         * Setter do objeto Weekday
         * @param s 
         */
        void setWeekday(string s);
        /**
         * @brief
         * Setter do objeto StartHour
         * @param s 
         */
        void setStartHour(float s);
        /**
         * @brief
         * Setter do objeto Duration
         * @param s 
         */
        void setDuration(float s);
        /**
         * @brief
         * Setter do objeto Type
         * @param s 
         */
        void setType(string s);

        /**
         * @brief
         * Getter do objeto ClassCode
         * @return string 
         */
        string get_ClassCode_();
        /**
         * @brief
         * Getter do objeto UcCode
         * @return string 
         */
        string get_UcCode_();
        /**
         * @brief
         * Getter do objeto Weekday
         * @return string 
         */
        string get_Weekday();
        /**
         * @brief
         * Getter do objeto StartHour
         * @return float 
         */
        float get_StartHour();
        /**
         * @brief
         * Getter do objeto Duration
         * @return float 
         */
        float get_Duration();
        /**
         * @brief
         * Getter do objeto Type
         * @return string 
         */
        string get_Type();

};

#endif
/**
 * @file Classes.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "classes.h"
#include <string>

using namespace std;

/**
 * @brief
 * Construtor default
 */
classes::classes(){
    UcCode = "";
    ClassCode = "";
    Weekday = "";
    StartHour = 0;
    Duration = 0;
    Type = "";
}

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
classes::classes(string UcCode, string ClassCode, string Weekday, float StartHour, float Duration, string Type){
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
    this->Weekday = Weekday;
    this->StartHour = StartHour;
    this->Duration = Duration;
    this->Type = Type;
}

/**
 * @brief
 * Setter do objeto UcCode
 * @param s 
 */
void classes::setUcCode_(string s){
    UcCode = s;
}

/**
 * @brief
 * Setter do objeto ClassCode
 * @param s 
 */
void classes::setClassCode_(string s){
    ClassCode = s;
}

/**
 * @brief
 * Setter do objeto Weekday
 * @param s 
 */
void classes::setWeekday(string s){
    Weekday = s;
}

/**
 * @brief
 * Setter do objeto StartHour
 * @param s 
 */
void classes::setStartHour(float s){
    StartHour = s;
}

/**
 * @brief
 * Setter do objeto Duration
 * @param s 
 */
void classes::setDuration(float s){
    Duration = s;
}

/**
 * @brief
 * Setter do objeto Type
 * @param s 
 */
void classes::setType(string s){
    Type = s;
}

/**
 * @brief
 * Getter do objeto ClassCode
 * @return string 
 */
string classes::get_ClassCode_(){
    return ClassCode;
}

/**
 * @brief
 * Getter do objeto UcCode
 * @return string 
 */
string classes::get_UcCode_(){
    return UcCode;
}

/**
 * @brief 
 * Getter do objeto Weekday
 * @return string 
 */
string classes::get_Weekday(){
    return Weekday;
}

/**
 * @brief 
 * Getter do objeto StartHour
 * @return float 
 */
float classes::get_StartHour(){
    return StartHour;
}

/**
 * @brief 
 * Getter do objeto Duration
 * @return float 
 */
float classes::get_Duration(){
    return Duration;
}
/**
 * @brief 
 * Getter do objeto Type
 * @return string 
 */
string classes::get_Type(){
    return Type;
}

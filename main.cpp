/**
 * @file main.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Student.h"
#include "classes.h"
#include "projeto.cpp"
#include "SaveStudents.cpp"
#include "Request.h"
#include "Request.cpp"

using namespace std;

int main(){
    
    int studentswithmorethanNucs = 0;
    int numberofstudents = 0;
    int numberofucs;
    string cap;
    int numero;
    int numero2;
    int option;
    string studentcode;
    string UC;
    string classname;
    string classname2;
    vector<Student> vectorofstudents;
    queue<Request> requests_;
    vector<classes> avector;
    vector<string> somevector;
    list<Student> alist_;
    Request arequest;
    set<Student> aset_ = savestudents();
    vector<Student> avector_ = savestudents2();

    /**
     * @brief 
     * Opções do menu
     */
    do {
        cout << "----------------------------------" << endl;
        cout << "1 - Student's UCs" << endl;
        cout << "2 - Student's schedule" << endl;
        cout << "3 - Schedule change request" << endl;
        cout << "4 - Show students in a certain UC" << endl;
        cout << "5 - Show students in a certain class for an UC" << endl;
        cout << "6 - Show students with more than a number of UCs" << endl;
        cout << "7 - Quit" << endl;
        cout << "Select an option" << endl;
        cout << "----------------------------------" << endl;

        cin >> numero;

        switch(numero){
            case 1:
                cout << "Enter your student number: ";

                cin >> studentcode;

                vectorofstudents = studentsclasses(studentcode);

                if (vectorofstudents.size() == 0){
                    cout << "Student number invalid" << endl;
                }
                else{
                    string name = vectorofstudents[0].get_StudentName();
                    cout << "----------------------------------"  << endl;
                    cout << studentcode << " " << name << " classes are:" << endl;
                    cout << endl;
                    for (Student smth : vectorofstudents){
                        cout << smth.get_UcCode() <<  " : " << smth.get_ClassCode() << endl;
                    }
                }
                break;
            
            case 2:
                cout << "Enter your student number: ";

                cin >> studentcode;

                avector = schedule(studentcode);

                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Monday" << endl;


                for (classes smth : avector){
                    if (smth.get_Weekday() == "Monday"){
                        cout << " " << endl;
                        cout << time(smth.get_StartHour()) << " - " << time(smth.get_StartHour() + smth.get_Duration()) << endl;
                        cout << smth.get_UcCode_() << " | " << smth.get_ClassCode_() << " | " << smth.get_Type() << endl;
                    }
                }

                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Tuesday" << endl;

                for (classes smth : avector){
                    if (smth.get_Weekday() == "Tuesday"){
                        cout << endl;
                        cout << time(smth.get_StartHour()) << " - " << time(smth.get_StartHour() + smth.get_Duration()) << endl;
                        cout << smth.get_UcCode_() << " | " << smth.get_ClassCode_() << " | " << smth.get_Type() << endl;
                    }
                }

                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Wednesday" << endl;

                for (classes smth : avector){
                    if (smth.get_Weekday() == "Wednesday"){
                        cout << endl;
                        cout << time(smth.get_StartHour()) << " - " << time(smth.get_StartHour() + smth.get_Duration()) << endl;
                        cout << smth.get_UcCode_() << " | " << smth.get_ClassCode_() << " | " << smth.get_Type() << endl;
                    }
                }

                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Thursday" << endl;

                for (classes smth : avector){
                    if (smth.get_Weekday() == "Thursday"){
                        cout << endl;
                        cout << time(smth.get_StartHour()) << " - " << time(smth.get_StartHour() + smth.get_Duration()) << endl;
                        cout << smth.get_UcCode_() << " | " << smth.get_ClassCode_() << " | " << smth.get_Type() << endl;
                    }
                }

                cout << endl;
                cout << endl;
                cout << endl;
                cout << "Friday" << endl;

                for (classes smth : avector){
                    if (smth.get_Weekday() == "Friday"){
                        cout << endl;
                        cout << time(smth.get_StartHour()) << " - " << time(smth.get_StartHour() + smth.get_Duration()) << endl;
                        cout << smth.get_UcCode_() << " | " << smth.get_ClassCode_() << " | " << smth.get_Type() << endl;
                    }
                }

                cout << endl;
                cout << endl;
                cout << endl;

                break;
            
            case 3:
                cout << "----------------------------------" << endl;
                cout << "1 - Remove a student from a class" << endl;
                cout << "2 - Add a student to a class" << endl;
                cout << "3 - Swap classes" << endl;
                cout << "4 - Swap a group of classes" << endl;
                cout << "----------------------------------" << endl;

                cin >> numero;

                switch(numero){
                    case 1:
                        {
                        cout << "Enter your student number: ";

                        cin >> studentcode;

                        cout << "Enter the UC you would like to be removed: ";

                        cin >> UC;

                        cout << "Enter the class you would like to be removed: ";

                        cin >> classname;

                        vector<string> somevector = {studentcode, UC, classname};

                        arequest.setTipo("Remove");
                        arequest.setData(somevector);
                        requests_.push(arequest);

                        break;
                        }

                    case 2:
                        {
                        cout << "Enter your student number: ";

                        cin >> studentcode;

                        cout << "Enter the UC you would like to be added to: ";

                        cin >> UC;

                        cout << "Enter the class you would like to be added to: ";

                        cin >> classname;

                        cout << "Enter the maximum number of students in a class: ";

                        cin >> cap;

                        vector<string> somevector = {studentcode, UC, classname, cap};

                        arequest.setTipo("Add");
                        arequest.setData(somevector);
                        requests_.push(arequest);

                        break;
                        }
                    case 3:
                        {
                        cout << "Enter your student number: ";

                        cin >> studentcode;

                        cout << "Enter the UC you are in: ";

                        cin >> UC;

                        cout << "Enter the class you are in: ";

                        cin >> classname;

                        cout << "Enter the class you would like to be added to: ";

                        cin >> classname2;

                        cout << "Enter the maximum number of students in a class: ";

                        cin >> cap;

                        vector<string> somevector = {studentcode, UC, classname, classname2, cap};

                        arequest.setTipo("Change");
                        arequest.setData(somevector);
                        requests_.push(arequest);
                        break;
                        }
                    case 4:
                        {
                        do {
                            cout << "Enter your student number: ";

                            cin >> studentcode;

                            cout << "Enter the UC you are in: ";

                            cin >> UC;

                            cout << "Enter the class you are in: ";

                            cin >> classname;

                            cout << "Enter the class you would like to be added to: ";

                            cin >> classname2;

                            cout << "Enter the maximum number of students in a class: ";

                            cin >> cap;

                            vector<string> somevector = {studentcode, UC, classname, classname2, cap};

                            arequest.setTipo("Change");
                            arequest.setData(somevector);
                            requests_.push(arequest);
                            
                            cout << "----------------------------------------------------------------------" << endl;

                            cout << "Would you like to swap more classes? Press any key if yes, press 2 if not." << endl;
                            
                            cout << "----------------------------------------------------------------------" << endl;

                            cin >> numero2;

                        } while (numero2 != 2);
                        }

                }

                break;
            
            case 4:
                cout << "Enter the UC: ";

                cin >> UC;

                cout << endl;
                
                alist_ = getstudentsinuc(UC);

                if (alist_.size() == 0){

                    cout << "Please enter a valid UC" << endl;
                }

                else{

                    cout << "How would you like the list to be sorted?" << endl;
                    cout << "Options: 1- Sorted by name     2- Sorted by the student number" << endl;

                    cin >> option;

                    if (option == 1){
                        alist_.sort(NameComparator);
                        for (list<Student>::iterator it = alist_.begin(); it != alist_.end(); ++it){
                            numberofstudents++;
                            cout << it->get_StudentCode() << "  -  " << it->get_StudentName() << endl;
                        }
                    }
                    else{
                        alist_.sort(StudentNumberComparator);
                        for (list<Student>::iterator it = alist_.begin(); it != alist_.end(); ++it){
                            numberofstudents++;
                            cout << it->get_StudentCode() << "  -  " << it->get_StudentName() << endl;
                        }
                    }
                }
                    cout << endl;
                    cout << "This UC has " << numberofstudents << " students" << endl;
                    numberofstudents = 0;

                break;

            case 5:
                cout << "Enter the UC: ";

                cin >> UC;

                cout << "Enter the class: ";

                cin >> classname;

                cout << endl;

                alist_ = getstudentsinuc(UC);

                if (alist_.size() == 0){

                    cout << "Please enter a valid UC and class" << endl;
                }

                else{
                    cout << "How would you like the list to be sorted?" << endl;
                    cout << "Options: 1- Sorted by name     2- Sorted by the student number" << endl;

                    cin >> option;

                    cout << endl;
                    cout << endl;

                    if (option == 1){
                        alist_.sort(NameComparator);
                    }

                    else{
                        alist_.sort(StudentNumberComparator);
                    }

                    for (list<Student>::iterator it = alist_.begin(); it != alist_.end(); it++){
                        if (it->get_ClassCode() == classname){
                            numberofstudents++;
                            cout << it->get_StudentCode() << "  -  " << it->get_StudentName() << endl;
                        }
                    }
                    if (numberofstudents == 0){
                        cout << "Please enter a valid UC and class" << endl;
                        break;
                    }

                    else{
                        cout << endl;
                        cout << "This class has " << numberofstudents << " students" << endl;
                        numberofstudents = 0;
                    }
                }
                
                break;
            
            case 6:
                {
                cout << "Enter the number of UCs: " << endl;

                cin >> numberofucs;

                for (Student astudent : aset_){
                    vectorofstudents = studentsclasses(astudent.get_StudentCode());
                    if (vectorofstudents.size() > numberofucs){
                        studentswithmorethanNucs++;
                        cout << astudent.get_StudentCode() << " - " << astudent.get_StudentName() << endl;
                    }
                }
                cout << "There are " << studentswithmorethanNucs << " students with more than " << numberofucs << " UCs" << endl;
                studentswithmorethanNucs = 0;
                

                break;
                }

            case 7:
                
                break;
                
            default:
                cout << "Invalid selection, please try again." << endl;
        }

    } while (numero != 7);

    /**
     * @brief
     * Funçao do tipo void que processa todos os pedidos de mudança de horário
     */
    processtherequests(requests_, avector_);

    ofstream output;
    output.open("output.csv");
    
    sort(avector_.begin(), avector_.end(), NameComparator);

    /**
     * @brief
     * Novo ficheiro atualizado com os pedidos de mudança de horários
     * @param avector_ 
     */
    for (Student element : avector_) {
        output << element.get_StudentCode() << ',' << element.get_StudentName() << ',' << element.get_UcCode() << ',' << element.get_ClassCode() << endl; 
    }

    

    output.close();

    return 0;
}
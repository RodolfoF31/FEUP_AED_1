/**
 * @file projeto.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "func_auxiliares.cpp"
#include <queue>
#include "Request.h"

using namespace std;

/**
 * @brief 
 * Retorna uma lista do tipo class Student com todos os estudantes de uma unidade curricular, sendo o estudante caracterizado pelo seu número UP, nome e turma a que pertence..
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro.
 * @param uc É uma unidade curricular
 * @return list<Student> 
 */
list<Student> getstudentsinuc(string uc){
    Student somestudent;
    list<Student> alist;

    ifstream studentsinuc;
    studentsinuc.open("students_classes.csv");

    string line;
    getline(studentsinuc, line); // Passar à frente a primeira linha do ficheiro ("StudentCode,StudentName,UcCode,ClassCode")

    while (getline(studentsinuc, line)){
        string theuccode;
        string theclasscode;
        string thestudentcode;
        string thestudentname;

        stringstream input(line);

        getline(input, thestudentcode, ','); // Obter StudentCode
        getline(input, thestudentname, ','); // Obter StudentName
        getline(input, theuccode, ','); // Obter UcCode
        getline(input, theclasscode, ','); // Obter ClassCode
        if (uc == theuccode){
            somestudent.setStudentCode(thestudentcode);
            somestudent.setStudentName(thestudentname);
            somestudent.setClassCode__(theclasscode);
            alist.push_back(somestudent);
        }
    }
    return alist;
}

/**
 * @brief 
 * Retorna um vetor do tipo class Student com todas as UCs e turmas a que um estudante pertence, devolvendo também o seu nome, número UP, unidade curricular e turma.
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro.
 * @param studentnumber Número UP do estudante
 * @return vector<Student> 
 */
vector<Student> studentsclasses(string studentnumber){
    Student somestudent;
    vector<Student> a;

    ifstream students_classes;
    students_classes.open("students_classes.csv");

    string line;
    getline(students_classes, line); // Passar à frente a primeira linha do ficheiro ("StudentCode,StudentName,UcCode,ClassCode")

    while (getline(students_classes, line)){
        string temp;
        
        stringstream input(line);
        getline(input, temp, ','); // Obter StudentCode
        if (studentnumber == temp){
            somestudent.setStudentCode(temp);
            getline(input, temp, ','); // Obter StudentName
            somestudent.setStudentName(temp); // Guardar StudentName
            getline(input, temp, ','); // Obter UcCode
            somestudent.setUcCode__(temp); // Guardar UcCode
            getline(input, temp, ','); // Obter ClassCode
            somestudent.setClassCode__(temp); // Guardar ClassCode
            a.push_back(somestudent); // Meter no vetor "a" o conjunto UcCode, ClassCode, StudentCode e StudentName
        }
        else{
            continue;
        }
    }
    return a;
}

/**
 * @brief 
 * Retorna um vetor do tipo class classes com o horário do estudante. Cada elemento do vetor é constituido pela UC e turma a que o estudante pertence, dia da semana, hora de inicio da aula, a sua duração e também o tipo.
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro
 * @param studentnumber Número UP do estudante
 * @return vector<classes> 
 */
vector<classes> schedule(string studentnumber){
    classes someclass;
    vector<classes> alist;
    vector<Student> a = studentsclasses(studentnumber);
    
    ifstream classes;
    classes.open("classes.csv");

    string line;

    getline(classes, line); // Passar à frente a primeira linha do ficheiro ("ClassCode,UcCode,Weekday,StartHour,Duration,Type")

    while (getline(classes, line)){
        string temp_;
        string temp;
        string temp2;

        stringstream input(line);

        getline(input, temp, ','); // Obter ClassCode
        getline(input, temp2, ','); // Obter UcCode

        for (Student smth : a){
            if (smth.get_ClassCode() == temp && smth.get_UcCode() == temp2){
                someclass.setClassCode_(temp);
                someclass.setUcCode_(temp2);
                getline(input, temp_, ','); // Obter Weekday
                someclass.setWeekday(temp_);
                getline(input, temp_, ','); // Obter Starthour
                someclass.setStartHour(stof(temp_));
                getline(input, temp_, ','); // Obter Duration
                someclass.setDuration(stof(temp_));
                getline(input, temp_, ','); // Obter Type
                someclass.setType(temp_);
                alist.push_back(someclass);
            }
            else{
                continue;
            }
        }
    }
    sort(alist.begin(), alist.end(), FloatComparator);
    return alist;
}

/**
 * @brief 
 * Retorna o número de estudantes de uma certa turma de uma UC.
 * A complexidade é O(n) sendo "n" o tamanho da lista somelist.
 * @param UC Número UP do estudante
 * @param class_ Turma 
 * @return int 
 */
int CheckStudents(string UC, string class_){
    int numberofstudents = 0;
    list<Student> somelist = getstudentsinuc(UC);
    for (list<Student>::iterator it = somelist.begin(); it != somelist.end(); it++){
        if (it->get_ClassCode() == class_){
            numberofstudents++;
        }
    }
    return numberofstudents;
}

/**
 * @brief 
 * Retorna um vetor do tipo classe classes_per_uc com todas as turmas de uma certa unidade curricular.
 * A complexidade é O(n) sendo "n" o tamanho do ficheiro.
 * @param uc Unidade curricular.
 * @return vector<classes_per_uc> 
 */
vector<classes_per_uc> allclassesperuc(string uc){
    classes_per_uc allclassesinauc;
    vector<classes_per_uc> vector1;

    ifstream classesperuc;
    classesperuc.open("classes_per_uc.csv");

    string line;

    getline(classesperuc, line); // passar primeira linha á frente

    while(getline(classesperuc, line)){
        string temp;
        string temp2_;

        stringstream input(line);

        getline(input, temp, ','); // UcCode
        if (uc == temp){
            allclassesinauc.setUcCode(temp);
            getline(input, temp2_, ','); // ClassCode
            allclassesinauc.setClassCode(temp2_);
            allclassesinauc.setSize(CheckStudents(temp, temp2_));
            vector1.push_back(allclassesinauc);
        }
    }
    return vector1;
}



/**
 * @brief 
 * Função para processar todos os pedidos de mudança de horário.
 * @param requests_ Queue do tipo class Request com todos os pedidos de mudança de horários
 * @param avector_ Vetor do tipo Student com todos os estudantes
 */
void processtherequests(queue<Request>& requests_, vector<Student>& avector_){
    int numberofstudents;
    bool inclass = false;
    while (!requests_.empty()){

        Request temp = requests_.front();
        requests_.pop();

        string studentcode = temp.get_Data()[0];
        string UC = temp.get_Data()[1];
        string classname = temp.get_Data()[2];

        vector<Student> anothervector = studentsclasses(studentcode);

        if (temp.get_Tipo() == "Remove"){

            if (anothervector.empty()) {
                cout << "Please enter a valid student number, UC and class" << endl;
            }
            else {
                for (Student smth : anothervector){
                    if (smth.get_UcCode() == UC && smth.get_ClassCode() == classname){
                        inclass = true;
                    }
                }
            }
            if (!inclass) {
                cout << "The student does not belong to the UC or class" << endl;
            }
            else {
                Student aux = Student(studentcode, anothervector[0].get_StudentName(), UC, classname);
                remove(avector_.begin(), avector_.end(), aux);
                cout << "Successfully removed the student " << studentcode << "from the UC " << UC << "and class " << classname << endl;
            }
        }
        else if(temp.get_Tipo() == "Add"){

            bool InUc = false;
            for (Student e : anothervector){
                if (e.get_UcCode() == UC){
                    InUc = true;
                }
            }

            int cap = stoi(temp.get_Data()[3]);

            if (anothervector.empty()) {
                cout << "Please enter a valid student number" << endl;
            }
            else{
                int numerotemporario = 0;
                vector<classes_per_uc> vector1 = allclassesperuc(UC);

                for (classes_per_uc turma : vector1){
                    if (turma.get_ClassCode() == classname){
                        turma.setSize(turma.get_Size() + 1);
                        numerotemporario = turma.get_Size();
                    }
                }
                sort(vector1.begin(), vector1.end(), NumberofStudentsComparator);
                if ((vector1[vector1.size() - 1].get_Size() - vector1[0].get_Size() >= 4) || (numerotemporario > cap) || (InUc)){
                    cout << "It is not possible to add you to this class" << endl;
                    for (classes_per_uc turma : vector1){
                        if (turma.get_ClassCode() == classname){
                            turma.setSize(turma.get_Size() - 1);
                        }
                    }
                }
                else{
                    Student aux = Student(studentcode, anothervector[0].get_StudentName(), UC, classname);
                    avector_.push_back(aux);
                    cout << "Successfully added the student " << studentcode << "to the UC " << UC << "and class " << classname << endl;
                }
            }
        }
        else if(temp.get_Tipo() == "Change"){
            int cap = stoi(temp.get_Data()[4]);
            string classname2 = temp.get_Data()[3];
            if (anothervector.empty()) {
                cout << "Please enter a valid student number, UC and class" << endl;
            }
            else{
                int numerotemporario = 0;
                int numerotemporario2 = 0;
                vector<classes_per_uc> vector1 = allclassesperuc(UC);
                
                for (classes_per_uc turma : vector1){
                    if (turma.get_ClassCode() == classname){
                        turma.setSize(turma.get_Size() - 1);
                        numerotemporario = turma.get_Size();
                    }
                    else if (turma.get_ClassCode() == classname2){
                        turma.setSize(turma.get_Size() + 1);
                        numerotemporario2 = turma.get_Size();
                    }
                }
                sort(vector1.begin(), vector1.end(), NumberofStudentsComparator);
                if ((vector1[vector1.size() - 1].get_Size() - vector1[0].get_Size() >= 4) || (numerotemporario > cap) || (numerotemporario2 > cap)){
                    cout << "It is not possible to add you to this class" << endl;
                    for (classes_per_uc turma : vector1){
                        if (turma.get_ClassCode() == classname){
                            turma.setSize(turma.get_Size() + 1);
                        }
                        else if (turma.get_ClassCode() == classname2){
                            turma.setSize(turma.get_Size() - 1);
                        }
                    }
                }
                else{
                    Student aux = Student(studentcode, anothervector[0].get_StudentName(), UC, classname);
                    Student aux2 = Student(studentcode, anothervector[0].get_StudentName(), UC, classname2);
                    remove(avector_.begin(), avector_.end(), aux);
                    avector_.push_back(aux2);
                    cout << "Successfully swap classes of the student " << studentcode << "from the class " << classname << "to the class " << classname2 << endl;
                }
            }
        }
    }
}
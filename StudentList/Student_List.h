#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include<list>
#include<Windows.h>
using namespace std;

class Student_List
{
	string name;
	string surname;
	string group;
	string dateBirth;
	int course;

public:
	Student_List();
	Student_List(string name, string surname, string group, string dateBirth, int course);
	Student_List(const Student_List& obj);
	~Student_List();
	void setName(string name);
	void setSurname(string surname);
	void setGroup(string group);
	void setDateBirth(string dateBirth);
	void setCourse(int course);
	string getName();
	string getSurname();
	string getGroup();
	string getDateBirth();
	int getCourse();
	friend ostream& operator<<(ostream& out, Student_List& obj);
	bool operator<( Student_List& obj);
	void toFile(fstream &f);
	void fromFile(fstream &f);
};

class Univer {

	list<Student_List> students;
public:
	Univer();
	~Univer();
	void addStudent(Student_List& obj);
	void delStudent(list<Student_List>::iterator it);
	void sortSurname();// сортировка по фамилии
	void sortGroup();// сортировка по группе
	void sortCourse();// сортировка по курсу
	list<Student_List>::iterator searchStudent(string name, string surname);//поиск студента по имени и фамилии
	void searchGroup(string group);// поиск студентов по группе
	void searchCourse(int course); //поиск студентов по курсу
	void toFile();
	void fromFile();
	list<Student_List>* getStudents();// получение списка студентов (для того, что бы обратиться к нему в классе Group)
	friend ostream& operator<<(ostream& out, Univer& obj);


};

class Group {
	string name_group;
	list<Student_List> students2;
public:
	Group();
	Group(string name_group);
	~Group();
	void addStudentToGroup(Univer& obj);//добавление студента нужной группы из списка в классе Универ
	friend ostream& operator<<(ostream& out, Group& obj);
};

bool sort_surname(Student_List& obj1, Student_List& obj2);// функции для выбора сортировки в методе Sort(строки 127, 132, 137)
bool sort_group(Student_List& obj1, Student_List& obj2);
bool sort_course(Student_List& obj1, Student_List& obj2);

#include "Student_List.h"

Student_List::Student_List()
{
	course = 0;
}

Student_List::Student_List(string name, string surname, string group, string dateBirth, int course)
{
	this->name = name;
	this->surname = surname;
	this->group = group;
	this->dateBirth = dateBirth;
	this->course = course;
}

Student_List::Student_List(const Student_List& obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->group = obj.group;
	this->dateBirth = obj.dateBirth;
	this->course = obj.course;
}

Student_List::~Student_List()
{
}

void Student_List::setName(string name)
{
	this->name = name;
}

void Student_List::setSurname(string surname)
{
	this->surname = surname;
}

void Student_List::setGroup(string group)
{
	this->group = group;
}

void Student_List::setDateBirth(string dateBirth)
{
	this->dateBirth = dateBirth;
}

void Student_List::setCourse(int course)
{
	this->course = course;
}

string Student_List::getName()
{
	return name;
}

string Student_List::getSurname()
{
	return surname;
}

string Student_List::getGroup()
{
	return group;
}

string Student_List::getDateBirth()
{
	return dateBirth;
}

int Student_List::getCourse()
{
	return course;
}

bool Student_List::operator<(Student_List& obj)
{
	if (obj.getSurname() > this->getSurname())
		return true;
	else
		return false;
}

void Student_List::toFile(fstream &f)
{
	f << name << " "<< surname << " " << group << " " << dateBirth << " " << course<< " ";
}

void Student_List::fromFile(fstream &f)
{
	f>>name>> surname  >> group >> dateBirth >> course;
}

ostream& operator<<(ostream& out, Student_List& obj)
{
	out << "Имя: " << obj.name 
		<< "\nФамилия: " << obj.surname 
		<< "\nКурс: " 	<< obj.course 
		<< "\nДата рождения: "	<< obj.dateBirth
		<< "\nГруппа: "	<< obj.group <<endl;
	return out;
}

Univer::Univer()
{
}

Univer::~Univer()
{
	students.clear();
}

void Univer::addStudent(Student_List& obj)
{
	students.push_back(obj);
}

void Univer::delStudent(list<Student_List>::iterator it)
{
	students.erase(it);
}

void Univer::sortSurname()
{
	students.sort(sort_surname);
}

void Univer::sortGroup()
{
	students.sort(sort_group);
}

void Univer::sortCourse()
{
	students.sort(sort_course);
}

list<Student_List>::iterator Univer::searchStudent(string name, string surname)
{
	for (list<Student_List>::iterator iter = students.begin(); iter !=students.end(); iter++)
	{
		if ((*iter).getSurname() == surname && (*iter).getName() == name) {
			return iter;
		}
	}
	return students.end();
}

void Univer::toFile()
{
	fstream f("Student.txt", ios::app);
	for (list<Student_List>::iterator iter = students.begin(); iter != students.end(); iter++)
	{
		(*iter).toFile(f);
	}
	f.close();
}

void Univer::fromFile()
{
	fstream f("Student.txt", ios::in);
	while(!f.eof())
	{
		Student_List temp;
		temp.fromFile(f);
		students.push_back(temp);
	}
	f.close();
}

list<Student_List>* Univer::getStudents()
{
	return  &students;
}

void Univer::searchGroup(string group)
{
	for (list<Student_List>::iterator iter = students.begin(); iter !=students.end(); iter++)
	{
		if ((*iter).getGroup() == group)
			cout << (*iter);
	}
}

void Univer::searchCourse(int course)
{
	for (list<Student_List>::iterator iter = students.begin(); iter != students.end(); iter++)
	{
		if ((*iter).getCourse() == course)
			cout << (*iter);	
	}
}

ostream& operator<<(ostream& out, Univer& obj) {
	for (list<Student_List>::iterator iter = obj.students.begin(); iter != obj.students.end(); iter++)
		out << *iter << endl;
	return out;
}

bool sort_surname(Student_List& obj1, Student_List& obj2)
{
	return obj1.getSurname() < obj2.getSurname();
}

bool sort_group(Student_List& obj1, Student_List& obj2)
{
	return obj1.getGroup() < obj2.getGroup();;
}

bool sort_course(Student_List& obj1, Student_List& obj2)
{
	return obj1.getCourse() < obj2.getCourse();
}

Group::Group()
{
}

Group::Group(string name_group)
{
	this->name_group = name_group;
}

Group::~Group()
{
	students2.clear();
}

void Group::addStudentToGroup(Univer &obj)
{
	list<Student_List>::iterator iter1 = obj.getStudents()->begin();
	list<Student_List>::iterator it=students2.begin();
	for (iter1; iter1!= obj.getStudents()->end(); iter1++)
	{
		if(name_group== (*iter1).getGroup())
			students2.insert(it, (*iter1));
	}
}

ostream& operator<<(ostream& out, Group& obj)
{
	out << "Название группы: " << obj.name_group << endl;
	for (list<Student_List>::iterator iter = obj.students2.begin(); iter != obj.students2.end(); iter++)
		out << *iter << endl;
	return out;
}


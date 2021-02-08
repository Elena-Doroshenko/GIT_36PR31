#include "Student_List.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Student_List A("Иван","Иванов","36ПР31", "25.01.1990" ,2), B("Петр", "Петров", "36ПР32", "25.05.1995",1);
	//Student_List D("Андрей","Попов","36ЛГ32", "12.08.1988" ,2), R("Петр", "Петров", "36ПР32", "06.01.1974",1);
	//Student_List A, B;
	//D.toFile();
	//R.toFile();

	Univer X;

	//X.addStudent(D);
	//X.addStudent(R);
	//X.toFile();
	X.fromFile();
	Group A("36ЛГ32");
	A.addStudentToGroup(X);
	cout << A;
	//cout << (*X.searchStudent("Андрей", "Попов"));
	//X.searchGroup("36ПР32");
	return 0;
}
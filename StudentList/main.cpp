#include "Student_List.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Student_List A("����","������","36��31", "25.01.1990" ,2), B("����", "������", "36��32", "25.05.1995",1);
	//Student_List D("������","�����","36��32", "12.08.1988" ,2), R("����", "������", "36��32", "06.01.1974",1);
	//Student_List A, B;
	//D.toFile();
	//R.toFile();

	Univer X;

	//X.addStudent(D);
	//X.addStudent(R);
	//X.toFile();
	X.fromFile();
	Group A("36��32");
	A.addStudentToGroup(X);
	cout << A;
	//cout << (*X.searchStudent("������", "�����"));
	//X.searchGroup("36��32");
	return 0;
}
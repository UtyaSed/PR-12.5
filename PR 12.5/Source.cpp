#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	string info;
};

void push(Elem*& top, Info value);
string pop(Elem*& top);
void readTXT(Elem*& top);
void count(Elem* top);
void check(Elem* top, string element);
bool check_repeat(Elem* top, Elem* start, string element, Info l);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* top = NULL;
	readTXT(top);
	count(top);
	cout << endl << endl << endl;
	cout << "Stack: " << endl;
	while (top != NULL) {
		cout << pop(top) << " "; // ��������� �� ���� �� ����� �����
	}
	cout << endl;
}


void push(Elem*& top, string value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = top;
	top = tmp;
}

string pop(Elem*& top)
{
	Elem* tmp = top->link;
	string value = top->info;
	delete top;
	top = tmp;
	return value;
}

void readTXT(Elem*& top)
{
	ifstream f("symbols.txt"); // �������� ������ ���������� �����
	string element;
	if (!f.eof()) { // ������ �������
		f >> element;
		push(top, element);
	}
	while (!f.eof()) { // �� ���� ��������
		f >> element;
		push(top, element);
	}
}

void count(Elem* top) // ������� �������� � ��������
{
	Elem* start = top; // �������
	Info l = 0;
	string element = top->info;
	top = top->link;
	while (top->link != NULL) {
		if (check_repeat(top, start, element, l)) {
			check(top, element);
			element = top->info;
			top = top->link;
		}
		else {
			top = top->link;
			element = top->info;
		}
		l++;
	}
	if (check_repeat(top, start, element, l)) {
		check(top, element);
	}
}

void check(Elem* top, string element) { // �������� �������� �� ����������
	Elem* temp = top;
	Info k = 1;
	while (top->link != NULL) {
		if (element == top->info) {
			k++;
		}
		top = top->link;
	}
	if (element == top->info) { // ��� ���������� ��������
		k++;
	}
	top = temp;
	cout << element << " ����������� " << k << " ���;" << endl;
}

bool check_repeat(Elem* top, Elem* start, string element, Info l)  // �������� �� ����������
{
	Elem* temp = top;
	top = start; // ����������� �� �������
	for (Info i = 0; i < l; i++) {
		if (element == top->info) {
			top = temp;
			return false;
		}
		top = top->link; // ������� ���
	}
	top = temp;
	return true;
}
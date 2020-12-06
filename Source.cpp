#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANNYA };
string specialnistStr[] = { "��", "���", "���&����", "���&���", "����.����" };
struct Student
{
	string prizv;
	unsigned kurs;
	Specialnist specialnist;
	unsigned phisyka;
	unsigned matematyka;
	union
	{
		unsigned programuvannia;
		unsigned chiselni_metody;
		unsigned pedagogika;
	};
	
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Kilkist_otsinok(Student* p, const int N);
void Kilkist_studentiv(Student* p, const int N);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	Kilkist_otsinok(p, N);
	Kilkist_studentiv(p, N);
	return 0;
}
void Create(Student* p, const int N)
{
	int specialnist;

	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - ������� ��������):";
		cin >> specialnist;
		cout << " ������ � ������: "; cin >> p[i].phisyka;
		cout << "������ � ����������: "; cin >> p[i].matematyka;
		p[i].specialnist = Specialnist(specialnist);
		switch (p[i].specialnist)
		{
		case KOMPUTERNI_NAUKY:
			cout << " ������ � ������������� : "; cin >> p[i].programuvannia;
			break;
		case INFORMATYKA:
			cout << "������ � ��������� ������: "; cin >> p[i].chiselni_metody;
			break;
		case MATEMATYKA_TA_EKONOMIKA:
		case PHISYKA_TA_INFORMATYKA:
		case TRUDOVE_NAVCHANNYA:
			cout << " ������ � ����������� : "; cin >> p[i].pedagogika;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << p[i].prizv
			<< "| " << setw(2) << right << p[i].kurs << " "
			<< "| " << setw(15) << left << specialnistStr[p[i].specialnist]
			<< "| " << setw(6) << right << p[i].phisyka << " "
			<< "| " << setw(10) << left << p[i].matematyka << " ";
		switch (p[i].specialnist)
		{
		case KOMPUTERNI_NAUKY:
			cout << "| " << setw(13) <<right << p[i].programuvannia << " "<<"|"<<setw(14)<<"|"<<setw(13)<<"|";
			break;
		case INFORMATYKA:
			cout <<"|"<<setw(16)<<right<<fixed<<"|"<<setw(13)<<left<<p[i].chiselni_metody<<"|"<<setw(11)<<right<<" "<<" |";
			break;
		case MATEMATYKA_TA_EKONOMIKA:
		case PHISYKA_TA_INFORMATYKA:
		case TRUDOVE_NAVCHANNYA:
			cout<<"|"<<setw(17)<<right<<fixed<<"| "<<setw(12)<<left<<" "<< "| " << setw(11) << right << p[i].pedagogika << "|";
			break;
		}
		cout << endl;
	}
	cout << "========================================================================================================"
		<< endl;
	cout << endl;
}
void Kilkist_otsinok(Student* p, const int N)
{
	int k = 0;
	int m = 0;
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].phisyka == 5)
			k++;
		if (p[i].phisyka == 4)
			m++;
		if (p[i].phisyka == 3)
			t++;
	}
	cout << "������� ������ 5 � ������: " << k << endl;
	cout << "������� ������ 4 � ������: " << m << endl;
	cout << "������� ������ 3 � ������: " << t << endl;

}
void Kilkist_studentiv(Student* p, const int N)
{
	int a = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].phisyka == 4 || p[i].phisyka == 5) && (p[i].matematyka == 4 || p[i].matematyka == 5))
			a++;
	}
	cout << "������� ��������, �� � � ������, � � ���������� ����� ������ 4 ��� 5: " << a << endl;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANNYA };
string specialnistStr[] = { "КН", "інф", "мат&екон", "фіз&інф", "труд.навч" };
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
	cout << "Введіть N: "; cin >> N;
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
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - трудове навчання):";
		cin >> specialnist;
		cout << " оцінка з фізики: "; cin >> p[i].phisyka;
		cout << "оцінка з математики: "; cin >> p[i].matematyka;
		p[i].specialnist = Specialnist(specialnist);
		switch (p[i].specialnist)
		{
		case KOMPUTERNI_NAUKY:
			cout << " оцінка з програмування : "; cin >> p[i].programuvannia;
			break;
		case INFORMATYKA:
			cout << "оцінка з чисельних методів: "; cin >> p[i].chiselni_metody;
			break;
		case MATEMATYKA_TA_EKONOMIKA:
		case PHISYKA_TA_INFORMATYKA:
		case TRUDOVE_NAVCHANNYA:
			cout << " оцінка з педагогігики : "; cin >> p[i].pedagogika;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
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
	cout << "кількість оцінок 5 з фізики: " << k << endl;
	cout << "кількість оцінок 4 з фізики: " << m << endl;
	cout << "кількість оцінок 3 з фізики: " << t << endl;

}
void Kilkist_studentiv(Student* p, const int N)
{
	int a = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].phisyka == 4 || p[i].phisyka == 5) && (p[i].matematyka == 4 || p[i].matematyka == 5))
			a++;
	}
	cout << "кількість студентів, які і з фізики, і з математики мають оцінку 4 або 5: " << a << endl;
}

#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <istream>
#include <list>
#include <string>
#include <random>
#include <chrono>
#include <time.h>
#include <sstream>


using	std::cout;
using	std::cin;
using	std::endl;
using	std::setw;
using	std::setprecision;
using	std::fixed;
using	std::left;
using	std::right;
using	std::string;
using	std::vector;
using	std::ostream;
using	std::istream;
using	std::sort;
using	std::getline;
using	std::ifstream;
using	std::istringstream;

//#include "Header.h"

int option = 0;

class student {
	string id_name;
	string id_surname;
	vector<float>nd;
	float exam;
	float mean;
	float median;
	float gradeMean;
	float gradeMedian;
public:
	void Set_name(string a) {
		id_name = a;
	}
	string get_name() const {
		return id_name;
	}

	student() {
		id_surname = "no surname";
		id_name = "no name";
		vector<float>nd{ 0 };
		exam = 0;
		mean = 0;
		median = 0;
		gradeMean = 0;
		gradeMedian = 0;
	}
	student(string s_id_name, string s_id_surname, float s_gradeMean, float s_gradeMedian) {
		id_name = s_id_name;
		id_surname = s_id_surname;
		gradeMean = s_gradeMean;
		gradeMedian = s_gradeMedian;
	}

	student(string new_id_name, string new_id_surname, vector<float>new_nd, float new_exam) {
		id_name = new_id_name;
		id_surname = new_id_surname;
		nd = new_nd;
		exam = new_exam;

		/* setDataMean();
		 setDataMedian();
		 setDataGradeMean();
		 setDataGradeMedian();*/
	}

	student(const student& original) {
		id_name = original.id_name;
		id_surname = original.id_surname;
		nd = original.nd;
		exam = original.exam;
		gradeMean = original.gradeMean;
		gradeMedian = original.gradeMedian;
	}

	void setDataMean();
	void setDataMedian();
	float setDataGradeMean();
	float setDataGradeMedian();

	// Function test soliution
	// void printMean();
	// void printMedian();
	// void printAllMean();
	// void printAllMedian();

	friend istream& operator>>(istream& input, student& set_data) {

		set_data.setDataMean();
		set_data.setDataMedian();
		set_data.setDataGradeMean();
		set_data.setDataGradeMedian();

		//	Operator overlodet test solution
		//	cout << set_data.mean << endl;
		//	cout << set_data.median << endl;
		//	cout << set_data.gradeMean << "gradeMean"<<endl;
		//	cout << set_data.gradeMedian << "gradeMedian"<<endl;

		return input;
	}

	friend ostream& operator<<(ostream& output, const student& set_data) {
		if (option == 1) {
			output << fixed << setprecision(2) << setw(15) << left << set_data.id_name << "" << setw(15) << set_data.id_surname << setw(15) << "" << set_data.mean << endl;
		}
		if (option == 2) {
			output << fixed << setprecision(2) << setw(15) << left << set_data.id_name << "" << setw(15) << set_data.id_surname << "" << setw(35) << "" << set_data.median << endl;
		}
		if (option == 3) {
			output << fixed << setprecision(2) << setw(15) << left << set_data.id_name << "" << setw(15) << set_data.id_surname << setw(15) << "" << set_data.gradeMean << endl;
		}
		if (option == 4) {
			output << fixed << setprecision(2) << setw(15) << left << set_data.id_name << "" << setw(15) << set_data.id_surname << "" << setw(35) << "" << set_data.gradeMedian << endl;
		}
		if (option == 5)
		{
			output << fixed << setprecision(2) << setw(15) << left << set_data.id_name << setw(15) << set_data.id_surname << setw(15) << "" << set_data.gradeMean << setw(15) << "" << set_data.gradeMedian << endl;
		}
		return output;
	}
	~student() {};
};

int main()
{
	int rez;
	int ndqty;
	int count = 0;
	int mIndex = 1;
	float exTemp;
	char n = 'z';
	string s;
	string temp;
	string id_naTemp;
	string id_suTemp;
	vector<student> list;
	vector<float> nd;
	srand(time(NULL));

	
	cout << "                                                                       " << endl;
	cout << "                 Studentu pazymiu ivedimo programa		                " << endl;
	cout << "                                                                       " << endl;
		while ( mIndex !=0 )
	{
		cout << "               Ivesti duomenis / Pildyti							" << endl;

		cout << " 1. Ivesti studento duomenis;										" << endl;
		cout << " 2. Ivesti duomenis atsitiktiniam generavimui;						" << endl;
		cout << " 3. Ikelti duomenis is failo;										" << endl;
		cout << " 4. Duomenu spausdinimas											" << endl;
		cout << " 5. Panaikinti ivestus duomenis									" << endl;
		cout << " 0. Baigti darba.													" << endl;

		cout << "Iveskite pasirinkta numeri: ";
		cin >> mIndex;
		while (mIndex > 5 || mIndex < 0)
		{
			cout << "Tokio pasirinkimo nera, iveskite tinkama pasirinkimo numeri : ";
			cin >> mIndex;
		};
		if (mIndex == 0)
		{
			break;
		}
		system("CLS");
		if (mIndex != 5)
		{
			cout << "                                                                 " << endl;
			cout << "							Rezultatai                            " << endl;
			cout << "                                                                 " << endl;
			cout << " 1. Namu darbu iverciu vidurkis;                                 " << endl;
			cout << " 2. Namu darbu iverciu mediana;								  " << endl;
			cout << " 3. Galutinis ivertis remiantis vidurkiu;                        " << endl;
			cout << " 4. Galutinis ivertis remiantis medianu;                         " << endl;
			cout << " 5. Galutinius iverti remiantis vidurkiu ir medianu;			  " << endl;

			cout << "Pasirinkite numeri : ";
			cin >> option;
			while (option > 5 || option < 1)
			{
				cout << "Tokio pasirinkimo nera, iveskite tinkama pasirinkimo numeri : ";
				cin >> option;
			};
		}
		system("CLS");
		if (mIndex == 1)
		{
			count = 0;
			cout << "\nStudento vardas: ";
			cin >> id_naTemp;
			cout << "Studento pavarde: ";
			cin >> id_suTemp;
			while (n != 'n')
			{
				count++;
				cout << "Namu darbu kiekis :" << count << " Ivertinimas : ";
				cin >> rez;
				cout << "Testi duomenu ivedima (y / n) :";
				nd.push_back(rez);
				cin >> n;
			}
			n = 'z';
			cout << "\nEgzamino rezultatas: ";
			cin >> exTemp;

			//system("CLS");

			cout << "" << setw(5) << "Vardas" << setw(10) << "" << setw(4) << "Pavarde"
				<< setw(15) << "" << setw(10) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;

			student getObj(id_naTemp, id_suTemp, nd, exTemp);
			cin >> getObj;
			nd.clear();
			list.push_back(getObj);
			cout << getObj;
			getObj.~student();
			system("pause");
			system("CLS");
		}
		if (mIndex == 2)
		{
			count = 0;
			cout << "Duomenys is atsitiktiniu skaiciu nuo 0 iki 10: " << endl;
			cout << "\nNamu darbu kiekis: ";
			cin >> ndqty;
			id_naTemp = "Vardas(rnd)";
			id_suTemp = "Pavarde(rnd)";
			for (int i = 0; i < ndqty; i++)
			{
				count++;
				cout << "\n" << count << "" << setw(3) << ". Namu darbu ivertinimas : ";
				rez = rand() % 11;
				cout << rez;
				nd.push_back(rez);
			}
			exTemp = rand() % 11;

			cout << "\n\nEgzaminu rezultatai: ";
			cout << exTemp << endl << endl;

			//system("CLS");

			cout << "" << setw(5) << "Vardas" << setw(10) << "" << setw(4) << "Pavarde"
				<< setw(15) << "" << setw(10) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;


			student getObj(id_naTemp, id_suTemp, nd, exTemp);
			cin >> getObj;
			nd.clear();
			list.push_back(getObj);
			cout << getObj;
			getObj.~student();
			system("pause");
			system("CLS");
		}
		if (mIndex == 3)
		{
			system("CLS");
			cout << "" << setw(5) << "Vardas" << setw(10) << "" << setw(4) << "Pavarde" << setw(15) << "" << setw(10) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;


			ifstream ins("indata.txt");

			getline(ins, s);
			while (ins)
			{
				getline(ins, s);
				if (!ins) break;
				istringstream sts(s);
				sts >> id_naTemp >> id_suTemp;
				while (sts)
				{
					sts >> rez;
					nd.push_back(rez);
				}
				exTemp = nd.at(nd.size() - 1);
				nd.pop_back();

				student getObj(id_naTemp, id_suTemp, nd, exTemp);
				cin >> getObj;
				nd.clear();
				list.push_back(getObj);
				getObj.~student();
			}
			sort(list.begin(), list.end(),
				[](const student& x, student& y)
				{
					return x.get_name() < y.get_name();
				});
			for (int i = 0; i < list.size(); ++i)
			{
				cout << list.at(i);
			};
			system("pause");
			system("CLS");

		}
		if (mIndex == 4)
		{
			cout << "" << setw(5) << "Vardas" << setw(10) << "" << setw(4) << "Pavarde"
				<< setw(15) << "" << setw(10) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;
			sort(list.begin(), list.end(),
				[](const student& x, student& y)
				{
					return x.get_name() < y.get_name();
				});
			for (int i = 0; i < list.size(); ++i)
			{
				cout << list.at(i);
			};
			system("pause");
			system("CLS");
		}
		if (mIndex == 5) {
			list.clear();
			system("CLS");
			cout << "\n\tDuomenys sekmingai pasalinti" << endl << endl;
			system("pause");
			system("CLS");
		}
	}

	return 0;
};

void student::setDataMean() {
	mean = 0;
	float sum = 0;

	for (auto& a : nd) {
		sum = sum + a;
	}
	mean = sum / nd.size();
}

void student::setDataMedian() {

	median = 0;
	int size = nd.size();

	sort(nd.begin(), nd.end());

	if (size % 2 != 0) {
		median = nd.at(size / 2);
	}
	else {
		median = (nd.at(size / 2 - 1) + nd.at(size / 2)) / 2;
	}
}

float student::setDataGradeMean() {
	setDataMean();
	gradeMean = ((mean * 0.4) + (exam * 0.6));
	return gradeMean;
}
float student::setDataGradeMedian() {
	setDataMedian();
	gradeMedian = ((median * 0.4) + (exam * 0.6));
	return gradeMedian;
}

// Test void print solution 

//void student::printMean() {
//	setDataMean();
//	cout << id_surname << id_name << mean;
//}
//
//void student::printMedian() {
//	setDataMedian();
//	cout << id_surname << id_name << median;
//}
//
//void student::printAllMean() {
//	cout << "\n" << id_surname << endl;
//	cout << "\n" << id_name << endl;
//	cout << "\n" << gradeMean << endl;
//	cout << "\n" << gradeMedian << endl;
//}
//
//void student::printAllMedian() {
//	cout << id_surname << " / " << id_name << " / " << gradeMedian;
//}
/*
 * Copyright Mytthew (c) 2020. Copying and modifying not allowed.
 * Autor: Mateusz Domagała
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

// Korzystam z gotowych funkcji sprawdzająych, które Pan polecił.

bool spr_int(char *wsk_char) {
	int i = 0;
	if(wsk_char[0] == '-') i = 1;
	while(wsk_char[i]) {
		if(wsk_char[i] < '0' || wsk_char[i] > '9') return false;
		i++;
	}
	return true;
}

int czyt_int() {
	char text[100];
	while(true) {
		cin.getline(text, sizeof(text));
		if (!spr_int(text)) cout << "\nWprowadz ponownie: ";
		else break;
	}
	return atoi(text);
}

float celToKel(float st_cel) {
	return st_cel + 273.15;
}

float celToFahr(float st_cel) {
	return (st_cel * 1.8) + 32;
}

string display(int first, int last, int step) {
	for (int i = first; i <= last; i+=step) {
		cout << "\t"
		     << setw(3) << i << "    "
		     << setw(8) << setprecision(2) << celToKel(i) << "    "
		     << setw(6) << setprecision(1) << celToFahr(i) << endl;
	}
}

int main() {
	cout << "Podaj poczatek zakresu: " << endl;
	int first = czyt_int();
	cout << "Podaj koniec zakresu: " << endl;
	int last = czyt_int();
	cout << "Co ile przeliczac temperature?: " << endl;
	int step = czyt_int();
	if (step > (last - first) / 2) {
		cout << "Zbyt duza wartosc.";
		return 0;
	}
	cout << "\tT[st.C]  T[K]       T[st.F]" << endl;
	cout.setf(ios::fixed | ios::right);
	string result = display(first, last, step);
	string file;
	cout << "Podaj nazwe pliku: " << endl;
	cin >> file;
	ofstream output(file, ios_base::app);
	output.setf(ios::fixed | ios::right);
	for (int i = first; i <= last; i+=step) {
		output << "\t"
		     << setw(3) << i << "    "
		     << setw(8) << setprecision(2) << celToKel(i) << "    "
		     << setw(6) << setprecision(1) << celToFahr(i) << endl;
	}
	return 0;
}


#include <iostream>

using namespace std;

class Siec {
public:

	/**
	* Konstruktor
	*/
	Siec() {
		// Zerowanie wag
		for (int i = 0; i < 35; i++) {
			for (int j = 0; j < 35; j++) {
				table[i][j] = 0;
			}
		}
	}

	/**
	* Destruktor
	*/
	~Siec() {
	}

	/**
	* Funkcja wyznaczjaca wagi
	* @param int count Ilosc wzorcow
	* @param char** templateArray Tablica wzorcow
	*/
	void set(char templateArray[4][35]) {
		for (int i = 0; i < 35; i++) {
			for (int j = 0; j < 35; j++) {
				table[i][j] = 0;
				if (i != j) {
					for (int index = 0; index < 4; index++) {
						table[i][j] += templateArray[index][i] * templateArray[index][j];
					}
				}
			}
		}
	}

	/**
	* Funkcja wypisujaca wartosci wag
	*/
	void show() {
		for (int i = 0; i < 35; i++) {
			for (int j = 0; j < 35; j++) {
				cout << table[i][j];
			}
			cout << endl;
		}
	}

	/**
	* Funkcja wczytuje zaszumiona informacje
	* @param char _template[35] Zaszumiona informacja
	*/
	void run(char _template[35]) {
		cout << endl;
		cout << "Wczytane: " << endl;
		cout << endl;

		for (int i = 0; i < 35; i++) {
			if (i % 5 == 0)
				cout << endl;
			cout << ((_template[i] > 0) ? '#' : ' ');
		}

		cout << endl;
		cout << endl;
		cout << "Wynik dzialania sieci: " << endl;
		cout << endl;

		for (int i = 0; i < 35; i++) {
			if (i % 5 == 0)
				cout << endl;
			cout << ((countNet(i, _template) > 0) ? '#' : ' ');
		}
	}

private:

	// Tablica wag
	int table[35][35];

	/**
	* Funkcja zwracajaca wartosc Net dla wybranego neuronu
	* @param int neuronIndex Index neuronu
	* @param char _template[35] Zaszumiona informacja
	* @return int Wartosc Net
	*/
	int countNet(int neuronIndex, char _template[35]) {
		int answer = 0;
		for (int i = 0; i < 35; i++) {
			answer += table[neuronIndex][i] * _template[i];
		}
		return answer;
	}
};

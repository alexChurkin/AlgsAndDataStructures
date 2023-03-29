#pragma once
#include <string>
typedef unsigned int uint32;

using namespace std;

class TBitField {

private:
	unsigned int* mem;
	int size;

	/*
	   Принимает: номер элемента подмножества k
	   Возвращает: номер элемента массива i, в котором он хранится

	   sizeof(*mem) = sizeof(uint32) = 4

	   sizeof(*mem) возвращает размер int в байтах; умножаем на 4
	   для получения размера в битах.
	*/
	int GetNumberMem(int k) {
		return (k - 1) / (8 * sizeof(*mem));
	}

	/*
	   Принимает: номер элемента подмножества k
	   Возвращает: номер бита в элементе массива, в котором он хранится
	*/
	int GetBit(int k) {
		return (k - 1) % (8 * sizeof(*mem));
	}

public:
	//Конструктор (принимает размер USize, а не кол-во mem-ов!)
	TBitField(int n = 0) {
		size = n / (8 * sizeof(*mem)) + 1;
		mem = new uint32[size];
		for (int i = 0; i < size; i++) {
			mem[i] = 0;
		}
	}

	//Деструктор
	~TBitField() {
		delete[] mem;
	}

	//Конструктор копирования
	TBitField(const TBitField& tmp) {
		size = tmp.size;
		mem = new uint32[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}

	//Оператор присваивания
	TBitField& operator=(TBitField tmp) {
		if (size != tmp.size) {
			delete[] mem;
			size = tmp.size;
			mem = new uint32[size];
		}

		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	/* ............................................... */

	void Add(int k) {
		int i = GetNumberMem(k);
		mem[i] = mem[i] | (1 << GetBit(k));
	}

	string ToString(int U, string sep = ",") {
		string str;

		//--> Идёт по mem[i]-м элементам
		for (int i = 0; i < size; i++) {
			//<-- Идёт по битам внутри mem[i]-го эл-та
			for (int j = 0; j < 8 * sizeof(*mem); j++) {
				if ((mem[i] & (1 << j)) > 0) {
					int k = i * (8 * sizeof(*mem)) + j + 1;

					if (k <= U) {
						str += (to_string(k) + sep);
					}
				}
			}
		}
		if (str.size() >= 2) {
			str = str.substr(0, str.size() - sep.length());
		}
		return str;
	}

	TBitField operatorV(const TBitField& tmp) {
		//size должен снова стать n, чтобы всё работало верно!
		TBitField res((8 * sizeof(*mem)) * (size - 1));

		for (int i = 0; i < size; i++) {
			res.mem[i] = mem[i] | tmp.mem[i];
		}
		return res;
	}

	TBitField operatorv(const TBitField& tmp) {
		TBitField res((8 * sizeof(*mem)) * (size - 1));

		for (int i = 0; i < size; i++) {
			res.mem[i] = mem[i] & tmp.mem[i];
		}
		return res;
	}

	TBitField operator~() {
		TBitField res((8 * sizeof(*mem)) * (size - 1));

		for (int i = 0; i < size; i++) {
			res.mem[i] = ~mem[i];
		}
		return res;
	}
};
#pragma once
#include "TBitField.h"

class TSet {
private:
	int USize;
	TBitField tb;

	//Считывает строку и добавляет числа, содержащиеся в ней, в массив w (mem)
	//str - строка, seps - набор разделителей, w - итоговый массив слов (строк)
	void StringToWords(string str, string seps, int& k, string* w) {
		k = 0;
		w[0] = "";
		str += " ";

		for (int i = 0; i < str.length(); i++) {
			//Ищем символ из str в seps
			//find выдаёт номер позиции, где он найден, или -1
			if (seps.find(str[i]) == -1) {
				w[k] += str[i];
			}
			else {
				if (w[k].length() > 0) {
					w[++k] = "";
				}
			}
		}
	}

	/*Собственный метод
	void ReadStringToTBitField(string str) {
		for (int i = 0; i < str.size(); i++) {
			//Найден символ - цифра.
			if (isdigit(str[i])) {
				//Найдём правую границу j (конец строки либо запятая, если есть)
				int j = i;
				if (j == str.size() - 1) {
					uint32 k = str[j] - '0';
					if(k >= 1 && k <= USize)
						tb.Add(k);
					break;
				}

				while (j < str.size() && isdigit(str[j])) j++;

				//Здесь j - правая граница (нужное число в диапазоне [i; j])
				string nStr = str.substr(i, (uint32) j - i);
				uint32 k = stol(nStr);

				if (k >= 1 && k <= USize)
					tb.Add(k);

				//Переход к считыванию следующего числа в строке
				i = j;
			}
		}
	}*/

public:
	TSet(int USize = 0, string str = "") {
		this->USize = USize;
		tb = TBitField(USize);
		string* w;
		w = new string[str.length() + 2];
		int k;

		StringToWords(str, ", ", k, w);
		for (int i = 0; i < k; i++) {
			int n = stoi(w[i]);
			if (n >= 1 && n <= USize) {
				tb.Add(n);
			}
		}
	}

	TSet(const TSet& tmp) {
		USize = tmp.USize;
		tb = tmp.tb;
	}

	TSet& operator=(const TSet& tmp) {
		if (USize != tmp.USize) {
			USize = tmp.USize;
		}
		tb = tmp.tb;
		return *this;
	}

	~TSet() {
	}

	/* ............................................... */

	void Add(int k) {
		if (k >= 0 && k <= USize) {
			tb.Add(k);
		}
	}

	string TSetToString(string sep = ",") {
		return tb.ToString(USize, sep);
	}

	TSet operatorV(const TSet& tmp) {
		if (tmp.USize != USize) {
			throw "USize should be equal";
		}

		TSet res(USize);
		res.tb = tb.operatorV(tmp.tb);
		return res;
	}

	TSet operatorv(const TSet& tmp) {
		if (tmp.USize != USize) {
			throw "USize should be equal";
		}

		TSet res(USize);
		res.tb = tb.operatorv(tmp.tb);
		return res;
	}

	TSet operator~() {
		TSet res(USize);
		res.tb = tb.operator~();
		return res;
	}
};
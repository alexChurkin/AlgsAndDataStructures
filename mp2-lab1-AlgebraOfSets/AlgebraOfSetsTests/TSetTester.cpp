#include "pch.h"
#include "CppUnitTest.h"
#include "TestExtensions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define private public
#include "../AlgebraOfSets/TSet.h"

namespace AlgebraOfSetsTests
{
	TEST_CLASS(TSetTester)
	{
	public:

		TEST_METHOD(Test_Constructors) {
			LogLine("Testing constructors:\n");

			TSet A(33);
			A.Add(1);
			A.Add(32);

			LogLine("> A(33) = {1, 32}: " + A.TSetToString());

			TSet B(A);
			B.Add(2);

			LogLine("> B(A) + 2: " + B.TSetToString());

			TSet C;
			C = B;

			LogLine("> C = B: " + C.TSetToString());

			//.......

			Log("> D(12, \"11, 12\"):   ");
			TSet D(12, "11, 12");
			LogLine(A.TSetToString());


			Log("> E(120, \",,,3 ,,, 14 18 15,19 120,     119    \"):   ");
			TSet E(120, ",,,3 ,,, 14 18 15,19 120,     119    ");
			LogLine(B.TSetToString());

			Log("> F(100, \"1, 16, 2,100, 11\"):   ");
			TSet F(100, "1, 16, 2,100, 11");
			LogLine(F.TSetToString() + "\n");

			LogLine("\nConstructors work fine!");
		}

		TEST_METHOD(Test_Add) {
			LogLine("Testing Add:\n");

			//A
			LogLine("TSet A(68) full:");
			TSet A(68);
			for (int i = 1; i <= 68; i++) {
				A.Add(i);
			}
			LogLine(A.TSetToString(", ") + "\n");

			//B
			LogLine("TSet B(67) only 1...16, 32, 64, 65:");
			TSet B(67);
			for (int i = 1; i <= 16; i++) {
				B.Add(i);
			}
			B.Add(32);
			B.Add(64);
			B.Add(65);
			LogLine(B.TSetToString(", ") + "\n");

			//C
			LogLine("TSet C(17) only 12 and 16:");
			TSet C(17);
			C.Add(12);
			C.Add(16);
			LogLine(C.TSetToString(", ") + "\n");

			LogLine("Add works fine!");
		}

		TEST_METHOD(Test_Operations) {
			LogLine("Testing operations:\n");

			TSet A(33), B(33);

			LogLine("TSet A(33), B(33)");
			LogLine("A = {3, 9, 7}; B = {4, 3, 2, 6}\n");

			A.Add(3);
			A.Add(9);
			A.Add(7);

			B.Add(4);
			B.Add(3);
			B.Add(2);
			B.Add(6);

			LogLine("TSet C = { A U B elements }: ");
			TSet C = A.operatorV(B);
			LogLine(C.TSetToString(", ") + "\n");

			LogLine("TBitField D = { AB elements }: ");
			TSet D = A.operatorv(B);
			LogLine(D.TSetToString(", ") + "\n");

			LogLine("TBitField E = { ~A elements }: ");
			TSet E = ~A;
			LogLine(E.TSetToString(", ") + "\n");

			LogLine("Operations work fine!");
		}

		TEST_METHOD(Test_StringToWordss) {
			LogLine("Testing StringToWords:");

			string str = "1, 23, 34,1    , 22";
			string* w = new string[str.length() + 2];
			int k;
			TSet t;
			t.StringToWords(str, ", ", k, w);

			for (int i = 0; i < k; i++) {
				LogLine(w[i] + "\n");
			}

			LogLine("StringToWords works fine!");
		}
	};
}
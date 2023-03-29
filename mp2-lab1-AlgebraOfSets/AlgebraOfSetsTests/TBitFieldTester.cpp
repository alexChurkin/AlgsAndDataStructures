#include "pch.h"
#include "CppUnitTest.h"
#include "TestExtensions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define private public
#include "../AlgebraOfSets/TBitField.h"

namespace AlgebraOfSetsTests
{
	TEST_CLASS(TBitFieldTester)
	{
	public:

		TEST_METHOD(Test_Constructors) {
			LogLine("Testing constructors:\n");

			int USize = 230;

			LogLine("TBitField A(230) = {11, 13}: ");
			TBitField A(USize);
			A.Add(11);
			A.Add(13);
			LogLine(A.ToString(230) + "\n");

			LogLine("TBitField B(A); B.Add(15): ");
			TBitField B(A);
			B.Add(15);
			LogLine(B.ToString(230) + "\n");


			LogLine("TBitField C = A; C.Add(128): ");
			TBitField C;
			C = A;
			C.Add(128);
			LogLine(C.ToString(230) + "\n");

			LogLine("Constructors work fine!");
		}

		TEST_METHOD(Test_GetNumberMem)
		{
			TBitField A(64);

			LogLine("Testing GetNumberMem:\n");

			for (int i = 1; i <= 32; i++) {
				Assert::IsTrue(A.GetNumberMem(i) == 0);
			}
			LogLine("Numbers from 1 to 32 are in mem[0]");

			for (int i = 33; i <= 64; i++) {
				Assert::IsTrue(A.GetNumberMem(i) == 1);
			}
			LogLine("Numbers from 33 to 64 are in mem[1]");

			for (int i = 65; i <= 96; i++) {
				Assert::IsTrue(A.GetNumberMem(i) == 2);
			}
			LogLine("Numbers from 65 to 96 are in mem[2]");

			for (int i = 97; i <= 128; i++) {
				Assert::IsTrue(A.GetNumberMem(i) == 3);
			}
			LogLine("Numbers from 97 to 128 are in mem[3]\n");

			LogLine("GetNumberMem works fine!");
		}

		TEST_METHOD(Test_GetBit) {
			TBitField A(64);

			LogLine("Testing GetBit:\n");

			for (int i = 1; i <= 32; i++) {
				Assert::IsTrue(A.GetBit(i) == i - 1);
			}
			LogLine("Numbers [1, 32] are in [0, 31] bit");

			for (int i = 33; i <= 64; i++) {
				Assert::IsTrue(A.GetBit(i) == i - 33);
			}
			LogLine("Numbers [33, 64] are in [0, 31] bit\n");

			LogLine("GetBit works fine!");
		}

		TEST_METHOD(Test_Add) {
			LogLine("Testing Add:\n");

			//A
			LogLine("TBitField A(68) full:");
			TBitField A(68);
			for (int i = 1; i <= 68; i++) {
				A.Add(i);
			}
			LogLine(A.ToString(68) + "\n");

			//B
			LogLine("TBitField B(67) only 1...16, 32, 64, 65:");
			TBitField B(67);
			for (int i = 1; i <= 16; i++) {
				B.Add(i);
			}
			B.Add(32);
			B.Add(64);
			B.Add(65);
			LogLine(B.ToString(67) + "\n");


			//C
			LogLine("TBitField C(17) only 12 and 16:");
			TBitField C(17);
			C.Add(12);
			C.Add(16);
			LogLine(C.ToString(17) + "\n");

			LogLine("Add works fine!");
		}

		TEST_METHOD(Test_Operaions) {
			LogLine("Testing operations:\n");

			TBitField A(33), B(33);

			LogLine("TBitField A(33), B(33)");
			LogLine("A = {3, 9, 7}; B = {4, 3, 2, 6}\n");

			A.Add(3);
			A.Add(9);
			A.Add(7);

			B.Add(4);
			B.Add(3);
			B.Add(2);
			B.Add(6);

			LogLine("TBitField C = { A U B elements }: ");
			TBitField C = A.operatorV(B);
			LogLine(C.ToString(10) + "\n");

			LogLine("TBitField D = { AB elements }: ");
			TBitField D = A.operatorv(B);
			LogLine(D.ToString(10) + "\n");

			LogLine("TBitField E = { ~A elements }: ");
			TBitField E = ~A;
			LogLine(E.ToString(10) + "\n");

			LogLine("Operations work fine!");
		}
	};
}

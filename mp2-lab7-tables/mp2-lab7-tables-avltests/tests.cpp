#include "pch.h"
#include "..\mp2-lab7-tables\TBalTreeTable.h"
#include "..\mp2-lab7-tables\Randomex.h"

/*
��������� ��������� ������� � 3000 ������� � ��������
�� ����������� ���� ����������� �������.
*/
TEST(TBalTreeTable, MassInsertion_IsCorrect)
{
	TBalTreeTable t;
	std::set<TKey> keys;

	for (int i = 0; i < 3000;)
	{
		TKey randKey = Randomex::RandInt(0, 4000);

		if (std::find(
			keys.begin(),
			keys.end(),
			randKey) == keys.end())
		{
			TRecord newRec = TRecord(randKey, "value" + std::to_string(randKey));

			keys.insert(newRec.key);
			t.Insert(newRec);
			std::cout << newRec.key << " inserted\n";
			ASSERT_TRUE(t.Find((newRec).key));
			i++;
		}
	}

	for (auto key : keys)
		ASSERT_TRUE(t.Find(key));

	t.Print(std::cout);
}

/*
��������� ��������� ������� � 4000 �������, �������� 2000 �� ���.
�������� �� ���������� ���� �������� ������� � �������
� ����������� ���� �� ��������.
*/
TEST(TBalTreeTable, MassDeletion_IsCorrect)
{
	TBalTreeTable t;
	std::set<TKey> keys;

	for (int i = 0; i < 4000;)
	{
		TKey randKey = Randomex::RandInt(0, 5000);

		if (std::find(
			keys.begin(),
			keys.end(),
			randKey) == keys.end())
		{
			TRecord newRec = TRecord(randKey, "value" + std::to_string(randKey));

			keys.insert(newRec.key);
			t.Insert(newRec);
			std::cout << newRec.key << " inserted\n";
			ASSERT_TRUE(t.Find((newRec).key));
			i++;
		}
	}

	std::cout << "Generated tree:\n";
	t.Print(std::cout);

	for (int i = 0; i < 2000;)
	{
		TKey randKey = Randomex::RandInt(0, 5000);

		//���� ������ � ������ randKey ����������� � ������ �����
		if (std::find(
			keys.begin(),
			keys.end(),
			randKey) != keys.end())
		{
			keys.erase(randKey);
			t.Delete(randKey);
			std::cout << randKey << " deleted\n";
			ASSERT_TRUE(!t.Find((randKey)));
			i++;
		}
	}

	for (auto key : keys)
		ASSERT_TRUE(t.Find((key)));

	std::cout << "Updated tree:\n";
	t.Print(std::cout);
}

/*
��������� ��������� 50 ������ �� 20 �������,
����� �� �������� � ��������� �� ������������.
*/
TEST(TBalTreeTable, MassDeletion2_IsCorrect)
{
	for (int i = 0; i < 50; i++)
	{
		TBalTreeTable t;

		for (int j = 0; j < 20;)
		{
			TKey randKey = Randomex::RandInt(0, 40);

			TRecord newRec = TRecord(randKey, "value" + std::to_string(randKey));
			bool result = t.Insert(newRec);
			if (result) j++;
		}

		std::cout << ">>> Generated tree " << (i + 1) << "\n";
		t.Print(std::cout);

		for (int j = 0; j < 20;)
		{
			TKey randKey = Randomex::RandInt(0, 40);

			bool result = t.Delete(randKey);

			if (result)
			{
				std::cout << randKey << " deleted\n";
				std::cout << "Updated tree " << i << ":" << "\n";
				t.Print(std::cout);
				std::cout << '\n';
				j++;
			}
		}
	}
}

/*
���������� ������� ��������� �� 1 �� 100 � ����� �������� ��������� ������.
��������� � ������������������ �������
*/
TEST(TBalTree, Insertion_1_100)
{
	TTreeTable t;
	TBalTreeTable bt;

	for (int i = 0; i < 100; i++)
	{
		t.Insert(i + 1);
		bt.Insert(i + 1);
	}

	std::cout << "TTreeTable: \n";
	t.Print(std::cout);
	std::cout << "\n\n";

	std::cout << "TBalTreeTable: \n";
	bt.Print(std::cout);
	std::cout << '\n';
}
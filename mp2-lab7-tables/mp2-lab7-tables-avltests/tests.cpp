#include "pch.h"
#include "..\mp2-lab7-tables\TBalTreeTable.h"
#include "..\mp2-lab7-tables\Randomex.h"

/*
—лучайна€ генераци€ таблицы с 3000 записей и проверка
на присутствие всех добавленных записей.
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
—лучайна€ генераци€ таблицы с 4000 записей, удаление 2000 из них.
ѕроверка на отсутствие всех удалЄнных записей в таблице
и присутствие всех не удалЄнных.
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

		//≈сли запись с ключом randKey добавл€лась в дерево ранее
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
—лучайна€ генераци€ 50 таблиц по 20 записей,
затем их удаление с проверкой на балансировку.
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
ƒобавление таблицу элементов от 1 до 100 и вывод конечной структуры дерева.
—равнение с несбалансированным деревом
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
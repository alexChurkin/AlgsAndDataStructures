#include "pch.h"
#include <iostream>
#include "..\mp2-lab4-queue\TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-10));
}

TEST(TQueue, cant_create_queue_with_zero_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(0));
}

TEST(TQueue, cant_create_one_element_queue)
{
	ASSERT_ANY_THROW(TQueue<int> q(1));
}

TEST(TQueue, new_created_queue_is_empty)
{
	TQueue<int> q(5);
	ASSERT_TRUE(q.IsEmpty());
	ASSERT_FALSE(q.IsNotEmpty());
}

TEST(TQueue, new_created_queue_is_not_full)
{
	TQueue<int> q(5);
	ASSERT_FALSE(q.IsFull());
	ASSERT_TRUE(q.IsNotFull());
}

TEST(TQueue, full_queue_is_not_empty)
{
	TQueue<int> q(3);
	q.Push(1); q.Push(2); q.Push(3);

	ASSERT_FALSE(q.IsEmpty());
	ASSERT_TRUE(q.IsNotEmpty());
}

TEST(TQueue, full_queue_is_full)
{
	TQueue<int> q(3);
	q.Push(1); q.Push(2); q.Push(3);

	ASSERT_TRUE(q.IsFull());
	ASSERT_FALSE(q.IsNotFull());
}

TEST(TQueue, not_empty_queue_is_not_empty)
{
	TQueue<int> q(3);
	q.Push(1); q.Push(2);

	ASSERT_FALSE(q.IsEmpty());
	ASSERT_TRUE(q.IsNotEmpty());
}

TEST(TQueue, not_empty_queue_is_not_full)
{
	TQueue<int> q(3);
	q.Push(1); q.Push(2);

	ASSERT_FALSE(q.IsFull());
	ASSERT_TRUE(q.IsNotFull());
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(TQueue<int> copy = q);
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	int size = 5;

	TQueue<int> q(size);
	for (int i = 0; i < size; i++)
		q.Push(i + 1);

	TQueue<int> copy = q;

	EXPECT_EQ(copy, q);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	int size = 5;

	TQueue<int> q(size);
	for (int i = 0; i < size; i++)
		q.Push(i + 1);

	TQueue<int> copy = q;
	copy.Clear();
	for (int i = 0; i < size; i++)
		copy.Push(i + 2);

	for (int i = 0; i < size; i++)
		EXPECT_NE(q.Pop(), copy.Pop());
}

TEST(TQueue, can_assign_queues_of_equal_sizes)
{
	int size = 5;

	TQueue<int> q1(size);
	for (int i = 0; i < size; i++)
		q1.Push(i + 1);

	TQueue<int> q2(size);
	q2 = q1;
	
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queues_of_different_sizes)
{
	int size = 5;

	TQueue<int> q1(size);
	for (int i = 0; i < size; i++)
		q1.Push(i + 1);

	TQueue<int> q2(size + 5);
	q2 = q1;

	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q(10);
	for (int i = 0; i < 10; i++)
		q.Push(i + 1);

	q = q;

	EXPECT_EQ(q, q);
}

TEST(TQueue, equal_queues_comparison_returns_true)
{
	TQueue<int> q1(10);
	for (int i = 0; i < 10; i++)
		q1.Push(i + 1);

	TQueue<int> q2(10);
	for (int i = 0; i < 10; i++)
		q2.Push(i + 1);

	EXPECT_EQ(q1, q2);
}

TEST(TQueue, unequal_queues_comparison_returns_false)
{
	TQueue<int> q1(10);
	for (int i = 0; i < 10; i++)
		q1.Push(i + 1);

	TQueue<int> q2(10);
	for (int i = 0; i < 10; i++)
		q2.Push(i + 2);

	EXPECT_NE(q1, q2);
}

TEST(TQueue, queues_with_different_maxsizes_are_not_equal)
{
	TQueue<int> q1(10);
	TQueue<int> q2(20);

	EXPECT_NE(q1, q2);
}

TEST(TQueue, can_push_and_pop_single)
{
	TQueue<double> q(5);
	double number = 1.23;
	double popped;

	ASSERT_NO_THROW(q.Push(number));
	ASSERT_NO_THROW(popped = q.Pop());
	EXPECT_EQ(popped, number);
}

TEST(TQueue, can_push_and_pop_three)
{
	TQueue<double> q(5);
	double n1 = 1.23;
	double n2 = 4.56;
	double n3 = 7.89;

	ASSERT_NO_THROW(q.Push(n1));
	ASSERT_NO_THROW(q.Push(n2));
	ASSERT_NO_THROW(q.Push(n3));

	EXPECT_EQ(q.Pop(), n1);
	EXPECT_EQ(q.Pop(), n2);
	EXPECT_EQ(q.Pop(), n3);
}

TEST(TQueue, queue_is_looped)
{
	TQueue<double> q(3);

	q.Push(1);
	std::cout << q << '\n';
	EXPECT_EQ(q.Pop(), 1);
	std::cout << q << '\n';

	q.Push(2); q.Push(3);
	std::cout << q << '\n';
	EXPECT_EQ(q.Pop(), 2);
	std::cout << q << '\n';

	q.Push(4); q.Push(5);
	std::cout << q << '\n';
	EXPECT_EQ(q.Pop(), 3);
	std::cout << q << '\n';

	q.Push(6);
	std::cout << q << '\n';
	EXPECT_EQ(q.Pop(), 4);
	std::cout << q << '\n';

	q.Push(7);
	std::cout << q << '\n';
	EXPECT_EQ(q.Pop(), 5);
	std::cout << q << '\n';

	q.Push(8);
	std::cout << q << '\n';
}

TEST(TQueue, cant_push_to_a_full_queue)
{
	int size = 5;
	TQueue<int> q(size);
	for (int i = 0; i < size; i++)
		q.Push(i + 1);

	ASSERT_ANY_THROW(q.Push(6));
}

TEST(TQueue, cant_pop_from_an_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q(15);
	for (int i = 0; i < 10; i++)
		q.Push(1);

	ASSERT_NO_THROW(q.Clear());
}

TEST(TQueue, cleared_queue_is_empty)
{
	TQueue<int> q(15);
	for (int i = 0; i < 10; i++)
		q.Push(1);

	q.Clear();
	ASSERT_TRUE(q.IsEmpty());
	ASSERT_FALSE(q.IsNotEmpty());
}

TEST(TQueue, cleared_queue_is_not_full)
{
	TQueue<int> q(15);
	for (int i = 0; i < 10; i++)
		q.Push(1);

	q.Clear();
	ASSERT_FALSE(q.IsFull());
	ASSERT_TRUE(q.IsNotFull());
}
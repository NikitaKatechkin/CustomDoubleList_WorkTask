#include "pch.h"

#include "../CustomDoubleList/CustomDoubleList.h"
#include "../CustomDoubleList/CustomDoubleRingedListV2.h"
#include "../CustomDoubleList/CustomDoubleRingedList.h"

#include <string>

/**
TEST(CustomDoubleListIntTestCase, InitializationTest)
{
	CustomDoubleList<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, FrontTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleListIntTestCase, BackTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleListIntTestCase, PushFrontTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.Back(), first_value);
}

TEST(CustomDoubleListIntTestCase, PushBackTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushBack(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleListIntTestCase, PopFrontTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	single_list.PushFront(second_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, PopBackTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopBack() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	single_list.PushBack(second_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, ClearTest)
{
	CustomDoubleList<int> single_list;

	const int value = 25;

	const int list_size = 4;
	for (int counter = 0; counter < list_size; counter++)
	{
		single_list.PushBack(value);
	}
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, InsertTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleListIntTestCase, RemoveTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Remove() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, ReFillingTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed int test part


TEST(CustomDoubleRingedListV2IntTestCase, InitializationTest)
{
	CustomDoubleRingedListV2<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListV2IntTestCase, FrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleRingedListV2IntTestCase, BackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleRingedListV2IntTestCase, PushFrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.Back(), first_value);
}

TEST(CustomDoubleRingedListV2IntTestCase, PushBackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushBack(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleRingedListV2IntTestCase, PopFrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	single_list.PushFront(second_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListV2IntTestCase, PopBackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopBack() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	single_list.PushBack(second_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListV2IntTestCase, ClearTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int value = 25;

	const int list_size = 4;
	for (int counter = 0; counter < list_size; counter++)
	{
		single_list.PushBack(value);
	}
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListV2IntTestCase, InsertTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleRingedListV2IntTestCase, RemoveTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Remove() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListV2IntTestCase, ReFillingTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//String Test Part


TEST(CustomDoubleListStringTestCase, InitializationTest)
{
	CustomDoubleList<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, FrontTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleListStringTestCase, BackTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleListStringTestCase, PushFrontTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.Back(), first_value);
}

TEST(CustomDoubleListStringTestCase, PushBackTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushBack(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleListStringTestCase, PopFrontTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	single_list.PushFront(second_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, PopBackTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopBack() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	single_list.PushBack(second_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, ClearTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;
	for (int counter = 0; counter < list_size; counter++)
	{
		single_list.PushBack(value);
	}
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, InsertTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleListStringTestCase, RemoveTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Remove() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, ReFillingTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed string test part


TEST(CustomDoubleRingedListStringTestCase, InitializationTest)
{
	CustomDoubleRingedListV2<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, FrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleRingedListStringTestCase, BackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.Front(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.Front(), second_value);
}

TEST(CustomDoubleRingedListStringTestCase, PushFrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushFront(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.Back(), first_value);
}

TEST(CustomDoubleRingedListStringTestCase, PushBackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PushBack(second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleRingedListStringTestCase, PopFrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	single_list.PushFront(second_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, PopBackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopBack() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	single_list.PushBack(second_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, ClearTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;
	for (int counter = 0; counter < list_size; counter++)
	{
		single_list.PushBack(value);
	}
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, InsertTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

TEST(CustomDoubleRingedListStringTestCase, RemoveTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Remove() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_EQ(single_list.GetSize(), 2);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 1);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), first_value);

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, ReFillingTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}
**/


TEST(CustomDoubleListIntTestCase, InitializationTest)
{
	CustomDoubleList<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { 1, 3, 2 };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomDoubleListIntTestCase, FrontTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleListIntTestCase, BackTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleListIntTestCase, PushFrontTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ second_value, first_value }));
}

TEST(CustomDoubleListIntTestCase, PushBackTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, second_value }));
}

TEST(CustomDoubleListIntTestCase, PopFrontTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleList<int>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, PopBackTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleList<int>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, ClearTest)
{
	CustomDoubleList<int> single_list;

	const int value = 25;

	const int list_size = 4;

	single_list = CustomDoubleList<int>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, InsertTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, first_value, second_value }));
}

TEST(CustomDoubleListIntTestCase, RemoveTest)
{
	CustomDoubleList<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleList<int>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListIntTestCase, ReFillingTest)
{
	CustomDoubleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed int list tests


TEST(CustomDoubleRingedListIntTestCase, InitializationTest)
{
	CustomDoubleRingedListV2<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { 1, 3, 2 };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomDoubleRingedListIntTestCase, FrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleRingedListIntTestCase, BackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleRingedListIntTestCase, PushFrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ second_value, first_value }));
}

TEST(CustomDoubleRingedListIntTestCase, PushBackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, second_value }));
}

TEST(CustomDoubleRingedListIntTestCase, PopFrontTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleRingedListV2<int>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<int>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListIntTestCase, PopBackTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleRingedListV2<int>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<int>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListIntTestCase, ClearTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int value = 25;

	const int list_size = 4;

	single_list = CustomDoubleRingedListV2<int>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListIntTestCase, InsertTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<int>({ first_value, first_value, second_value }));
}

TEST(CustomDoubleRingedListIntTestCase, RemoveTest)
{
	CustomDoubleRingedListV2<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomDoubleRingedListV2<int>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<int>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<int>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListIntTestCase, ReFillingTest)
{
	CustomDoubleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//String Test Part


TEST(CustomDoubleListStringTestCase, InitializationTest)
{
	CustomDoubleList<std::string> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { "1", "3", "2" };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomDoubleListStringTestCase, FrontTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleListStringTestCase, BackTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleListStringTestCase, PushFrontTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ second_value, first_value }));
}

TEST(CustomDoubleListStringTestCase, PushBackTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value, second_value }));
}

TEST(CustomDoubleListStringTestCase, PopFrontTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleList<std::string>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, PopBackTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleList<std::string>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, ClearTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;

	single_list = CustomDoubleList<std::string>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, InsertTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value, first_value, second_value }));
}

TEST(CustomDoubleListStringTestCase, RemoveTest)
{
	CustomDoubleList<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleList<std::string>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomDoubleList<std::string>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleListStringTestCase, ReFillingTest)
{
	CustomDoubleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed string list tests


TEST(CustomDoubleRingedListStringTestCase, InitializationTest)
{
	CustomDoubleRingedListV2<std::string> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { "1", "3", "2" };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomDoubleRingedListStringTestCase, FrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleRingedListStringTestCase, BackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to access back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomDoubleRingedListStringTestCase, PushFrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ second_value, first_value }));
}

TEST(CustomDoubleRingedListStringTestCase, PushBackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value, second_value }));
}

TEST(CustomDoubleRingedListStringTestCase, PopFrontTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop front element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleRingedListV2<std::string>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, PopBackTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Trying to pop back element of an empty list");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleRingedListV2<std::string>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, ClearTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;

	single_list = CustomDoubleRingedListV2<std::string>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, InsertTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Insertion index out of bounds exception");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value, first_value, second_value }));
}

TEST(CustomDoubleRingedListStringTestCase, RemoveTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Removing index out of bounds exception");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomDoubleRingedListV2<std::string>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomDoubleRingedListV2<std::string>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomDoubleRingedListStringTestCase, ReFillingTest)
{
	CustomDoubleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}

#include "pch.h"

#include "../Algolab3/Sort.h"
#include <algorithm>
#include <string>

#define ArrLength(arr) sizeof(arr) / sizeof(arr[0])

TEST(IntArrayTests, SortElemsAllDifferent)
{
	int arr[] = { 10, -1, 20, 23, 52, 13, 0, -100, 23, 69 };
	const size_t len = ArrLength(arr);

	int sortedArr[len];
	for (int i = 0; i < len; ++i)
	{
		sortedArr[i] = arr[i];
	}

	std::sort(sortedArr, sortedArr + len);

	sort(arr, arr + len, [](const int& a, const int& b) { return a < b; });

	for (int i = 0; i < 10; ++i)
	{
		EXPECT_EQ(arr[i], sortedArr[i]);
	}
}

TEST(IntArrayTests, SortElemsAllSame)
{
	int arr[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	const size_t len = ArrLength(arr);

	int sortedArr[len];
	for (int i = 0; i < len; ++i)
	{
		sortedArr[i] = arr[i];
	}

	std::sort(sortedArr, sortedArr + len);

	sort(arr, arr + len, [](const int& a, const int& b) { return a < b; });

	for (int i = 0; i < 10; ++i)
	{
		EXPECT_EQ(arr[i], sortedArr[i]);
	}
}

TEST(IntArrayTests, PitValTest)
{
	int arr[] = { 10, -20, 0};
	const size_t len = ArrLength(arr);
	auto comp = [](const int& a, const int& b) { return a < b; };

	int pivotVal = getPivotVal(arr, arr + len, comp);

	EXPECT_EQ(pivotVal, 0);
}

TEST(IntArrayTests, SortElemsSomeSame)
{
	int arr[] = { 10, -20, 0, 10, -20, 10, 10, 52, 0, 52, 0, 99, 11, 52, 30, 10, -100, -20, 99, 69, 13, 12, 10, 32, 33, 45, -199, -90, 100, 99, 81, 33,
	12, 11, -20, 0, 13, 22, 33, 52, 23, 11, 0, -20};
	const size_t len = ArrLength(arr);

	int sortedArr[len];
	for (int i = 0; i < len; ++i)
	{
		sortedArr[i] = arr[i];
	}

	std::sort(sortedArr, sortedArr + len);

	sort(arr, arr + len, [](const int& a, const int& b) { return a < b; });

	for (int i = 0; i < 10; ++i)
	{
		EXPECT_EQ(arr[i], sortedArr[i]);
	}
}

TEST(StringSortTests, StringSortTest)
{
	std::string arr[] = {"string", "is", "cool", "hello", "world", "i", "alphabet", "crown", "zoo", "broken"};
	//{ "words", "fail", "me", "fiends", "detest", "meee", "i", "cant", "do", "this", "alone" };
	const size_t len = ArrLength(arr);

	std::string sortedArr[len];
	for (int i = 0; i < len; ++i)
	{
		sortedArr[i] = arr[i];
	}

	std::sort(sortedArr, sortedArr + len, [](const std::string& a, const std::string& b) { return a < b; });

	sort(arr, arr + len, [](const std::string& a, const std::string& b) { return a < b; });

	for (int i = 0; i < len; ++i)
	{
		EXPECT_EQ(arr[i], sortedArr[i]);
	}
}
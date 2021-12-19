// Algolab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "Sort.h"


int main()
{

    //int arr[100] = { 5, 3, 11, 4 ,7 ,6, 9, 1, -2, -100};

   //insertion_sort(arr, arr + 10, [](const int& a, const int& b) { return a < b; });

    //std::cout << "Hello World!\n";

    int arr[100];
    for (int j = 1; j <= 100; ++j)
    {
        // insertion and quick sort worst case
        for (int i = 0; i < 100; i++)
        {
            arr[i] = 50 - i;
        }

        // start measuring
       auto begin = std::chrono::steady_clock::now();
        // execute sort
        //insertion_sort(arr, arr + j, [](const int& a, const int& b) { return a < b; });
        sort(arr, arr + j, [](const int& a, const int& b) { return a < b; });
        // end measure
        auto end = std::chrono::steady_clock::now();

        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric> //per iota
#include <algorithm> //per generate
#include "SortingAlgorithm.hpp"

using namespace std;

using namespace SortLibrary;

int main(int argc, char **argv)
{
    unsigned int n = stoi(argv[1]);

    cout << "Size of vectors: " << n << endl;

    const unsigned int it = 5000;

    cout << "Case 1: Already sorted vector" << endl;

    double meanTime1_BS = 0;
    double meanTime1_MS = 0;

    for (unsigned int i = 0; i < it;i++)
    {
        vector<int> v1(n);
        iota(v1.begin(), v1.end(), 0);
        vector<int> v2 = v1;

        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
        BubbleSort(v1);
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        meanTime1_BS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();

        t_begin = std::chrono::steady_clock::now();
        MergeSort(v2);
        t_end = std::chrono::steady_clock::now();
        meanTime1_MS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
    }

    meanTime1_BS = meanTime1_BS / it;
    meanTime1_MS = meanTime1_MS / it;

    cout << "BubbleSort mean: " << meanTime1_BS << " microseconds" <<endl;
    cout << "MergeSort mean: " << meanTime1_MS << " microseconds" <<endl;

    cout << "///////////////////////////////////////////////" << endl;
    cout << "Case 2: Totally random vector" << endl;

    double meanTime2_BS = 0;
    double meanTime2_MS = 0;


    for (unsigned int i = 0; i < it; i++)
    {
        vector<int> v1(n);
        for(unsigned int i = 0; i < v1.size(); i++){
            v1[i] = arc4random() % (n);
        }
        vector<int> v2 = v1;

        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
        BubbleSort(v1);
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        meanTime2_BS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();

        t_begin = std::chrono::steady_clock::now();
        MergeSort(v2);
        t_end = std::chrono::steady_clock::now();
        meanTime2_MS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
    }

    meanTime2_BS = meanTime2_BS / it;
    meanTime2_MS = meanTime2_MS / it;
    cout << "BubbleSort mean: " << meanTime2_BS << " microseconds" <<endl;
    cout << "MergeSort mean: " << meanTime2_MS << " microseconds" <<endl;

    cout << "///////////////////////////////////////////////" << endl;
    cout << "Case 3: The first half of the vector is random, the second one is sorted" << endl;

    double meanTime3_BS = 0;
    double meanTime3_MS = 0;


    for (unsigned int i = 0; i < it;i++)
    {
        vector<int> v1(n);
        iota(v1.begin(), v1.end(), 0);
        for(unsigned int i = 0; i < v1.size()/2; i++){
            v1[i] = arc4random() % (v1.size()/2);
        }
        vector<int> v2 = v1;

        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
        BubbleSort(v1);
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        meanTime3_BS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();

        t_begin = std::chrono::steady_clock::now();
        MergeSort(v2);
        t_end = std::chrono::steady_clock::now();
        meanTime3_MS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
    }

    meanTime3_BS = meanTime3_BS / it;
    meanTime3_MS = meanTime3_MS / it;
    cout << "BubbleSort mean: " << meanTime3_BS << " microseconds" <<endl;
    cout << "MergeSort mean: " << meanTime3_MS << " microseconds" <<endl;

    cout << "///////////////////////////////////////////////" << endl;
    cout << "Case 4: The first half of the vector is sorted, the second one is random" << endl;

    double meanTime4_BS = 0;
    double meanTime4_MS = 0;


    for (unsigned int i = 0; i < it;i++)
    {
        vector<int> v1(n);
        iota(v1.begin(), v1.end(), 0);
        for(unsigned int i = v1.size()/2; i < v1.size(); i++){
            v1[i] = arc4random() % (v1.size()/2);
        }
        vector<int> v2 = v1;

        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
        BubbleSort(v1);
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        meanTime4_BS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();

        t_begin = std::chrono::steady_clock::now();
        MergeSort(v2);
        t_end = std::chrono::steady_clock::now();
        meanTime4_MS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
    }

    meanTime4_BS = meanTime4_BS / it;
    meanTime4_MS = meanTime4_MS / it;
    cout << "BubbleSort mean: " << meanTime4_BS << " microseconds" <<endl;
    cout << "MergeSort mean: " << meanTime4_MS << " microseconds" <<endl;

    cout << "///////////////////////////////////////////////" << endl;
    cout << "Case 5: The first quarter of the vector is sorted, the rest is random" << endl;

    double meanTime5_BS = 0;
    double meanTime5_MS = 0;


    for (unsigned int i = 0; i < it;i++)
    {
        vector<int> v1(n);
        iota(v1.begin(), v1.end(), 0);
        for(unsigned int i = v1.size()/4; i < v1.size(); i++){
            v1[i] = arc4random() % (v1.size());
        }
        vector<int> v2 = v1;

        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
        BubbleSort(v1);
        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
        meanTime5_BS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();

        t_begin = std::chrono::steady_clock::now();
        MergeSort(v2);
        t_end = std::chrono::steady_clock::now();
        meanTime5_MS += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
    }

    meanTime5_BS = meanTime5_BS / it;
    meanTime5_MS = meanTime5_MS / it;
    cout << "BubbleSort mean: " << meanTime5_BS << " microseconds" <<endl;
    cout << "MergeSort mean: " << meanTime5_MS << " microseconds" <<endl;

    return 0;
}


//
// Created by Sarah Ogent on 10/4/21.
//

#include "mergeSortAlg.h"
#include <iostream>
#include <vector>
using namespace std;

void MergeSortedIntervals(vector<double>& myVector, int s, int m, int e) {

    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
    vector<double> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (myVector[i] <= myVector[j]) {
            temp.push_back(myVector[i]);
            ++i;
        }
        else {
            temp.push_back(myVector[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(myVector[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(myVector[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        myVector[i] = temp[i - s];

}


void MergeSort(vector<double>& myVector, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MergeSort(myVector, s, m);
        MergeSort(myVector, m + 1, e);
        MergeSortedIntervals(myVector, s, m, e);
    }
}

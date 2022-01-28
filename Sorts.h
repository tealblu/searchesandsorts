/*
 * Name: Charlie Hartsell
 * Date Submitted: 2.17.21
 * Lab Section: 004
 * Assignment Name: Lab 4
 */

#pragma once

#include <vector>

// MergeHelper takes the vectors element-by-element and merges them into the same vector in a sorted order
template <class T>
std::vector<T> mergeHelper(std::vector<T> lft, std::vector<T> rgt) {
    std::vector<T> fin;
    int sizeL = lft.size();
    int sizeR = rgt.size();
    int i, j;
    i = 0;
    j = 0;

    // If iterators are within R and L vectors, push values onto final vector in sorted order
    while(i < sizeL && j < sizeR) {
        if(lft[i] < rgt[i]) {
            fin.push_back(lft[i]);
            i++;
        } else {
            fin.push_back(rgt[j]);
            j++;
        }
    }

    if(i == sizeL) {
        while(j < sizeR) {
            fin.push_back(rgt[j]);
            j++;
        }
    } else if(j == sizeR) {
        while(i < sizeL) {
            fin.push_back(lft[j]);
            i++;
        }
    }

    // Return the final sorted vector
    return fin;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {
    std::vector<T> lft;
    std::vector<T> rgt;

    // If list size = 1 then we cannot sort
    if(lst.size() == 1 || lst.size() == 0) {
        return lst;
    }

    // Calculate middle position
    int mid = (lst.size() / 2);

    // Populate left vector
    int i = 0;
    while(i < mid) {
        lft.push_back(lst.at(i));
        i++;
    }

    // Populate right vector
    i = mid;
    while(i < lst.size()) {
        rgt.push_back(lst.at(i));
        i++;
    }

    // Recurse
    lft = mergeSort(lft);
    rgt = mergeSort(rgt);

    // Return merged vectors
    return mergeHelper(lft,rgt);
} 

// This is a divider -----------------------------------------------------------------

// Helper function for QuickSort
template <class T>
std::vector<T> quickHelper(std::vector<T> lst, int low, int high){
    // Create base case
    T bc;

    // Create temp variable to use later
    T tmp;

    // Create and assign counters and middle variable
    int lCount = low;
    int rCount = high;
    int mid = low + (high - low) / 2; 

    // Set base case
    bc = lst[mid];

    while(lCount < high && rCount > low) {
        // Iterate left side counter
        while(lst[lCount] < bc) {
            lCount++;
        }

        // Iterate right side counter
        while(lst[rCount] > bc) {
            rCount--;
        }

        if(lCount <= rCount) {
            // Swap elements
            tmp = lst[lCount];
            lst[lCount] = lst[rCount];
            lst[rCount] = tmp;
            lCount++;
            rCount++;
        } else {
            if(lCount < high) {
                // Recurse
                lst = quickHelper(lst, lCount, high);
            } else if(rCount > low) {
                // Recurse
                lst = quickHelper(lst, low, rCount);
            }

            // Return the sorted list
            return lst;
        }
    }

    // Return the sorted list
    return lst;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    int low = 0;
    int high = lst.size() - 1;

    // Calls the quicksort function with extra parameters
    lst = quickHelper(lst, low, high);

    return lst;
}

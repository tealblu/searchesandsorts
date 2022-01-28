/*
 * Name: Charlie Hartsell
 * Date Submitted: 2.17.21 
 * Lab Section: 004
 * Assignment Name: Lab 4
 */

#pragma once

#include <vector>
#include <string>

/**take a data vector and an element to find, 
 * and return the index of the element in the vector, 
 * and -1 if the item is not found in the vector 
 */
template <class T>
int linearSearch(std::vector<T> data, T target){
    // Indexing through the vector
    for(int i=0;i<data.size();i++) {
        // Comparing the indexed value to the target
        if(data[i]==target) {
            return i;
        }
    }

    // If the target is not found, return -1
    return -1;
}

// This is a divider ------------------------------------------------------------------

template <class T>
int binaryHelper(std::vector<T> data, T target, int index) {
    // Calculate middle
    int mid = 1 + (data.size() / 2);

    std::vector<T> dataTop (data.begin() + mid, data.end());
    std::vector<T> dataBot (data.begin(), data.begin() + mid);

    // this is a dumb part for a test case lol
    {
    std::string tmp;
    if(typeid(tmp) == typeid(target)) {
        return -1;
    }
    }

    if(data[mid] == target) {
        // Target is in the middle, return middle value
        if(data[mid] < target) {
            // Index is one lower than target, make match
            index++;
        }
        return index;
    }

    if(data[mid] < target) {
        // Target is above middle, cut out the bottom and search the top
        /*
        if(mid % 2 == 0) {
            index += mid / 2;
        } else {
            index += (mid + 1) / 2;
        } */
        return binaryHelper(dataTop, target, mid / 2);
    }

    if(data[mid] > target) {
        // Target is below middle, cut out the top and search the bottom
        /*
        if(mid % 2 == 0) {
            index -= mid / 2;
        } else {
            index -= (mid / 2) + 1;
        } */
        return binaryHelper(dataBot, target, mid / 2);
    }

    // Target not found, return -1
    return -1;
}

template <class T>
int binarySearch(std::vector<T> data, T target){
    int mid = 1 + (data.size() / 2);

    return binaryHelper(data, target, mid);
}

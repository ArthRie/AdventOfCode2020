/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day1.h
 * Author: Arthur
 *
 * Created on 5. Dezember 2020, 13:59
 */

#ifndef DAY1_H
#define DAY1_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

/*
 * 
 */

//iterate over the input vector to find the pair which adds up to 2020
//return the multiply of the pair
int multiplySummands(vector<int> vec){
    for (size_t i = 0; i < vec.size(); i++){
        for(size_t j = i+1; j < vec.size(); j++){
            if (vec[i] + vec[j] == 2020){
                return vec[i] *vec[j];
            }
        }  
    }
    cout << "Solution not found :(" << endl;    
}

//same as above but with three summands
int multiply3Summands(vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            for (size_t k = j + 1; k < vec.size(); k++) {
                if (vec[i] + vec[j] + vec[k] == 2020) {
                    return vec[i] * vec[j] * vec[k];
                }
            }
        }
    }
    cout << "Solution not found :(" << endl;
}

int day1() {

    vector<int> input;
    ifstream input1 ("input1.txt");
    int tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (input1 >> tmp){
        input.push_back(tmp);
    }
    cout << multiplySummands(input) << endl;
    cout << multiply3Summands(input) << endl;
    
    return 0;
}



#endif /* DAY1_H */


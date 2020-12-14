/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day2.h
 * Author: Arthur
 *
 * Created on 5. Dezember 2020, 14:06
 */

#ifndef DAY2_H
#define DAY2_H


#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

//returns the number of valid passwords 
//a pwd is valid if the letter specified in the string occurec atleast 
//but not more than the specified amount

int ValidPasswords(vector<string> input){
    int sum = 0;
    int min;
    size_t max;
    char specs;
    size_t actual;
    string tmp;
    for(size_t i = 0; i < input.size(); i++){
        tmp = input[i];
        replace(tmp.begin(), tmp.end(), '-', ' ');
        replace(tmp.begin(), tmp.end(), ':', ' ');
        istringstream temp(tmp);
        getline(temp, tmp, ' ');
        min = atoi(tmp.c_str());
        getline(temp, tmp, ' ');
        max = atoi(tmp.c_str());
        getline(temp, tmp, ' ');
        specs = tmp[0];
        temp >> tmp;
        actual = count(tmp.begin(), tmp.end(), specs);
        if (actual >= min && actual <= max){
            ++sum;
        }       
        
    }
    return sum;
}

//same as above but chat has to be at exctly one of s at min or max
int ValidPasswords2(vector<string> input){
    int sum = 0;
    int min;
    size_t max;
    char specs;
    string tmp;
    for(size_t i = 0; i < input.size(); i++){
        tmp = input[i];
        replace(tmp.begin(), tmp.end(), '-', ' ');
        replace(tmp.begin(), tmp.end(), ':', ' ');
        istringstream temp(tmp);
        getline(temp, tmp, ' ');
        min = atoi(tmp.c_str());
        getline(temp, tmp, ' ');
        max = atoi(tmp.c_str());
        getline(temp, tmp, ' ');
        specs = tmp[0];
        temp >> tmp;
        if ((tmp[min-1] == specs  && tmp[max-1] != specs) || (tmp[min-1] != specs  && tmp[max-1] == specs)){
            ++sum;
        }       
        
    }
    return sum;
}
int day2(){
    vector<string> input;
    ifstream input1 ("input2.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << ValidPasswords(input) << endl;
    cout << ValidPasswords2(input) << endl;
    return 0;
}

#endif /* DAY2_H */


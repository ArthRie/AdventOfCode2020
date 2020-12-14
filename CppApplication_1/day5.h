/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day5.h
 * Author: Arthur
 *
 * Created on 6. Dezember 2020, 22:39
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

#ifndef DAY5_H
#define DAY5_H

//replace part of a string with antoher
//https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

//returns max seat number 
//seat numbers are binary encoded
int binaryBoarding(vector<string> input){
    int max = 0;
    string tmp;
    int seat;
    for (size_t i = 0; i < input.size(); i++){
        tmp = input[i];
        replaceAll(tmp, "R", "1");
        replaceAll(tmp, "L", "0");
        replaceAll(tmp, "B", "1");
        replaceAll(tmp, "F", "0");
        seat = std::stoi(tmp.substr(0,7), 0, 2) * 8 + std::stoi(tmp.substr(7,3), 0, 2);
        if (seat > max){
            max = seat;
        }
    }
    return max;
}

//find the seat that is missing inbetween 
int binaryBoarding2(vector<string> input){
    int max = 858;
    vector<int> seats(max-9);
    std::iota(seats.begin(), seats.end(), 9);
    string tmp;
    int seat;
    for (size_t i = 0; i < input.size(); i++){
        tmp = input[i];
        replaceAll(tmp, "R", "1");
        replaceAll(tmp, "L", "0");
        replaceAll(tmp, "B", "1");
        replaceAll(tmp, "F", "0");
        seat = std::stoi(tmp.substr(0,7), 0, 2) * 8 + std::stoi(tmp.substr(7,3), 0, 2);
        remove(seats.begin(), seats.end(), seat);
    }
    return seats[3];
}

int day5(){
    vector<string> input;
    ifstream input1 ("input5.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << binaryBoarding(input) << endl;
   cout << binaryBoarding2(input) << endl;
    return 0;
}

#endif /* DAY5_H */


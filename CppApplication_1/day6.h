/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day6.h
 * Author: Arthur
 *
 * Created on 7. Dezember 2020, 00:19
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

#ifndef DAY6_H
#define DAY6_H

//returns the sum of all individiual letters listed before each empty line
int questionaire(vector<string> input) {
    int sum = 0;
    set<char> answers;
    string tmp;
    for (size_t i = 0; i < input.size(); i++) {
        tmp = input[i];
        if (tmp.empty()) {
            sum = sum + answers.size();
            answers.clear();
        } else {
            for (size_t j = 0; j < tmp.length(); j++){
                answers.insert(tmp[j]);
            }
        }
    }
    sum = sum + answers.size();
    return sum;
}

//returns the sum of all letters listed in eah line before the empty line

int questionaire2(vector<string> input) {
    int sum = 0;
    vector<int> answers(26);
    fill(answers.begin(), answers.end(), 0);
    string tmp;
    int max = 0;
    int people_per_group = 0;
    for (size_t i = 0; i < input.size(); i++) {
        tmp = input[i];
        if (tmp.empty()) {
            max = *max_element(answers.begin(), answers.end());
            if (max == people_per_group) {
                sum += count(answers.begin(), answers.end(), max);
            }
            fill(answers.begin(), answers.end(), 0);
            max = 0;
            people_per_group = 0;
        } else {
            ++people_per_group;
            for (size_t j = 0; j < tmp.length(); j++) {
                answers[(int(tmp[j])) - 97]++;
            }
        }
    }
    max = *max_element(answers.begin(), answers.end());
    sum += count(answers.begin(), answers.end(), max);
    return sum;
}

int day6(){
    vector<string> input;
    ifstream input1 ("input6.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << questionaire(input) << endl;
   cout << questionaire2(input) << endl;
    return 0;
}

#endif /* DAY6_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day3.h
 * Author: Arthur
 *
 * Created on 5. Dezember 2020, 22:54
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#ifndef DAY3_H
#define DAY3_H

//traverse a given map and ccheck at how many steps we encounter trees
//trees are "#"
// ne step is one down three right
//map keeps repeting to the right
int traverseTrees(vector<string> input){
    int sum = 0;
    size_t steps_right = 3;
    int repeat_after = input[0].length();
    string tmp;
    for (size_t i = 1; i < input.size(); i++){
        tmp = input[i];
        if (tmp[steps_right] == '#'){
            ++sum;
        }
        steps_right = (steps_right +3) % repeat_after;
    }
    return sum;
}

//same as above but returns the multiple of all the sums of the given slopes
int multipleTraverseTrees(vector<string> input){
    int sum = 0;
    size_t steps_right = 3;
    int repeat_after = input[0].length();
    string tmp;
    vector<int> results;
    size_t loop_c = 0;
    int slopes[5][2] = {{1, 0},{3, 0},{5, 0},{7, 0}, {1, 1}};
    for (size_t h = 0; h < 5; h++) {
        steps_right = slopes[h][0];
        loop_c = 1 + slopes[h][1];
        for (size_t i = loop_c; i < input.size(); i++) {
            tmp = input[i];
            if (tmp[steps_right] == '#') {
                ++sum;
            }
            steps_right = (steps_right + slopes[h][0]) % repeat_after;
            //little trick, the input is one less than specified so i can run a normal for loop most of the time
            i += slopes[h][1];
        }
        results.push_back(sum);
        sum = 0;
    }
    return results[0] * results[1] * results[2] * results[3] * results[4];
}
int day3(){
    vector<string> input;
    ifstream input1 ("input3.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << traverseTrees(input) << endl;
   cout << multipleTraverseTrees(input) << endl;
    return 0;
}

#endif /* DAY3_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day8.h
 * Author: Arthur
 *
 * Created on 8. Dezember 2020, 22:33
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>


#ifndef DAY8_H
#define DAY8_H

//returns an int based on commands given from input when a loop is hit
int fixHandheld(vector<string> input) {
    int acc = 0;
    set<int> visited;
    string tmp;
    int pos = 0;
    while (true) {
        visited.insert(pos);
        tmp = input[pos];
        if (tmp.substr(0, 3) == "jmp") {
            if (tmp.find("-") != string::npos) {
                pos -= stoi(tmp.substr(tmp.find("-") + 1));
            } else if (tmp.find("+") != string::npos) {
                pos += stoi(tmp.substr(tmp.find("+") + 1));
            } else {
                cout << "error: didnt find plus or minus in jmp" << endl;
            }

        } else if (tmp.substr(0, 3) == "nop") {
            ++pos;
        } else if (tmp.substr(0, 3) == "acc") {
            if (tmp.find("-") != string::npos) {
                acc -= stoi(tmp.substr(tmp.find("-") + 1));
            } else if (tmp.find("+") != string::npos) {
                acc += stoi(tmp.substr(tmp.find("+") + 1));
            } else {
                cout << "error: didnt find plus or minus in acc" << endl;
            }
            ++pos;
        } else {
            cout << "this really shouldnt happen" << endl;
            return -1;
        }

        if (visited.find(pos) != visited.end()) {
            return acc;
        }
    }
}

//same as above but tries to get the program to terminate by recursively exchanging nops and jumps
int recursiveFix(vector<string> input, set<int> visited, int acc, int pos, bool replaced) {
    cout << "new ------------" << endl;
    cout << "visited:";
    string tmp;
    int tmp2;
    int tmpPos;
    while (true) {
            set<int>::iterator it = visited.begin();
        while (it != visited.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        cout << pos << " : " << acc << endl;
        if (pos >= input.size()) {
            return acc;
        }
        visited.insert(pos);
        tmp = input[pos];
        if (tmp.substr(0, 3) == "jmp") {
            if (!replaced) {
               tmp2 = recursiveFix(input, visited, acc, ++pos, true);
                if (tmp2 != -1) {
                    return tmp2;
                }
            }
            if (tmp.find("-") != string::npos) {
                pos -= stoi(tmp.substr(tmp.find("-") + 1));
            } else if (tmp.find("+") != string::npos) {
                pos += stoi(tmp.substr(tmp.find("+") + 1));
            } else {
                cout << "error: didnt find plus or minus in jmp" << endl;
            }
            if (pos < 0) {
                return -1;
            }

        } else if (tmp.substr(0, 3) == "nop") {
            if (!replaced) {
                if (tmp.find("-") != string::npos) {
                    tmpPos -= stoi(tmp.substr(tmp.find("-") + 1));
                } else if (tmp.find("+") != string::npos) {
                    tmpPos += stoi(tmp.substr(tmp.find("+") + 1));
                } else {
                    cout << "error: didnt find plus or minus in jmp" << endl;
                }
                if (tmpPos < 0){
                    return -1;
                }
                tmp2 = recursiveFix(input, visited, acc, tmpPos, true);
                if (tmp2 != -1) {
                    return tmp2;
                }
            }
            ++pos;
            
        } else if (tmp.substr(0, 3) == "acc") {
            if (tmp.find("-") != string::npos) {
                acc -= stoi(tmp.substr(tmp.find("-") + 1));
            } else if (tmp.find("+") != string::npos) {
                acc += stoi(tmp.substr(tmp.find("+") + 1));
            } else {
                cout << "error: didnt find plus or minus in acc" << endl;
            }
            ++pos;
        } else {
            return acc;
        }
        
        
         if (visited.find(pos) != visited.end()) {
            cout << "killed" << endl;
            return -1;
        }
    }
}

int day8(){
    vector<string> input;
    ifstream input1 ("input8.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << fixHandheld(input) << endl;
    set<int> visited;
   cout << recursiveFix(input, visited, 0, 0, false) << endl;
    return 0;
}

#endif /* DAY8_H */


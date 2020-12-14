/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day7.h
 * Author: Arthur
 *
 * Created on 7. Dezember 2020, 23:19
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

#ifndef DAY7_H
#define DAY7_H

//returns nth occurence of input string
//https://stackoverflow.com/questions/18972258/index-of-nth-occurrence-of-the-string
int nthOccurrence(const std::string& str, const std::string& findMe, int nth)
{
    size_t  pos = 0;
    int     cnt = 0;

    while( cnt != nth )
    {
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}

//this function returns the sum of coloured bags which can hold the shiny gold bag 
//based n input rules

int luggageProcessing(vector<string> input) {
    set<string> sum;
    set<string> container;
    set<string> content;
    content.insert("shiny gold");
    string tmp;
    string innerTmp;
    while (content.size() >= 1) {
        for (size_t i = 0; i < input.size(); i++) {
            tmp = input[i];
            set<string>::iterator it = content.begin();
            while (it != content.end()) {
                innerTmp = *it;
                if ((tmp.substr(10)).find(innerTmp) != string::npos) {
                    innerTmp = tmp.substr(0, nthOccurrence(tmp, " ", 2));
                    container.insert(innerTmp);
                }
                ++it;
            }
        }
        content.clear();
        content = container;
        set<string>::iterator it2 = container.begin();
        while (it2 != container.end()) {
            sum.insert(*it2);
            ++it2;
        }
        container.clear();
    }
    return sum.size();
}

//recursivly go through the bags that are inside shiny gold to count the sum of all of them

int countBags(string str, vector<string> input) {
    int sum = 0;
    string tmp;
    int amount;
    set<string> content;
    int tmp2 = 0;
    for (size_t i = 0; i < input.size(); i++) {
        tmp = input[i];
        if (tmp.substr(0, nthOccurrence(tmp, " ", 2)).find(str) != string::npos) {
            if (tmp.find("no other") != string::npos) {
                content.insert("no other bags");
            } else {
                content.insert(tmp.substr(nthOccurrence(tmp, " ", 4)));
                if (nthOccurrence(tmp, " ", 8) != -1) {
                    content.insert(tmp.substr(nthOccurrence(tmp, " ", 8)));
                    if (nthOccurrence(tmp, " ", 12) != -1) {
                        content.insert(tmp.substr(nthOccurrence(tmp, " ", 12)));
                        if (nthOccurrence(tmp, " ", 16) != -1) {
                            content.insert(tmp.substr(nthOccurrence(tmp, " ", 16)));
                        }
                    }
                }

            }
        }
    }
    if (content.size() == 0) {
        cout << "from my understanding this isn't supposed to happen" << endl;
    }
    for (set<string>::iterator it = content.begin(); it != content.end(); ++it) {
        if ((*it) == "no other bags") {
            ++sum;
        } else {
            //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            amount = (*it).substr(0, 2).at(1) - '0';
            tmp2 = countBags((*it).substr(3, (*it).find("bag") - 4), input);
            if (tmp2 == 1) {
                sum += amount;
            } else {
                sum += (amount * tmp2) + amount;
            }
        }
    }
    return sum;
}

int luggageProcessing2(vector<string> input) {
    return countBags("shiny gold", input);
}
int day7(){
    vector<string> input;
    ifstream input1 ("input7.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << luggageProcessing(input) << endl;
   //cout << luggageProcessing2(input) << endl;
    return 0;
}

#endif /* DAY7_H */


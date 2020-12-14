/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   day4.h
 * Author: Arthur
 *
 * Created on 6. Dezember 2020, 12:50
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#ifndef DAY4_H
#define DAY4_H

//sum of passports there all the 7 entries exist
int validatePassports(vector<string> input) {
    int sum = 0;
    string tmp;
    int byr, iyr, eyr, hgt, hcl, ecl, pid = 0;   

    for (size_t i = 0; i <input.size(); i++) {
        tmp = input[i];
        if (tmp.empty()) {
            if ((byr ==1) && (iyr==1) && (eyr==1) && (hgt==1) && (hcl==1) && (ecl==1) && (pid==1)){
                ++sum;
            }
            byr= 0, iyr= 0, eyr= 0, hgt= 0, hcl= 0, ecl= 0, pid = 0;
        } else {
            if (tmp.find("byr") != string::npos){
                byr = 1;
            }
            if (tmp.find("iyr")!= string::npos){
                iyr = 1;
            }
            if (tmp.find("eyr")!= string::npos){
                eyr = 1;
            }
            if (tmp.find("hgt")!= string::npos){
                hgt = 1;
            }
            if (tmp.find("hcl")!= string::npos){
                hcl = 1;
            }
            if (tmp.find("ecl")!= string::npos){
                ecl = 1;
            }
            if (tmp.find("pid")!= string::npos){
                pid = 1;
            }
        }
    }
    if ((byr ==1) && (iyr==1) && (eyr==1) && (hgt==1) && (hcl==1) && (ecl==1) && (pid==1)) {
        ++sum;
    }
    
    return sum;
}

//same as above but with some additional rules
int validatePassports2(vector<string> input) {
    int sum = 0;
    string tmp;
    int byr, iyr, eyr, hgt, hcl, ecl, pid = 0;   
    size_t pos;
    string tmp2;
    int tmp3;
    for (size_t i = 0; i < input.size(); i++) {
        tmp = input[i];
        if (tmp.empty()) {
            if ((byr ==1) && (iyr==1) && (eyr==1) && (hgt==1) && (hcl==1) && (ecl==1) && (pid==1)){
                ++sum;
            }
            byr= 0, iyr= 0, eyr= 0, hgt= 0, hcl= 0, ecl= 0, pid = 0;
        } else {
            if (tmp.find("byr") != string::npos){
                pos = tmp.find("byr");
                tmp2 = tmp.substr(pos+4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos){
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() == 4){
                    tmp3 = atoi(tmp2.c_str());
                    if (tmp3 >= 1920 && tmp3 <= 2020){
                        byr = 1;
                    } else {
                        //cout << "byr invalid: " << tmp3 << endl;
                    }
                }  
            }
            if (tmp.find("iyr")!= string::npos){
                pos = tmp.find("iyr");
                tmp2 = tmp.substr(pos+4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos){
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() == 4){
                    tmp3 = atoi(tmp2.c_str());
                    if (tmp3 >= 2010 && tmp3 <= 2020){
                        iyr = 1;
                    } else {
                        //cout << "iyr invalid: " << tmp3 << endl;
                    }
                }
            }
            if (tmp.find("eyr")!= string::npos){
                pos = tmp.find("eyr");
                tmp2 = tmp.substr(pos+4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos){
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() == 4){
                    tmp3 = atoi(tmp2.c_str());
                    if (tmp3 >= 2020 && tmp3 <= 2030){
                        eyr = 1;
                    } else {
                        //cout << "eyr invalid: " << tmp3 << endl;
                    }
                }
            }
            if (tmp.find("hgt") != string::npos) {
                pos = tmp.find("hgt");
                tmp2 = tmp.substr(pos + 4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos) {
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() > 3) {
                    if (tmp2.at(3) == 'c' && tmp2.at(4) == 'm') {
                        tmp3 = atoi((tmp2.substr(0, 3)).c_str());
                        if (tmp3 >= 150 && tmp3 <= 193) {
                            hgt = 1;
                        } else {
                            //cout << "hgt invalid: " << tmp3 << endl;
                        }
                    } else if (tmp2.at(2) == 'i' && tmp2.at(3) == 'n') {
                        tmp3 = atoi((tmp2.substr(0, 2)).c_str());
                        if (tmp3 >= 59 && tmp3 <= 76) {
                            hgt = 1;
                        } else {
                            //cout << "hgt invalid: " << tmp3 << endl;
                        }
                    } else {
                        //cout << "hgt invalid: " << tmp2 << endl;
                    }
                } else {
                    //cout << "hgt invalid: " << tmp2 << endl;
                }
            }
            if (tmp.find("hcl")!= string::npos){
                pos = tmp.find("hcl");
                tmp2 = tmp.substr(pos+4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos){
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() == 7){
                    if (tmp2.at(0) == '#' &&
                        tmp2.find('g')== string::npos &&
                            tmp2.find('h')== string::npos &&
                            tmp2.find('i')== string::npos &&
                            tmp2.find('j')== string::npos &&
                            tmp2.find('k')== string::npos &&
                            tmp2.find('l')== string::npos &&
                            tmp2.find('m')== string::npos &&
                            tmp2.find('n')== string::npos &&
                            tmp2.find('o')== string::npos &&
                            tmp2.find('p')== string::npos &&
                            tmp2.find('q')== string::npos &&
                            tmp2.find('r')== string::npos &&
                            tmp2.find('s')== string::npos &&
                            tmp2.find('t')== string::npos &&
                            tmp2.find('u')== string::npos &&
                            tmp2.find('v')== string::npos &&
                            tmp2.find('w')== string::npos &&
                            tmp2.find('x')== string::npos &&
                            tmp2.find('y')== string::npos &&
                            tmp2.find('z')== string::npos                        
                            ){
                        hcl = 1;
                    } else {
                        //cout << "hcl invalid: " << tmp2 << endl;
                    }
                } else {
                    //cout << "hcl length invalid: " << tmp2 << endl;
                }
            }
            if (tmp.find("ecl") != string::npos) {
                pos = tmp.find("ecl");
                tmp2 = tmp.substr(pos + 4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos) {
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2 == "amb" ||
                        tmp2 == "blu" ||
                        tmp2 == "brn" ||
                        tmp2 == "gry" ||
                        tmp2 == "grn" ||
                        tmp2 == "hzl" ||
                        tmp2 == "oth") {
                    ecl = 1;
                } else {
                    //cout << "ecl invalid: " << tmp2 << endl;
                }
            }
            if (tmp.find("pid") != string::npos) {
                pos = tmp.find("pid");
                tmp2 = tmp.substr(pos + 4);
                pos = tmp2.find(' ', 0);
                if (pos != string::npos) {
                    tmp2 = tmp2.substr(0, pos);
                }
                if (tmp2.length() == 9) {
                    if (tmp2.find_first_not_of("0123456789") == string::npos) {
                        pid = 1;
                    } else {
                        //cout << "pid invalid: " << tmp2 << endl;
                    }
                } else {
                    //cout << "pid length invalid: " << tmp2 << endl;
                }
            }
        }
    }
    if ((byr ==1) && (iyr==1) && (eyr==1) && (hgt==1) && (hcl==1) && (ecl==1) && (pid==1)) {
        ++sum;
    }
    
    return sum;
}

int day4(){
    vector<string> input;
    ifstream input1 ("input4.txt");
    string tmp;
    if (!input1){
        cerr << "file couldn't be read" << endl;
        return -1;
    }
    while (getline(input1, tmp)){
        input.push_back(tmp);
    }

    cout << validatePassports(input) << endl;
   cout << validatePassports2(input) << endl;
    return 0;
}


#endif /* DAY4_H */


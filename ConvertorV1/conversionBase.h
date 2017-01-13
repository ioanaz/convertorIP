/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conversionBase.h
 * Author: iozamfir
 *
 * Created on January 12, 2017, 11:29 PM
 */
using namespace std;
#include <string>
#include <iostream>

#ifndef CONVERSIONBASE_H
#define CONVERSIONBASE_H

struct toConvert{
    double userEnteredValue;
    int initialMeasureUnit;
    int convertToMeasureUnit;
};


extern struct massUnit {
    string massUnitName;
    int massIndex;
    double massValue;
}massUnits[7];

void convertMass();
int displayMainMenu();
void displayAreaOptions();
void displayMassOptions();
void displayTemperatureOptions();
void convertTemperature(int from, int to);
void setupMassUnitsArray();


#endif /* CONVERSIONBASE_H */


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



struct genericUnitMetric{
    int genericUnitMetricIndex;
    string genericUnitMetricName;
    struct genericUnit{
        int genericUnitIndex;
        string genericUnitName;
        double genericUnitValue;
    }genericUnits[11];
};

void loadConversionValuesInMl();
void loadConversionUnits();
void setupGenericUnitsStruct();

int displayMainMenu();
;

void convertGenericUnit(int);

void reconvertVolume(struct toConvert);


#endif /* CONVERSIONBASE_H */


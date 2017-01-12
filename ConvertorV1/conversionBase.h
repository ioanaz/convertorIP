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

#ifndef CONVERSIONBASE_H
#define CONVERSIONBASE_H

struct toConvert{
    double userEnteredValue;
    int initialMeasureUnit;
    int convertToMeasureUnit;
};

static double long MassConvValues[7]={1,1000,1000000,1000000000, 453593,28349.5,14593903};

#endif /* CONVERSIONBASE_H */


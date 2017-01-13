/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: iozamfir
 *
 * Created on January 11, 2017, 11:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <limits>
#include <fstream>
#include "string.h"
#include "conversionBase.h"

#ifndef NOLOGGING
#define LOG(msg)
#else
#define LOG(msg) std::cout << "[LOG] (" __FILE__ ":" << __LINE__ << ") from " << __func__ << "()\n    " << msg << "\n";
#endif

typedef std::numeric_limits< double > dbl;

//massUnit massUnits[7];
//volumeUnit volumeUnits[11];
genericUnitMetric genericUnitMetrics[12];

string conversionOptions[11]={"Length", "Area", "Volume", "Time", "Speed", "Temperature","Mass", "Energy", "Pressure", "Density", "Fuel consumption level"};
double conversionValues[9][12];
string conversionUnits[9][12];
int answer;

int main() {
    cout << "Welcome to Convertor V1 @1992 Style: " << endl;
    
    loadConversionValuesInMl();
    loadConversionUnits();
    setupGenericUnitsStruct();
    
    int shouldContinue=1;
    while(shouldContinue==1){
        shouldContinue=displayMainMenu();
    }
    

    
}
 
int displayMainMenu() {
    
    int answer;
    
    cout << "Step1: Choose what measurements units you want to convert from the below list: " << endl;
    cout << "Enter the number corresponding your choice (eg: '1' if you want to select '1. Length'\n";
    cout << "1.Length\n";
    cout << "2.Area\n";
    cout << "3.Volume\n";
    cout << "4.Time formats \n";
    cout << "5. Speed (km /h in mph in m/s)\n";
    cout << "6. Temperature (Fahrenheit to Celsius to Kelvin)\n";
    cout << "7. Mass (grams to kg to lbs to stones. you name it)\n";
    cout << "8. Energy \n";
    cout << "9. Pressure (bar to psi)\n";
    cout << "10. Density \n";
    cout << "11. Fuel consumption level (din l/100km in mile la galon si km la litru)\n";
    cout<< "12. Exit";
    
    cin>> answer;
    if(answer==12) return 0;
    else
    convertGenericUnit(answer);
       
    return 1;
} 
/*
void convertVolume(){
    double newVolume;
    toConvert volume;
    cout<<"1.ml, 2.cm3, 3.cl, 4.in3, 5.dl, 6.l, 7.dm3, 8.ft3, 9.gal(us), 10.gal(uk), 11.m3" ;
    
    cout<<"Please enter FROM and TO units you want to convert"<<endl;
    cin>>volume.initialMeasureUnit>>volume.convertToMeasureUnit;
    cout<<"Please enter value for conversion"<<endl;
    cin>>volume.userEnteredValue;
 
    
    newVolume = volume.userEnteredValue *  
            volumeUnits[volume.initialMeasureUnit-1].volumeValue / 
            volumeUnits[volume.convertToMeasureUnit-1].volumeValue;
            
    cout<<"You converted " 
            << volume.userEnteredValue 
            << volumeUnits[volume.initialMeasureUnit-1].volumeUnitName 
            << " to "
            << newVolume <<volumeUnits[volume.convertToMeasureUnit-1].volumeUnitName
            <<endl;
    
    
    bool reconvert;
    cout<<"Do you want to reconvert this value? 1.Yes 0.No";
    cin>>reconvert;
    if(reconvert) {
        volume.userEnteredValue=newVolume;
        volume.initialMeasureUnit=volume.convertToMeasureUnit;
        reconvertVolume(volume);
    }
}
*/
/*
void reconvertVolume(toConvert volume){
    cout<<" Please enter to what unit you want to convert again";
    cin>> volume.convertToMeasureUnit;
    double newVolume = volume.userEnteredValue *  volumeUnits[volume.initialMeasureUnit-1].volumeValue / volumeUnits[volume.convertToMeasureUnit-1].volumeValue;
    cout<<"Now converted" << volume.userEnteredValue <<volumeUnits[volume.initialMeasureUnit-1].volumeUnitName<<
            " to "<<newVolume<<volumeUnits[volume.convertToMeasureUnit-1].volumeUnitName<< endl;
    
}
 */
   
void convertGenericUnit(int answer){
    double newValue;
    toConvert newConversion;
            cout<< genericUnitMetrics[answer-1].genericUnitMetricIndex<<".";
            cout<< genericUnitMetrics[answer-1].genericUnitMetricName<<endl;

            for(int j=0; j<12; j++){         
               cout<< genericUnitMetrics[answer-1].genericUnits[j].genericUnitIndex 
                << "."<< genericUnitMetrics[answer-1].genericUnits[j].genericUnitName<<endl;
            }
            
    cout<<"Please enter FROM and TO units you want to convert"<<endl;
    cin>>newConversion.initialMeasureUnit>>newConversion.convertToMeasureUnit;
    cout<<"Please enter value for conversion"<<endl;
    cin>>newConversion.userEnteredValue;
    
    //cout<<"entered initial measure unit"<<newConversion.initialMeasureUnit<<endl;
    //cout<<"entered initial measure unit"<<newConversion.convertToMeasureUnit<<endl;
    
    //cout<<"initial  measurement unit value: "<<genericUnitMetrics[answer-1].genericUnits[newConversion.initialMeasureUnit].genericUnitValue<<endl;
    //cout<<"convert to measure value: "<< genericUnitMetrics[answer-1].genericUnits[newConversion.convertToMeasureUnit].genericUnitValue<<endl;
    
    newValue = newConversion.userEnteredValue *  
            genericUnitMetrics[answer-1].genericUnits[newConversion.initialMeasureUnit].genericUnitValue / 
            genericUnitMetrics[answer-1].genericUnits[newConversion.convertToMeasureUnit].genericUnitValue ;
            
    cout<<"You converted " 
            << newConversion.userEnteredValue 
            << genericUnitMetrics[answer-1].genericUnits[newConversion.initialMeasureUnit].genericUnitName
            << " to "
            << newValue
            << genericUnitMetrics[answer-1].genericUnits[newConversion.convertToMeasureUnit].genericUnitName
            <<endl;
     
}


void setupGenericUnitsStruct(){
    cout.precision(17);
    cout<<"Now creating generic units struct"<<endl;;
   
    for(int i=0; i<9; i++){
        genericUnitMetrics[i].genericUnitMetricIndex=i;
        genericUnitMetrics[i].genericUnitMetricName= conversionOptions[i];
        cout<<genericUnitMetrics[i].genericUnitMetricIndex<< "." << genericUnitMetrics[i].genericUnitMetricName<<endl;
        
        for(int j=0; j<12; j++){         
                genericUnitMetrics[i].genericUnits[j].genericUnitIndex=j;
                genericUnitMetrics[i].genericUnits[j].genericUnitName=conversionUnits[i][j];
                genericUnitMetrics[i].genericUnits[j].genericUnitValue=conversionValues[i][j];
           
                cout<<genericUnitMetrics[i].genericUnits[j].genericUnitIndex 
                << " || "<< genericUnitMetrics[i].genericUnits[j].genericUnitName
                << " || "<< genericUnitMetrics[i].genericUnits[j].genericUnitValue<<endl;
            }
        cout<<endl;
        }
    }

void loadConversionValuesInMl() {
    cout.precision(10);
    ifstream infile("ConversionValuesInML.txt");
    if (!infile) {
        cout << "Cannot open file.\n";
        return;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 12; j++) {
            double value;
            infile >> value;
            
            if(value==-1){break;}
             conversionValues[i][j]=value;
           //  cout<<conversionValues[i][j]<<endl;
          
        }
    }
    infile.close();
}

void loadConversionUnits() { 
    ifstream infile("ConversionUnits.txt");
    if (!infile) {
        cout << "Cannot open file.\n";
        return;
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 12; j++) {
            string line;
            infile >> line;
            if( line == "."){
                break;
            }
            else conversionUnits[i][j]=line;
          //cout<<conversionUnits[i][j]<<endl;
        }
    }
    infile.close();
}
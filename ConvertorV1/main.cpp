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
#include "conversionBase.h"

#ifndef NOLOGGING
#define LOG(msg)
#else
#define LOG(msg) std::cout << "[LOG] (" __FILE__ ":" << __LINE__ << ") from " << __func__ << "()\n    " << msg << "\n";
#endif

typedef std::numeric_limits< double > dbl;

massUnit massUnits[7];
volumeUnit volumeUnits[11];
genericUnitMetric genericUnitMetrics[11];

string conversionOptions[11]={"Length", "Area", "Volume", "Time", "Speed", "Temperature","Mass", "Energy", "Pressure", "Density", "Fuel consumption level"};
double conversionValues[4][11];
string conversionUnits[3][11];

int main() {
    cout << "Welcome to Convertor V1 @1992 Style: " << endl;
    int shouldContinue=1;
   /* while(shouldContinue==1){
        shouldContinue=displayMainMenu();
    }
    */
    loadConversionValuesInMl();
    loadConversionUnits();
    setupGenericUnitsStruct();
    
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
        switch (answer)
        {
            case 1:
                cout << "1.Length options:\n";
                cout << "1. m || 2. km || 3. mile";
                break;
            case 2:
                cout << "2.Area\n";
                displayAreaOptions();
                break;
            case 3:
                cout << "3.Volume\n";
                setupGenericUnitsStruct();
                convertGenericUnit();
               // convertVolume();
                break;
            case 4:
                cout << "4.Time formats \n";
                break;
            case 5:
                cout << "5. Speed (km /h in mph in m/s)\n";
                break;
            case 6:
                cout << "6. Temperature (Fahrenheit to Celsius to Kelvin)\n";
                displayTemperatureOptions();
                break;
            case 7:
                cout << "7. Mass (grams to kg to lbs to stones. you name it)\n";
                convertMass();
                break;
            case 8:
                cout << "8. Energy \n";
                break;
            case 9:
                cout << "9. Pressure (bar to psi)\n";
                break;
            case 10:
                cout << "10. Density \n";
                break;
            case 11:
                cout << "11. Fuel consumption level (din l/100km in mile la galon si km la litru)\n";
                break;
            case 12:
                cout<< "Exit -12";
                return 0;
            default:
                cout << "Please pick a number from the options above, thanks!";
        }
        return 1;
} 

void displayAreaOptions() {
    cout<<"U so void";
}
void displayTemperatureOptions() {
    int from, to;
    cout << "6. Temperature options (in degrees):\n";
        cout << "1. Celsius || 2. Fahrenheit|| 3. Kelvin";
        cout<< "Enter what you are converting from and to \n ";
        cout<< "eg: first option number represent FROM. second option number represents TO. eg: 1 3 will convert from F to K\n ";
        cout<< "from:";
        cin>>from;
        cout<<"to:";
        cin>>to;
        convertTemperature(from, to);
}

void convertMass() {
    int from, to;
    double mass, newMass;
    cout<<"1. mg || 2. g || 3. kg || 4.tone || 5. lb || 6. oz || 7. slug \n";
       cin>>from>>to;
    cout<<"Enter value:\n";
    cin>>mass;
    setupMassUnitsStruct();
    newMass=mass *  massUnits[from-1].massValue / massUnits[to-1].massValue;
    cout<<"You converted "<<mass<<massUnits[from-1].massUnitName<< "to "<< newMass <<massUnits[to-1].massUnitName<< "\n";
}

void convertTemperature(int from, int to) {
    double degrees;
    cout<<"Please enter value you want to convert";
    cin>>degrees;
    if(from==1)
        if(to==1)cout<<degrees<<" hey, you just converted a bunch!";
        else 
            if (to==2) {
                degrees*=33.8;
                cout<< degrees <<"F\n";
                
            }

}
void convertVolume(){
    double newVolume;
    toConvert volume;
    cout<<"1.ml, 2.cm3, 3.cl, 4.in3, 5.dl, 6.l, 7.dm3, 8.ft3, 9.gal(us), 10.gal(uk), 11.m3" ;
    
    cout<<"Please enter FROM and TO units you want to convert"<<endl;
    cin>>volume.initialMeasureUnit>>volume.convertToMeasureUnit;
    cout<<"Please enter value for conversion"<<endl;
    cin>>volume.userEnteredValue;
    
    setupVolumeUnitsStruct();
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

void reconvertVolume(toConvert volume){
    cout<<" Please enter to what unit you want to convert again";
    cin>> volume.convertToMeasureUnit;
    double newVolume = volume.userEnteredValue *  volumeUnits[volume.initialMeasureUnit-1].volumeValue / volumeUnits[volume.convertToMeasureUnit-1].volumeValue;
    cout<<"Now converted" << volume.userEnteredValue <<volumeUnits[volume.initialMeasureUnit-1].volumeUnitName<<
            " to "<<newVolume<<volumeUnits[volume.convertToMeasureUnit-1].volumeUnitName<< endl;
    
}
/*
void convertGeneric(genericUnitMetric newUnitMetric){
    double newConversion;
    if(newUnitMetric.genericUnitMetricIndex==3) {
       cout<<"1.ml, 2.cm3, 3.cl, 4.in3, 5.dl, 6.l, 7.dm3, 8.ft3, 9.gal(us), 10.gal(uk), 11.m3" ;
       toConvert volume;
       cin>>volume.initialMeasureUnit>>volume.convertToMeasureUnit;
       cin>>volume.userEnteredValue;
       setupVolumeUnitsStruct();
    }
   
}
*/
 
   
void convertGenericUnit(){
    double newVolume;
    toConvert newConversion;
    cout<<"1.ml, 2.cm3, 3.cl, 4.in3, 5.dl, 6.l, 7.dm3, 8.ft3, 9.gal(us), 10.gal(uk), 11.m3" ;
    cout<<"Please enter FROM and TO units you want to convert"<<endl;
    cin>>newConversion.initialMeasureUnit>>newConversion.convertToMeasureUnit;
    cout<<"Please enter value for conversion"<<endl;
    cin>>newConversion.userEnteredValue;
    
    newVolume = newConversion.userEnteredValue *  
            genericUnitMetrics[3].genericUnits[newConversion.initialMeasureUnit-1].genericUnitValue / 
            genericUnitMetrics[3].genericUnits[newConversion.convertToMeasureUnit-1].genericUnitValue ;
            
    cout<<"You converted " 
            << newConversion.userEnteredValue 
            << genericUnitMetrics[3].genericUnits[newConversion.initialMeasureUnit-1].genericUnitName
            << " to "
            << newVolume
            << genericUnitMetrics[3].genericUnits[newConversion.convertToMeasureUnit-1].genericUnitName
            <<endl;
}


void setupGenericUnitsStruct(){
    cout.precision(17);
    cout<<"Now creating generic units struct"<<endl;;
   
    for(int i=0; i<3; i++){
        genericUnitMetrics[i].genericUnitMetricIndex=i;
        genericUnitMetrics[i].genericUnitMetricName= conversionOptions[i];
        cout<<genericUnitMetrics[i].genericUnitMetricIndex<< "." << genericUnitMetrics[i].genericUnitMetricName<<endl;
        
        for(int j=0; j<11; j++){         
                genericUnitMetrics[i].genericUnits[j].genericUnitIndex=j;
                genericUnitMetrics[i].genericUnits[j].genericUnitName=conversionUnits[i][j];
                genericUnitMetrics[i].genericUnits[j].genericUnitValue=conversionValues[i][j];
           
                cout<<genericUnitMetrics[i].genericUnits[j].genericUnitIndex 
                << " || "<< genericUnitMetrics[i].genericUnits[j].genericUnitName
                << " || "<< genericUnitMetrics[i].genericUnits[j].genericUnitValue;  
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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 11; j++) {
          infile >> conversionValues[i][j];
          //cout<<conversionValues[i][j]<<endl;
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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 11; j++) {
          infile >> conversionUnits[i][j];
          //cout<<conversionUnits[i][j]<<endl;
        }
    }
    infile.close();
}
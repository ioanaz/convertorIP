/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "conversionBase.h"


void setupMassUnitsStruct(){
    if(massUnits[1].massIndex==0){
        static double massConvValues[7]={1, 1000, 1000000, 1000000000, 453592, 28349.5, 14593903};
        string massUnitsNames[7]={"mg", "g", "kg", "tone", "oz(AV)", "slug"};
        for(int i=0; i<7; i++){
            massUnit massUnit;
            massUnit.massIndex = i;
            massUnit.massUnitName = massUnitsNames[i];
            massUnit.massValue = massConvValues[i];
            massUnits[i]=massUnit;      
        }
  
    }
    
}

void setupVolumeUnitsStruct(){
    if(volumeUnits[1].volumeIndex==0){
        static double volumeConvValues[11]={1, 1, 10, 16.387, 100, 1000, 1000, 28320, 3785, 4546, 1000000};
        string volumeUnitsNames[11]={"ml", "cm3", "cl", "in3", "dl", "l", "dm3", "ft3", "gal(us)", "gal(uk)", "m3" };
        for(int i=0; i<11; i++){
            volumeUnit volumeUnit;
            volumeUnit.volumeIndex = i;
            volumeUnit.volumeUnitName = volumeUnitsNames[i];
            volumeUnit.volumeValue = volumeConvValues[i];
            volumeUnits[i]=volumeUnit;      
        }
  
    }
    
}



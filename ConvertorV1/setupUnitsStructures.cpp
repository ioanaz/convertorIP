/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "conversionBase.h"


void setupMassUnitsArray(){
    if(massUnits[1].massIndex==0){
        
        cout<< "/n lalal/n";
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

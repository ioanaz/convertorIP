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

using namespace std;

void displayMainMenu();
void displayAreaOptions();
void displayTemperatureOptions();
void convertTemperature(int from, int to);
int answer;

int main() {
    cout << "Welcome to Convertor V1 @1992 Style: " << endl;
    displayMainMenu();
   
    
}

void displayMainMenu() {
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
            default:
                cout << "Please pick a number from the options above, thanks!";
        }
        cout << "You picked option "<< answer;
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

void convertTemperature(int from, int to) {
    double degrees;
    cout<<"Please enter value you want to convert";
    cin>>degrees;
    if(from==1)
        if(to==1)cout<<degrees<<" hey dumbass, you just converted a bunch!";
        else 
            if (to==2) {
                degrees*=33.8;
                cout<< degrees <<"F\n";
                
            }

}
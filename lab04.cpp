//
// Created by Sarah Ogent on 10/4/21.
//
#include <iostream>
#include <fstream>
#include "calc3DDistModule.h"
#include <vector>
using namespace std;




int main(){
    ifstream fin;
    ofstream fout;
    float inputData;
    float x1, x2, y1, y2, z1, z2;
    float coordinateDistance;
    vector<float>inputCoordinates;
    int i;
    cout<<"Opening input.txt file"<<endl;

    fin.open("/Users/sogent/CLionProjects/lab4-sogent/input.txt");
    if(!fin.is_open()){
        cout<<"Could not open input.txt file"<<endl;
        return 1;
    } else{
        cout<<"\"input.txt\" file has successfully opened"<<endl;
    }
    cout<<endl;

    cout<<"Reading in x, y and z coordinates"<<endl;
    while(fin>>inputData){
        inputCoordinates.push_back(inputData);

    }

    cout<<"Closing input.txt file"<<endl;
    fin.close();
    cout<<endl;

    cout<<"Opening output.txt file"<<endl;
    fout.open("output.txt");
    if(!fout.is_open()){
        cout<<"Could not open \"input.txt\" file"<<endl;
        return 1;
    }else{
        cout<<"\"output.txt\" file has opened successfully"<<endl;
    }








    for(i=0;i<inputCoordinates.size()-1;i+=6){
        x1 = inputCoordinates.at(i);
        x2 = inputCoordinates.at(i+1);
        y1=inputCoordinates.at(i+2);
        y2=inputCoordinates.at(i+3);
        z1=inputCoordinates.at(i+4);
        z2=inputCoordinates.at(i+5);

        cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<z1<<" "<<z2<<endl;
        coordinateDistance = calc3Ddistance(x1, x2, y1, y2, z1, z2);
        cout << coordinateDistance<<endl;
    }



    //creat function for calculating distance
   // coordinateDistance= calc3Ddistance(x1, x2, y1, y2, z1, z2);
   //cout << coordinateDistance;



    return 0;
}


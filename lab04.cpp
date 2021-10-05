//
// Created by Sarah Ogent on 10/4/21.
//
#include <iostream>
#include <fstream>
#include "calc3DDistModule.h"
#include "mergeSortAlg.h"
#include <vector>

using namespace std;


int main(){
    ifstream fin; //initialize inputfile stream
    ifstream fin2;
    ofstream fout; //initialize outputfile stream
    ofstream fout2;
    double inputData;
    double x1, x2, y1, y2, z1, z2;
    double coordinateDistance;
    vector<double>inputCoordinates;
    vector<double>outputDistance;
    vector<double>sortedOutputDistance;
    int i;

    cout<<"Opening \"input.txt\" file"<<endl;

    fin.open("/Users/sogent/CLionProjects/lab4-sogent/input.txt");
    if(!fin.is_open()){
        cout<<"Could not open \"input.txt\" file"<<endl;
        return 1;
    } else{
        cout<<"\"input.txt\" file has opened successfully "<<endl;
    }
    cout<<endl;

    cout<<"Reading in x1, x2, y1, y2, z1, and z2 coordinates from file"<<endl;
    while(fin>>inputData){
        inputCoordinates.push_back(inputData);
    }

    cout<<"Closing \"input.txt\" file"<<endl;
    fin.close();
    cout<<endl;


    cout<<"Opening \"output.txt\" file"<<endl;
    fout.open("output.txt");
    if(!fout.is_open()){
        cout<<"Could not open \"output.txt\" file"<<endl;
        return 1;
    }else{
        cout<<"\"output.txt\" file has opened successfully"<<endl;
    }


    for(i=0;i<inputCoordinates.size()-1;i+=6) {
        x1 = inputCoordinates.at(i);
        x2 = inputCoordinates.at(i + 1);
        y1 = inputCoordinates.at(i + 2);
        y2 = inputCoordinates.at(i + 3);
        z1 = inputCoordinates.at(i + 4);
        z2 = inputCoordinates.at(i + 5);

        cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2 << endl;
        coordinateDistance = calcDistance(x1, x2, y1, y2, z1, z2);
        cout<<coordinateDistance<<endl;
        fout<<coordinateDistance<<endl;
        /*
        while(i<outputDistance.size()) {
            coordinateDistance = calcDistance(x1, x2, y1, y2, z1, z2);
            outputDistance.push_back(coordinateDistance);
            ++i;
        }
         */
    }

    cout<<"Closing \"output.txt\" file"<<endl;
    fout.close();


    cout<<"Re-opening \"output.txt\" file"<<endl;
    fin2.open("output.txt");
    if(!fin2.is_open()){
        cout<<"Could not open \"output.txt\" file"<<endl;
        return 1;
    }else{
        cout<<"\"output.txt\" file has opened successfully"<<endl;
    }

    cout<<"Reading in calculated distance coordinates from file"<<endl;
    while(fin2>>inputData){
        outputDistance.push_back(inputData);
    }

    cout<<"Closing \"output.txt\" file"<<endl;
    fin2.close();
    cout<<endl;

    /*
    for(i=0;i<outputDistance.size();++i){
        cout<<outputDistance.at(i)<<endl;
    }
     */

    cout<<endl;
    cout<<"Sorted calculated coordinates in ascending order: "<<endl;
    MergeSort(outputDistance, 0, outputDistance.size()-1);
    for(i=0;i<outputDistance.size();++i){
        cout<<outputDistance.at(i)<<endl;
    }

    cout<<"Opening \"output_sorted.txt\" file"<<endl;
    cout<<endl;

    fout2.open("output_sorted.txt");
    if(!fout2.is_open()){
        cout<<"Could not open \"output_sorted.txt\" file"<<endl;
        return 1;
    } else{
        cout<<"\"output_sorted.txt\" file has opened successfully "<<endl;
    }
    cout<<endl;

    for(i=0;i<outputDistance.size();++i){
        //cout<<outputDistance.at(i)<<endl;
        fout2<<outputDistance.at(i)<<endl;
    }

    cout<<"Closing \"output_sorted.txt\" file"<<endl;
    fout2.close();
    cout<<endl;

    return 0;
}
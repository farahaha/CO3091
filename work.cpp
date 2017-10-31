//
//  work.cpp
//  
//
//  Created by Farah Abubaker on 10/30/17.
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;


int main () {

    string line;
    string filename, filename2;
    int check = 0;

    ofstream myfile;
    ifstream in;    // Create an input file stream.
    in.open("config-opt4j-salesman-coursework.txt");  // Use it to read from a file named data.txt.
    
    
    
    //First for loop is to create the 4 different config files
    for(int i = 0; i < 4; i++){
        
        //Second for loop is to create 30 of each of the 4 config files
        for(int j = 0; j < 3; j++){
    
            filename = "config" + to_string(i+1) + "-seed" + to_string(j+1) + ".txt";
            filename2 = "config" + to_string(i+1) + "-seed" + to_string(j+1) + ".tsv";
            cout << filename << endl;
            myfile.open (filename);
            
            //getting line from config file, altering data & seed, creating new file
            while (getline(in, line)){
                check++;
                if(check == 3){
                    myfile << "    <property name=\"filename\">" << filename2 << "</property>" << endl;
                    continue;
                }
                if(check == 12){
                    myfile << "    <property name=\"seed\">" << to_string(j+1) << "</property>" << endl;
                    continue;
                }
                
                if(i == 1 && check == 44){
                
                    myfile << "    <property name=\"crossoverRate\">0.6</property>" << endl;
                    continue;
                    
                }
                if(i == 2 && check == 41){
                    
                    myfile << "    <property name=\"alpha\">155</property>" << endl;
                    continue;
                }
                if(i == 2 && check == 42){
                    
                    myfile << "    <property name=\"mu\">155</property>" << endl;
                    continue;
                }
                if(i == 2 && check == 43){
                    
                    myfile << "    <property name=\"lambda\">155</property>" << endl;
                    continue;
                }
                if(i == 3 && check == 41){
                    
                    myfile << "    <property name=\"alpha\">155</property>" << endl;
                    continue;
                }
                if(i == 3 && check == 42){
                    
                    myfile << "    <property name=\"mu\">155</property>" << endl;
                    continue;
                }
                if(i == 3 && check == 43){
                    
                    myfile << "    <property name=\"lambda\">155</property>" << endl;
                    continue;
                }
                if(i == 3 && check == 44){
                    
                    myfile << "    <property name=\"crossoverRate\">0.6</property>" << endl;
                    continue;
                    
                }
                
                myfile << line << endl;
        
            }
    
            check = 0;
            in.clear();
            in.seekg(0, in.beg);
            myfile.close();
        }
    }
    
    
}





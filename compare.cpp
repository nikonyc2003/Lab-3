//Author: Nikolas Bano
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: Lab 3
//This program prints out task c
//.
//.
//.
//.
//.

#include <iostream>
#include <fstream>
#include <cstdlib> // For exit()
#include <climits> // For INT_MAX
#include <string>

using namespace std;

int main(){
    string start, end;
    cout << "Enter starting date: ";
    cin >> start;
    cout << "Enter ending date: ";
    cin >> end;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
  }
  
    string junk;
    getline(fin, junk);

    string date;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 

    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

    if(date >= start && date <= end){
    cout << date << " ";
  
      if (eastEl > westEl){
          cout << "East" << endl;
    }  else if (eastEl < westEl){
          cout << "West" << endl;
    }  else if (eastEl == westEl){
          cout << "Equal" << endl;
    }
  }
}
    fin.close();
}
   

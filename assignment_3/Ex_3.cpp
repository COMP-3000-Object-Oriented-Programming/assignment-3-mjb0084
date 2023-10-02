#include <iostream>
#include <iomanip>
using namespace std;


int main(void){

    int length=0,temp=0;
    int inArray[50];
    int count=0;

    // Create array
    cout << "Enter elements of an  integer array followed by any non-integer to end\n";

    // Get user input for elements of array
    for (int i=0;i<49;i++){
        
        cin >> inArray[i];
        if (cin.fail()){
            inArray[i] = 0;
            break;
        }
        else {
            length ++;
        }
    }
 
    // sort values in descending order

    while (count<length){
        for (int i=0;i<length-1;i++){
            
            if (inArray[i]<inArray[i+1]){
                temp = inArray[i];
                inArray[i] = inArray[i+1];
                inArray[i+1] = temp;
                count = 0;
            }
            else count += 1;
        }
    }
    // assign values to the number of times a value occurs
    // and output left justified w/ width of 10
    count = 1;
    cout << setw(10) << left << "Value:"<< setw(10) << left << "Count:";
    for (int i=0;i<length;i++){
        if (inArray[i]==inArray[i+1]){
            count ++;

        }
        else {
            cout << "\n" << setw(10) << left << inArray[i] << " " << count;
            count = 1;
        }
    } 
    
}



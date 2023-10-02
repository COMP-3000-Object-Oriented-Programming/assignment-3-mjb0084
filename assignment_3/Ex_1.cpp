#include <iostream>
using namespace std;

string getNum(void);
// int* makeArray(string input);
bool numCheck(string num);

int main(void){

    string num1, num2;

	//get two numbers with less than 20 digits and store them as strings
    num1 = getNum();
    while (!(numCheck(num1))){
        cout << "Please enter a positive number with 20 or less digits\nNumber: ";
		cin >> num1;
    }
    num2 = getNum();
	while (!(numCheck(num2))){
        cout << "Please enter a positive number with 20 or less digits\nNumber: ";
		cin >> num2;
    }

	int length1 = num1.length();
	int length2 = num2.length();
	
	// Reverse the input numbers
	// 1st Number:
	char temp;
	for (int i = 0; i < length1/2; ++i){
		temp = num1[length1-i-1];
		num1[length1-i-1] = num1[i];
		num1[i] = temp;
   }
	// 2nd Number:
	for (int i = 0; i < length1/2; ++i){
		temp = num2[length2-i-1];
		num2[length2-i-1] = num2[i];
		num2[i] = temp;
   }

	// Put the 1st Number into a 20 element array
	int A1[20];
	for (int i=0; i<20; i++){
        if (i<(20-length1)){
			A1[i] = 0;
			// cout << A1[i];
		}
		else {
			A1[i] = int(num1[20-i-1]-48);
			// cout << A1[i];
		}
	}
	
	// Put the 2nd Number into a 20 element array
	int A2[20];
	for (int i=0; i<20; i++){
        if (i<(20-length2)){
			A2[i] = 0;
			// cout << A2[i];
		}
		else {
			A2[i] = int(num2[20-i-1]-48);
			// cout << A2[i];
		}
	}
	

	// Do iterative math for each value, take carry value and
	// add it to the next term
	int carry = 0;
	float sum = 0;
	for (int i=19; i>=0; i--){
		float isum = A1[i]+A2[i]+carry;
		if (isum>=10){
			sum += (isum-10)*pow(10,(19-i));
			carry = 1;	
		}
		else {
			
			sum += (isum)*pow(10,(19-i));
			carry = 0;
		}
	}

	cout << "The sum is: " << int(sum);

    return 0;
}

string getNum(void){
    string number;

    cout << "Number: ";
    cin >> number;
    return number;

}


bool numCheck(string num){
    return ((num.length()<20));
}


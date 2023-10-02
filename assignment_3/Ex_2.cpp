#include <iostream>

using namespace std;

bool isFull(char seatChar[7][5]);
char checkSeat(char seatChar[7][5],int row,char seatc, int seat);
void printSeats(char seatChart[7][5]);
int convertSeat(char seatc);

int main() {
	char seatChart[7][5] = {
        {'1','A','B','C','D'},
        {'2','A','B','C','D'},
        {'3','A','B','C','D'},
        {'4','A','B','C','D'},
        {'5','A','B','C','D'},
        {'6','A','B','C','D'},
        {'7','A','B','C','D'}
    }; 
	int row = 0,
    seat = 0;
	char seatc = ' ',
    enterAgain = 'N';

	do {
        // Display available seats
        cout << "\nAvailable Seats:";
		printSeats(seatChart);

        // Get desired seat
		cout << "\nEnter desired row number: ";
		cin  >> row;
		while (row < 1 || row > 7) {
			cout << "Enter a value between 1 and 7: ";
            cin >> row;
		}
		cout << "Enter desired seat letter: ";
		cin  >> seatc;
		// Use ASCII values for A - D to validate input
		while (seatc < 'A' || seatc > 'D') {
			cout << "Enter A, B, C, or D: ";
			cin  >> seatc;
		}

        // Convert seatc to integer
        seat = convertSeat(seatc);
        // Check if seat is available and book if it is
		
        seatChart[7][5] = checkSeat(seatChart,row,seatc, seat);
		cout << "\nWould you like to book another seat?" << endl
		     << "Enter Y for yes and anything else to quit:";
		cin  >> enterAgain;
	} while(enterAgain == 'Y' && !(isFull(seatChart)));
 
	if (isFull(seatChart))
		cout << "Sorry, there are no more empty seats on this plane." << endl;
 
	return 0;
}

bool isFull(char seatChar[7][5]) {
	for (int i = 0; i < 7; i++) {
        for (int j = 1; j < 4; j++) {
			if (seatChar[i][j] != 'X')
				return false;
		}
	}
	return true;
}

char checkSeat(char seatChart[7][5], int row, char seatc,int seat) {
	
    if (seatChart[row-1][seat] == 'X'){
        cout << "That seat is taken.";
        return seatChart[7][5];
    }
    else {
        seatChart[row-1][seat] = 'X';
        cout << "Your seat is " << row << seatc;
        return seatChart[7][5];
    }

}

void printSeats(char seatChart[7][5]) {
	for (int i = 0; i<=6; i++){
        cout << "\n";
        for (int j =0; j<=4;j++){
            cout << seatChart[i][j] << " ";

        }

    }
    
	
}

int convertSeat(char seatc){
    switch(seatc){
        case 'A':return 1;
        case 'B':return 2;
        case 'C':return 3;
        case 'D':return 4;
        default :return 0;
    }
}
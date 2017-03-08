/* Nicholas Vadivelu
 * TER 4M1
 * 1 March 2017
 * Mr. Jay
 * Functions problem set
 */
 
 
#include <iostream>
#include <conio.h> //allows for getch
#include <tgmath.h> //square root

using namespace std;

int getInt(int low, int high = INT_MAX) { 
//Forces user to enter a value between the high and low integer then returns that value
	int val = 0; // declare variables
	cin >> val; //user input
	
	//loop until val is in the range
	while (val > high || val < low) {
		cout << "Enter a value between " << low << " and " << high << ": ";
		cin >> val;
	}
	return val;
}

int sumLimit (int val) {
	//Returns sum of all integers from 1 up to val
	int sum = 0; //sum variable
	
	for (int i = 1 ; i <= val ; i++)
		sum += i; //adds up sum
	
	return sum;
}

void sumLimit () {
	//outputs sum of all integers from a 1 up to a value
	int sum = 0;
	
	cout << "Enter a positive integer: "; //promt user
	sum = sumLimit(getInt(0));//calculate
	cout << "\nThe sum is " << sum << endl; //output sum
}

bool prime (int num){
	//returns true if num is prime
	bool isPrime = true;
	
	for (int i = 2 ; i <= num/2 ; i++)
		isPrime = isPrime && num % i != 0; //check for each value
	
	return isPrime;
}

void prime() {
	//says is prime is positive
	bool isPrime;
	
	cout << "Enter a positive integer: "; //promt user
	isPrime = prime(getInt(0));//calculate
	cout << "\nThis is" << (isPrime ? "" : " not") << " a prime number.\n";
}

bool quadratic (int A, int B, int C, double &x1, double &x2) {
	//solves the quadratic equation then returns roots x1 and x2
	int det = B*B - 4*A*C; //calculate determinant
	bool hasRoots = det >= 0; //checks if it has roots
	if (hasRoots){ //finds roots
		x1 = (- 1.0*B - sqrt(det))/(2*A);
		x2 = (- 1.0*B + sqrt(det))/(2*A);
	}
	
	return hasRoots;
}

void quadratic () {
	//solves user inputted quadratic equation
	//declare variables
	int a, b, c;
	double x1, x2;
	bool hasRoots;
	
	//prompt user
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;
	cout << "Enter C: ";
	cin >> c;
	
	//calculate
	hasRoots = quadratic(a, b, c, x1, x2);
	
	//output roots
	cout << endl;
	if (hasRoots && x1 == x2) 
		cout << "This quadratic has one root at x = " << x1 << endl;
	else if (hasRoots)
		cout << "This quadratics has roots at x1 = " << x1 << " and x2 = " << x2 << endl;
	else
		cout << "This quadratic has no real roots" << endl;
}

int main () { //main driver class
	int choice = 1;

    while (choice != 0) //exit when 0
    {
        system("cls"); // clears screen
        
        //prompts user with selection info
        cout << "Functions Practice Problem Set\n";
        cout << "------------------------------\n";
        cout << "1. Sum Limit\n";
        cout << "2. Prime\n";
        cout << "3. Quadratic\n";
        cout << "0. Quit\n\n";
        cout << "Choice: ";
        //gets user input
        choice = getInt(0, 3);
        
        system("cls"); // clears screen
        //calls appropriate method based on number user chooses
        if (choice == 1)
            sumLimit (); // call arithmetic
        else if (choice == 2)
            prime (); //call equation
        else if (choice == 3)
            quadratic (); //call quadratic
          
		//prompt user to continue  
		if (choice != 0){
        	cout << endl << "Press any key to continue...";
        	getch();
    	}
    }
    return 0; //ends program
}

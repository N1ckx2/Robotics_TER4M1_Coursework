/* Nicholas Vadivelu
 * TER 4M1
 * 27 February 2017
 * Mr. Jay
 * For problem set
 */

#include <iostream>
#include <conio.h> //allows for getch

using namespace std;

void squares() { //displays integers along with their squares up to a user defined value
	//declare variables 
	int num = 0;
	
	//prompt for inpuit
	cout << "Enter an integer: ";
	cin >> num;
	
	//loops through output
	cout << "\nNumber  Square" << endl;
	for (int i = 1; i <= num ; i++) { //loops through numbers up to num
		cout.width(3); 
		cout << i; //output num
		cout.width(8);
		cout << (i*i) << endl; //output square
	}
}

void products () { //multiplies inputted number of positive ingtegers
	//declare variables
	int num = 0, input = 0, product = 1;
	
	//prompt user for number of numbesr to input
	cout << "How many numbers to process? ";
	cin >> num;
	
	//loop and get input
	cout << "\nEnter " << num << " positive integers" << endl;
	for (int i = 1; i <= num ; i++) {
		cout << "#" << i << ": ";
		cin >> input;
		
		//checks for negative inputs
		if (input <= 0)
			cout << input << " not counted" << endl;
		else
			product *= input;
	}
	
	//output resultss
	cout << endl << "The product of the positives is " << product << "." << endl;
}

void factorial () { //calculates the factorial of the inputted number
	//declare variables
	unsigned long long num = 0, factorial = 1;
	
	//prompt user for input
	cout << "Enter a non-negative integer: ";
	cin >> num;
	
	//output factorial
	cout << endl;
	if (num < 0 || num > 20) //checks for bounds
		cout << "Invalid input: number must <= 20 and >= 0" << endl;
	else if (num > 1) { //normal case
		for (int i = num ; i >= 2 ; i--){
			cout << i << " x ";
			factorial *= i;
		}
		cout << "1 = " << factorial << endl;
	} else if (num == 1 || num == 0)  //normal case
		cout << num << "! = " << factorial << endl;
}

void invest () {
	//determines balance, interest, and other factors about a bank account based on initial conditions
	
	//declare variables
	double deposit, interest, term;
	double balance = 0, iearned = 0;
	
	//prompt user for input
	cout << "Monthly Deposit         :  ";
	cin >> deposit;
	cout << "Annual Interest Rate (%):  ";
	cin >> interest;
	cout << "Term (Months)           :  ";
	cin >> term;
	
	//output information
	cout << "\nStarting     Interest     Monthly     Ending" << endl;
	cout << "Balance        Earned     Deposit    Balance" << endl;
	cout << "--------     --------     -------    -------" << endl;
	
	for (int i = 0 ; i < term ; i++){
		// calcualte and output interest and balance for each month in term
		iearned = balance*interest/12.0/100.0; //interest earned
		printf("%7.2f%14.2f", balance, iearned); //starting balance
		balance += iearned + deposit; //final deposit
		
		//display information
		printf("%12.2f%11.2f\n", deposit, balance);
	}
}

int main () { //main method
	char choice = 't';

    while (choice != '0') //exit when 0
    {
        system("cls"); // clears screen
        
        //prompts user with selection info
        cout << "Problem Set #1 - For Loop Practice Problems\n";
        cout << "-------------------------------------------\n";
        cout << "1. Squares\n";
        cout << "2. Products\n";
        cout << "3. Factorial\n";
        cout << "4. Invest\n";
        cout << "0. Quit\n\n";
        cout << "Choice: ";
        //gets user input
        cin >> choice;
        
        system("cls"); // clears screen
        //calls appropriate method based on number user chooses
        if (choice == '1')
            squares (); // call arithmetic
        else if (choice == '2')
            products (); //call equation
        else if (choice == '3')
            factorial ();
        else if (choice == '4')
            invest ();
          
		//prompt user to continue  
		if (choice != '0'){
        	cout << endl << "Press any key to continue...";
        	getch();
    	}
    }
    return 0; //ends program
}

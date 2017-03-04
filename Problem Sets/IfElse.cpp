/* Nicholas Vadivelu
 * TER 4M1
 * 27 February 2017
 * Mr. Jay
 */

#include <iostream>
#include <conio.h> //allows for getch

using namespace std;

void arithmetic() { //shows mathematical operations for two user inputted integers
	//declare variables
	double a, b;
	
	//prompts user for two operands
	cout << "Operand #1: ";
	cin >> a;
	cout << "Operand #2: ";
	cin >> b;
	
	//outputs operations for operands
	cout << endl << a << " + " << b << " = " << (a+b) << endl;
	cout << a << " - " << b << " = " << (a-b) << endl;
	cout << a << " x " << b << " = " << (a*b) << endl;
	cout << a << " / " << b << " = ";
	
	//conditional to check for denominator = 0
	if (b == 0 ) cout << "undefined" << endl << endl;
	else cout << (a/b) << endl;
}

void equation () { //shows the solution to a linear expression of the form mx + b = y
	int a, b;
	double x;
	
	cout.setf(ios::fixed); // sets format for decimals 
   	cout.precision(3); //three decimal place accuracy
	
	//prompts user for input and receives input
	cout << "Enter values for Ax + B = 0" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << endl;
	
	//output steps to solve
	cout << a << "x " << (b < 0 ? "- " : "+ ") << (b < 0 ? (0-b) : b)<< " = 0" << endl;
	cout << a << "x = " << (0-b) << endl;
	cout << "x = " << (a < 0 ? "-" :"") << (0-b) << "/" << (a < 0 ? 0-a:a) << endl;;
	cout << "x = ";
	
	//check for 0 divisor
	if (a != 0) {
		x = -b*1.0 / a;
		cout << x << endl;
	} else {
		cout << "undefined" << endl;
	}
	
}

void paycheque() {//calculates regular and overtime pay of employee based on wage and hours worked
	//declare variables
	double wage, hrs, regpay, overpay;
	
	cout.setf(ios::fixed); // sets format for decimals 
	cout.precision(2); //three decimal place accuracy
	
	//prompt for input
	cout << "Enter hourly wage: $";
	cin >> wage;
	cout << "Enter number of hours worked for one week: ";
	cin >> hrs;
	
	// calculate pay
	if (hrs <= 40) {
		regpay = wage*hrs;
		overpay = 0;
	} else if (hrs > 40) {
		regpay = 40 * wage;
		overpay = (hrs-40) * wage * 1.5;
	}
	
	//output regular and overtime pay
	cout << "\nRegular Pay = $" << regpay << endl;
	cout << "Overtime Pay = $" << overpay << endl;
	cout << "Total Pay = $" << (regpay + overpay) << endl;
}

void pizza() { //calculates cost of order based on size and number of pizzas
	//declare variables
	int numPizzas;
	double cost = 0, price = 0;
	char size;
	bool valid = true;
	
	cout.setf(ios::fixed); // sets format for decimals 
	cout.precision(2); //three decimal place accuracy
   	
	//prompt for input
	cout << "Enter number of pizzas: ";
	cin >> numPizzas;
	cout << "Enter size (S, M, L): ";
	cin >> size;
	
	//calculate cost
	valid = numPizzas > 0;
	
	if (size == 's' || size == 'S') price = 6.99;
	else if (size == 'm' || size == 'M') price = 8.99;
	else if (size == 'l' || size == 'L') price = 10.99;
	else valid = false;
	cost = numPizzas * price;
	
	//output cost of order
	if (valid) {
		cout << "\nNumber of pizzas = " << numPizzas << endl;
		cout << "Price per pizza = $" << price << endl;
		cout << "Total cost = $" << cost << endl;
	} else {
		cout << "\nInvalid input" << endl;
	}
}

void sort() { //sorts three integer inputs
	//declare variables
	int a, b, c;
	int max, min, mid;
	
	//prompt user for input
	cout << "Enter 3 integers: " << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "C: ";
	cin >> c;
	
	//calculate max, min, and middle
	max = (a > b ? a : b);
	max = (max > c ? max : c);

	min = (a < b ? a : b);
	min = (min < c ? min : c);
	 
	if (a == max) mid = (b == min ? c : b);
	else if (b == max) mid = (a == min ? c : a);
	else mid = (a == min ? b : a);
	
	//output sorted integers
	cout << "\nSorted integers: " << max << ", " << mid << ", " << min << endl;
}

int main () {
	char choice = 't';

    while (choice != '0') //exit when 0
    {
        system("cls"); // clears screen
        
        //prompts user with selection info
        cout << "Problem Set #1 - If Practice Problems\n";
        cout << "--------------\n";
        cout << "1. Arithmetic\n";
        cout << "2. Equation\n";
        cout << "3. Paycheque\n";
        cout << "4. Pizza\n";
        cout << "5. Sort\n";
        cout << "0. Quit\n\n";
        cout << "Choice: ";
        //gets user input
        cin >> choice;
        
        system("cls"); // clears screen
        //calls appropriate method based on number user chooses
        if (choice == '1')
            arithmetic (); // call arithmetic
        else if (choice == '2')
            equation (); //call equation
        else if (choice == '3')
            paycheque ();
        else if (choice == '4')
            pizza ();
        else if (choice == '5')
            sort ();
          
		//prompt user to continue  
		if (choice != '0'){
        	cout << endl << "Press any key to continue...";
        	getch();
    	}
    }
    return 0; //ends program
}

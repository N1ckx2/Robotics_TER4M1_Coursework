/* Nicholas Vadivelu
 * TER 4M1
 * 1 March 2017
 * Mr. Jay
 * While Loop problem set
 */

#include <iostream>
#include <conio.h> //allows for getch

using namespace std;

void addingIntegers () { //adds integers inputted by user until 0 is inputted
	//declare variables
	int num, total = 0;
	
	//prompt user for input
	cout << "Enter first integer (enter 0 to quit): ";
	cin >> num;
	
	//continuous input until 0
	if (num == 0)
		cout << "No integers were entered.\n";
	else {
		total += num;
		while (num != 0) {
			cout << "Enter an integer (or 0 to quit): ";
			cin >> num;
			total += num;
		}
		
		//output sums
		cout << "Sum of the integers: " << total << endl;
	}
	cout << "bye\n";
}

void milesPerGallon () { //calculates miles per gallon of cars
	//declare variables
	double initial = 0, final, gallons, mpg;
	
	cout.setf(ios::fixed); // sets format for decimals 
   	cout.precision(1); //three decimal place accuracy
	
	while (initial >= 0) {
		//prompt for user input
		cout << "Initial miles:\n";
		cin >> initial;
		if (initial >= 0) {
			cout << "Final miles:\n";
			cin >> final;
			cout << "Gallons\n";
			cin >> gallons;
		
			//calculate mpg
			mpg = (final - initial)*1.0/gallons;
			
			//output MPG
			cout << "Miles per Gallon: " << mpg << endl << endl;
		}
	}
	cout << "bye\n";
}

void inRangeAdder () {
 //asks user for range, then adds up numbers in and outside or range independently. displays both sums at the end
	
	//declare variables
	int low, high, num = -1, sumInRange = 0, sumOutRange = 0;
	
	//prompt user for input
	cout << "In-range Adder" << endl;
	cout << "Low end of range:" << endl;
	cin >> low;
	cout << "High end of range:" << endl;
	cin >> high;
	
	while (num != 0) { //keeps going until input is
		//prompt for all the data
		cout << "Enter data:" << endl;
		cin >> num;
		
		//check to see which sum to add the number to
		if (num != 0 && num >= low && num <= high)
			sumInRange += num;
		else if (num != 0)
			sumOutRange += num;
	}
	
	//out final sums
	cout << "Sum of in range values: " << sumInRange << endl;
	cout << "Sum of out of range values: " << sumOutRange << endl;
}

void shippingCostCalculator () { //calcaulates shipping based on weight inputted and variable shipping & handling costs
	//declare variables
	int weight = 1;
	double shipping;
	
	cout.setf(ios::fixed); // sets format for decimals 
   	cout.precision(2); //three decimal place accuracy
	
	while (weight > 0) {
		//prompt for user input
		cout << "Weight of Order:\n";
		cin >> weight;
		
		if (weight > 0){
			//calculate shipping cost
			shipping = (weight <= 10 ? 3 : 3 + (weight-10.0)*0.25);
		
			//output result
			cout << "Shipping Cost: $" << shipping << endl << endl;
		}
	}
	
	cout << "\nbye\n";
}

void hailstoneNumbers() {
	//asks user for positive integer, calculates new value based on even or odd
	// repeat until reach 1
	
	//declare variables
	int n = 0, length = 1, max = 0;
	
	//prompt user for input
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << endl << n << endl;
	//calculate new value for n
	while (n != 1){
		if (n%2 == 0) n/= 2; //even
		else n = 3*n + 1; //odd
		
		//output numbers
		cout << n << endl;
		
		length++;
		max = (n > max ? n : max);
	}
	
	//output length
	cout << "\nLength of sequence: " << length << endl;
	cout << "Maximum integer: " << max << endl;
}

int main () { //main driver class
	char choice = 't';

    while (choice != '0') //exit when 0
    {
        system("cls"); // clears screen
        
        //prompts user with selection info
        cout << "Problem Set 8 - Sentinel Controlled Loops\n";
        cout << "-----------------------------------------\n";
        cout << "1. Adding Integers\n";
        cout << "2. Miles per Gallon\n";
        cout << "3. In-range Adder\n";
        cout << "4. Shipping Cost Calculator\n";
        cout << "5. Hailstone Numbers\n";
        cout << "0. Quit\n\n";
        cout << "Choice: ";
        //gets user input
        cin >> choice;
        
        system("cls"); // clears screen
        //calls appropriate method based on number user chooses
        if (choice == '1')
            addingIntegers (); // call arithmetic
        else if (choice == '2')
            milesPerGallon (); //call equation
        else if (choice == '3')
            inRangeAdder ();
        else if (choice == '4')
            shippingCostCalculator ();
    	else if (choice == '5')
            hailstoneNumbers ();
          
		//prompt user to continue  
		if (choice != '0'){
        	cout << endl << "Press any key to continue...";
        	getch();
    	}
    }
    return 0; //ends program
}

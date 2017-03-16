/* Nicholas Vadivelu
 * TER 4M1
 * 14 March 2017
 * Mr. Jay
 * Arrays Problem Set
 */
 
#include <iostream>
#include <conio.h> //allows for getch
#include <stdlib.h> // srand, rand 
#include <time.h> //time

using namespace std;

int* fill (int size) {
	//accepts desired size, creates and returns array with random integers from 1 - 10
	int* temp = new int[size]; //declare array
	
  	srand (time(NULL)); //initialize random seed
	//fill array up
	for (int i = 0 ; i < size ; i ++) 
		temp[i] = rand() % 10 + 1; //num between 1 and 10
	
	return temp;
}

double avg (int array[], int size){
	//accepts array and its size, returns average of values
	double avg = 0; //declare variable
	
	//compute average
	for (int i = 0 ; i < size ; i++)
		avg += array[i];
	avg /= size;
	
	return avg;
}

int min (int* array, int size){
	//accepts array and its size, returns minimum of values
	int min = INT_MAX;
	
	for (int i = 0 ; i < size ; i++) //find minimum
		min = (array[i] < min ? array[i] : min);
		
	return min;
}

int max (int* array, int size){
	//accepts array and its size, returns maximum of values
	int max = INT_MIN; //declare variable
	
	for (int i = 0 ; i < size ; i++) //find minimum
		max = (array[i] > max ? array[i] : max);
		
	return max;
}

int search (int array[], int size, int toFind) {
	//finds first occurence of toFind, or -1 if not found
	int index = -1; //declare variable
	
	for (int i = 0 ; i < size && index == -1; i++)
		index = (array[i] == toFind ? i : -1); //finds first occurence of toFind
		
	return index;
}

int* addItem (int* array, int &size, int val, int pos){
	//inserts value at position and returns array
	int *temp = new int[++size]; //declare temp
	
	for (int i = 0, j = 0 ; i < size ; i++) //temp with the new val inserted
		temp[i] = (i == pos ? val : array[j++]);
	
	return temp;
}

int* removeItem (int array[], int &size, int pos){
	//removes item from specified position and return array
	int *temp = new int[--size];
	
	for (int i = 0, j = 0; i < size; i++) 
		temp[i] = (i == pos ? array[++i] : array[i]); //removes item
	
	return temp;
}


int* input (int *array, int &size) {
	//allows user to input values into array until enter -1 to quit
	int input; //declare variables
	
	//get values
	cout << "Input value (-1 to quit): ";
	cin >> input;
	while (input != -1){
		array = addItem(array, size, input, size);
		cout << "Input value (-1 to quit): "; //prompt user
		cin >> input;
	}
	
	return array;
}

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

int main () { //main method
	char choice = -1;
	int* array;
	int size = 0;

    while (choice != 0) //exit when 0
    {
        system("cls"); // clears screen
        
        //prompts user with selection info
        cout << "Problem Set #6 - Array Practice\n";
        cout << "-------------------------------\n";
        
    	//display array
    	cout << "Current Array: ";
    	if (size == 0)
    		cout << "null";
    	else {
    		for (int i = 0 ; i < size ; i++)
    			cout << *(array+i) << " ";
    	}
    	cout << "\nSize: " << size << endl << endl;
    	
    	//show options
        cout << "1. Fill\n";
        cout << "2. Input\n";
        cout << "3. Average\n";
        cout << "4. Min\n";
        cout << "5. Max\n";
        cout << "6. Search\n";
        cout << "7. Add Item\n";
        cout << "8. Remove Item\n";
        cout << "0. Quit\n\n";
        cout << "Choice: ";
        //gets user input
        choice = getInt(0, 8);
          
        system("cls"); // clears screen
        
        //calls appropriate method based on number user chooses
        if (choice == 1) {
        	cout << "Desired array size: "; //prompt user for input
        	size = getInt(0); //receive size
        	array = fill(size);
		} else if (choice == 2)
			array = input(array, size);
		else if (choice == 3)
			cout << "The average of the array is " << avg(array, size) << endl;
		else if (choice == 4)
			cout << "The minimum of the array is " << min(array, size) << endl;
		else if (choice == 5)
			cout << "The maximum of the array is " << max(array, size) << endl;
		else if (choice == 6){
			int toFind, pos; //declare variable
			cout << "Value to be found: "; //prompt user
			cin >> toFind; //input value
			pos = search(array, size, toFind);
			cout << (pos == -1 ? "Value not in array. Position returned by function: " : "Value is at position ") << pos;
		}
		else if (choice == 7) {
			int item, pos; //declare variables
			
			//user input
			cout << "Item to be added: ";
			cin >> item;
			cout << "Position where it is to be added: ";
			pos = getInt(0, size);
			
			array = addItem(array, size, item, pos); //add item
		} else if (choice == 8) {
			int pos; //declare variables
			if (size > 0){
				cout << "Position of item to be removed: ";
				pos = getInt(0, size-1);
				array = removeItem(array, size, pos);
			} else {
				cout << "Cannot remove items from an empty array";
			}
		}
			
		//prompt user to continue  
		if (choice != 0){
        	cout << endl << endl << "Press any key to continue...";
        	getch();
    	}
    }
    return 0; //ends program
}

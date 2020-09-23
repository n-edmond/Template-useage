//NEHESIA EDMOND
//CS 201L
//PROGRAM 14
//DUE 29 APRIL

#include <iostream>
#include <fstream>

using namespace std;

template <class T> void readFile(T myArray[], string fileName);//READS FILE AND SAVES INFO INTO ARRAY
template <class T> void mySwap(T myArray[], int pos1, int pos2);//SWAPS THE POSITION OF 2 CHOSEN ELEMENTS
template <class T> T myMin(T myArray[]);//SEARCHES ARRAY AND FINDS THE MIN VALUE 
template <class T> T myMax(T myArray[]);//SEARCHES ARRAY AND FINDS THE MAX VALUE
template <class T> int mySearch(T myArray[], T itemToFind);//SEARCHES ARRAY FOR CHOSEN ITEM. RETURNS -1 IF NOT FOUND, OTHERWISE RETURN POSITON
template <class T> void writeData(T myArray[], string placeHolderWord, int pos1, int pos2, T search1, T search2);//SAVES ALL INFO TO OUTPUT FILE

int main()
{
	int intArray[100];
	double dblArray[100];
	string strArray[100];
	readFile(intArray, "integers.txt");
	readFile(dblArray, "doubles.txt");
	readFile(strArray, "strings.txt");

	//CHANGE DESIRED INTEGER OUTPUT HERE
	string placeHolderWord = "Integers:";
	int swapPos1 = 10;//CHANGE POSITION INDEXES HERE. POSITION 1 ALL FUNCTIONS USE SAME POSITON
	int swapPos2 = 20;//CHANGE POSITION INDEXES HERE. POSITION 2 ALL FUNCTIONS USE SAME POSITION
	int searchPos1 = 1;
	int searchPos2 = 5;
	writeData(intArray, placeHolderWord, swapPos1, swapPos2, searchPos1, searchPos2);

	//CHANGE DESIRED DOUBLE OUTPUT HERE
	placeHolderWord = "Doubles:";
	double dsearchPos1 = 4.62557;
	double dsearchPos2 = 1.23456;
	writeData(dblArray, placeHolderWord, swapPos1, swapPos2, dsearchPos1, dsearchPos2);

	//CHANGE DESIRED STRING OUTPUT HERE
	placeHolderWord = "Strings:";
	string ssearchPos1 = "Shoes";
	string ssearchPos2 = "Pumpkin";
	writeData(strArray, placeHolderWord, swapPos1, swapPos2, ssearchPos1, ssearchPos2);

	return 0;
}

template <class T> void readFile(T myArray[], string fileName)//TEMPLATE USED SINCE SEVERAL ARRAYS W/ VARYING TYPES ARE USING THIS
{
	ifstream fileIn;
	fileIn.open(fileName);
	if ( fileIn.fail() ) 
	{
		cout << "Input file opening failed\n";//DISPLAYS ERROR MESSAGE IF FILE DOES NOT OPEN CORRECTLY.
	}
	int i = 0;//USED TO DETERMINE WHERE TO PUT FILE CONTENTS. INITILIZED TO 0
	while (fileIn.good() ) 
	{
		fileIn >> myArray[i];
		i++;//INCREMENT I TO MOVE ARRAY TO NEXT POSITION
	}
	fileIn.close();
	return;
}

template <class T> void mySwap(T myArray[], int pos1, int pos2)
{
	T tempPos = myArray[pos1];//CREAE TEMP VARIABLE TO SAVE POSITON 1 INTO
	myArray [pos1]= myArray [pos2]; //POSITION 1 IS NOW EQUAL TO POSITON 2.
	myArray [pos2] = tempPos; // POSITION 2 IS SET TO THE SAVED VALUE OF POSITION 1
}

template <class T> T myMin(T myArray[])
{
	T myMin = myArray[0];//ASSUME FIRST ITEM IN ARRAY IS THE SMALLEST
	for (int i = 0; i < 100; ++i)//WHILE SEARCHING THROUGH ARRAY, COMPARE THE SAVED MIN TO THE CURRENT INDEX
	{
		if (myArray[i] < myMin)
		{
			myMin = myArray[i];//IF LOWER, CURRENT INDEX IS NOW THE NEW MIN
		}
	}
	return myMin;
}

template <class T> T myMax(T myArray[])
{//SAME CONCEPT WITH MIN
	T myMax = myArray[0];//ASSUME FIRST ITEM IN ARRAY IS THE LARGEST
	for (int i = 0; i < 100; ++i)//WHILE SEARCHING THROUGH ARRAY, COMPARE THE SAVED MAX TO THE CURRENT INDEX
	{
		if (myArray[i] > myMax)
		{
			myMax = myArray[i];//IF HIGHER, CURRENT INDEX IS NOW THE NEW MAX
		}
	}
	return myMax;
}

template <class T> int mySearch(T myArray[], T itemToFind)
{
	for (int i = 0; i < 100; ++i)//WHILE SEARCHING THROUGH ARRAY, SEE IF ITEM TO FIND IS IN ARRAY
	{
		if (myArray[i] == itemToFind)
		{
			return i;//IF FOUND RETURN THE INDEX I
		}
		else if ((myArray[i] != itemToFind) && (i == 99))
		{
			return -1; //IF IT IS NOT FOUND AND AT THE END OF ARRAY, RETURN -1 TO INDICATE NOT FOUND
		}
	}
}

template <class T> void writeData(T myArray[], string placeHolderWord, int pos1, int pos2, T search1, T search2)//TEMPLATE USED SINCE VARYING ARRAY TYPES NEEDED
{
	ofstream fileOut;
	fileOut.open("output.txt",std::ios_base::app);//USED TO OPEN THE FILE AND APPEND NEW INFO INSTEAD OF OVERWRITTING
	if ( fileOut.fail() ) 
	{
		cout << "Output file opening failed\n";//ERROR MESSAGE FOR IF THE FILE IS NOT CREATED
	}
	//FORMATTING DESIRED OUTPUT HERE
	fileOut << placeHolderWord << endl;//USED TO CHANGE THE SECTION HEADER WHEN CALLED
	fileOut << "Swapped items at positions " << pos1 << " and " << pos2 << endl;
	fileOut << "Before: [" << pos1 << "] " << myArray[pos1] << "   [" << pos2 << "] " << myArray[pos2] << endl;
	mySwap(myArray, pos1, pos2);//SWAP POSITION FUNCTION CALLED HERE TO CHANGE ARRAY AFTER INITIAL ARRAY DISPLAYED
	fileOut << "After:  [" << pos1 << "] " << myArray[pos1] << "   [" << pos2 << "] " << myArray[pos2] << endl;
	fileOut << "Minimum: " << myMin(myArray) << endl;
	fileOut << "Maximum: " << myMax(myArray) << endl;
	fileOut << "The number " << search1 << " is at position " << mySearch(myArray, search1) << endl;
	fileOut << "The number " << search2 << " is at position " << mySearch(myArray, search2) << endl << endl;

	fileOut.close();
}
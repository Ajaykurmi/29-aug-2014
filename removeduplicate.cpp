 /*4.Design an algorithm and write code to remove the duplicate characters in a string 
without using any additional buffer NOTE: One or two additional variables are fine 
An extra copy of the array is not 
FOLLOW UP
Write the test cases for this method  removeduplicate.cpp */

/*  Algo for removing duplicate 
	Step 1: define removeDuplicate(character array)
	Step 2: // write loop logic
	Step	2.0: FOR I to End of the size of charcter array
	Step		2.0.0: Check if string contain space then ignore it jump to 2.0 step
	Step		2.0.1: FOR J to End of the size of charcter array
	Step			2.0.1.0: I==J Jump to 2.0.1 step // leave same character comparison
	Step		 	2.0.1.1: Check array[I]==array[j] then shift the array to one position on right site 
	step 3:	return array // return un duplicate array				
	
	// BEST CASE: best would be when string will contain only spaces then it would be 0(n)
	// Worst CASE: if all character will be same then 0(n qube)
*/

#include<iostream>
using namespace std;

class duplicateTreatment{
	public: char* removeDuplicate(char *arr) {
		for (int i = 0; arr[i]!= '\0'; ++i)
		{
			if(arr[i]==32)
				continue;
			for (int j = i+1;  arr[j]!= '\0'; ++j)
			{
				if(i==j)
					continue;
				if(arr[i]==arr[j]) { // array shifting
					for(int k=j;arr[k]!= '\0';k++){
						arr[k]=arr[k+1];
					}
				}
			}
		}
		return arr;
	}
};

void main(){

	char arr[200];
	cout<<"Please Enter charcter string for finding duplicate values: ";
	if(cin.getline(arr,100)){
		//int strLength = (sizeof(arr)/sizeof(*arr)); // getting size of string
		duplicateTreatment revStr;
		char* value = revStr.removeDuplicate(arr);
		printf("\nWithout Duplicated string are: %s\n", value);
	}
}
/*
Test Cases
Case 1: Please Enter charcter string for finding duplicate values: this is test
		Without duplicated string are: this  e

*/
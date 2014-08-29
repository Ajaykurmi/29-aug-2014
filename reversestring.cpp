// Write code to reverse a C-Style String (C-String means that “abcd” is represented as five characters, including the null character)
#include<iostream>
using namespace std;

class reverseString {
	public: int strLength;
	public: reverseString(int strLen){
		strLength = strLen;
	}
	
	public: char* getReverseString(char arr[]){
		//char revArr[2];
		char *input;
		int i;
		input = (char *) malloc(sizeof(char));  // creating dynamic character array for inserting rever
		int arrSize = strLength;
		for (i = 0; arr[i]!='\0'; ++i)
		{
			input[arrSize-2]=arr[i];
			arrSize--;
		}
		input[i] = '\0';
		return input;
	}

	void reverseStringUsingRecursion(char *str,char *container,int counter)
	{
   		if(*str) {
       		return reverseStringUsingRecursion(str+1,container,counter++);
       		//cout << *str;
       		container[counter] = *str;
   		} else 
   			return container; 
	}

};

int main(){
	char arr[] = "ajays ";
	int strLength = (sizeof(arr)/sizeof(*arr)); // getting size of string 
	
	
	reverseString revStr(strLength);

	char* value = revStr.getReverseString(arr);

	printf("\nReversed String is: %s\n", value);


}
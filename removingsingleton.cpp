/* 
4 question: Given a string and a character, remove from the string all single occurrences of the character, 
while retaining all multiple consecutive instances of the character. For instance, given string "XabXXcdX", removing singleton Xs leaves the string "abXXcd".
*/

#include<iostream>
using namespace std;

class removingsingleton
{
public:
	removingsingleton(){}
	~removingsingleton(){}
	char* removeSingleTon(char *str,char removechar){
		char* dynamic = (char *) malloc(100*sizeof(char));
		int counter=0;
		int repeatCount=0;
		for (int i = 0; str[i]!='\0'; ++i)
		{//counter
			if(str[i]==removechar) {
				if(i==0) {
					if(str[i]==str[i+1]){
						dynamic[counter]=str[i];
						counter++;
					}
				} else {
					if(str[i]==str[i+1] || str[i]==str[i-1]){
						dynamic[counter]=str[i];
						counter++;
					}
				}
			} else {
				repeatCount=0;
				dynamic[counter]=str[i];
				counter++;
			}
		}
		dynamic[counter]='\0';
		return dynamic;
	}
};

void main(){
	cout<<"Please enter charaters string ";
	char str[100];
	if(cin.getline(str,100)){
		char removingChar;
		cout<<"\nRemovale charater(enter only single character)";
		if(cin>>removingChar){
			removingsingleton rs;
			char* value=rs.removeSingleTon(str,removingChar);
			printf("\nFiltered charaters are: %s\n", value);
		} else {
			cout<<"\nPlease enter only one character";	
		}
	} else
		cout<<"Please enter only character string";
	
}

/*
Test Case 1:  Please enter charaters string: ajaysing
				Removale charater(enter only single character) j
				Filtered charaters are: aaysing

*/
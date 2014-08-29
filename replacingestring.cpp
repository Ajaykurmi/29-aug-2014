/* Write a method to replace all spaces in a string with ‘%20’*/

#include<iostream>
using namespace std;
class StringReplace{
	public: char* replaceSpace(char *arr){
		int i=0;
		int j=0;
		char *dynamic;
		//dynamic = (char *) malloc(sizeof(char));
		dynamic = new char[100];
		for (int i = 0; arr[i]!='\0'; ++i)
		{
			if(arr[i]==32){
				dynamic[j]='%';
				j++;
				dynamic[j]='2';
				j++;
				dynamic[j]='0';
				j++;
			} else {
				dynamic[j]=arr[i];
				j++;
			}
		}
		dynamic[j]='\0';
		return dynamic;
	}
};

void main(){
	

	cout<<"Please enter charaters string ";
	char str[100];
	if(cin.getline(str,100)){
		StringReplace repl;
		char* value = repl.replaceSpace(str);
		printf("\nReplaced St are: %s\n", value);
	}
	else
		cout<<"Please enter only character string";
}
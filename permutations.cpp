/*
	Q.8 Write a C program to print all permutations of a given string
*/
#include<iostream>
using namespace std;

class Permutations {
public:
	Permutations(){}
	~Permutations(){}
	char * generatePermutations(char *str,int n,int index){
		int i;
		if((n-1)==index) {
			printf("%s\n",str);
		}
		for (i = index; i < n; ++i)
		{
			swap((str+index),(str+i));
			generatePermutations(str,n,(index+1));
			swap((str+index),(str+i));	
		}

	}

	void swap (char *x, char *y)
	{
    	char temp;
    	temp = *x;
    	*x = *y;
    	*y = temp;
}

};

void main(){
	char str[10];
	cout<<"Please enter a string to find permutations(max length is 10)";
	if(cin.getline(str,10)) {
		  Permutations p;
		  char *res = p.generatePermutations(str,strlen(str),0);
	} else cout<<"Please enter valid data for generating permutations";
}
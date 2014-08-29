/*
Q.6 Given a stream of characters, find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at any moment.
*/
#include<iostream>
using namespace std;

class repeatingCharacter {
	public: repeatingCharacter(){}
		~repeatingCharacter(){}
		int findFirstNonRepeatingCharacter(char * str,int n) {
			
			int i,j;
			for (i = 0; str[i]!='\0'; ++i)
			{
				for (j = i+1; str[j]!='\0'; ++j)
				{
					if(str[i]==str[j])
						break;
				}
				if(n==j) {
					return i;
				}
			}
		}
};
void main(){
	cout<<"Please enter string (max length 100)";
	char str[100];
	if(cin.getline(str,100)) {
		repeatingCharacter rc;
			//char *sequence= ls.findLongestSubSequesce(seq1,seq2);
			int charPos= rc.findFirstNonRepeatingCharacter(str,strlen(str));
			printf("\nResults are:: %c\n", str[charPos]);
	}
}

/* 
Progra complexity is O(n2)
*/
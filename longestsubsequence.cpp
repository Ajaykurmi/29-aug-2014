/*
Q.2 Given two sequences, print the longest subsequence present in both of them.
Examples: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
Here LCS stands for  Longest Common Subsequence ABCDGH
												AEDFHR
												AGGTAB
												GXTXAYB
*/
#include<iostream>
using namespace std;
class longestSubsequence {
public:
	longestSubsequence(){}
	~longestSubsequence(){}

	char * findLongestSubSequesce(char *seq1,char *seq2){
		char* c = new char[100];
		int counter=0;
		for (int i = 0; seq1[i]!='\0'; ++i)
		{
			for (int j = 0; seq2[j]!='\0'; ++j)
			{
				if(seq1[i]==seq2[j]) {
					c[counter] = seq1[i];
					counter++;
					break;
				}
			}
		}
		c[counter]='\0';
		return c;
	}

	char* lcs(char *seq1,int seq1Lenght,char *seq2,int seq2Lenght){
		int maxLenStr = seq1Lenght;
		char temp[100];
		int tempIncrement=0;
		if(seq2Lenght>seq1Lenght)
			maxLenStr = seq2Lenght;
		

		for (int i = 0; i < maxLenStr; ++i)
		{
			char seq1Value = '|';
			char seq2Value = '|';
			if(seq1Lenght>i)
				seq1Value = seq1[i];

			if(seq2Lenght>i)
				seq2Value = seq2[i];
			int seq1FindIndex = 0;
			int seq2FindIndex = 0;
			
			// run first inner loop for first string
			for (int j = 0; seq1[j]!='\0'; ++j)
			{
				
				if(seq2Value==seq1[j]) 	
					break;
				
				seq1FindIndex++;
			} 
			// run second inner loop for second string
			for (int k = 0; seq2[k]!='\0'; ++k)
			{
				
				if(seq1Value==seq2[k]) 
					break;
				
				seq2FindIndex++;
			} 
			
			if(seq1FindIndex==seq1Lenght && seq2FindIndex==seq2Lenght) {
				continue;
			} else {
				if(seq1FindIndex==seq1Lenght) {
					temp[tempIncrement]=seq1Value;
					
					tempIncrement++;
				} else if(seq2FindIndex==seq2Lenght) {
					temp[tempIncrement]=seq2Value;
					tempIncrement++;
				} else {
					if(seq1FindIndex<=seq2FindIndex) {
						temp[tempIncrement]=seq2Value;
						tempIncrement++;
					} else {
						temp[tempIncrement]=seq1Value;
						tempIncrement++;
					}
				}

			} 
		}
		temp[tempIncrement]='\0';
		return removeDuplicate(temp);
	}

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
					i--;
				}
			}
		}
		return arr;
	}
};

void main(){
	cout<<"Please enter text for first string for seq1(max length 100)";
	char seq1[100];
	if(cin.getline(seq1,100)) {
		cout<<"Please enter text for first string for seq2(max length 100)";
		char seq2[100];
		if(cin.getline(seq2,100)) {
			longestSubsequence ls;
			//char *sequence= ls.findLongestSubSequesce(seq1,seq2);
			char *sequence= ls.lcs(seq1,strlen(seq1),seq2,strlen(seq2));
			printf("\nResults are:: %s\n", sequence);
		}
	}
}

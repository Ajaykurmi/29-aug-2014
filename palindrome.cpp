/*
Q.9 Given a string, check if it is a rotation of a palindrome. For example your function should return true for “aab” as it is a rotation of “aba”.
Examples:
Input:  str = "aaaad"
Output: 1  
// "aaaad" is a rotation of a palindrome "aadaa"

Input:  str = "abcd"
Output: 0
// "abcd" is not a rotation of any palindrome.
*/
#include<iostream>
using namespace std;
class Palindrome {
	public:
		Palindrome(){}
		~Palindrome(){}
		/* 
			function veryfy is any string is palindrome or not
		*/
		bool isPalindrome(char *str,int n){
			for (int i = 0; i<(n/2); ++i)
			{
				if(str[i]!=str[(n-1)-i])
					return false;
			}
			return true;
		}
		/*
			function do rotation of string and checks palindrome using isPalindrome function
		*/
		bool rotateStrPalindrome(char *str,int n){
			if(isPalindrome(str,n)) {
				return true;
			}

			for (int i = 0; i<(n/2); ++i)
			{
				char backStr=str[0];
				for (int i = 0; i < n-1; ++i)
				{
					str[i]=str[i+1];
				}
				str[n-1]=backStr;
				if (isPalindrome(str,n))
				{
					return true;
				}
			}
			return false;
		}
};

void main(){
	char str[200];
	cout<<"Please Enter charcter string to check palindrome ";
	if(cin.getline(str,100)){
		Palindrome pd;
		if(pd.rotateStrPalindrome(str,strlen(str)))
			cout<<"\n String is palindrome";
		else 
			cout<<"\n String is not palindrome";
	}
}
/*
function best case is O(n/2)  : if string already is pailindrome

Worst case is  n/2((n-1)+(n/2)) : O(n2) operation
*/
/*Q.1 Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[])that prints all occurrences of pat[] in txt[].
You may assume that n > m.*/
#include<iostream>
using namespace std;

class searchPattern {
public:
	searchPattern(){}
	~searchPattern(){}
	int findPattern(char *txt,char *patt){
		int occurrences=0;
		int patternLength=-1 ;
		for (int i = 0; patt[i]!='\0'; ++i)
		{
			patternLength++;
		}
		//cout<<"patlen"<<patternLength<<"\n";
		for (int i = 0; txt[i]!= '\0'; ++i){
			//cout<<txt[i]<<"\n";
			//cout<<"I value:"<<i<<"\n";
			if(i>=patternLength) {
				int j=0;
				while(patt[j]!= '\0' && i>=j) {
					//cout<<patt[j]<<"\n";
					//cout<<txt[j+(i-patternLength)]<<"\n";

					if(patt[j]==txt[j+(i-patternLength)]) {
						j++;
					} else  break;
				}
				//cout<<"End of the loop\n";
				//cout<<j<<"\n";
				//cout<<patternLength<<"\n";
				if(j==patternLength+1)
					occurrences++;
				//cout<<"\n";
			}
		}
		return occurrences;
	}
};

void main(){
	cout<<"Please enter charaters text(max length is 100) ";
	char txt[100];
	if(cin.getline(txt,100)){
		char patt[100];
		cout<<"\nsearch pattern(max length is 98)";
		cin.getline(patt,100);
		searchPattern sp;
		int value = sp.findPattern(txt,patt);
		cout<<"Total pattern occurrences:"<<value; 
	}
}
/*
Q.4 MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.
Given a column number, find its corresponding Excel column name. Following are more examples.
Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
*/

 #include<iostream>
 using namespace std;
 class excelCalc {
 	public: excelCalc(){}
 			~excelCalc(){}

 			char* calculateExcelcolumn(char* columnsArr,int columnsNo){
 					int counter=0;
 					while(columnsNo>0) {
 						
 						int reminderVal=columnsNo%26;
 						cout<<reminderVal;
 						if(reminderVal==0) {
 							columnsArr[counter++]='Z';
 							columnsNo=(columnsNo/26)-1;
 						} else {
 							columnsArr[counter++]=(reminderVal-1)+'A';
 							columnsNo=(columnsNo/26);
 						}
 					}
 					columnsArr[counter]='\0';
 					return columnsArr;
 			}
 };

 void main(){
 	char columnsArr[50];
 	int columnsNo;
 	cout<<"Please enter a excel sheet column no for generating its alphabetic number";
 	if(cin>>columnsNo) {
 		excelCalc ec;
 		char* columnsName = ec.calculateExcelcolumn(columnsArr,columnsNo);
 		printf("\nExcel columns value is: %s\n", columnsName);
  	} else {
 		cout<<"Please enter only numbers";
 	}
 }

 /*
	
 */
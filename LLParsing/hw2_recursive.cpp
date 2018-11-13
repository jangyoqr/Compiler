/*
LRS(Language Recognition System)

테스트 스트링 : "abb$", "aaabbb$"


*/
/*
Language Recognizer for the following CFG.

0. A  -> CB
1. B -> +CB
2. B -> epsilon
3. C  -> ED
4. D -> *ED
5. D -> epsilon
6. E  -> (A)
7. E  -> a
*/

#include <stdio.h>
#include<iostream>
using namespace std;

char ch;
int errflag = 0;

/*
Recognition-failed message.
*/
void pA();  void pB(); void pC(); void pD(); void pE();
void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}

void pa()
{
	cout << "pa" << endl;
	if (ch == 'a')
		ch = getchar();
	else error();
}
void pplus()
{
	cout << "pplus" << endl;
	if (ch == '+')
		ch = getchar();
	else error();
}
void pmul()
{
	cout << "pmul" << endl;
	if (ch == '*')
		ch = getchar();
	else error();
}
void pl()
{
	cout << "pl" << endl;
	if (ch == '(') ch = getchar();
	else error();
}
void pr()
{
	cout << "pr" << endl;
	if (ch == ')')
		ch = getchar();
	else error();
}
void pb()
{
	cout << "pb" << endl;
	if (ch == 'b')
		ch = getchar();
	else error();
}

/*
A --> CB
*/
void pA()
{
	cout << "pA" << endl;
	pC();
	pB();
}

/*
B --> +CB
B --> epsilon
*/
void pB()
{
	cout << "pB" << endl;
	
		switch (ch) {
		case '+':
			pplus();
			pC();
			pB();
			break;
			/*case NULL:
				ch = getchar();
				break;
			*/
	
		}
		
	
}

/*
C --> ED
*/
void pC()
{
	cout << "pC" << endl;
	pE();
	pD();
}
/*
D --> *ED 
D --> epslion
*/
void pD()
{
	cout << "pD" << endl;
	
		switch (ch) {
		case '*':
			pmul();
			pE();
			pD();
			break;
		
		}
	
}
/*
E --> (A)
E --> a
*/
void pE()
{
	cout << "pE" << endl;
	switch (ch) {
	case '(':
		pl();
		pA();
		pr();
		break;
	case 'a' :
		pa();
		break;
	default:
		error();
	}
}
void main()
{
	puts("Production Rules:");
	puts("\tS --> aAb");
	puts("\tA --> aS");
	puts("\tA --> b");
	puts("\tA->CB");
	puts("\tB -> + CB");
	puts("\tB->epsilon");
	puts("\tC->ED");
	puts("\tD -> *ED");
	puts("\tD->epsilon");
	puts("\tE  -> (A)");
	puts("\tE->a");
	printf("$로 끝나는 입력스트링 : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}

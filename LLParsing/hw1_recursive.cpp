/*



*/
/*
Language Recognizer for the following CFG.

A-> aB
B->.A | epslion
*/

#include <stdio.h>
#include<iostream>
using namespace std;
char ch;
int errflag = 0;

/*
Recognition-failed message.
*/
void pA();
void pB();
void pcomma();
void pa();

void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}
void pcomma()
{

	if (ch == '.')
		ch = getchar();
	else error();
}
void pa()
{
	if (ch == 'a')
	{
		ch=getchar();
	
	}
	else error();
}
void pA()
{
	if (ch == 'a')
	{
		pa();
		pB();
	}
	else error();
}

void pB()
{

	if (ch == '.')
	{
		pcomma();
		pA();
	}
	else if (ch == '$') {  }
	else error();
}



void main()
{
	puts("Production Rules:");
	puts("\tA --> aB");
	puts("\tB -->.A | epslion");
	printf("$로 끝나는 입력스트링 : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}
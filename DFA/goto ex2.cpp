/*
DFA by goto statement.


Regular grammar for
	X -> aX | bY | a
	Y -> bX | aY | b
is Regular expression for (a+ba*b)*

*/
#include <stdio.h>

#define FAIL 0;
#define OKAY 1;

int ch;

int dfa()
{
	ch = getchar();
S:
	if (ch == 'a') {
		ch = getchar();
		goto A;
	}
	

	else return FAIL;
A:
	if (ch == 'b') {
		ch = getchar();
		goto B;
	}
	
	else return FAIL;
B:
	if (ch == 'a') {
		ch = getchar();
		goto C;
	}
	else return FAIL;
C:
	if (ch == 'a') {
		ch = getchar();
		goto C;

	}
	else if (ch == 'b') {
		ch = getchar();
		goto D;
	}
	else return FAIL;
D:
	if (ch == '\n') { goto F; }
	else if (ch == 'a')
	{
		ch = getchar();
		goto A;
	}
	else return FAIL;
F:
	return OKAY;

}

int main()
{
	if (dfa())
		puts("OK");
	else puts("FAIL");
}

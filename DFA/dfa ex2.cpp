/*
Simple DFA recognition program.
DFA -- (10)*(01)*
*/
#include <stdio.h>

#define STATES	4	/* number of states */
#define SYMBOLS	2	/* number of symbols */

/*
State Tranisition Table in p102.
4 is empty 
*/
int ST_TAB[STATES][SYMBOLS] = {
	/* state A */{ 1,2 },
	/* state B */{ 4,0 },  //and 4 is empty like null
 	/* state C */{ 3, 4 },
	/* state D */{ 4,2 }
};

void put_table(int tab[][SYMBOLS], int m, int n)
{
	int i;

	puts("State Transition Table");
	puts("\t0\t1");
	for (i = 0; i < m; i++)
		printf("%c\t%c\t%c\n",
			'A' + i, 'A' + tab[i][0], 'A' + tab[i][1]);
	puts("-----E is Empty-----");
	puts("Final states = { A,D }");
}

void main()
{
	int ch;	/* input symbol */
	int cur_state = 0;	/* start state */

	put_table(ST_TAB, STATES, SYMBOLS);

	ch = getchar();
	while (ch != '\n') {
		cur_state = ST_TAB[cur_state][ch - '0'];
		if (cur_state < 0) { puts("FAIL"); return; }
		ch = getchar();
	}

	if (cur_state == 0 || cur_state == 3) puts("OK");	/* final states = { 2 } */
	else puts("FAIL");
}

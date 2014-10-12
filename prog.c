#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define gi(x,y) (y*w + x)
#define size (h*w)

#define SEXT (char*)EXT
#define EL strlen(SEXT)
#define EXT &IS[4]
#define SIS (char *)IS

#define P V[0]

#define SX (b*)((int)p ^ (int)c)
#define S p = SX; c = SX; p = SX;

#define COMMENT ((IS[6]&0xff))
#define STOP  	((IS[6]>>8)&0xff)
#define EMPTY 	((IS[6]>>16)&0xff)
#define ED 		((IS[6]>>24)&0xff)

#define DEAD IS[7]
#define h IS[8]
#define w IS[9]

#define D addch(DEAD
#define MC memcpy((char*)a
#define I foo[4](SIS);foo[4](SEXT);initscr();getmaxyx(stdscr,h,w);halfdelay(1);start_color();init_pair(1, COLOR_RED, COLOR_WHITE);attron(COLOR_PAIR(1));curs_set(0);

#define r0 return(0);

#define O foo[v--](0,0);
#define bar(x) foo[x]();
#define b bool

b *c, *p;
//                   |Iteration               End of Iteration|  | .life         | IS[6]     |IS[7]|IS[8]|IS[9]
unsigned int IS[] = {0x0df12b49, 0x06f513ef, 0x05e6ccff, 0x9c3f, 0xfdfd3e2e, 0xff, 0x0a2e7121, 0x20, 0x00, 0x00}; // Game constants

int sIS(char *c)
{
	char prev = 0;
	sIS:
	if(c[0])	// Only do something when we are not at the end
	{
		c[0] += prev;
		prev = c[0];
		c++;
		goto sIS;
	}
	r0
}

int getNrED(int x, int y)
{
	int nrED;
	(p[gi(x, y)]) ? (nrED=-1) : (nrED=0);
	
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{			
			int xt = dx;
			int yt = dy;

			(xt < 0) ? (xt = w -1) : ((xt >= w ) ? (xt = 0) : 0);
			(yt < 0) ? (yt = h-1) : ((yt >= h) ? (yt = 0) : 0);

			p[gi(xt, yt)] ? nrED++:0;
		}
	}
	return nrED;
}

int ul(int x, int y)
{
	p[gi(x,y)] ? ((!(((unsigned int)getNrED(x, y)-2)<2))? (c[gi(x,y)] = false) : (c[gi(x,y)] = true)) : ((getNrED(x, y) == 3) ? (c[gi(x,y)] = true) : (c[gi(x,y)] = false));
	x++;
	
	(x >= w) ? (x = 0,	y++) : 0;
	(y < h+1) ?  (ul(x, y), x=x) : 0;
	r0
}

int pl(int i, int j)
{
	if(i == 0)
	{
		move(0,0);
	}
	
	if (i >= size)
	{
		static int iteration;
		mvprintw(0,0, SIS, iteration++);
		refresh();
	}
	else
	{
		i[c] ? D|ED) : D);
		pl(i+1, 2);
	}
	r0
}

b rf(char *filename)
{
	b retVal = false;
	FILE *readFP = fopen(filename, "r");
	if(readFP == NULL)
	{
		return false;
	}
	
	b sol = true;
	b sl = false;
	
	if ( readFP != NULL )
	{
		retVal = true;

		int x = 0;
		int y = 0;
		int ch;
notEOF:
		ch = fgetc( readFP );
		
		if(ch == EOF)
		{
			goto done;
		}
		
		sol ? (sol = false, (ch == COMMENT) ? sl = true : 0) : 0;
		(ch == '\n') ? (y++, x=0, sol = true, sl = false) : ((!sl)?	(c[gi(x,y)] = !(isspace(ch) || ch == EMPTY)), x++:0);
		(x >= w) ? (x = 0, y++) : 0;
		
		if(y >= h)
		{
			goto done;
		}
		goto notEOF;
	}	
	done:
	fclose(readFP);
	
	return retVal;
}

int (*foo[])() = {getch, pl, ul, endwin, sIS};

int main(int a, char **V)
{		
	I

	c = calloc(size<<1, sizeof(b));// Create a double sized buffer  
	p = c+size;				// Set p to half of the buffer
	b ld = true;
	
	// Initial board
	(a > 1) ? (ld = !rf(V[1])):0;
	ld ? (a = (int)calloc( strlen(P) + EL + 1, 1), MC, P, strlen(P)), MC+strlen(P), EXT, EL), rf((char*)a)) : 0;
	
	foo[1](0);
	
	while(foo[0]() == ERR);// Wait for user to press a button
	
again:
	S
	int v=2;
	O
	O
	a = bar(0);
	
	if(a == STOP || a == (STOP-0x20))
		goto stop;
	goto again;
stop:	
	foo[3]();
}
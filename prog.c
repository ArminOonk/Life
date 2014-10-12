#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#define getIndex(x,y) (y*w + x)
#define born(x,y) (getNrED(x, y) == 3)
#define dies(x,y) (!(((unsigned int)getNrED(x, y)-2)<2))

#define size (h*w)

#define SEXT (char*)EXT
#define EL strlen(SEXT)
#define EXT &IS[4]
#define SIS (char *)IS

#define P argv[0]

#define S p = (bool*)((int)p ^ (int)c); c = (bool*)((int)p ^ (int)c); p = (bool*)((int)p ^ (int)c);
#define COMMENT IS[6]
#define STOP  IS[7]
#define EMPTY IS[8]
#define ED IS[9]
#define DEAD IS[10]

#define D addch(DEAD
#define MC memcpy((char*)argc
#define I sIS(SIS);sIS(SEXT);initscr();getmaxyx(stdscr,h,w);halfdelay(1);start_color();init_pair(1, COLOR_RED, COLOR_WHITE);attron(COLOR_PAIR(1));curs_set(0);

int h, w;	// to store the number of hs and the number of wums of the screen
bool *c, *p;

unsigned int IS[] = {0x0df12b49, 0x06f513ef, 0x05e6ccff, 0x00009c3f, 0xfdfd3e2e, 0xff, 0x21, 0x71, 0x2e, 0x0a, 0x20}; // Game constants

void sIS(char *c)
{
	static char prev;
	if(c[0])	// Only do something when we are not at the end
	{
		c[0] += prev;
		prev = c[0];
		
		sIS(&c[1]);
	}
}

int getNrED(int x, int y)
{
	int nrED;
	(p[getIndex(x, y)]) ? (nrED=-1) : (nrED=0);
	
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{			
			int xt = dx;
			int yt = dy;

			(xt < 0) ? (xt = w -1) : ((xt >= w ) ? (xt = 0) : 0);
			(yt < 0) ? (yt = h-1) : ((yt >= h) ? (yt = 0) : 0);

			p[getIndex(xt, yt)] ? nrED++:0;
		}
	}
	return nrED;
}

void updateLife(int x, int y)
{
	p[getIndex(x,y)] ? (dies(x, y) ? (c[getIndex(x,y)] = false) : (c[getIndex(x,y)] = true)) : (born(x, y) ? (c[getIndex(x,y)] = true) : (c[getIndex(x,y)] = false));
	x++;
	
	(x >= w) ? (x = 0,	y++) : 0;
	(y < h+1) ?  (updateLife(x, y), x=x) : 0;
}

void printLife(int i)
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
		printLife(i+1);
	}
}

bool readFile(char *filename)
{
	bool retVal = false;
	FILE *readFP = fopen(filename, "r");
	if(readFP == NULL)
	{
		return false;
	}
	
	bool startOfLine = true;
	bool skipLine = false;
	
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
		
		startOfLine ? (startOfLine = false, (ch == COMMENT) ? skipLine = true : 0) : 0;
		(ch == '\n') ? (y++, x=0, startOfLine = true, skipLine = false) : ((!skipLine)?	(c[getIndex(x,y)] = !(isspace(ch) || ch == EMPTY)), x++:0);
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

int main(int argc, char **argv)
{			
	I

	c = calloc(size<<1, sizeof(bool));// Create a double sized buffer  
	p = c+size;				// Set p to half of the buffer
	bool loadDemo = true;
	
	// Initial board
	(argc > 1) ? (loadDemo = !readFile(argv[1])):0;
	loadDemo ? (argc = (int)calloc( strlen(P) + EL + 1, 1), MC, P, strlen(P)), MC+strlen(P), EXT, EL), readFile((char*)argc)) : 0;
	
	printLife(0);
	
	while(getch() == ERR);// Wait for user to press a button
	
again:
	S
	updateLife(0,0);
	printLife(0);
	
	argc = getch();
	if(argc == STOP || argc == (STOP-0x20))
		goto stop;
	goto again;
stop:	
	endwin();
}
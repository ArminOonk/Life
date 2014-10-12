#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define getIndex(x,y) (y*width + x)
#define born(x,y) (getNrAlive(x, y) == 3)
#define dies(x,y) (!(((unsigned int)getNrAlive(x, y)-2)<2))

#define size (height*width)
#define EXT ".life"
#define EL strlen(EXT)

#define P argv[0]

#define SWAP previous = (bool*)((int)previous ^ (int)current); current = (bool*)((int)previous ^ (int)current); previous = (bool*)((int)previous ^ (int)current);
#define COMMENT 0x21
#define STOP 0x71 
#define EMPTY 0x2e
#define ALIVE 0x0a
#define DEAD 0x20

#define MC memcpy((char*)argc

int getNrAlive(int x, int y);
bool readFile(char *filename);
void updateLife(int x, int y);
void printLife(int i);

int height, width;	// to store the number of heights and the number of widthums of the screen
bool *current, *previous;

const char itString[] = "Iteration: %d";

int main(int argc, char **argv)
{		
	initscr();								// start the curses mode
	getmaxyx(stdscr,height,width);			// get the number of heights and widthumns
	halfdelay(1);							// Set timeout on getch()
	
	start_color();							// Start color
	init_pair(1, COLOR_RED, COLOR_WHITE);	// Create pair
	attron(COLOR_PAIR(1));					// Set pair
		
	curs_set(0);							// Disable the cursor
		
	current = calloc(size<<1, sizeof(bool));// Create a double sized buffer  
	previous = current+size;				// Set previous to half of the buffer
	bool loadDemo = true;
	
	// Initial board
	(argc > 1) ? (loadDemo = !readFile(argv[1])):0;
	loadDemo ? (argc = (int)calloc( strlen(P) + EL + 1, 1), MC, P, strlen(P)), MC+strlen(P), EXT, EL), readFile((char*)argc)) : 0;
	
	printLife(0);
	
	while(getch() == ERR);// Wait for user to press a button
	
again:
	SWAP
	updateLife(0,0);
	printLife(0);
	
	argc = getch();
	if(argc == STOP || argc == (STOP-0x20))
		goto stop;
	goto again;
stop:	
	endwin();
}

int getNrAlive(int x, int y)
{
	int nrAlive;
	(previous[getIndex(x, y)]) ? (nrAlive=-1) : (nrAlive=0);
	
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{			
			int xt = dx;
			int yt = dy;

			(xt < 0) ? (xt = width -1) : ((xt >= width ) ? (xt = 0) : 0);
			(yt < 0) ? (yt = height-1) : ((yt >= height) ? (yt = 0) : 0);

			previous[getIndex(xt, yt)] ? nrAlive++:0;
		}
	}
	return nrAlive;
}

void updateLife(int x, int y)
{
	previous[getIndex(x,y)] ? (dies(x, y) ? (current[getIndex(x,y)] = false) : (current[getIndex(x,y)] = true)) : (born(x, y) ? (current[getIndex(x,y)] = true) : (current[getIndex(x,y)] = false));
	x++;
	
	(x >= width) ? (x = 0,	y++) : 0;
	(y < height+1) ?  (updateLife(x, y), x=x) : 0;
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
		mvprintw(0,0, itString, iteration++);
		refresh();
	}
	else
	{
		i[current] ? addch(DEAD|ALIVE) : addch(DEAD);
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
		(ch == '\n') ? (y++, x=0, startOfLine = true, skipLine = false) : ((!skipLine)?	(current[getIndex(x,y)] = !(isspace(ch) || ch == EMPTY)), x++:0);
		(x >= width) ? (x = 0, y++) : 0;
		
		if(y >= height)
		{
			goto done;
		}
		goto notEOF;
	}	
	done:
	fclose(readFP);
	
	return retVal;
}
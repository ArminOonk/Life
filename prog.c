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
#define EXTENSION ".life"

#define SWAP previous = (bool*)((int)previous ^ (int)current); current = (bool*)((int)previous ^ (int)current); previous = (bool*)((int)previous ^ (int)current);
#define COMMENT 0x21
#define STOP 0x71 
#define EMPTY 0x2e
#define ALIVE 0x0a
#define DEAD 0x20

int getNrAlive(int x, int y);
bool readFile(char *filename);
void updateLife(int x, int y);
void printLife();

int height, width;	// to store the number of heights and the number of widthums of the screen
bool *current, *previous;

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
	if(argc > 1)
	{
		loadDemo = !readFile(argv[1]);
	}
	
	if(loadDemo)
	{		
		argc = (int)calloc( strlen(argv[0]) + strlen(EXTENSION) + 1, 1);
		memcpy((char*)argc, argv[0], strlen(argv[0]));
		memcpy((char*)argc+strlen(argv[0]), EXTENSION, strlen(EXTENSION));
		readFile((char*)argc);
	}
	
	printLife();
	
	while(getch() == ERR);// Wait for user to press a button
	
again:
	SWAP
	updateLife(0,0);
	printLife();
	
	argc = getch();
	if(argc == STOP || argc == (STOP-0x20))
		goto stop;
	goto again;
stop:	
	endwin();
}

int getNrAlive(int x, int y)
{
	int nrAlive = 0;
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{
			if(dx == x && dy == y)
			{
				continue;
			}
			
			int xt = dx;
			int yt = dy;

			if(xt < 0)
			{
				xt = width-1;
			}
			else if(xt >= width)
			{
				xt = 0;
			}

			if(yt < 0)
			{
				yt = height-1;
			}
			else if(yt >= height)
			{
				yt = 0;
			}

			if(previous[getIndex(xt, yt)])
			{
				nrAlive++;
			}
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

void printLife()
{
	move(0,0);
	for(int i=0; i<size; i++)
	{
		i[current] ? addch(DEAD|ALIVE) : addch(DEAD);
	}
	static int iteration;
	mvprintw(0,0,"Iteration: %d", iteration++);
	refresh();
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
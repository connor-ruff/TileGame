// Connor Ruff

#include"proj.h"


int main() {

	
	char u; // Reads user input
	Game g; // Variable to play the game
	// Set Widths and Board Size
	g.setwd(800);
	g.setht(800);
	g.setsz(4);
	
	// Open Starting Board	
	gfx_open(g.getwd(),g.getht(),"Sexy");
	gfx_clear_color(255,255,255);
	gfx_color(0,0,0);
	g.setBoard(); // Sets Up An Arry Representing Board
	g.configure(); // Translates This Array Into Data For Graphic Display
	g.display(); // The First Display of the Board
	
	bool over = false;

	// Infinity Loop
	while(!over) {
		
		if(gfx_event_waiting()) {
		
			u = gfx_wait();

			switch (u) {
				case 'R': // User Shifts Board Up
					if(g.getEmptyi() == 3) { continue;}
					g.shiftUp(); // Shift Array Properly
					g.configure();
					g.animateUP(); // Show This Shift As Animation
					break;
				case 'T': // User Shifts Board Down
					if(g.getEmptyi() == 0) { continue;}
					g.shiftDown(); 
					g.configure();
					g.animateDOWN();
					break;
				case 'Q': // User Shifts Board Left
					if(g.getEmptyj() == 3) { continue;}
					g.shiftLeft();
					g.configure();
					g.animateLEFT();
					break;
				case 'S': // User Shifts Board Right
					if(g.getEmptyj() == 0) { continue;}
					g.shiftRight();
					g.configure();
					g.animateRIGHT();
					break;
				case 'q': // q to Quit
					return 0;
				case 'r': // User resets the board
					g.setBoard();
					g.configure();
					g.display();
					break;
			}
		
		}
		if (g.checkWin()) {    // Check if they won!
			over = true;
			g.displayWin();  // Congratulate them
		}
	}



	return 0;
}

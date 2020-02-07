// Connor B Ruff
#include<iostream>
#include"gfx2.h"
#include<cmath>
#include<unistd.h>
#include<cstdlib>
#include<vector>
using namespace std;

struct Col { //for a color combination
	int r;
	int g;
	int b;
};
struct Pt {  // For a point
	int x;
	int y;
};
struct Tile { // Data on each tile
	Pt UL; // Coordinates of upper left corner of tile
	Pt LR; // Coordinates of lower right corner of tile
	int val; // Number Current On Tile
	Col c; // Color Correspoding To tile
};

class Game {
	public:
	Game();
	~Game();
	int getwd();
	int getht();
	int getsz();
	void setsz(int);
	void setwd(int);
	void setht(int);
	void display();
	void setBoard();
	void shiftUp();
	void shiftDown();
	void shiftLeft();
	void shiftRight();
	int getEmptyi();
	int getEmptyj();
	void configure();
	void writeText(Tile);
	void animateUP();
	void animateDOWN();
	void animateRIGHT();
	void animateLEFT();
	void Border();
	bool checkWin();
	void displayWin();
	private:
	int sz;
	int board[6][6]; // Array Representing Tiles on board
	int wd;
	int ht;
	Tile tiles[6][6];// Contains actual data on tiles
	Pt zeroT; // Point Where The Blank Tile Is
	
};




// Connor Ruff

#include<iostream>
using namespace std;
#include"proj.h"

// Empty Constructor and De-Structor
Game::Game() {} 
Game::~Game() {}

// Set and Access Methods
int Game::getwd() { return wd; }
int Game::getht() { return ht; }
int Game::getsz() { return sz; }
void Game::setwd(int w) { wd = w; }
void Game::setht(int h) { ht = h;}
void Game::setsz(int s) { sz = s;}

// Displays the Initial Board
void Game::display() {
	
	gfx_clear();

	// The Center of a Tile
	int xc;
	int yc;

	// Fills Each Tile Green
	for(int i=0; i< getsz(); ++i)
		for(int j=0; j <getsz(); ++j) {
			gfx_color(tiles[i][j].c.r, tiles[i][j].c.g,tiles[i][j].c.b);
			gfx_fill_rectangle(tiles[i][j].UL.x+1, tiles[i][j].UL.y+1,148,148);
			writeText(tiles[i][j]);
		}

	// Create Board
	Border();
}
// Fills In a black border around the tiles
void Game::Border() {

	// Display "Menu"
	gfx_color(0,0,0);
	gfx_text(400,10,"Order The Puzzle By Number Going Left to Right and Up to Down");
	gfx_text(400,20,"q: Quit");
	gfx_text(400,30,"r: Reset Board");

	for(int i=0; i<=4; ++i){
		gfx_line(100,100+150*i,700,100+150*i);
		gfx_line(100,(100+150*i)-1,700,(100+150*i)-1);
		gfx_line(100+150*i,100,100+150*i,700);
		gfx_line((100+150*i)-1,100,(100+150*i)-1,700);	
	}

}
// Creates the Array Representing the Board
void Game::setBoard() {

	vector<int> v;

	// Create Array of Numbers For Board
	for(int i=0; i< getsz()*getsz();++i) 
		v.push_back(i);

	// Use Shuffle Algorithm To Make Order Random
	srand(time(0));
	int j;
	int temp;
	
	for (int i = getsz()*getsz() - 1; i>0; i--) {
		j = rand() % (getsz()*getsz());
		temp = v.at(i);
		v.at(i) = v.at(j);
		v.at(j) = temp;
	}

	// Assign These To the Board
	int counter = 0;
	for (int i=0; i<getsz(); ++i)
		for(int j=0; j<getsz(); ++j) {
			board[i][j] = v.at(counter);
			counter++;
         }




	
}

// Gets i location of the 0 in the board array
int Game::getEmptyi() {


	for(int i= 0; i <getsz(); ++i)
		for(int j=0; j<getsz(); ++j)
			if (board[i][j] == 0) 
				return i; 
}
//Get j location of the 0 in the board array
int Game::getEmptyj() {

	for(int i=0; i <getsz(); ++i)
		for(int j=0; j<getsz(); ++j)
			if (board[i][j] == 0) 
				return j;
}

// Shifts methods for the board array (NOT tile array)
void Game::shiftUp() {
	
	int i = getEmptyi();
	int j = getEmptyj();

	if (i == getsz()-1) {return;}

	board[i][j] = board[i+1][j];
	board[i+1][j] = 0;
}

void Game::shiftDown() {

	int i = getEmptyi();
	int j = getEmptyj();

	if (i == 0) {return;}

	board[i][j] = board[i-1][j];
	board[i-1][j] = 0;
}

void Game::shiftLeft() {

	int i = getEmptyi();
	int j = getEmptyj();

	if (j==getsz()-1) { return; }

	board[i][j] = board[i][j+1];
	board[i][j+1] =0;
}

void Game::shiftRight() {

	int i = getEmptyi();
	int j = getEmptyj();

	if (j==0) { return; }

	board[i][j] = board[i][j-1];
	board[i][j-1] = 0;
	}



// Populates the array of struct Tile which contains data about board
void Game::configure() {

	Tile t;
	int xStart =  100;
	int yStart =  100;
	int d = 150;
	int k;
	int p = 0;

	for(int i=0; i < getsz(); ++i) {
		k =0;
		for(int j=0; j < getsz(); ++j) {
			t.UL.x = xStart + k*d;
			t.UL.y = yStart + p*d;
			t.LR.x = t.UL.x + 150;
			t.LR.y = t.UL.y + 150;
			t.val = board[i][j];
			if (t.val == 0) {
				t.c.r = 255;
				t.c.g = 255;
				t.c.b = 255;
				zeroT.y = i;
				zeroT.x = j;
			}
			else {
				t.c.r = 0;
				t.c.g = 255;
				t.c.b = 0;
			}
			tiles[i][j] = t;
			++k;
			 }
			++p; 
}
			


}


// Puts the text in each tile
void Game::writeText(Tile t) {


	int	x = (t.UL.x + t.LR.x) / 2;
	int y = (t.UL.y + t.LR.y) /2;
	int v = t.val;
	gfx_color(0,0,0);	
	

	switch (v) {
		case 1:
			gfx_text(x,y,"1");
			break;
		case 2:
			gfx_text(x,y,"2");
			break;
		case 3:
			gfx_text(x,y,"3");
			break;
		case 4:
			gfx_text(x,y,"4");
			break;
		case 5:
			gfx_text(x,y,"5");
			break;
		case 6:
			gfx_text(x,y,"6");
			break;
		case 7:
			gfx_text(x,y,"7");
			break;
		case 8:
			gfx_text(x,y,"8");
			break;
		case 9:
			gfx_text(x,y,"9");
			break;
		case 10:
			gfx_text(x,y,"10");
			break;
		case 11:
			gfx_text(x,y,"11");
			break;
		case 12:
			gfx_text(x,y,"12");
			break;
		case 13:
			gfx_text(x,y,"13");
			break;
		case 14:
			gfx_text(x,y,"14");
			break;
		case 15:
			gfx_text(x,y,"15");
			break;
	}

}

// The Animation Methods
void Game::animateUP(){

	Tile t = tiles[zeroT.y][zeroT.x];
	
	

	for(int i=0; i<=150; i+=15) {
		gfx_color(0,255,0);
		gfx_fill_rectangle(t.UL.x+1,t.UL.y+1-i,148,148);
		gfx_color(255,255,255);
		gfx_fill_rectangle(t.UL.x+1,t.UL.y+1-i+148,148,i);
		usleep(0.000001);	
	}
	Tile t2 = tiles[zeroT.y-1][zeroT.x];
	writeText(t2);

	Border();	

}

void Game::animateDOWN() {

	Tile t = tiles[zeroT.y][zeroT.x];
	
	
	for(int i=0; i<=150; i+=15) {
		gfx_color(0,255,0);
		gfx_fill_rectangle(t.UL.x+1,t.UL.y+1+i,148,148);
		gfx_color(255,255,255);
		gfx_fill_rectangle(t.UL.x+1,t.UL.y+1,148,i);
		usleep(0.000001);	
	}
	Tile t2 = tiles[zeroT.y+1][zeroT.x];
	writeText(t2);

	Border();

}

void Game::animateRIGHT() {

	Tile t = tiles[zeroT.y][zeroT.x];
	

	for( int i=0; i <=150; i+=15) {
		gfx_color(0,255,0);
		gfx_fill_rectangle(t.UL.x+1+i,t.UL.y+1,148,148);
		gfx_color(255,255,255);
		gfx_fill_rectangle(t.UL.x+1,t.UL.y+1,i,148);
		usleep(0.000001);
	}

	Tile t2 = tiles[zeroT.y][zeroT.x+1];
	writeText(t2);

	Border();

}

void Game::animateLEFT() {

	Tile t = tiles[zeroT.y][zeroT.x];

	for(int i=0; i<=150; i+=15) {
		gfx_color(0,255,0);
		gfx_fill_rectangle(t.UL.x+1-i,t.UL.y+1,148,148);
		gfx_color(255,255,255);
		gfx_fill_rectangle(t.UL.x+1+148-i,t.UL.y+1,i,148);
		usleep(0.000001);
	}

	Tile t2 = tiles[zeroT.y][zeroT.x-1];
	writeText(t2);

	Border();
}

// Checks if the board is entirely correct
bool Game::checkWin() {

	int count = 0;
	int k = 0;
	for(int i=0;i<4; ++i)
		for(int j=0;j<4;++j) { 
			++k;
			if (board[i][j] == k)
				++count;  
		}

	if (count == 15)
		return true;
	else
		return false;

}

// Displays a little win message
void Game::displayWin(){

	gfx_clear();
	gfx_color(0,0,0);
	gfx_text(400,400,"Nice");
	gfx_flush();
	usleep(3000000);
	

}

#include "Start menu.h"
#include <iostream>
using namespace std;

void welcome() {
	cout << "*****************************************************************************************************************************************************" << endl;
	cout << "                      (◐‿◑)(◐‿◑)﻿(◐‿◑)﻿(◐‿◑)﻿(◐‿◑)  ﻿ Welcome to this game   (◐‿◑)﻿(◐‿◑)﻿(◐‿◑)﻿(◐‿◑)(◐‿◑)﻿﻿" << endl;
	cout << "********************************************************************************8********************************************************************" << endl;

}


void print_menu() {
	system("clear");
	cout << endl;
	cout << "*****************************************************************************************************************************************************" << endl;
	cout << endl;
	cout << "                                                      || Menu ||                            " << endl;
	cout << endl;
	cout << "                                                   __________________                      " << endl;
	cout << "                                                  |  Regulation (R)   |                    " << endl;
	cout << "                                                   ------------------                      " << endl;
	cout << endl;
	cout << "                                                   ___________________                     " << endl;
	cout << "                                                  | Begin the game (B)|                    " << endl;
	cout << "                                                   -------------------                     " << endl;
	cout << endl;
	cout << "                                                   ___________________                      " << endl;
	cout << "                                                  |  Exit the game (E)|                     " << endl;
	cout << "                                                   -------------------                      " << endl;
	cout << endl;
	cout << "                                                   ___________________                      " << endl;
	cout << "                                                  |     History (H)   |                     " << endl;
	cout << "                                                   -------------------                      " << endl;
	cout << "*****************************************************************************************************************************************************" << endl;
	cout << endl;
	cout << "▽ Your choice" << endl;
}

void print_regulation() {
	system("clear");
	cout << "                                      Introduction of our game (Jiang Feiyu & Long Kehan)               " << endl;
	cout << "                                 This is a confrontation game for two players at the same time          " << endl;
	cout << "  Here is a game with a 5 * 5 board, Player 1 and Player 2 are generated diagonally, with @ and # representing Player 1 and Player 2, respectively   " << endl;
	cout << "Your starting point is denoted by &, and your goal is to get to the other person's starting point before the other person gets to your starting point" << endl;
	cout << "                                   The first to reach the other team's starting point wins              " << endl;
	cout << " **************************************************     attention    ********************************************************************************" << endl;
	cout << "   The X on the board is the portal, which can be teleported between (but you can't use it when either of the door is occupied by your opponents')   " << endl;
	cout << "                                     You can choose to move one or two units at a time                  " << endl;
	cout << "                          * is the wall that you cannot pass and you can only move in the range of map  " << endl;
	cout << "" << endl;
	cout << "                                                    ENJOY YOUR GAME!!!                                  " << endl;
	
}

void bye() {
	//system("clear");
	cout << "*****************************************************************************************************************************************************" << endl;
	cout << "******************************************************    Bye   *************************************************************************************" << endl;
	cout << "*****************************************************************************************************************************************************" << endl;
}

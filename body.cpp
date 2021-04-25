//Author: Jiang Feiyu, Long Kehan
//UID: 3035770800, 3035771323
//Group number:61
//Text game
//Description:

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Start menu.h"

using namespace std;

int input (char order, int position); // input the command

void door(vector<char> vectors, char order, int &pos, bool turn); 
// This is a function of generating the choices from players during the game

void create_map(vector<char> &vectors, int &x, int &y, int &z, int &m, int &n); 
// This is a function to create a new map

void print_map(vector<char> &vectors, int &x, int &y, int &z, int pos1, int pos2); 
// This is a interface of the map

bool judge_win(int position_one, int position_two); 
// This is a function of judge whether it is a win situation and decide who is the winner, then output the interface

void operation(vector<char> &vectors, char &order, bool &turn, int &pos1, int &pos2);
// This is a function of changing the position.

bool judge_history();
// This is a function of juding whether there is a game history

void read_history(vector<char> &map, int &wall_one, int &wall_two, int &wall_three, int &door_one, int &door_two, int &player_one, int &player_two);
// This is a function of collecting data from history file and then generate a same map

void write_history(int wall_1, int wall_2, int wall_3, int door_1, int door_2, int door_3, int pos_1, int pos_2);
// This is a function of writing data to history

vector<char> map;
char order = 'A', wall = '*'; //initialization
int pos1 = 0,pos2 = 24,wall_1,wall_2,wall_3,door_1,door_2;
bool turn = true;

int main() {
	welcome();
	print_menu();
	char choice;
	cin >> choice;
	system("clear");
	
	if (choice == 'R'){
		print_regulation();
	} 
	else if (choice == 'H'){
		if (judge_history() == 1){
			cout << "Loading history..." << endl;
			//cout << map.size() << endl;
			read_history(map, wall_1, wall_2, wall_3, door_1, door_2, pos1, pos2);
			operation(map, order, turn, pos1, pos2);
		}
		else {
			create_map(map, wall_1, wall_2, wall_3, door_1, door_2);
			cout << "There is no history, a new game is loading..." << endl;
			operation(map, order, turn, pos1, pos2);
		} 
				
	}
	else if (choice == 'B') {
		create_map(map, wall_1, wall_2, wall_3, door_1, door_2);
		operation(map, order, turn, pos1, pos2);
	}
	bye();
}


int input(char order, int pos) {
	int step;

	cout << "How many step you want to move (1 or 2): " ;
	cin >> step;
	
	if (order == 'W') {
		pos = pos - 5 * step;
	}
	else if (order == 'A') {
		pos = pos - step;
	}
	else if (order == 'S') {
		pos = pos + 5 * step;
	}
	else {
		pos = pos + step;
	}
	return pos;
}
	

void door(vector<char> vectors, char order, int &pos, bool turn) {
	
	if (pos == door_1) { // To check if it has access to the door
	    cout << "Nice! You've reached the door, your'll be sent directly to the other door!" << endl;
		pos = door_2;
	}
	else if (pos == door_2) {
		cout << "Nice! You've reached the door, your'll be sent directly to the other door!" << endl;
		pos = door_1;
	}
	else {
		pos = pos;
	}
    }

bool judge_win (int pos1, int pos2) {
	if (pos1 == 24 ) {
		cout << " PLAYER1 WIN !!!" << endl;
		return true;
	}
	else if (pos2 == 0) {
		cout << " PLAYER2 WIN !!!" << endl;
		return true;
	}
	return false;
}

void create_map(vector<char> &map, int &wall_1, int &wall_2, int &wall_3, int &door_1, int &door_2) {
	int door_probability[] = {6,7,8,11,12,13,16,17,18}; //initialization of the vector, ’‚∏ˆ≤ø∑÷±‡“Î”¶∏√√ª¥Ì
//	for (int x : door_probability)
//		cout << x << " ";
	
	srand((int)time(0));
	
	int door_1_p = rand() % 9;
	int door_2_p = rand() % 9;
	
	while (door_2_p == door_1_p) {
		door_2_p = rand() % 9;
	}
	
	door_1 = door_probability[door_1_p];
	door_2 = door_probability[door_2_p];
	
	wall_1 = rand() % 23 + 1;
	
	while (wall_1 == door_1 || wall_1 == door_2) {
		wall_1 = rand() % 23 + 1;
	}
	
	wall_2 = rand() % 23 + 1;
	
	while (wall_2 == door_1 || wall_2 == door_2 || wall_2 == wall_1) {
		wall_2 = rand() % 23 + 1;
	}
	
	wall_3 = rand() % 23 + 1;
	
	while (wall_3 == door_1 || wall_3 == door_2 || wall_3 == wall_1 || wall_3 == wall_2) {
		wall_3 = rand() % 23 + 1;
	}
	
	for (int i = 0; i < 25; i++) {
		if (i == wall_1 || i == wall_2 || i == wall_3){
			map.push_back('*');//*pos = '*';
		}
		else if (i == door_1 || i == door_2){
			map.push_back('X');//*pos = 'X';
		}
		else if (i == pos2){
			map.push_back('#');//*pos = '#';
		}
		else if (i == pos1){
			map.push_back('@');//*pos = i;
		}
		else {
			map.push_back('0');
		}
    }
	
}

void print_map(vector<char> &map) { 

	for (int i = 0; i < 25; i++) {
		if (i % 5 == 4) {
			cout << map[i] << endl;
		}
		else {
			cout << map[i] << ' ';
		}
	}
}

bool judge_history() 
{
	char filename[80] = "history.txt";
	ifstream fin;
	fin.open(filename);
	
	if ( fin.fail() ){
		return false;
	}
	return true;
}

void read_history(vector<char> &map, int &wall_one, int &wall_two, int &wall_three, int &portal_one, int &portal_two, int &player_one, int &player_two){
	char filename[80] = "history.txt";
	ifstream fin;
	fin.open(filename);
	if (fin.fail()) {
		cout << "Error!" << endl;
		exit(1);
	}
	fin >> player_one >> player_two;
	fin >> portal_one >> portal_two;
	fin >> wall_one >> wall_two >> wall_three;
	for (int i = 0; i <  25; i++){
		if (i == player_one){
			map.push_back('@');
		} else if (i == player_two){
			map.push_back('#');
		} else if (i == portal_one || i == portal_two){
			map.push_back('X');
		} else if (i == wall_one || i == wall_two || i == wall_three){
			map.push_back('*');
		} else {
			map.push_back('0');
		}
	}
	fin.close();
}

void write_history(int wall_1, int wall_2, int wall_3, int door_1, int door_2, int pos_1, int pos_2) {
	char filename[80] = "history.txt";
	ofstream fout;
	fout.open(filename);
	if (fout.fail()){
		cout << "Error in file opening, you can't save the history : (" << endl;
		exit(1);
	}
	fout << pos_1 << " " << pos_2 << endl;
	fout << door_1 << " " << door_2 << endl;
	fout << wall_1 << " " << wall_2 << " "<< wall_3 << endl;
	fout.close();
}

void operation(vector<char> &map, char &order, bool &turn, int &pos1, int &pos2) {
	print_map(map);
			
	while (order != 'E') {
		int origin = 0; //initialization
		
		if (turn == true) {
			cout << "Player " << turn << ", which direction would you like to move (W/A/S/D): ";
		}
		else {
			cout << "Player 2" << ", which direction would you like to move (W/A/S/D): ";
		}
		cin >> order;
		if (order == 'E') {
			cout << "Do you want to save or not? (Y/N)"  << endl;
			cin >> order;
			if (order == 'N') {
				order = 'E';
				continue;	
			}
			else {
				order = 'E';
				write_history (wall_1, wall_2, wall_3, door_1, door_2, pos1, pos2);
				continue;
			}
			
		}
		if (turn == true) { // This is for player 1
		    origin = pos1;
			pos1 = input (order, pos1);
	    	if (0 > pos1 || 24 < pos1) {
				cout << "Sorry, this operation is out of range, please try again." << endl;
				pos1 = origin; 
				continue;
			}
			else if ( map[pos1] == wall) {
				pos1 = origin;
				cout << "Sorry, this operation will hit the wall, pleas try again." << endl;
			    continue;
			} 
			else if (pos1 == pos2) {
				pos1 = origin;
				cout << "Sorry, this position has already been occupied by player 2, please try again." << endl;
                continue;
			}
			else if (pos1 == door_1 || pos1 == door_2) {
				if (door_1 == pos2) {
					pos1 = origin;
					cout << "Sorry, the other door has already been occupied by player 2, please try again." << endl;
					continue;
				}
				else if (door_2 == pos2) {
					pos1 = origin;
					cout << "Sorry, the other door has already been occupied by player 2, please try again." << endl;
					continue;
				}
				map.insert(map.begin() + origin, '0');
				map.erase(map.begin() + origin + 1);
				door(map, order, pos1, 1);
			}
			map.insert(map.begin() + pos1, '@');
			map.erase(map.begin() + pos1 + 1);
			if (origin == door_1 || origin == door_2) {
				map.insert(map.begin() + origin, 'X');
			}
			else {
				map.insert(map.begin() + origin, '0');
			}
			map.erase(map.begin() + origin + 1);
			turn = false;
		}
		
		else { // This is for player 2
			origin = pos2;
			pos2 = input (order, pos2);
			if (0 > pos2 || 24 < pos2) {
				pos2 = origin;
				cout << "Sorry, this operation is out of range, please try again." << endl;
				continue;
			}
			else if (map[pos2] == '*') {
				pos2 = origin;
				cout << "Sorry, this operation will hit the wall, pleas try again." << endl;
				continue;
			}
			else if (pos2 == pos1) {
				pos2 = origin;
				cout << "Sorry, this position has already been occupied by player 1, please try again." << endl;
				continue;
			}
			else if (pos2 == door_1 || pos2 == door_2) {
				if (door_1 == pos1) {
					pos2 = origin;
					cout << "Sorry, the other door has already been occupied by player 1, please try again." << endl;
					continue;
				}
				else if (door_2 == pos1) {
					pos2 = origin;
					cout << "Sorry, the other door has already been occupied by player 1, please try again." << endl;
					continue;
				}
				map.insert(map.begin() + origin, '0');
				map.erase(map.begin() + origin + 1);
				door(map, order, pos2, 1);
			}
			map.insert(map.begin() + pos2, '#');
			map.erase(map.begin() + pos2 + 1);
			if (origin == door_1 || origin == door_2) {
				map.insert(map.begin() + origin, 'X');
			}
			else {
				map.insert(map.begin() + origin, '0');
			}
			map.erase(map.begin() + origin + 1);
			turn = true;
			}
				// After a turn is over, we need to judge whether there is a winner
			print_map(map);
			if (judge_win(pos1, pos2)) {
				break;
			}
		}
	}
	

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string r1c1 = " - ";
string r1c2 = " - ";
string r1c3 = " - ";

string r2c1 = " - ";
string r2c2 = " - ";
string r2c3 = " - ";

string r3c1 = " - ";
string r3c2 = " - ";
string r3c3 = " - ";

void print_board() {
	
	std::cout << " \n";
	std::cout << "  " << r1c1 << "|" << r1c2 << "|" << r1c3 << "\n";
	std::cout << "  " << "-----------\n";
	std::cout << "  " << r2c1 << "|" << r2c2 << "|" << r2c3 << "\n";
	std::cout << "  " << "-----------\n";
	std::cout << "  " << r3c1 << "|" << r3c2 << "|" << r3c3 << "\n";
	std::cout << " \n";
			
}

void update_board(int position, string character) {
	
	switch (position) {
			case 0:
				r1c1 = character;
				break;
			case 1:
				r1c2 = character;
				break;
			case 2:
				r1c3 = character;
				break;
			case 3:
				r2c1 = character;
				break;
			case 4:
				r2c2 = character;
				break;
			case 5:
				r2c3 = character;
				break;
			case 6:
				r3c1 = character;
				break;
			case 7:
				r3c2 = character;
				break;
			case 8:
				r3c3 = character;
				break;
			default:
				NULL;
		}
}


int main() {

	int player1 = 0;
	int player2 = 1;
	
	
	//matrix
	vector<int> positions = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<vector<string>> vals = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
	// std::cout << vals[0][0] << "\n";
	/*
	for (int i=0; i<=8; i++) {
		cout << (i/3) << ((i%3)) << "\n";
	}
	*/
	
	
	bool winner = false;
	int rounds = 0;
	int turn = 0;
	int pos = 0;
	
	while (!winner) {
			
			print_board();
		
			if (turn == 0) {
				// player1 turn
				string character = " X ";
				
				bool valid_pos = false;
				while (!valid_pos) {
					cout << "P1 enter a valid pos: ";
					cin >> pos;
					pos--;
					
					
					if (positions[pos] == 0) {
						positions[pos] = 1;
						valid_pos = true;
					}
					
					int row = pos / 3;
					int col = pos % 3;
					
					vals[row][col] = character;
					
				}
				
				update_board(pos, character);
				
				
			} else {
				// player1 turn
				string character = " O ";
				
				bool valid_pos = false;
				while (!valid_pos) {
					cout << "P2 enter a valid pos: ";
					cin >> pos;
					pos--;
					
					
					if (positions[pos] == 0) {
						positions[pos] = 1;
						valid_pos = true;
					}
					
					int row = pos / 3;
					int col = pos % 3;
					
					vals[row][col] = character;
					
				}
				
				update_board(pos, character);
				
			}
			
			// switching player turns
			turn = 1 - turn;
			rounds++;
			
			// check if winner
			if (
				// checking rows
				vals[0][0] == vals[0][1] and vals[0][1] == vals[0][2] || 
				vals[1][0] == vals[1][1] and vals[1][1] == vals[1][2] ||
				vals[2][0] == vals[2][1] and vals[2][1] == vals[2][2] ||
				
				// checking columns
				vals[0][0] == vals[1][0] and vals[1][0] == vals[2][0] ||
				vals[0][1] == vals[1][1] and vals[1][1] == vals[2][1] ||
				vals[0][2] == vals[1][2] and vals[1][2] == vals[2][2] ||
				
				// checking diagonals
				vals[0][0] == vals[1][1] and vals[1][1] == vals[2][2] ||
				vals[2][0] == vals[1][1] and vals[1][1] == vals[0][2] ) {
					cout << "\n";
					cout << "  --- WINNER ---  \n";
					cout << "\n";
					
					print_board();
					winner = true;
			}
			
			// check if game full
			
			if (rounds >= 9 and !winner) {
				cout << "\n";
				cout << "  --- Game Over, No Winners ---  \n";
				cout << "\n";
				break;
			}
			
	}

}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char board[3][3] = {{'1', '2' ,'3'} , {'4','5','6'}, {'7','8','9'}};
char current_marker;
int current_player;

void drawBoard()
{

	std::cout << " " << board[0][0] << " \ " << board[0][1] << " | " << board[0][2] << endl;
	std::cout << "----------\n";

	std::cout << " " << board[1][0] << " \ " << board[1][1] << " | " << board[1][2] << endl;

	std::cout << "----------\n";

	std::cout << " " << board[2][0] << " \ " << board[2][1] << " | " << board[2][2] << endl;
}
bool placeMarker(int slot) {
	int row = slot / 3;
	int col;
	
	if (slot % 3 == 0) 
	{
		row = row - 1;
		col = 2;
	}
	else col = (slot % 3) - 1;

	if (board[row][col] != 'x' && board[row][col] != 'O')
	{
		board[row][col] = current_marker;
		return true;
	}
	else return false;
}

int winner() 
{
	for (int i = 0; i < 3; i++)
	{
		//rows
		if (board [i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
		//columns
		if (board [0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
	}
	    if (board [0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
		if (board [0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

		return 0;
}
void swap_player_and_marker()
{
	if (current_marker == 'x') current_marker = 'O';
	else current_marker = 'x';

	if (current_player == 1) current_player = 2;
	else current_player = 1;

}


void game()
{
	std::cout << " Player one , choose your marker x or O) : ";
	char marker_p1;
	std::cin >> marker_p1;

	current_player = 1;
	current_marker = marker_p1;

	drawBoard();
	int player_won;
	for (int i = 0; i < 9 /2; i++)
	{
		std::cout << "It's player " << current_player << "'s turn. Enter your slot : ";
		int slot;
		cin >> slot;
		if (slot < 1 || slot > 9) 
		{
			std::cout << "That slot is invalid ! Try another slot!";
			i--;
			continue;
		}
		if (!placeMarker(slot)) 
		{ 
			std::cout << "That slot is occupied ! Try another slot!"; 
			i--; 
			continue; 
		}
		
		drawBoard();
		player_won = winner();
		if (player_won == 1) { std::cout << "Player One won !! CONGRATULATIONS"; break; }
		if (player_won == 2) { std::cout << "Player Two won !! CONGRATULATIONS"; break; }
		swap_player_and_marker();
		
	}

	if (player_won == 0) std::cout << " That is a tie game!";
}

int main() 
{
	//srand(time(NULL));
	//std::cout << rand() % (rand() % (10 - 1 + 1)) + 1;

	

	game();
	
	//drawBoard();
	//std::cout << '\n';
	//current_marker = 'x';
	//current_player = 1;
	//placeMarker(1);
	//placeMarker(5);
	//placeMarker(9);
	//drawBoard();

	//std::cout << winner ();

}
#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == 'X')
	{
		turn = O;
	}
	else
	{
		turn = X;
	}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
 	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = Blank;
		}		
	}	
	turn = X;	
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = Blank;
		}		
	}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if(!(row >= 0 && row <= 2 && column >= 0 && column <= 2)) //if row or column is not
								  //in bounds return invalid
	{
		return Invalid;
	}
	else if(board[row][column] == Blank)
	{
		board[row][column] = turn;
		toggleTurn();		
		return board[row][column];
	}
	return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(!(row >= 0 && row <= 2 && column >= 0 && column <= 2)) //if row or column is not
								  //in bounds return invalid
	{
		return Invalid;
	}
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	bool filled = true;
	Piece check = Invalid;
	int count = 1;

	for(int i = 0; i < 3; i++)       //Loop  through the rows
	{
		count = 1;
		for(int j = 0; j < 3; j++)
		{
			if(check == Blank)
				filled = false;
			else if(check == board[i][j] && board[i][j] != Blank)
			{
				count++;
			}
			if(count == 3)
				return check;
			check = board[i][j];
		}
	}
	check = Invalid;
	for(int i = 0; i < 3; i++)       //loop through the columns
	{
		count = 1;
		for(int j = 0; j < 3; j++)
		{
			if(check == Blank)
				filled = false;
			else if(check == board[j][i] && board[j][i] != Blank)
			{
				count++;
			}
			if(count == 3)
				return check;
			check = board[j][i];
		}
	}
	
	//now check for diagnal winners	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Blank)
		return board[0][0];
	else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != Blank)
		return board[1][1];

	if(filled == true)    //if board is filled with no winner
		return Blank;
	return Invalid;

}

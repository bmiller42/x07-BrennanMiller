/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, testwinnerRow)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(0,1);
	board.placePiece(1,1);
	board.placePiece(0,2);
	Piece winner = board.getWinner();
	ASSERT_TRUE(winner == X);
}
TEST(TicTacToeBoardTest, testifwinEarly)
{
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,1);
	board.placePiece(0,2);
	Piece winner = board.getWinner();
	ASSERT_TRUE(winner == Invalid);
}
TEST(TicTacToeBoardTest, testwinnerColumn)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(2,0);
	Piece winner = board.getWinner();
	ASSERT_TRUE(winner == X);
}
TEST(TicTacToeBoardTest, testwinnerDiagnal)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(2,2);
	Piece winner = board.getWinner();
	ASSERT_TRUE(winner == X);
}
TEST(TicTacToeBoardTest, testwinnerOtherDiagnal)
{
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.placePiece(1,2);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(2,0);
	Piece winner = board.getWinner();
	ASSERT_TRUE(winner == X);
}

TEST(TicTacToeBoardTest, testPlacePiece)
{
	TicTacToeBoard board;
	Piece turn;
	bool outofbounds;
	turn = board.placePiece(2, 1);
	if(turn == X)
		outofbounds = true;
	else
		outofbounds = false;
	ASSERT_TRUE(outofbounds);
}
TEST(TicTacToeBoardTest, testifReplacesPiece)
{
	TicTacToeBoard board;
	board.placePiece(1,1);
	board.placePiece(1,1);
	ASSERT_TRUE(board.getPiece(1,1) == X);
}

TEST(TicTacToeBoardTest, getInvalidPiece)
{
	TicTacToeBoard board;
	Piece piece;
	piece = board.getPiece(3,1);
	ASSERT_TRUE(piece == Invalid);
}
TEST(TicTacToeBoardTest, testOutOfBounds)
{
	TicTacToeBoard board;
	Piece turn;
	bool outofbounds;
	turn = board.placePiece(3, 1);
	if(turn == X)
		outofbounds = false;
	else
		outofbounds = true;
	ASSERT_TRUE(outofbounds);
}

TEST(TicTacToeBoardTest, testNoWinnerFullBoard)
{
	TicTacToeBoard board;
	Piece piece;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,0);
	board.placePiece(2,0);
	board.placePiece(0,2);
	board.placePiece(2,2);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,1);
	piece = board.getWinner();
	ASSERT_TRUE(piece == X);
}

TEST(TicTacToeBoardTest, testifInitialized)
{
	TicTacToeBoard board;
	bool blank;
	if(board.getPiece(1,1) == Blank)
		blank = true;
	ASSERT_TRUE(blank);
}

TEST(TicTacToeBoardTest, testClearBoard)
{
	TicTacToeBoard board;
	bool blank;
	board.placePiece(1,1);
	board.clearBoard();
	if(board.getPiece(1,1) == Blank)
		blank = true;
	ASSERT_TRUE(blank);
}

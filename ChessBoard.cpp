/*********************************************************
 * Imperial College London - Department of Computing     *
 * MSc C++ Programming - Assessed Exercise No. 3         *
 * Chess Game Implementation                             *
 *                                                       *
 * Created by: Pablo Navajas Helguero                    *
 * Date: 9th December 2019                               *
 *                                                       *
 * File: ChessBoard.cpp                                  *
 *********************************************************/

#include"ChessBoard.h"

Board::Board() {

  turn = White;

  int row=0;
  while (row < 8) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = 0;
    }
    row++;
  }

  setUp();
  
}

Board::~Board() {

  int row=0;
  while (row < 8) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = NULL;
    }
    row++;
  }
}


void Board::setUp() {

  color team = White;

  for (int row = 1; row < 8; row += 5) {

    for (int col = 0; col < 8; col++) {

      board[row][col] = new Pawn(std::make_pair(row,col), team);
    }
    team = Black;
  }

  std::cout << "\nA new Chess Game is started!\n\n";
}

bool Board::checkCoord(string position) {

  if (position.length() != 2)
    return true;

  else if (position[0] - 'A' > 7 or position[0] - 'A' < 0)
    return true;

  else if (position[1] - '1' > 7 or position[1] - '1' < 0)
    return true;

  return false;
}


bool Board::squareState(coord pos) {

  if (board[pos.first][pos.second] != nullptr)
    return true;

  return false;
}


bool Board::pathFree(coord origin, coord destin) {

  int V_move = (destin.first == origin.first) ? 0 : (destin.first > origin.first) ? 1 : -1;
  int H_move = (destin.second == origin.second) ? 0 : (destin.second > origin.second) ? 1 : -1;

  int V_pos = origin.first + V_move;
  int H_pos = origin.second + H_move;

  while (V_pos != destin.first or H_pos != destin.second) {

    if (board[V_pos][H_pos] != nullptr) {
      
      return false;
    }
    V_pos += V_move;
    H_pos += H_move;
  }
  return true;
}


void Board::makeMove(coord origin, coord destin) {

  board[destin.first][destin.second] = board[origin.first][origin.second];
  board[origin.first][origin.second] = nullptr;

  board[destin.first][destin.second]->UpdatePos(destin);
  board[destin.first][destin.second]->moved();

  std::cout << "'s " << board[destin.first][destin.second]->type << " moves from ";
}

bool Board::moveValidity(coord origin, coord destin) {

  Piece* P_origin = board[origin.first][origin.second];
  Piece* P_destin = board[destin.first][destin.second];

  if (squareState(origin)) {

    if (P_origin->valid_move(origin, destin, P_destin)) {

	if (pathFree(origin, destin)) {
	  
	  return true;
	}
	else {
	  std::cout << "The path is not free!\n";
	  return false;
	}
    }
    
    else {
      
      std::cout << "The move is not valid!\n";
      return false;
    }
  }
  else {

    string origin_str = "" + char(origin.second + 'A') + char(origin.first + '1');
    
    std::cout << "There is no piece at position " << origin_str << "!\n";
    return false;
  }
}


void Board::submitMove(string origin_str, string destin_str) {

  if (checkCoord(origin_str) or checkCoord(destin_str)){
    std::cout << "invalid position\n";
    exit(1);
  }

  coord origin = std::make_pair(origin_str[1] - '1', origin_str[0] - 'A');
  coord destin = std::make_pair(destin_str[1] - '1', destin_str[0] - 'A');

  if (moveValidity(origin, destin)) {

    makeMove(origin, destin);
    std::cout << origin_str << " to " << destin_str << "!\n";
  }
  
}

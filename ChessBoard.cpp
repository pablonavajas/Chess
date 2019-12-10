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

ChessBoard::ChessBoard() {

  //Call to reset Function (to create new board)
  resetBoard();
  
}

ChessBoard::~ChessBoard() {

  //Deallocate all memory
  int row=0;
  while (row < 8) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = nullptr;
    }
    row++;
  }
}


void ChessBoard::resetBoard() {

  //Ensure White moves first (initialise turn strings used in messages)
  turn = White;
  noturn_str = "Black";
  turn_str = "White";
  
  color team = White;

  //Deallocate previous memory
  int row=0;
  while (row < 8) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = nullptr;
    }
    row++;
  }

  //Create first line for each player
  for (int row = 0; row < 8; row += 7) {

    //Create necessary Pieces in the Heap
    board[row][0] = new Rook(std::make_pair(row,0),team);
    board[row][1] = new Knight(std::make_pair(row,1),team);
    board[row][2] = new Bishop(std::make_pair(row,2),team);
    board[row][3] = new Queen(std::make_pair(row,3),team);
    board[row][4] = new King(std::make_pair(row,4),team);
    board[row][5] = new Bishop(std::make_pair(row,5),team);
    board[row][6] = new Knight(std::make_pair(row,6),team);
    board[row][7] = new Rook(std::make_pair(row,7),team);
    
    team = Black;
  }

  //Track both Kings
  King_White = board[0][4];
  King_Black = board[7][4];

  //Create line of Pawns for each player
  team = White;

  for (int row = 1; row < 8; row += 5) {

    for (int col = 0; col < 8; col++) {

      board[row][col] = new Pawn(std::make_pair(row,col), team);
    }
    team = Black;
  }

  std::cout << "A new chess game is started!" << std::endl;
}


bool ChessBoard::checkCoord(string position) {

  //Ensure only two coordinates are entered
  if (position.length() != 2)
    return true;

  //Ensure the coordinates are in the correct range:
  else if (position[0] - 'A' > 7 or position[0] - 'A' < 0)
    return true;

  else if (position[1] - '1' > 7 or position[1] - '1' < 0)
    return true;

  return false;
}


bool ChessBoard::squareState(coord pos) {

  if (board[pos.first][pos.second] != nullptr)
    return true;

  return false;
}


bool ChessBoard::pathFree(coord origin, coord destin) {

  //Extract direction of the movement
  int V_move = (destin.first == origin.first) ? 0 : (destin.first > origin.first) ? 1 : -1;
  int H_move = (destin.second == origin.second) ? 0 : (destin.second > origin.second) ? 1 : -1;

  //Start at square next to origin in the movement direction
  int V_pos = origin.first + V_move;
  int H_pos = origin.second + H_move;

  //Check state of squares in the movement's direction
  while (V_pos != destin.first or H_pos != destin.second) {

    if (board[V_pos][H_pos] != nullptr) {
      
      return false;
    }
    V_pos += V_move;
    H_pos += H_move;
  }
  return true;
}


void ChessBoard::makeMove(coord origin, coord destin) {

  //Use Piece* to keep track of the piece at the destination (if any)
  Piece* P_target = nullptr;

  if (board[destin.first][destin.second] != nullptr) {
    P_target = board[destin.first][destin.second];
  }

  //Change the Piece being pointed by the initial and final locations
  board[destin.first][destin.second] = board[origin.first][origin.second];
  board[origin.first][origin.second] = nullptr;

  //Update the moved Piece's data members
  board[destin.first][destin.second]->updatePos(destin);
  board[destin.first][destin.second]->moved();

  std::cout << turn_str << "'s " << board[destin.first][destin.second]->type << " moves from " <<
    char(origin.second + 'A') << char(origin.first + '1') << " to " <<
    char(destin.second + 'A') << char(destin.first + '1');

  //If there was a Piece at the target location inform players and deallocate memory
  if (P_target != nullptr) {

    std::cout << " taking " << noturn_str << "'s " << P_target->type;
    P_target = nullptr;
  }

  std::cout << "\n";
}


bool ChessBoard::moveValidity(coord origin, coord destin) {

  Piece* P_origin = board[origin.first][origin.second];
  Piece* P_destin = board[destin.first][destin.second];

  //Check the move is valid for the piece
  if (P_origin->valid_move(origin, destin, P_destin)) {

    //Check if movement can be done
    
    /* First, check if it can jump (which would only be the knight) to avoid  *
     * extracting the direction of the knight's movement in pathFree function */
    
    if (P_origin->can_jump or pathFree(origin, destin)) {
	  
      return true;
    }
    else {
      
      return false;
    }
  }
  
  return false;
}


bool ChessBoard::checkTurn(coord origin) {

  Piece* P_origin = board[origin.first][origin.second];

  //Check a Piece is being moved
  if (squareState(origin)) {

    //Check it is of the current turn's color
    if (P_origin->team != turn) {

      std::cerr << "It is not " << noturn_str << "'s turn to move!\n";
      return true;
    }
    return false;
  }
  else {

    std::cerr << "There is no piece at position " << char(origin.second + 'A') <<
      char(origin.first + '1') << "!\n";
    
    return true;
  }
}


bool ChessBoard::moveLegal(coord origin, coord destin) {

  bool legal;

  //Similarly to when completing a movement, check if there is a targeted Piece
  Piece* P_target = nullptr;

  if (board[destin.first][destin.second] != nullptr) {

    P_target = board[destin.first][destin.second];
  }

  //Perform change of Pieces being pointed
  board[destin.first][destin.second] = board[origin.first][origin.second];
  board[origin.first][origin.second] = nullptr;

  //Update the data member of Piece moved
  board[destin.first][destin.second]->updatePos(destin);

  //Check if it causes its king to be in check
  if (inCheck(turn)) {
    legal = false;
  }
  else {
    legal = true;
  }

  //Undo movement
  board[origin.first][origin.second] = board[destin.first][destin.second];
  board[destin.first][destin.second] = P_target;

  //Restore data member of Piece moved
  board[origin.first][origin.second]->updatePos(origin);

  //Deallocate memory if necessary
  if (P_target != nullptr) {

    P_target = nullptr;
  }

  return legal;    
}


bool ChessBoard::inCheck(color team) {

  //Select the king that needs to be checked
  Piece* teamKing = (team == White) ? King_White : King_Black;

  //Check all locations to see if they point to a Piece
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {

      //If they point to one, check that it is of the opponent's team
      if (board[row][col] != nullptr and board[row][col]->team != team) {

	coord start_pos = std::make_pair(row,col);

	//Check if they can attack the King:
	if (moveValidity(start_pos, teamKing->position)) {

	  if (moveLegal(start_pos, teamKing->position)) {
	    
	    return true;
	  }
	}
      }
    }
  }
  return false;
}


bool ChessBoard::cannotMove(color team) {

  //Check all locations to see if they point to a Piece
  for (int team_r = 0; team_r < 8; team_r++) {
    for (int team_c = 0; team_c < 8; team_c++) {

      //If they point to one, check that it is of the playing team
      if (board[team_r][team_c] != nullptr and board[team_r][team_c]->team == team){

	coord team_pos = std::make_pair(team_r, team_c);
	coord rival_pos;

	//Check if it can perform a valid legal move to any position in the board
	for (int rival_r = 0; rival_r < 8; rival_r++) {
	  for (int rival_c = 0; rival_c < 8; rival_c++) {

	    rival_pos = std::make_pair(rival_r, rival_c);

	    if (moveValidity(team_pos, rival_pos)) {

	      if (moveLegal(team_pos, rival_pos)) {

		return false;
	      }
	    }
	  }
	}
      }
    }
  }
  return true;       
}


void ChessBoard::submitMove(string origin_str, string destin_str) {

  //Ensure valid coordinates are introduced
  if (checkCoord(origin_str) or checkCoord(destin_str)){
    
    std::cerr << "Invalid position enterred\n";
    return;
  }

  //Transform input strings into coord type
  coord origin = std::make_pair(origin_str[1] - '1', origin_str[0] - 'A');
  coord destin = std::make_pair(destin_str[1] - '1', destin_str[0] - 'A');

  //Check right player is moving
  if (checkTurn(origin)) {
    return;
  }

  //Check the move is valid and can be done
  if (moveValidity(origin, destin)) {

    if (moveLegal(origin, destin)) {

      makeMove(origin, destin);

      //Update turn (and turn strings for messaging)
      noturn_str = turn_str;
      turn_str = (turn == White) ? "Black" : "White";
      turn = (turn == White) ? Black : White;

      //Check if opponent has no valid legal moves left
      if (cannotMove(turn)) {

	//Differentiate between checkmate and stalemate
	if (inCheck(turn)) {
	  std::cout << turn_str << " is in checkmate\n";
	}
	else {
	  std::cout << turn_str << "is in stalemate\n";
	}
	return;
      }

      //Check if opponent is in check
      else if (inCheck(turn)) {
	std::cout << turn_str << " is in check\n";
      }
    }
  }
  else {
    std::cout << turn_str << "'s " << board[origin.first][origin.second]->type <<
      " cannot move to " << destin_str << "\n";
  }
}


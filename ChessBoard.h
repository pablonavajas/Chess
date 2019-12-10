/*********************************************************
 * Imperial College London - Department of Computing     *
 * MSc C++ Programming - Assessed Exercise No. 3         *
 * Chess Game Implementation                             *
 *                                                       *
 * Created by: Pablo Navajas Helguero                    *
 * Date: 9th December 2019                               *
 *                                                       *
 * File: ChessBoard.h                                    *
 *********************************************************/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<exception>
#include<iomanip>

#include"ChessPieces.h"

using std::setw;

/********************Exceptions********************/

//Exception class to inherit from exception base class
class AnyError : public std::exception {

 protected:

  string explanation;

 public:

  AnyError(const string& msg);
  
  ~AnyError() override;

  const char* what() const noexcept override;
  
};

//Exception class to record input exceeding coordinates size
class InputError : public AnyError {

 public:

  InputError(const string& msg, const string& input);
  
};

//Exception class to record coordinate out of range
class CoordError : public AnyError {

 public:

  CoordError(const string& msg, const string& input, const char& coord);

};


/*******************ChessBoard*********************/

class ChessBoard {

  static const int sizeBoard = 8;
  
  //Data members to keep tract of the Kings at all times
  Piece* King_White;
  Piece* King_Black;

  //Data member consisting of an array of Piece pointers (simulate chess board)
  Piece* board[sizeBoard][sizeBoard];

  //Data members to implement turn and print informative messages
  color turn;
  string noturn_str;
  string turn_str;

  //Data function to check input is correct
  void checkCoord(string position);

  //Data function to check if a square coordinate holds a piece
  bool squareState(coord pos);
  
  //Data function to check if the path between to coordinates is free
  bool pathFree(coord origin, coord destin);

  //Data function to perform a movement
  void makeMove(coord origin, coord destin);

  //Data function to check if a piece can complete a movement
  bool moveValidity(coord origin, coord destin);

  //Data function to check the turn is respected
  bool checkTurn(coord origin);
  
  //Data function to check if a movement is legal
  bool moveLegal(coord origin, coord destin);

  //Data function to check if a color is in check
  bool inCheck(color team);

  //Data function to check if a color has any valid legal moves left
  bool cannotMove(color team);



  
  bool checkCastling(coord origin, coord destin);

  void makeCastling(coord origin, coord destin);

  void finishTurn();

 public:
  
  //Class constructor
  ChessBoard();

  //Class virtual destructor
  virtual ~ChessBoard();

  //Data function to reset the board to original positions
  void resetBoard();
  
  //Data function to try a movement
  void submitMove(string origin, string destin);

  //Data function to print current board
  void print();
  
};


#endif

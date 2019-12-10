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

#include"ChessPieces.h"

class ChessBoard {

  //Data members to keep tract of the Kings at all times
  Piece* King_White;
  Piece* King_Black;

  //Data member consisting of an array of Piece pointers (simulate chess board)
  Piece* board[8][8];

  //Data members to implement turn and print informative messages
  color turn;
  string noturn_str;
  string turn_str;

  //Data function to check input is correct
  bool checkCoord(string position);

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

 public:

  //Class constructor
  ChessBoard();

  //Class virtual destructor
  virtual ~ChessBoard();

  //Data function to reset the board to original positions
  void resetBoard();
  
  //Data function to try a movement
  void submitMove(string origin, string destin);
  
};

#endif

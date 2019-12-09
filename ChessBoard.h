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

 public:

  Piece* King_White;
  Piece* King_Black;

  Piece* board[8][8];

  color turn;
  string turn_str;

  ChessBoard();

  ~ChessBoard();

  void resetBoard();

  bool checkCoord(string position);

  bool squareState(coord pos);

  bool pathFree(coord origin, coord destin);

  void makeMove(coord origin, coord destin);

  bool moveValidity(coord origin, coord destin);

  bool checkTurn(coord origin);

  //

  bool moveLegal(coord origin, coord destin);

  bool inCheck(color team);

  bool cannotMove(color team);

  //

  void submitMove(string origin, string destin);
  
};

#endif

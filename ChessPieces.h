//Imperial College London - Department of Computing
//MSc C++ Programming - Assessed Exercise No. 3
//Chess Game Implementation
//
//Created by: Pablo Navajas Helguero
//Date: Xth December 2019
//
//File: ChessPieces.h

#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include<iostream>
#include<string>

using std::string;

class Piece {

  int H_pos;
  int V_pos;

  Piece{};
  virtual ~Piece{};
  
  virtual void Move(string initial, string final) const = 0;

  int* ExtractPos(string position);

};

class Pawn : public Piece { //8
  
  int* init_pos;
  int* final_pos;

  void Move(string initial, string final);

  //
};

class King : public Piece {

  int* init_pos;
  int* final_pos;

  void Move(string initial, string final);

  void CheckPos(string position);
  
};

class Queen : public Piece {
  //
};

class Rooks : public Piece { //2
  //
};

class Bishops : public Piece { //2
  //
};

class Knight : public Piece { //2
  //
};

#endif

/*********************************************************
 * Imperial College London - Department of Computing     *
 * MSc C++ Programming - Assessed Exercise No. 3         *
 * Chess Game Implementation                             *
 *                                                       *
 * Created by: Pablo Navajas Helguero                    *
 * Date: 9th December 2019                               *
 *                                                       *
 * File: ChessPieces.cpp                                 *
 *********************************************************/

#include"ChessPieces.h"

#include<iostream>

//PIECE (GENERAL)

Piece::Piece(coord position, color team) : position(position), team(team) {
    
    first_move = true;
    can_jump = false;
}
  
Piece::~Piece() {};


void Piece::UpdatePos(coord new_pos) {

  position = new_pos;
}

void Piece::moved() {

  first_move = false;
}


//PAWN

Pawn::Pawn(coord position, color team) : Piece(position, team) {

  name = "p";
  type = "Pawn";
}

Pawn::~Pawn() {}

bool Pawn::valid_move(coord origin, coord destin, Piece* target) {

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;
  
  if (V_change == 0 or abs(H_change) > 1) {
    return false;
  }
    
  int V_perm;

  if (target != nullptr) {

    V_perm = (team == White) ? 1 : -1;

    if (destin.first == origin.first + V_perm and abs(H_change) == 1) {

      if (target->team == team) {
	
	return false;
      }

      else {
	return true;
      }
    }
    else {
      return false;
    }
  }

  if (first_move) {

    V_perm = (team == White) ? 2 : -2;

    if (destin.first == origin.first + V_perm and H_change == 0) {
      return true;
    }
  }
  
  V_perm = (team == White) ? 1 : -1;

  if (destin.first == origin.first + V_perm and H_change == 0) {
    return true;
  }

  return false;
}



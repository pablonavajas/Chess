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

//Piece:

Piece::Piece(coord position, color team) : position(position), team(team) {
    
    first_move = true;
    can_jump = false;
}
  
Piece::~Piece() {};


void Piece::updatePos(coord new_pos) {

  position = new_pos;
}

void Piece::moved() {

  first_move = false;
}


/***************Pawn***********************/
//Constructor using base class initialiser:
Pawn::Pawn(coord position, color team) : Piece(position, team) {

  name = "p";
  type = "Pawn";
}

Pawn::~Pawn() {}

bool Pawn::valid_move(coord origin, coord destin, Piece* target) {

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //Move cannot be purely horizontal
  if (V_change == 0 or abs(H_change) > 1) {
    return false;
  }
    
  int V_perm;

  //If destination is occupied
  if (target != nullptr) {

    V_perm = (team == White) ? 1 : -1;

    //Implement taking pieces in diagonal
    if (destin.first == origin.first + V_perm and abs(H_change) == 1) {

      //Ensure they are not from the same team
      if (target->team == team) {
	
	return false;
      }

      else {
	return true;
      }
    }
    //It cannot take pieces in non-diagonal move
    else {
      return false;
    }
  }
  //In their first move they can advance 2 squares
  if (first_move) {

    V_perm = (team == White) ? 2 : -2;

    if (destin.first == origin.first + V_perm and H_change == 0) {
      return true;
    }
  }

  //Their basic move is one square vertically
  V_perm = (team == White) ? 1 : -1;

  if (destin.first == origin.first + V_perm and H_change == 0) {
    return true;
  }

  return false;
}


/***************King*********************/
//Constructor using base class initialiser
King::King(coord position, color team) : Piece(position, team) {

  name = "k";
  type = "King";
}

King::~King() {}


bool King::valid_move(coord origin, coord destin, Piece* target) {

  //Ensure it only takes pieces from the opposite color
  if (target != nullptr and target->team == team) {

    return false;
  }

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //Avoid case where it stays in its original position
  if (abs(H_change) == 0 and abs(V_change) == 0) {
    return false;
  }
  
  //It can only move 1 square in any direction
  if (abs(H_change) > 1 or abs(V_change) > 1) {
    return false;
  }

  return true;  
}



/*****************Queen*******************/
//Constructor using base class initialiser
Queen::Queen(coord position, color team) : Piece(position, team) {

  name = "q";
  type = "Queen";
}

Queen::~Queen() {}


bool Queen::valid_move(coord origin, coord destin, Piece* target) {

  //Ensure it only takes pieces of the opposite color
  if (target != nullptr and target->team == team) {

    return false;
  }

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //Avoid case where remains in its original position
  if (abs(H_change) == 0 and abs(V_change) == 0) {
    return false;
  }

  //It can perform the movement of the Rook
  else if ((abs(H_change) == 0 and abs(V_change) > 0) or (abs(H_change) > 0 and abs(V_change) == 0)) {
    return true;
  }

  //And of the Bishop
  else if (abs(H_change) == abs(V_change)) {
    return true;
  }    

  return false;  
}


/*********************Rook***********************/
//Constructor using base class initialiser
Rook::Rook(coord position, color team) : Piece(position, team) {

  name = "r";
  type = "Rook";
}

Rook::~Rook() {}

bool Rook::valid_move(coord origin, coord destin, Piece* target) {

  //Ensure it can only take pieces of the opposite color
  if (target != nullptr and target->team == team) {

    return false;
  }

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //It can move in a straight line any number of squares
  if ((abs(H_change) == 0 and abs(V_change) > 0) or (abs(H_change) > 0 and abs(V_change) == 0)) {
    return true;
  }    

  return false;  
}



/**********************Bishop*******************/
//Constructor using base class initialiser
Bishop::Bishop(coord position, color team) : Piece(position, team) {

  name = "b";
  type = "Bishop";
}

Bishop::~Bishop() {}


bool Bishop::valid_move(coord origin, coord destin, Piece* target) {

  //Ensure it can only take pieces of the opposite color
  if (target != nullptr and target->team == team) {

    return false;
  }

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //Avoid case where it remains in original position
  if (abs(H_change) == 0 and abs(V_change) == 0) {
    return false;
  }

  //It moves diagonally any number of squares
  else if (abs(H_change) == abs(V_change)) {
    return true;
  }    

  return false;  
}



/*********************Knight***********************/
//Constructor using base class initialiser
Knight::Knight(coord position, color team) : Piece(position, team) {

  can_jump = true;
  name = "t";
  type = "Knight";
}

Knight::~Knight() {}

bool Knight::valid_move(coord origin, coord destin, Piece* target) {

  //Ensure it only takes pieces from opponent's color
  if (target != nullptr and target->team == team) {

    return false;
  }

  int V_change = destin.first - origin.first;
  int H_change = destin.second - origin.second;

  //It can move performing an 'L' shape
  if (abs(H_change) == 2 and abs(V_change) == 1) {
    return true;
  }

  else if (abs(H_change) == 1 and abs(V_change) == 2) {
    return true;
  }
  
  return false;  
}

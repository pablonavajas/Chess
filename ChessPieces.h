/*********************************************************
 * Imperial College London - Department of Computing     *
 * MSc C++ Programming - Assessed Exercise No. 3         *
 * Chess Game Implementation                             *
 *                                                       *
 * Created by: Pablo Navajas Helguero                    *
 * Date: 9th December 2019                               *
 *                                                       *
 * File: ChessPieces.h                                   *
 *********************************************************/

#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include<iostream>
#include<string>

using std::string;

//Declare identifiers used to keep track of color and coordinates of Pieces
typedef enum{White, Black} color;
typedef std::pair<int, int> coord;

//Abstract Base Class Piece
class Piece {

 public:
  //Data members used to store color and coordinates of the Piece
  coord position;
  color team;

  //Data member holding a Piece identifier (used in print helper function)
  string name;
  //Data member holding Piece type (or chessman)
  string type;

  //Data members holding extra information about pieces
  bool first_move;
  bool can_jump;

  //Class constructor
  Piece(coord position, color team);

  //Class virtual destructor
  virtual ~Piece();

  //Member functions to update data members
  virtual void updatePos(coord new_pos);

  void moved();

  //Pure virtual function, to ensure Pieces of a certain type are created
  virtual bool valid_move(coord origin, coord destin, Piece* target) = 0;

  //Friend extraction operator (used in print helper function)
  friend std::ostream& operator<<(std::ostream& o, Piece& p) {

    //Print piece identifier plus color information
    string info;

    if (p.team == White)
      info = "w";

    else
      info = "b";

    o << p.name;
    return o << info;
  }
};


class Pawn : public Piece { 
  
 public:

  //Pawn constructor
  Pawn(coord position, color team);

  //Pawn virtual destructor
  virtual ~Pawn();
  
  //Overriding pure virtual function from base class to fit Pawn's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;

};


class King : public Piece {

 public:

  //King constructor
  King(coord position, color team);

  //King virtual destrcutor
  virtual ~King();

  //Overriding pure virtual function from base class to fit King's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};


class Queen : public Piece {

 public:

  //Queen constructor
  Queen(coord position, color team);

  //Queen virtual destructor
  virtual ~Queen();

  //Overriding pure virtual function from base class to fit Queen's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Rook : public Piece { 

 public:

  //Rook constructor
  Rook(coord position, color team);

  //Rook virtual destrcutor
  virtual ~Rook();

  //Overriding pure virtual function from base class to fit Rook's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Bishop : public Piece { 

 public:

  //Bishop constructor
  Bishop(coord position, color team);

  //Bishop virtual destructor
  virtual ~Bishop();

  //Overriding pure virtual function from base class to fit Bishop's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Knight : public Piece {

 public:

  //Knight constructor
  Knight(coord position, color team);

  //Knight virtual destructor
  virtual ~Knight();

  //Overriding pure virtual function from base class to fit Knight's rules
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};


#endif

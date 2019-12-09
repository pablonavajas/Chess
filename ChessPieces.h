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

typedef enum{White, Black} color;
typedef std::pair<int, int> coord;

class Piece {

 public:
  
  bool first_move;
  bool can_jump;
  coord position;
  color team;

  string name;
  string type;

  
  Piece(coord position, color team);
  
  virtual ~Piece();

  
  
  virtual void updatePos(coord new_pos);

  void moved();

  virtual bool valid_move(coord origin, coord destin, Piece* target) = 0;

  friend std::ostream& operator<<(std::ostream& o, Piece& p) {

    string info;

    if (p.team == White)
      info = "w";

    else
      info = "b";


    o << p.name;
    return o << info;
  }
};


class Pawn : public Piece { //8
  
 public:

  Pawn(coord position, color team);

  virtual ~Pawn();
  

  bool valid_move(coord origin, coord destin, Piece* target) override;

};


class King : public Piece {

 public:

  King(coord position, color team);

  virtual ~King();
  
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};


class Queen : public Piece {

 public:

  Queen(coord position, color team);

  virtual ~Queen();
  
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Rook : public Piece { 

 public:

  Rook(coord position, color team);

  virtual ~Rook();
  
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Bishop : public Piece { 

 public:

  Bishop(coord position, color team);

  virtual ~Bishop();
  
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};

class Knight : public Piece {

 public:

  Knight(coord position, color team);

  virtual ~Knight();
  
  bool valid_move(coord origin, coord destin, Piece* target) override;
  
};


#endif

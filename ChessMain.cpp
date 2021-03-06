/*********************************************************
 * Imperial College London - Department of Computing     *
 * MSc C++ Programming - Assessed Exercise No. 3         *
 * Chess Game Implementation                             *
 *                                                       *
 * Created by: Pablo Navajas Helguero                    *
 * Date: 9th December 2019                               *
 *                                                       *
 * File: ChessMain.cpp                                   *
 *********************************************************/

#include"ChessBoard.h"

#include<iostream>

using namespace std;


int main() {

  
  cout << "========================\n";
  cout << "Testing the Chess Engine\n";
  cout << "========================\n\n";
  
  ChessBoard cb;
  cout << '\n';
  
  cb.submitMove("D7", "D6");
  cout << '\n';

  
  cb.submitMove("D4", "H6");
  cout << '\n';

  
  cb.submitMove("D2", "D4");
  cout << '\n';
  
  cb.submitMove("F8", "B4");
  cout << '\n';

  cb.submitMove("Y3", "B4");

  
  cout << "=========================\n";
  cout << "Alekhine vs. Vasic (1931)\n";
  cout << "=========================\n\n";
  
  cb.resetBoard();
  cout << '\n';
  
  cb.submitMove("E2", "E4");
  cb.submitMove("E7", "E6");
  cout << '\n';

  cb.submitMove("D2", "D4");
  cb.submitMove("D7", "D5");
  cout << '\n';

  cb.submitMove("B1", "C3");
  cb.submitMove("F8", "B4");
  cout << '\n';
  
  cb.submitMove("F1", "D3");
  cb.submitMove("B4", "C3");
  cout << '\n';
  
  cb.submitMove("B2", "C3");
  cb.submitMove("H7", "H6");
  cout << '\n';
  
  cb.submitMove("C1", "A3");
  cb.submitMove("B8", "D7");
  cout << '\n';
  
  cb.submitMove("D1", "E2");
  cb.submitMove("D5", "E4");
  cout << '\n';
  
  cb.submitMove("D3", "E4");
  cb.submitMove("G8", "F6");
  cout << '\n';
  
  cb.submitMove("E4", "D3");
  cb.submitMove("B7", "B6");
  cout << '\n';
  
  cb.submitMove("E2", "E6");
  cb.submitMove("F7", "E6");
  cout << '\n';
  
  cb.submitMove("D3", "G6");
  cout << '\n';
  /*
  cout << "========================\n";
  cout << "Testing Chess Castling  \n";
  cout << "========================\n\n";

  cb.resetBoard();
  cout << '\n';
  
  cb.submitMove("E2", "E3");
  cout << '\n';
  
  cb.submitMove("E7", "E5");
  cout << '\n';
  
  cb.submitMove("B1", "C3");
  cout << '\n';
  
  cb.submitMove("B8", "A6");
  cout << '\n';

  cb.submitMove("B2", "B3");
  cout << '\n';

  cb.print();
  
  cb.submitMove("F8", "C5");
  cout << '\n';

  cb.print();
  
  cb.submitMove("C1", "A3");
  cout << '\n';

  cb.print();
  
  cb.submitMove("G8", "F6");
  cout << '\n';
  
  cb.submitMove("D1", "G4");
  cout << '\n';
  
  cb.print();
  
  cb.submitMove("E8", "G8");
  cout << '\n';
  
  cb.submitMove("E1", "C1");
  cout << '\n';
  
  cb.print();

  cb.submitMove("A8", "B8");
  cout << '\n';
  */
  
  return 0;
}


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
#include<iomanip>

using namespace std;

void printcb(Board cb);

int main() {

  Board cb;

  cb.submitMove("D2", "D4");

  printcb(cb);

  cb.submitMove("D4", "D5");
  
  printcb(cb);

  cb.submitMove("D5", "D6");

  cb.submitMove("D7", "D5");

  printcb(cb);

  cb.submitMove("E7", "D6");

  cb.submitMove("D7", "D5");

  printcb(cb);

  cb.submitMove("D6", "D5");

  cb.submitMove("D7", "D6");

  printcb(cb);
  
  
  
  /*
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
  */
	return 0;
}

void printcb(Board cb) {

  int row = 0;
  std::cout << "-------------------------------------------------\n";

  while (row < 8) {

    for (int col = 0; col < 8; col++) {

      coord posc = std::make_pair(row,col);

      if (cb.squareState(posc)) {
	std::cout << "| " << setw(2) << *cb.board[row][col] << " ";
      }
      else {
	std::cout << "| " << setw(2) << "   " << " ";
      }
    }
    row++;
    std::cout << "|\n-------------------------------------------------\n";
  }
  std::cout << "\n\n";
}

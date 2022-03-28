#include <iostream>
using namespace std;
#include"life2.h"


int main(){
    life board; // life is the class and board is the object
    board.rule();
    board.initialize();
    board.print();
    board.run();
}

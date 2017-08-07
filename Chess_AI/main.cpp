#include "libraries.h"
#include "bitboards.h"

int main()
{
    Board b;
    b.reset();
    b.output();
    b.board[3][0]->Move(b);

    cout << endl << "Checkmate found!" << endl;

    return 0;
}

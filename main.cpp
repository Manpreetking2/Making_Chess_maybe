#include <array>
#include <iostream>
#include <string>

using Board = std::array<std::array<char, 8>, 8>;

Board startingBoard()
{
    return {{
        {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}},
        {{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}},
        {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}}
    }};
}

void drawBoard(const Board& board)
{
    std::cout << "\n      a   b   c   d   e   f   g   h\n";
    std::cout << "    +---+---+---+---+---+---+---+---+\n";

    for (int row = 0; row < 8; ++row)
    {
        std::cout << "  " << 8 - row << " |";
        for (int column = 0; column < 8; ++column)
        {
            const char piece = board[row][column];
            std::cout << ' ' << (piece == ' ' ? '.' : piece) << " |";
        }
        std::cout << " " << 8 - row << '\n';
        std::cout << "    +---+---+---+---+---+---+---+---+\n";
    }

    std::cout << "      a   b   c   d   e   f   g   h\n";
}

void drawScreen(const Board& board)
{
    std::cout << "\n=======================================\n"
              << "              CHESS GAME\n"
              << "=======================================\n";
    drawBoard(board);
    std::cout << "\nWhite pieces: UPPERCASE    Black pieces: lowercase\n"
              << "Game status: Ready to play (move handling not connected yet)\n"
              << "\n1. Reset board\n"
              << "2. Quit\n"
              << "Choose an option: ";
}

int main()
{
    Board board = startingBoard();
    std::string choice;

    while (true)
    {
        drawScreen(board);

        if (!std::getline(std::cin, choice))
        {
            break;
        }

        if (choice == "1")
        {
            board = startingBoard();
            std::cout << "\nBoard reset to the starting position.\n";
        }
        else if (choice == "2" || choice == "q" || choice == "Q")
        {
            std::cout << "\nThanks for playing!\n";
            break;
        }
        else
        {
            std::cout << "\nPlease enter 1 to reset the board or 2 to quit.\n";
        }
    }

    return 0;
}

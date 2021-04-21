#include "GameManager.h"
#include <iostream>
#include <windows.h>
#include <wincon.h>

#include "CommonMethods.h"


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
GameManager::GameManager()
{
    for (int x=0; x < GAME_BOARD_SIZE; ++x)
    {
        m_GameBoardPieces[x] = EBoardPieceState::eNone;
    }
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
void GameManager::DrawBoard()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);

    std::cout << "\t" << "  " << "A" << "     " << "B" << "     " << "C" << std::endl;

    std::cout << "\t" << "_________________" << std::endl;
    std::cout << "\t" << "     |     |     " << std::endl;

    std::cout << "\t" << "  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[0]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[1]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[2]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "\t  1" << std::endl;

    std::cout << "\t" << "_____|_____|_____" << std::endl;
    std::cout << "\t" << "     |     |     " << std::endl;

    std::cout << "\t" << "  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[3]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[4]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[5]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "\t  2" << std::endl;

    std::cout << "\t" << "_____|_____|_____" << std::endl;
    std::cout << "\t" << "     |     |     " << std::endl;

    std::cout << "\t" << "  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[6]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[7]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "  |  ";
    SetConsoleTextAttribute(hConsole, PURPLE_COLOR_CODE);
    std::cout << BoardPieceStateToString(m_GameBoardPieces[8]);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);
    std::cout << "\t  3" << std::endl;

    std::cout << "\t" << "     |     |     " << std::endl << std::endl;

}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
void GameManager::SetBoardPiece(std::string& input, bool& player1turn)
{
    int index = ColumnRowStringToIndex(input);

    if (player1turn)
    {
        m_GameBoardPieces[index] = EBoardPieceState::ePlayer1;
    }
    else
    {
        m_GameBoardPieces[index] = EBoardPieceState::ePlayer2;
    }
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
bool GameManager::CheckWinCondition()
{
    // First Row
    if (m_GameBoardPieces[0] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[1] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[2] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[0] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[1] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[2] == EBoardPieceState::ePlayer2)
    {
        return true;
    }
    // Second Row
    if (m_GameBoardPieces[3] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[5] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[3] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[5] == EBoardPieceState::ePlayer2)
    {
        return true;
    }
    // Third Row
    if (m_GameBoardPieces[6] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[7] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[6] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[7] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer2)
    {
        return true;
    }

    // First Column
    if (m_GameBoardPieces[0] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[3] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[6] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[0] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[3] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[6] == EBoardPieceState::ePlayer2)
    {
        return true;
    }
    // Second Column
    if (m_GameBoardPieces[1] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[7] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[1] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[7] == EBoardPieceState::ePlayer2)
    {
        return true;
    }
    // Third Column
    if (m_GameBoardPieces[2] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[5] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[2] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[5] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer2)
    {
        return true;
    }

    // Left Right Diagonal
    if (m_GameBoardPieces[0] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[0] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[8] == EBoardPieceState::ePlayer2)
    {
        return true;
    }
    // Right Left Diagonal
    if (m_GameBoardPieces[2] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer1 && m_GameBoardPieces[6] == EBoardPieceState::ePlayer1
     || m_GameBoardPieces[2] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[4] == EBoardPieceState::ePlayer2 && m_GameBoardPieces[6] == EBoardPieceState::ePlayer2)
    {
        return true;
    }

    return false;
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
bool GameManager::UserInputIsValid(std::string& input, bool castingSpell)
{
    if (input == "cast")
    {
        return true;
    }

    // Make sure input is correct length.
    if (input.length() != 2)
    {
        return false;
    }

    // Make sure first character is a proper column.
    if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c')
    {
        return false;
    }

    // Make sure second character is a proper row.
    if (input[1] != '1' && input[1] != '2' && input[1] != '3')
    {
        return false;
    }

    // Make sure space is not already set.
    if (!castingSpell && m_GameBoardPieces[ColumnRowStringToIndex(input)] != EBoardPieceState::eNone)
    {
        return false;
    }

    return true;
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
std::string GameManager::BoardPieceStateToString(EBoardPieceState& inState)
{
    switch (inState)
    {
    case EBoardPieceState::eNone:
        return " ";
        break;
    case EBoardPieceState::ePlayer1:
        return "X";
        break;
    case EBoardPieceState::ePlayer2:
        return "0";
        break;
    default:
        return " ";
    }
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
int GameManager::ColumnRowStringToIndex(std::string& input)
{
    if (input == "a1")
    {
        return 0;
    }
    else if (input == "a2")
    {
        return 3;
    }
    else if (input == "a3")
    {
        return 6;
    }
    else if (input == "b1")
    {
        return 1;
    }
    else if ( input == "b2")
    {
        return 4;
    }
    else if (input == "b3")
    {
        return 7;
    }
    else if (input == "c1")
    {
        return 2;
    }
    else if (input == "c2")
    {
        return 5;
    }
    else if (input == "c3")
    {
        return 8;
    }

    return -1;
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
void GameManager::FormatUserInputString(std::string& input)
{
    for (unsigned int x=0; x < input.length(); ++x)
    {
        input[x] = tolower(input[x]);
    }
}


// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
void GameManager::CastSpell(std::string& input)
{
    bool randomBool = CommonMethods::GetRandomBool();

    // Destroy Row
    if (randomBool)
    {
        char rowNumber = input[1];
        if (rowNumber == '1')
        {
            m_GameBoardPieces[0] = EBoardPieceState::eNone;
            m_GameBoardPieces[1] = EBoardPieceState::eNone;
            m_GameBoardPieces[2] = EBoardPieceState::eNone;
        }
        else if (rowNumber == '2')
        {

            m_GameBoardPieces[3] = EBoardPieceState::eNone;
            m_GameBoardPieces[4] = EBoardPieceState::eNone;
            m_GameBoardPieces[5] = EBoardPieceState::eNone;
        }
        else
        {

            m_GameBoardPieces[6] = EBoardPieceState::eNone;
            m_GameBoardPieces[7] = EBoardPieceState::eNone;
            m_GameBoardPieces[8] = EBoardPieceState::eNone;
        }
    }
    // Destroy Column
    else
    {
        char columnLetter = tolower(input[0]);
        if (columnLetter == 'a')
        {
            m_GameBoardPieces[0] = EBoardPieceState::eNone;
            m_GameBoardPieces[3] = EBoardPieceState::eNone;
            m_GameBoardPieces[6] = EBoardPieceState::eNone;
        }
        else if (columnLetter == 'b')
        {

            m_GameBoardPieces[1] = EBoardPieceState::eNone;
            m_GameBoardPieces[4] = EBoardPieceState::eNone;
            m_GameBoardPieces[7] = EBoardPieceState::eNone;
        }
        else
        {

            m_GameBoardPieces[2] = EBoardPieceState::eNone;
            m_GameBoardPieces[5] = EBoardPieceState::eNone;
            m_GameBoardPieces[8] = EBoardPieceState::eNone;
        }
    }
}

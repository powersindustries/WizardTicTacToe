#pragma once
#include <string> 

#define GAME_BOARD_SIZE 9

#define DEFAULT_COLOR_CODE      3
#define RED_COLOR_CODE          4
#define PURPLE_COLOR_CODE       5
#define ORANGE_COLOR_CODE       6
#define LIGHTBLUE_COLOR_CODE    11


enum class EBoardPieceState
{
    eNone,
    ePlayer1,
    ePlayer2
};


class GameManager
{
public:

    GameManager();

    void DrawBoard();

    bool CheckWinCondition();

    bool UserInputIsValid(std::string& input, bool castingSpell = false);

    void SetBoardPiece(std::string& userInput, bool& player1Turn);

    void FormatUserInputString(std::string& input);
    void CastSpell(std::string& input);

private:

    std::string BoardPieceStateToString(EBoardPieceState& inState);

    int ColumnRowStringToIndex(std::string& input);

private:

    EBoardPieceState m_GameBoardPieces[GAME_BOARD_SIZE];

};

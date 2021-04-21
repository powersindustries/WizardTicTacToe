#include <iostream>
#include <windows.h>
#include <wincon.h>

#include "CommonMethods.h"
#include "GameManager.h"


int main()
{
    GameManager gameManager;

    bool gameRunning = true;
    bool player1Turn = true;

    bool player1SpellSlotAvailable = true;
    bool player2SpellSlotAvailable = true;

    bool invalidInputDialogue          = false;
    bool spellUsedSuccessfullyDialogue = false;
    bool spellFailedDialogue           = false;


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, ORANGE_COLOR_CODE);

    std::cout << "Welcome to Wizard TicTacToe" << std::endl;
    std::cout <<  std::endl;
    std::cout <<  std::endl;

    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);


    // Game loop
    while (gameRunning)
    {
        std::string userInput;
        std::string spellSlotInput;
        bool inputIsValid = false;

        // Print spell slot dialog and invalid input dialog if applicable.
        SetConsoleTextAttribute(hConsole, RED_COLOR_CODE);
        if (spellUsedSuccessfullyDialogue)
        {
            std::cout << "BLAAAM!!" << std::endl;
        }
        else if (spellFailedDialogue)
        {
            std::cout << "You muttered the spell incorrectly! The spell puffs up in a gasp of flame!" << std::endl;
        }
        else if (invalidInputDialogue)
        {
            std::cout << "Invalid Input. Try again." << std::endl;
        }
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);

        // Draw the board in its current state.
        gameManager.DrawBoard();

        // Print turn order and spell slot dialog.
        SetConsoleTextAttribute(hConsole, LIGHTBLUE_COLOR_CODE);
        if (player1Turn)
        {
            std::cout << "    " << "Wizard 1's Turn (You're X's)" << std::endl;

            std::cout << "    " << "Spell slots available: " << player1SpellSlotAvailable << std::endl;
            std::cout <<  std::endl;
        }
        else
        {
            std::cout << "    " << "Wizard 2's Turn (You're O's)" << std::endl;

            std::cout << "    " << "Spell slots available: " << player2SpellSlotAvailable << std::endl;
            std::cout <<  std::endl;
        }
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);

        // Print dialog for user input.
        std::cout << "Select a Column letter and then row number (EX: A1, A2, A3, etc)" << std::endl;
        if ((player1Turn && player1SpellSlotAvailable) || (!player1Turn && player2SpellSlotAvailable))
        {
            std::cout << "You have a spell slot available. Type 'CAST' to use it." << std::endl;
        }
        std::cin >> userInput;

        // Format userInput, then check to make sure if its valid.
        gameManager.FormatUserInputString(userInput);
        inputIsValid = gameManager.UserInputIsValid(userInput);

        // Cast Spell input.
        if (inputIsValid && userInput == "cast")
        {
            // Safety check to see if player has spell slots when they press cast
            if ((player1Turn && !player1SpellSlotAvailable) || (!player1Turn && !player2SpellSlotAvailable))
            {
                invalidInputDialogue = true;

                spellUsedSuccessfullyDialogue = false;
                spellFailedDialogue           = false;
            }
            else
            {
                std::cout << "Select a Column letter and row number to destroy." << std::endl;
                std::cin >> spellSlotInput;
                gameManager.FormatUserInputString(spellSlotInput);

                if (gameManager.UserInputIsValid(spellSlotInput, true))
                {
                    gameManager.CastSpell(spellSlotInput);

                    spellUsedSuccessfullyDialogue = true;
                }
                else
                {
                    spellFailedDialogue = true;
                }

                // Remove spell slot from player.
                if (player1Turn)
                {
                    player1SpellSlotAvailable = false;
                }
                else
                {
                    player2SpellSlotAvailable = false;
                }

                player1Turn = !player1Turn;
            }

            CommonMethods::ClearConsole();
        }
        // Regular column row input.
        else if (inputIsValid)
        {
            gameManager.SetBoardPiece(userInput, player1Turn);

            if (gameManager.CheckWinCondition())
            {
                gameManager.DrawBoard();

                SetConsoleTextAttribute(hConsole, RED_COLOR_CODE);
                if (player1Turn)
                {
                    std::cout << "Wizard 1 wins!" << std::endl;
                }
                else
                {
                    std::cout << "Wizard 2 wins!" << std::endl;
                }
                SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_CODE);

                gameRunning = false;
            }
            else
            {
                CommonMethods::ClearConsole();
            }

            player1Turn = !player1Turn;

            invalidInputDialogue          = false;
            spellUsedSuccessfullyDialogue = false;
            spellFailedDialogue           = false;
        }
        // Invalid input.
        else
        {
            // Display error dialog.
            invalidInputDialogue = true;

            spellUsedSuccessfullyDialogue = false;
            spellFailedDialogue           = false;
            
            CommonMethods::ClearConsole();
        }
    }
}

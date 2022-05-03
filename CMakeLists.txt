cmake_minimum_required(VERSION 2.7)
project(WizardTicTacToe)

set(SOURCE_FILES

    WizardTicTacToe.cpp

    CommonMethods.h
    CommonMethods.cpp
    GameManager.h
    GameManager.cpp

)

add_executable(WizardTicTacToe  ${SOURCE_FILES})
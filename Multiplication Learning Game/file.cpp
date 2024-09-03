#include <bits/stdc++.h>
#include "file_.h"
using namespace std;

int highScore = 0;

/**
 *  Starts the game where the user answers multiplication questions.
 *
 * This function handles the main game loop. It prompts the user for their name,
 * generates questions, checks answers, and adjusts the difficulty level. The game
 * ends if the user answers 3 questions wrong in a row or completes all levels.
 */

void startGame(void)
{
    string playerName;
    int score = 0;
    int successiveCorrect = 0;
    int successiveWrong = 0;
    int difficultyLevel = 1;
    const int maxQuestions = 20;

    cout << "Enter your name: ";
    cin >> playerName;

    for (int i = 0; i <= maxQuestions; i++)
        {
        int correctAnswer = generateQuestion(difficultyLevel);
        int playerAnswer;

        cout << "Your answer: ";
        cin >> playerAnswer;

        if (playerAnswer == correctAnswer)
        {
            cout << "Correct"<<endl;
            score += 10;
            successiveCorrect++;
            successiveWrong = 0;

            if (successiveCorrect == 3)
            {
                difficultyLevel++;
                successiveCorrect = 0;
                cout << "Difficulty increased"<<endl;
            }
        }
        else
        {
            cout << "Incorrect. The correct answer was " << correctAnswer<<endl;
            successiveWrong++;
            successiveCorrect = 0;

            if (successiveWrong == 3)
            {
                cout << "Game Over! You've answered 3 questions wrong in a row."<<endl;
                break;
            }
        }

        if (difficultyLevel == 4)
        {
            cout << "Congratulations! You've mastered all difficulty levels."<<endl;
            break;
        }
    }

    cout  << playerName << ", your final score is: " << score <<endl;
    updateHighScore(score);
}


/**
 * Displays the help menu for the game.
 *
 * This function provides instructions and guidance on how to play the game.
 * It explains the purpose of the game, how to answer questions, and the rules
 * for advancing difficulty levels and ending the game.
 */

void showHelp(void)
 {
    cout << "***Help***"<<endl;
    cout << "The Multiplication Learning Game helps you practice multiplication."<<endl;
    cout << "Answer the multiplication questions as they appear on the screen."<<endl;
    cout << "After 3 consecutive correct answers, the difficulty level increases."<<endl;
    cout << "If you answer 3 questions wrong in a row, the game ends."<<endl;
    cout << "Your goal is to achieve the highest score possible"<<endl;
}

/**
 *  Displays the highest score achieved in the game.
 *
 * This function outputs the current high score stored in the global variable
 * `highScore`.
 */

void showHighScore(void)
{
    cout << "The current high score is: " << highScore <<endl;
}


/**
 *  Exits the game and thanks the player for participating.
 *
 * This function displays a farewell message and ends the program.
 */

void exitGame(void)
 {
    cout << "Thanks for playing! Goodbye."<<endl;
}


/**
 * Generates a multiplication question based on the current difficulty level.
 *
 * This function generates two random numbers based on the difficulty level,
 * displays a multiplication question, and returns the correct answer.
 *
 *  difficultyLevel The current difficulty level of the game.
 * return The correct answer to the multiplication question.
 */

int generateQuestion(int difficultyLevel)
{
    int num1, num2;

    switch (difficultyLevel)
     {
        case 1:
            num1 = rand() % 10 + 1;  // Numbers from 1 to 10
            num2 = rand() % 10 + 1;
            break;
        case 2:
            num1 = rand() % 50 + 1;  // Numbers from 1 to 50
            num2 = rand() % 50 + 1;
            break;
        case 3:
            num1 = rand() % 100 + 1; // Numbers from 1 to 100
            num2 = rand() % 100 + 1;
            break;
        default:
            num1 = rand() % 10 + 1;
            num2 = rand() % 10 + 1;
            break;
    }

    cout << "Question: " << num1 << " * " << num2 << " = ?"<<endl;
    return num1 * num2;
}
/**
 * Updates the high score if the current score is greater.
 *
 * This function compares the current score with the existing high score. If the
 * current score is higher, it updates the high score and informs the user.
 *
 * score The score achieved by the player in the current game session.
 */

void updateHighScore(int score)
 {
    if (score > highScore)
    {
        highScore = score;
        cout << "New high score "<<endl;
    }
}

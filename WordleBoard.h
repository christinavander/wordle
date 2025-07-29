/*Christina Vanderwerf
CS360
This program takes a five letter word from user input and compares it to a randomly selected five letter word to see if they match. If a letter is green, the letter is correct and in the correct spot. If a letter is yellow, the letter is correct but in the wrong spot in the word.*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;
using std::vector;

class WordleBoard {
  private:
    vector<string> guesses;
    string solution, guess;
    string coloredGuess;
    string const yellow = "\033[33m"; 
    string const endColor = "\033[0m";
    string const green = "\033[32m";
    bool solutionWordLetterUsage [5] = { false, false, false, false, false};
    int guessWordLetterUsage [5] = { 3, 3, 3, 3, 3};

    int const rightLetterRightPos = 1;
    int const rightLetterWrongPos = 2;
    int const letterNotUsed = 3;

  public:

    /*This is the default constructor of the WordleBoard class. It takes no parameters. solution and guess strings will be empty.

    Reurn: none */
    WordleBoard();


    /*This is the constructor of the WordleBoard class. It takes a string and sets that as the solution and takes another string and sets that as the guess.

    s - solution
    g - guess

    Return: none */
    WordleBoard(string s, string g);


    /*This function takes a string in the parameters and sets the guess variable to that string.

    g - guess

    Return: none*/
    void setGuess(string guess);


    /*This function takes a string in the parameteres and sets the solution variable to that string.

    s - solution

    Return: none */
    void setSolution(string s);


  /*This function first resets guessWordLetterUsage and solutionWordLetterUsage using the resetArrays() function. It then compares the guess word and solution word to see if any letters match. If they do then solutionWordLetterUsage[index] is set to true and guessWordLetterUsage[index] is set to rightLetterRightPos. It uses fundUnusedLetterInRealWorld(letter) function to see if the letter in guess is used in the solution. Once the arrays are correct, it calls the colorWord function.

  Return: none */
    void compareSolutionAndGuess();


  /* This function takes a single character from guess variable 
and checks to see if there is an unused match somewhere in the real word
if so, it marks that letter in that location as used and returns that
index value

if no match is found anywhere or if a match is found but it's already
been used,
the function returns -1

    Return: int
*/
    int findUnusedLetterInRealWord(char guessChar);


  /* This function takes the guessWordLetterUsage array in parameters and if the position is correct, color letter of the guess green. If the position is wrong but the letter is correct, color the letter yellow, if the letter is not used, don't color the letter. It adds the new colord guess to the guesses vector.

  Return: none
*/
    void colorWord(int guessUsage[5]); 


   /* This function prints the colored guesses stored in the vector guesses.

  Return: none */
    void printGuess();


    /*This function resets solutionWordLetterUsage all to false and resets guessWordLetterUsage all to letterNotUsed.

  Return: none*/
    void resetArrays();

};

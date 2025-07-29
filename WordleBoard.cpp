/*Christina Vanderwerf
CS360
This program takes a five letter word from user input and compares it to a randomly selected five letter word to see if they match. If a letter is green, the letter is correct and in the correct spot. If a letter is yellow, the letter is correct but in the wrong spot in the word.*/

#include "WordleBoard.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;



/*This is the default constructor of the WordleBoard class. It takes no parameters. solution and guess strings will be empty.

    Reurn: none */
WordleBoard::WordleBoard(){
  solution = "";
  guess = "";
}


/*This is the constructor of the WordleBoard class. It takes a string and sets that as the solution and takes another string and sets that as the guess.

    s - solution
    g - guess

    Return: none */
WordleBoard::WordleBoard(string s, string g){
  solution = s;
  guess = g;
  
}


/*This function takes a string in the parameters and sets the guess variable to that string.

    g - guess

    Return: none*/
void WordleBoard::setGuess(string g){
  guess = g;
}


/*This function takes a string in the parameteres and sets the solution variable to that string.

    s - solution

    Return: none */
void WordleBoard::setSolution(string s){
  solution = s;
}


/*This function first resets guessWordLetterUsage and solutionWordLetterUsage using the resetArrays() function. It then compares the guess word and solution word to see if any letters match. If they do then solutionWordLetterUsage[index] is set to true and guessWordLetterUsage[index] is set to rightLetterRightPos. It uses fundUnusedLetterInRealWorld(letter) function to see if the letter in guess is used in the solution. Once the arrays are correct, it calls the colorWord function.

    Return: none */
void WordleBoard::compareSolutionAndGuess(){
    resetArrays();
    for (int i = 0; i < guess.length(); i++){
      //if the letter in guess is the same as solution the letter is in the right spot.
      if (guess[i] == solution[i]){
        solutionWordLetterUsage[i] = true;
        guessWordLetterUsage[i] = rightLetterRightPos;
        }
      }

  
     for (int j = 0; j < guess.length(); j++){
       //check if letter is used
        int unused = findUnusedLetterInRealWord(guess[j]);
       
        int notUsedIndex = 0;

        //if letter is used
        if (unused != -1){
          solutionWordLetterUsage[unused] = true;
          for(int i = 0; i < guess.length(); i++){
            if (guessWordLetterUsage[i] == 1 && solutionWordLetterUsage[i] == true){
             continue;
             }

            //check if the used letter in solution matches a letter in the guess
            if (guess[i] == solution[unused]){
             guessWordLetterUsage[i] = rightLetterWrongPos;
             solutionWordLetterUsage[i] = false;
             solutionWordLetterUsage[unused] = true;
            }
           }
          }


       //if letter is unused and is not a rightLetterWrongPos letter (we don't want duplicates) then letter is not used again
       if (unused == -1 && guessWordLetterUsage[j] != rightLetterRightPos){
         notUsedIndex = j;
         guessWordLetterUsage[notUsedIndex] = letterNotUsed;
       }
    }

  colorWord(guessWordLetterUsage);
  
}


/* This function takes a single character from guess variable 
and checks to see if there is an unused match somewhere in the real word
if so, it marks that letter in that location as used and returns that
index value

if no match is found anywhere or if a match is found but it's already
been used,
the function returns -1
*/
int WordleBoard::findUnusedLetterInRealWord(char guessChar){
    int foundUnusedAtIndex = -1;
    for(int i=0; i<solution.length(); i++){
      if(solution[i] == guessChar){
          if (solutionWordLetterUsage[i] == true)
          continue; // skip this letter as it's already been used by some other letter in the guess
    else
      {
        solutionWordLetterUsage[i] = true;
        foundUnusedAtIndex = i;
      }
    }
  }

  return foundUnusedAtIndex;
}



/* This function takes the guessWordLetterUsage array in parameters and if the position is correct, color letter of the guess green. If the position is wrong but the letter is correct, color the letter yellow, if the letter is not used, don't color the letter. It adds the new colord guess to the guesses vector.

  Return: none
*/
void WordleBoard::colorWord(int guessUsage[5]){
  coloredGuess = "";
  for (int i = 0; i < guess.length(); i++){
    if (guessUsage[i] == rightLetterRightPos){
      coloredGuess += green + guess[i] + endColor;
    }
    if (guessUsage[i] == rightLetterWrongPos){
      coloredGuess += yellow + guess[i] + endColor;
    }
    if (guessUsage[i] == letterNotUsed){
      coloredGuess += guess[i];
    }
  }
  guesses.push_back(coloredGuess);
}




/* This function prints the colored guesses stored in the vector guesses.

  Return: none */
void WordleBoard::printGuess(){
  if (guesses.size() == 1){
    cout << "1 " << guesses[0] << endl;
    cout << "2 -----" << endl;
    cout << "3 -----" << endl;
    cout << "4 -----" << endl;
    cout << "5 -----" << endl;
    cout << "6 -----" << endl;
    }

  if (guesses.size() == 2){
    cout << "1 " << guesses[0] << endl;
    cout << "2 " << guesses[1] << endl;
    cout << "3 -----" << endl;
    cout << "4 -----" << endl;
    cout << "5 -----" << endl;
    cout << "6 -----" << endl;
    }

  if (guesses.size() == 3){
    cout << "1 " << guesses[0] << endl;
    cout << "2 " << guesses[1] << endl;
    cout << "3 " << guesses[2] << endl;
    cout << "4 -----" << endl;
    cout << "5 -----" << endl;
    cout << "6 -----" << endl;
    }

  if (guesses.size() == 4){
    cout << "1 " << guesses[0] << endl;
    cout << "2 " << guesses[1] << endl;
    cout << "3 " << guesses[2] << endl;
    cout << "4 " << guesses[3] << endl;
    cout << "5 -----" << endl;
    cout << "6 -----" << endl;
    }

  if (guesses.size() == 5){
    cout << "1 " << guesses[0] << endl;
    cout << "2 " << guesses[1] << endl;
    cout << "3 " << guesses[2] << endl;
    cout << "4 " << guesses[3] << endl;
    cout << "5 " << guesses[4] << endl;
    cout << "6 -----" << endl;
    }

  if (guesses.size() == 6){
    cout << "1 " << guesses[0] << endl;
    cout << "2 " << guesses[1] << endl;
    cout << "3 " << guesses[2] << endl;
    cout << "4 " << guesses[3] << endl;
    cout << "5 " << guesses[4] << endl;
    cout << "6 " << guesses[5] << endl;
    }
  
}


/*This function resets solutionWordLetterUsage all to false and resets guessWordLetterUsage all to letterNotUsed.

  Return: none*/
void WordleBoard::resetArrays(){
  for (int i = 0; i < guess.length(); i++){
    guessWordLetterUsage[i] = letterNotUsed;
    solutionWordLetterUsage[i] = false;
  }
}

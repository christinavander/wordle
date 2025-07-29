/*Christina Vanderwerf
CS360 
This program takes a five letter word from user input and compares it to a randomly selected five letter word to see if they match. If a letter is green, the letter is correct and in the correct spot. If a letter is yellow, the letter is correct but in the wrong spot in the word.*/

#include <iostream>
#include <string>
#include <fstream> //to read from file
#include <array>
#include <algorithm> //to use binary_search()
#include <random> //to use random
#include "WordleBoard.h"
using namespace std;


int main() {
  //create an array to hold from text file
  array<string, 5758> words;
  int arraySize = sizeof(words)/sizeof(words[0]);
  bool won = false;

  //Declare ifstream variable read from file
  ifstream inFile;
  
  //Open the words text file
  inFile.open("sgb-words.txt");

  //If file not found, print cerr and exit
  if (!inFile.is_open()){
    cerr << "File not found.";
    return -1;
  }
  
  //store words from text file into an array
  string word;
  int i = 0;
  while (inFile >> word){
    words[i] = word;
    i += 1;
  }

  string guess;

  //sort the array of 5 letter words
  sort(words.begin(), words.end());
 
  //get random solution from array
  random_device random; //random device with random seed
  
  default_random_engine generator(random()); //create random number generator

  uniform_int_distribution<int> distribution(0, arraySize); //each number is equally likely to get picked from 0 - size of the array
  
  int randomNum = distribution(generator); //get the random number

  string solution = words[randomNum];
  

  int numOfGuesses = 1;
  int totalGuesses = 6;
  WordleBoard wordle;
  wordle.setSolution(solution);
  

  while (numOfGuesses <= totalGuesses && won == false){
      cout << "Enter a word: ";
      cin >> guess;
      wordle.setGuess(guess);
        
    if(guess == solution){
        wordle.compareSolutionAndGuess();
        wordle.printGuess();
        cout << "You win!" << endl;
        won = true;
        break;
      }
    else{
      while ((!binary_search(words.begin(), words.end(), guess))){
        if (guess.length() >= 6 || guess.length() <= 4){
          cout << "must be five letters" << endl;
          cout << "Enter a word: ";
          cin >> guess;
        }
        else{
        cout << "word not found" << endl;
        cout << "Enter a word: ";
        cin >> guess;
        }
      }

      wordle.setGuess(guess);
      wordle.compareSolutionAndGuess();
      wordle.printGuess();
      numOfGuesses +=1;
      won = false;
    }
  }

  if (won == false){
    wordle.printGuess();
    cout << "you lose!" << endl;
    cout << "solution was: " << solution;
  }

  inFile.close();

}

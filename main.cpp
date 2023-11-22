#include <iostream> 
#include <cstdlib> //rand srand
#include <ctime> //needed for current time 
#include <limits> //needed for numeric_limits

// generateRandomNumber function is created to generate the random number, making the code more modular and easier to maintain.
int generateRandomNumber() {
  srand(time(0));
  return rand() % 10 + 1;
}
// getUserGuess function is created to validate the user's input and prompt the user for input until they enter a valid integer.
int getUserGuess() {
  int guess;
  while(!(std::cin >> guess)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer between 1 and 10: ";
  }
  return guess;
}

void Play() {
   std::cout << "Guess a number between 1 and 10: " << std::endl;

   int randomNumber = generateRandomNumber();

   int maxGuesses = 4;      
   int numGuesses = 0;
   
   while(numGuesses < maxGuesses) {
   int guess = getUserGuess();
   numGuesses++;

   if(guess == randomNumber) {
       std::cout << "Congratulations! You guessed the number in " << numGuesses << " attempts.\n" << std::endl;
       break;
   } else if(guess < randomNumber) {
       std::cout << "Too low! Try again.\n";
   } else {
       std::cout << "Too high! Try again.\n";
   }
}
    if(numGuesses == maxGuesses) {
    std::cout << "Sorry, you didn't guess the number. The number was " << randomNumber << ".\n" << std::endl;
    std::cout << "You guessed " << numGuesses << " times. \n" << std::endl;
    }
}

int main() {
   char playAgain;
   do {
       Play();
       std::cout << "Do you want to play again? (Y/N): ";
       std::cin >> playAgain;
   } while (playAgain == 'Y' || playAgain == 'y');

   return 0;
}

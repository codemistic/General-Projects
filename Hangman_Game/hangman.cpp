#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string &);

int main()
{
    string name;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;
    string words[] =
        {
            "india",
            "pakistan",
            "nepal",
            "malaysia",
            "philippines",
            "australia",
            "iran",
            "ethiopia",
            "oman",
            "indonesia"};

    srand(time(NULL));
    int n = rand() % 10;
    word = words[n];

    string unknown(word.length(), '*');

    // welcome the user
    cout << "\n\nWelcome to hangman...Guess a country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n";

    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << "\n\n"
             << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl
                 << "Whoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << endl
                 << "You found a letter! Isn't that exciting!" << endl;
        }

        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;

        if (word == unknown)
        {
            cout << word << endl;
            cout << "Yeah! You got it!";
            break;
        }
    }
    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        cout << "The word was : " << word << endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}

int letterFill(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {

        if (guess == guessword[i])
            return 0;

        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

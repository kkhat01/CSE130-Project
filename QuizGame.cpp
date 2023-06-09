#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
    const int Num_Questions = 15; // number of questions
    float prizeList[Num_Questions] = { 500, 500, 1000, 1000, 2000, 2500, 2500, 5000, 10000, 25000, 25000, 75000, 100000, 250000, 500000 }; // list of prize money
    int prize = 0; // current prize
    char answer; // user's answer
    char correctAnswer; // correct answer
    string user_lifeline = "";
    bool is_correct = false; // check for whether user's answer is correct
    bool use_fifty_fifty = false;
    bool use_phone_a_friend = false;
    bool use_ask_aud = false;

    // set up questions and answers
    string questions[Num_Questions] = {
        "Which of the following is not a primary color?",
        "What letter is in the name of every odd number?",
        "Who painted the Mona Lisa?",
        "Which Shakespearean play feautures the character of Lady Macbeth?",
        "What is the name of the closest planet to the sun in our solar system?",
        "What is the largest organ in the human body?",
        "Which country gifted the Statue of Liberty to the United States?",
        "In what year did the first man walk on the moon?",
        "Which of the following is not a type of cloud?",
        "What president was in office during the Cuban Missile Crisis?",
        "Who is the author of To Kill a Mockingbird?",
        "What is the capital of Canada?",
        "Who was the first person to win a Nobel Prize twice?",
        "Who is the creator of the TV show The Simpsons?",
        "Who is the current Prime Minister of Australia?"
    };

    string answers[Num_Questions][4] = {
        {"A. Red", "B. Green", "C. Blue", "D. Yellow"},
        {"A. e", "B. n", "C. t", "D. v"},
        {"A. Frida Kahlo", "B. Leonardo da Vinci", "C. Vincent van Gogh", "D. Andy Warhol"},
        {"A. Macbeth", "B. Hamlet", "C. A Midsummer Night's Dream", "D. Romeo and Juliet"},
        {"A. Earth", "B. Venus", "C. Neptune", "D. Mercury"},
        {"A. Lungs", "B. Brain", "C. Heart", "D. Skin"},
        {"A. France", "B. China", "C. Mexico", "D. Hungary"},
        {"A. 1965", "B. 1969", "C. 1975", "D. 1979"},
        {"A. Cumulus", "B. Cirrus", "C. Nibbus", "D. Stratus"},
        {"A. William McKinley", "B. Lyndon B. Johnson", "C. Bill Clinton", "D. John F. Kennedy"},
        {"A. Harper Lee", "B. Charles Dickens", "C. J.R.R. Tolkien", "D. Emily Dickinson"},
        {"A. Toronto", "B. Montreal", "C. Ottawa", "D. Vancouver"},
        {"A. Marie Curie", "B. Albert Einstein", "C. Ada Lovelace", "D. Nikola Tesla"},
        {"A. Shonda Rhimes", "B. Matt Groening", "C. Neil Druckman", "D. Denzel Washington"},
        {"A. Anthony Albanese", "B. Katherine Johnson", "C. Justin Trudeau", "D. Elizabeth Warren"}
    };

    string fifty_fifty_ans[Num_Questions][4] = {
        {"B. Green", "D. Yellow"},
        {"A. e", "C. t"},
        {"B. Leonardo da Vinci", "C. Vincent van Gogh"},
        {"A. Macbeth", "D. Romeo and Juliet"},
        {"B. Venus", "D. Mercury"},
        {"A. Lungs", "D. Skin"},
        {"A. France", "C. Mexico"},
        {"A. 1965", "B. 1969"},
        {"C. Nibbus", "D. Stratus"},
        {"A. William McKinley", "D. John F. Kennedy"},
        {"A. Harper Lee", "C. J.R.R. Tolkien"},
        {"B. Montreal", "C. Ottawa"},
        {"A. Marie Curie", "C. Ada Lovelace"},
        {"B. Matt Groening", "C. Neil Druckman"},
        {"A. Anthony Albanese", "B. Katherine Johnson"}
    };

    char correctAnswers[Num_Questions] = { 'B', 'A', 'B', 'A', 'D','D', 'A', 'B', 'C','D', 'A', 'C', 'A', 'B', 'A' };

    // welcome message
    cout << "Welcome to Who Wants to Be a Millionaire?" << endl;
    cout << "You will be asked " << Num_Questions << " questions." << endl;
    cout << "For each correct answer, you will win the prize money associated with the question." << endl;
    cout << "You have three lifelines, fifty-fifty, phone-a-friend, and ask-the-audience which you can use once each." << endl;
    cout << "You have 30 seconds to answer the questions." << endl;
    cout << "If you answer a question wrong it is game over." << endl;
    cout << "If you answer all " << Num_Questions << " questions correctly, you will win $1,000,000." << endl;
    cout << "Good luck!" << endl;
    cout << "Press [Enter] To Play!" << endl;
    cin.get();

    // ask questions
    for (int i = 0; i < Num_Questions; i++) {
        // display question and choices
        cout << endl << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << answers[i][j] << endl;
        }

        // Asking the user if they want to use lifeline
        cout << "\nEnter [fifty-fifty] or [phone-a-friend] or [ask-the-audience] to use lifeline or press [enter] to continue: " << endl;

        int lifeline_wait_sec = 15; // number of seconds to wait for user input.
        while (lifeline_wait_sec > 0 && !_kbhit()) {
            cout << lifeline_wait_sec-- << "... ";
            Sleep(1000); // sleep for 1 second.
        }
        if (_kbhit()) {
            getline(cin, user_lifeline);
            if (user_lifeline == "fifty-fifty" && use_fifty_fifty == false) {
                use_fifty_fifty = true;
                for (int j = 0; j < 2; j++) {
                    cout << fifty_fifty_ans[i][j] << endl;
                }
            }

            else if (user_lifeline == "phone-a-friend" && use_phone_a_friend == false) {
                use_phone_a_friend = true;
                cout << "Your friend thinks the answer is: " << correctAnswers[i] << endl;
                for (int j = 0; j < 4; j++) {
                    cout << answers[i][j] << endl;
                }
            }

            else if (user_lifeline == "ask-the-audience" && use_ask_aud == false) {
                use_ask_aud = true;
                int aud_wait_sec = 30; // number of seconds to wait for user input.
                cout << "Talk with your team members" << endl;
                while (aud_wait_sec > 0 && !_kbhit()) {
                    cout << aud_wait_sec-- << "... ";
                    Sleep(1000); // sleep for 1 second.
                }
                if (_kbhit()) {
                    answer = _getch();
                }
                else {
                    cout << "\nTime to answer the question." << endl;
                }
            }

            else if (user_lifeline == "fifty-fifty" && use_fifty_fifty == true) {
                cout << "You are out of the fifty-fifty lifeline" << endl;
            }

            else if (user_lifeline == "phone-a-friend" && use_phone_a_friend == true) {
                cout << "You are out of the phone a friend lifeline" << endl;
            }

            else if (user_lifeline == "ask-the-audience" && use_phone_a_friend == true) {
                cout << "You are out of the ask the audience lifeline" << endl;
            }

            else {
                cout << "\nHere we go!" << endl;
            }
        }

        else {
            cout << "\nTime to answer the question." << endl;
        }

        cout << "\nEnter your answer [A, B, C, D]: " << endl;
        correctAnswer = correctAnswers[i];

        int waitSeconds = 30; // number of seconds to wait for user input.
        while (waitSeconds > 0 && !_kbhit()) {
            cout << waitSeconds-- << "... ";
            Sleep(1000); // sleep for 1 second.
        }
        if (_kbhit()) {
            answer = _getch();
        }
        else {
            cout << "\nTimes Up! The correct answer is: " << answers[i][correctAnswer - 'A'] << "." << endl;
            cout << "Here is your final prize $" << prize << "." << endl;
            is_correct = false;
            exit(0); // end the program.
        }

        // check if answer is correct
        if (toupper(answer) == correctAnswer) {
            cout << "Correct! You win $" << prizeList[i] << "." << endl;
            prize = prize + prizeList[i];
            is_correct = true;
        }
        else {
            cout << "Incorrect. The correct answer is: " << answers[i][correctAnswer - 'A'] << "." << endl;
            cout << "Here is your final prize $" << prize << "." << endl;
            is_correct = false;
            exit(0);
        }

        // check if user has won the game
        if (is_correct && i == Num_Questions - 1) {
            cout << "\nCongratulations!  You have won the game and $" << prize << "!" << endl;
        };
    }
}
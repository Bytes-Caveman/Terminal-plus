<<<<<<< HEAD
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>


using namespace std;

int main()
{
    cout << "Advanced Terminal: Running" << endl ;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //command handler
    string commandDir = "./Commands/";
    char inputCommand[1024];
    string fullCommand;
    string command;
    string commandArguments[32];

    while (true)
    {
        cout << endl << "> " ;
        cin.getline(inputCommand, 1024);
        fullCommand = inputCommand;

        command = fullCommand.substr(0, fullCommand.find(" "));
        cout << "Command: " << command << " Full Command: " << fullCommand << endl ;

        //look for command
        try {
            string dir = commandDir + command + ".h" ;
            ifstream file(dir);

            if (!file.is_open()) {
                throw(404);
            } else {
                file.close();
                throw(200);
            }
        } catch (int exitCode) {
            if (exitCode == 200) {
                //was found
                int iterations = 0;
                int lengthOfCommand = count(fullCommand.begin(), fullCommand.end(), ' ') + 1;
                
                while (iterations < lengthOfCommand) {
                    commandArguments[iterations] = fullCommand.substr(0, fullCommand.find(" "));
                    fullCommand = fullCommand.substr(fullCommand.find(" ") + 1, fullCommand.length());
                    iterations += 1;
                }
            }
            else if (exitCode == 404) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << endl << "[Error] Command " + command + " was not found" ;
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
    }

    return 0;
}
=======
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>


using namespace std;

int main()
{
    cout << "Advanced Terminal: Running" << endl ;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //command handler
    string commandDir = "./Commands/";
    char inputCommand[1024];
    string fullCommand;
    string command;
    string commandArguments[32];

    while (true)
    {
        cout << endl << "> " ;
        cin.getline(inputCommand, 1024);
        fullCommand = inputCommand;

        command = fullCommand.substr(0, fullCommand.find(" "));
        cout << "Command: " << command << " Full Command: " << fullCommand << endl ;

        //look for command
        try {
            string dir = commandDir + command + ".h" ;
            ifstream file(dir);

            if (!file.is_open()) {
                throw(404);
            } else {
                file.close();
                throw(200);
            }
        } catch (int exitCode) {
            if (exitCode == 200) {
                //was found
                int iterations = 0;
                int lengthOfCommand = count(fullCommand.begin(), fullCommand.end(), ' ') + 1;

                while (iterations < lengthOfCommand) {
                    commandArguments[iterations] = fullCommand.substr(0, fullCommand.find(" "));
                    fullCommand = fullCommand.substr(fullCommand.find(" ") + 1, fullCommand.length());
                    iterations += 1;
                }
            }
            else if (exitCode == 404) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "[Error] Command " + command + " was not found" ;
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
    }

    return 0;
}
>>>>>>> e745d30 (First Commit)

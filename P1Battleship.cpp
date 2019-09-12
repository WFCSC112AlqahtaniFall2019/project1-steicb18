#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //Create 3 vectors that each represent a row of the grid.
    vector<string> row1(3, " ");
    vector<string> row2(3, " ");
    vector<string> row3(3, " ");

    //Output each row to form blank grid
    for (int i = 0; i < row1.size(); i++) {
        cout << row1.at(i);
        if (i < row1.size() - 1) {
            cout << "!";
        }
    }
    cout << endl << "~~~~~" << endl;
    for (int i = 0; i < row1.size(); i++) {
        cout << row2.at(i);
        if (i < row2.size() - 1) {
            cout << "!";
        }
    }
    cout << endl << "~~~~~" << endl;
    for (int i = 0; i < row1.size(); i++) {
        cout << row3.at(i);
        if (i < row3.size() - 1) {
            cout << "!";
        }
    }
    cout << endl << "~~~~~" << endl;


    //Initialize random values that will determine "hit" coordinates.
    srand(time(0));
    int randRow = (rand() % 3) + 1;
    int randCol = (rand() % 3) + 1;

    string status = "MISS";
    //Initialization of input variables.
    int entRow;
    int entCol;
    int attemptNum = 0;

    /*While loop that executes "miss" vector update and print procedure until both
     the entered col and row match their random counterparts(boolean is changed to true).*/
    bool guess = false;
    while (guess == false) {
        cout << "Enter Coordinates (row column): " << endl;
        cin >> entRow;
        cin >> entCol;
        if (entRow == randRow && entCol == randCol) {
            if (entRow == 1) {
                row1.at(entCol - 1) = "X";
            } else if (entRow == 2) {
                row2.at(entCol - 1) = "X";

            } else {
                row3.at(entCol - 1) = "X";
            }
            status = "HIT";
            guess = true;
        } else {
            if (entRow == 1) {
                row1.at(entCol - 1) = "O";
            } else if (entRow == 2) {
                row2.at(entCol - 1) = "O";

            } else {
                row3.at(entCol - 1) = "O";
            }
        }

        attemptNum++;
        for (int i = 0; i < row1.size(); i++) {
            cout << row1.at(i);
            if (i < row1.size() - 1) {
                cout << "!";
            }
        }
        cout << endl << "~~~~~" << endl;
        for (int i = 0; i < row1.size(); i++) {
            cout << row2.at(i);
            if (i < row2.size() - 1) {
                cout << "!";
            }
        }
        cout << endl << "~~~~~" << endl;
        for (int i = 0; i < row1.size(); i++) {
            cout << row3.at(i);
            if (i < row3.size() - 1) {
                cout << "!";
            }
        }
        cout << endl << "~~~~~" << endl;
        cout << "ATTEMPT #: " << attemptNum << " ---> " << status << endl;
    }

    return 0;
}
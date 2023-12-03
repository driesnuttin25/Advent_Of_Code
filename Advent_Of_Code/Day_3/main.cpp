#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#define HEIGHT 142
#define WIDTH 143

using namespace std;

bool isSpecialChar(char ch) {
    return ch == '*' || ch == '+' || ch == '=' || ch == '/' ||
           ch == '#' || ch == '@' || ch == '&' || ch == '$' ||
           ch == '%' || ch == '-';
}

int main() {
    ifstream file("C:\\Users\\dries\\OneDrive\\Desktop\\Cpp\\Advent_Of_Code\\file.txt");
    string line;
    string array[HEIGHT][WIDTH];

    // Initialize boundary cells
    for (int i = 0; i < WIDTH; i++) {
        array[0][i] = ".";
        array[HEIGHT - 1][i] = ".";
    }
    for (int j = 0; j < HEIGHT; j++) {
        array[j][0] = ".";
        array[j][WIDTH - 1] = ".";
    }

    int total = 0;

    if (file.is_open()) {
        int j = 1; // Start from 1 to respect boundary
        while (getline(file, line)) {
            if (j >= HEIGHT - 1) {
                cout << "Warning: File has more lines than array height." << endl;
                break;
            }
            if (line.length() > WIDTH - 2) {
                cout << "Warning: Line length exceeds array width." << endl;
                break;
            }
            for(int i = 1; i <= line.length(); i++) {
                array[j][i] = line[i - 1];
            }
            j++;
        }
        file.close();
        cout << "File reading completed." << endl;

        // Process the array
        for(int j = 1; j < HEIGHT - 1; j++){
            for(int i = 1; i < WIDTH - 1; i++) {
                if (isdigit(array[j][i][0]) && (i == 1 || !isdigit(array[j][i-1][0]))) {
                    string number = "";
                    int k = i;
                    while (k < WIDTH - 1 && isdigit(array[j][k][0])) {
                        number += array[j][k];
                        k++;
                    }

                    bool valid = false;
                    // Check surrounding cells for special characters
                    for (int x = i; x < k; x++) {
                        // Check eight surrounding cells of each digit
                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                if (dx == 0 && dy == 0) continue; // Skip the cell itself
                                if (isSpecialChar(array[j + dy][x + dx][0])) {
                                    valid = true;
                                }
                            }
                        }
                    }

                    if (valid) {
                        int num = stoi(number);
                        total += num;
                        cout << "Valid number found: " << num << ", Total: " << total << endl;
                    }

                    i = k - 1; // Skip to the end of the current number
                }
            }
        }
        cout << "Total: " << total << endl;
    } else {
        cerr << "Unable to open file" << endl;
    }

    // Print final array state for verification
    cout << "Final array state:" << endl;
    for(int j = 0; j < HEIGHT; j++){
        for(int i = 0; i < WIDTH; i++){
            cout << array[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}

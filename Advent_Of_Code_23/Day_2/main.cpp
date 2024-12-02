#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <sstream>

using namespace std;
int main() {
    ifstream file("C:\\Users\\dries\\OneDrive\\Desktop\\Cpp\\Advent_Of_Code\\file.txt");
    string line;
    string part;
    string token;
    string amount;
    string amountdouble;
    int correct = 0;
    int power = 0;
    int maxblue = 0;
    int maxgreen = 0;
    int maxred = 0;
    int amountint = 0;
    int blue =14;
    int red = 12;
    int green = 13;
    int i =  0;
    int id = 1;
    int total = 0;
    int impossible = 0;


    if (file.is_open()) {
        while (getline(file, line)) {
            cout << endl <<  "Processing line: " << line << endl;
            //Game Logic
            cout << "The Game ID is: " << id << endl;

            while(i < line.size()){
                if(line[i] == 'b'){
                    if(isspace(line[i-3])){
                        amount = line[i-2];
                        amountint = stoi(amount);
                    }
                    else{
                        amount = line[i-3];
                        amountdouble = line[i-2];
                        amount = amount + amountdouble;
                        amountint = stoi(amount);
                    }
                    cout << "Blue amount: " << amountint << endl;
                }
                if(amountint > blue){
                    cout << "IMPOSSIBLE BECAUSE BLUE = " << amountint << endl;
                    impossible = 1;
                }
                if(amountint > maxblue){
                    maxblue = amountint;
                }
                amountint = 0;
                i++;
            }
            i = 0;
            while(i < line.length()){
                if(line[i] == 'r'){
                    if(line[i-1] != 'g'){
                        if(isspace(line[i-3])){
                            amount = line[i-2];
                            amountint = stoi(amount);
                        }
                        else{
                            amount = line[i-3];
                            amountdouble = line[i-2];
                            amount = amount + amountdouble;
                            amountint = stoi(amount);
                        }
                        cout << "Red amount: " << amountint << endl;
                    }
                }
                if(amountint > red){
                    cout << "IMPOSSIBLE BECAUSE RED = " << amountint << endl;
                    impossible = 1;
                }
                if(amountint > maxred){
                    maxred = amountint;
                }
                amountint = 0;
                i++;
            }
            i = 0;
            while(i < line.length()){
                if(line[i] == 'g'){
                    if(isspace(line[i-3])){
                        amount = line[i-2];
                        amountint = stoi(amount);
                    }
                    else{
                        amount = line[i-3];
                        amountdouble = line[i-2];
                        amount = amount + amountdouble;
                        amountint = stoi(amount);
                    }
                    cout << "Green amount: " << amountint << endl;
                }
                if(amountint > green){
                    cout << "IMPOSSIBLE BECAUSE GREEN = " << amountint << endl;
                    impossible = 1;
                }
                if(amountint > maxgreen){
                    maxgreen = amountint;
                }
                amountint = 0;
                i++;
            }
            i = 0;

            if(impossible == 0){
                total += id;
                cout << "POSSIBLE" << endl;
                cout << "Total = " << total << endl;
                correct +=1;
                cout <<"Total correct: " << correct << endl;
            }
            else{
                cout << "Game is impossible" << endl;
            }
            power += (maxblue * maxgreen * maxred);
            cout << "max blue: " << maxblue << endl;
            cout << "max red: " << maxred << endl;
            cout << "max green: " << maxgreen << endl;

            cout << "Power = " << (maxblue * maxgreen * maxred) << endl;
            cout << "Total power = " << power << endl;
            maxblue = 0;
            maxred = 0;
            maxgreen = 0;
            id += 1;
            impossible = 0;

        }
        cout << "TOTAL SCORE IS: " << total << endl;
        cout << "TOTAL POWER IS: " << power << endl;
        file.close();
    }

    //Error Case
    else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}

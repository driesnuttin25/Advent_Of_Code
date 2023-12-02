#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {
    std::ifstream file("C:\\Users\\dries\\OneDrive\\Desktop\\Cpp\\Advent_Of_Code\\file.txt");
    std::string line;
    std::string reverse;
    std::string num1;
    std::string num2;
    int i = 0;
    int num = 0;
    int total = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << "Processing line: " << line << std::endl;
            while(i < line.length()){

                if (isdigit(line[i])){
                    num1 = line[i];
                    i = 0;
                    std::cout << "First number: " << num1 << std::endl;
                    break;
                }


                else if (line[i] == 'o'){
                    if(line.substr(i,3) == "one"){
                        num1 = "1";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                }
                else if(line[i] == 't'){
                    if(line.substr(i,3) == "two"){
                        num1 = "2";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                    else if(line.substr(i,5) == "three"){
                        num1 = "3";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }

                }
                else if (line[i] == 's') {
                    if (line.substr(i, 3) == "six") {
                        num1 = "6";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                    else if (line.substr(i, 5) == "seven") {
                        num1 = "7";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'f') {
                    if (line.substr(i, 4) == "four") {
                        num1 = "4";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                    else if (line.substr(i, 4) == "five") {
                        num1 = "5";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'e') {
                    if (line.substr(i, 5) == "eight") {
                        num1 = "8";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'n') {
                    if (line.substr(i, 4) == "nine") {
                        num1 = "9";
                        i = 0;
                        std::cout << "First number: " << num1 << std::endl;
                        break;
                    }
                }


                i++;
            }
            std::reverse(line.begin(), line.end());

            i = 0;
            //std::cout << "Processing reverse line: " << line << std::endl;

            while (i < line.length()) {
                //std::cout << line[i] << std::endl;
                if (isdigit(line[i])) {
                    num2 = line[i];
                    i = 0;
                    std::cout << "Second number: " << num2 << std::endl;
                    break;
                } else if (isspace(line[i])) {
                    break;
                }

                else if (line[i] == 't') {
                     if (line.substr(i, 5) == "thgie") {
                        num2 = "8";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'r') {
                     if (line.substr(i, 4) == "ruof") {
                        num2 = "4";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'o') {
                    if (line.substr(i, 3) == "owt") {
                        num2 = "2";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'x') {
                    if (line.substr(i, 3) == "xis") {
                        num2 = "6";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'n') {
                    if (line.substr(i, 5) == "neves") { // Check for 'seven' reversed
                        num2 = "7";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }
                else if (line[i] == 'e') {
                    if (line.substr(i, 3) == "eno") {
                        num2 = "1";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                    else if (line.substr(i, 5) == "eerht") {
                        num2 = "3";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                    else if (line.substr(i, 4) == "evif") {
                        num2 = "5";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                    else if (line.substr(i, 4) == "enin") {
                        num2 = "9";
                        i = 0;
                        std::cout << "Second number: " << num2 << std::endl;
                        break;
                    }
                }

                i++;
            }
            num1 = num1+num2;
            std::cout << "Combined = " << num1 << std::endl << std::endl;
            num = stoi(num1);
            total += num;
        }
        file.close();
        std::cout << std::endl << "The Grand Total is: " << total << std::endl;
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return 0;
}

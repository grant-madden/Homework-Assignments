/**
 *   @file: cc-balance.cc
 * @author: Grant Madden
 *   @date: 10/7
 *  @brief: this program sorts credit card data from a file and outputs certain items to a new file based on user input. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

//Asks user for their zipcode
string getFinalDigitCode(int programCounter);

string getDigitCode(char digit);
int getCheckDigitValue(int sum);
string getCheckDigitCode(int checkDigitValue);
void printFinalBarcode(string digitCode);
bool moreCodes();

void runProgram(int programCounter);

int main(){
    bool exit;
    int runCounter = 0;
    runProgram(runCounter);
    exit = moreCodes();
    while (exit == true){
        runCounter++;
        runProgram(runCounter);
        exit = moreCodes();
    }
    return 0;
}
//Runs entire program and resets variables to uninitialized
void runProgram(int programCounter){
    int num;

    string zipcode;
    string finalDigitCode = "";
    string checkDigitCode = "";
    
    //Asks user for their zipcode
    finalDigitCode = getFinalDigitCode(programCounter);
    // Print final code
    printFinalBarcode(finalDigitCode);

    return;
}
//Asks user for their zipcode
string getFinalDigitCode(int programCounter){
    char zipcode;
    string digitCode;
    string checkDigitCode;

    int zipcodeCharCounter = 0;
    int sum = 0;
    int checkDigitValue;

    cout << "Enter a zipcode: " << endl;

    do{
        //Get Zipcode from user
        cin.get(zipcode);
        //Count number of char in zipcode
        zipcodeCharCounter++;
        
            if (zipcodeCharCounter <= 5){
                //Convert input to type int, and add it to sum
                sum = (zipcode - '0') + sum;
                if (sum < 0){
                    sum = 0;
                }
            }
        //Convert int to digitCode (Ex: "5" to ":|:|:"), and add it to current digitCode
        digitCode = digitCode + getDigitCode(zipcode);

        //Check for invalid Characters
        if (zipcode >= 'A' && zipcode <= 'Z' && zipcode >= 'a' && zipcode <= 'z'){
            cout << "Error, character not specified.";  
            cin.clear();
            zipcodeCharCounter = 0;
            zipcode = 'a';
            sum = 0;
            digitCode = ""; 
        }
        //Check for zipcodes that are too short in length
        else if (zipcodeCharCounter < 5 && zipcode == '\n'){
            
            //This if statement fixes a bug where the error message is always displayed when the user has previously converted a zip code
            if (programCounter > 0){
                
                zipcodeCharCounter = 0;
                zipcode = 'a';
                sum = 0;
                digitCode = "";
                programCounter = 0;
            }
            else {
                cout << "Error, not enough digits. Enter a zipcode: "; 
                zipcodeCharCounter = 0;
                zipcode = 'a';
                sum = 0;
                digitCode = ""; 
            }
                  
        }
        //Check for zipcodes that are too long in length
        else if (zipcodeCharCounter > 6 && zipcode == '\n' ){
            cout << "Error, too many digits. Enter a zipcode: " << endl;
            
            zipcodeCharCounter = 0;
            zipcode = 'a';
            sum = 0;
            digitCode = "";
        }
    } while (zipcode != '\n');


        checkDigitValue = getCheckDigitValue(sum);
        checkDigitCode = getCheckDigitCode(checkDigitValue);
        digitCode = digitCode + checkDigitCode;
         
    return digitCode; 
}

string getDigitCode(char digit) {
    string middleOfBarcode;
    digit = digit - '0';
    switch (digit){
        case 1:
            middleOfBarcode = middleOfBarcode + ":::||";
            break;
        case 2:
            middleOfBarcode = middleOfBarcode + "::|:|";
            break;
        case 3:
            middleOfBarcode = middleOfBarcode + "::||:";
            break;
        case 4:
            middleOfBarcode = middleOfBarcode + ":|::|";
            break;
        case 5:
            middleOfBarcode = middleOfBarcode + ":|:|:";
            break;
        case 6:
            middleOfBarcode = middleOfBarcode + ":||::";
            break;
        case 7:
            middleOfBarcode = middleOfBarcode + "|:::|";
            break;
        case 8:
            middleOfBarcode = middleOfBarcode + "|::|:";
            break;
        case 9:
            middleOfBarcode = middleOfBarcode + "|:|::";
            break;
        case 0:
            middleOfBarcode = middleOfBarcode + "||:::";
            break;

        
    }
    return middleOfBarcode;
}

int getCheckDigitValue(int sum){
    int checkDigitValue = 10 - (sum % 10);
    if (checkDigitValue == 10){
        checkDigitValue = 0;
    }
    return checkDigitValue;
}
string getCheckDigitCode(int checkDigitValue){
    string endOfBarcode;

    switch (checkDigitValue){
        case 1:
            endOfBarcode = endOfBarcode + ":::||";
            break;
        case 2:
            endOfBarcode = endOfBarcode + "::|:|";
            break;
        case 3:
            endOfBarcode = endOfBarcode + "::||:";
            break;
        case 4:
            endOfBarcode = endOfBarcode + ":|::|";
            break;
        case 5:
            endOfBarcode = endOfBarcode + ":|:|:";
            break;
        case 6:
            endOfBarcode = endOfBarcode + ":||::";
            break;
        case 7:
            endOfBarcode = endOfBarcode + "|:::|";
            break;
        case 8:
            endOfBarcode = endOfBarcode + "|::|:";
            break;
        case 9:
            endOfBarcode = endOfBarcode + "|:|::";
            break;
        case 0:
            endOfBarcode = endOfBarcode + "||:::";
            break;
        
    }
    return endOfBarcode;
}
//Prints final barcode to user screen
void printFinalBarcode(string digitCode){
    cout << "|" << digitCode << "|" << endl;
}
bool moreCodes(){
    char yesOrNo;

    cout << "More codes? (y/n): ";
    cin >> yesOrNo;
    
    do{
        if ((yesOrNo == 'Y') || (yesOrNo == 'y')){
            
           return true;
        }
        else if ((yesOrNo == 'n') || (yesOrNo == 'N')){
            return false;
        }
        else {
            cout << "Error, invalid input. More codes? (y/n): ";
            cin >> yesOrNo;
        }
    } while (true);
}
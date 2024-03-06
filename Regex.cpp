// This file is an example of a common regular expression interview problem
// Program checks validity of string, it is valid if string is a sequence of 
// either the value '2' or '212' 

#include <iostream>
#include <string>
#include <limits>


using namespace std;

bool isValidString(const string& str){

    for(size_t i = 0; i < str.size();){
        if (str.substr(i,3) == "212"){
            cout << "Matched '212' at index " << i << endl;
            i+=3;
        }
        else if (str[i] == '2') {
             cout << "Matched '2' at index " << i << endl;
            i++;
        }
        else {
            cout << "Invalid character '" << str[i] << "' at index " << i << endl;
            return false;
        }
    }
    return true; 

}

int main() {

    string input;
    cout << "enter a string: ";
    getline(cin, input);

    if(isValidString(input)){
        cout << "The following string: " << input << " is a valid string" << endl;
    }
    else {
        cout << "The following string: " << input << " is an invalid string" << endl;
    }
    
    return 0;
}


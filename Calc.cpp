#include <iostream>

using namespace std;

int main(){
    char operation;
    float num1, num2;

    cout << "enter the operation you wish to perform (+,-,*,/):+ ";
    cout << endl;
    cin >> operation;

    cout << "enter two numbers: ";
    cin >> num1 >> num2;
    
    switch (operation)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;
    case '-': 
        cout << num1 << " - " << num2 << " = " << num1 - num2;
        break;
    case '*': 
        cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;
    case '/': 
        if(num2 != 0)
            cout << num1 << " * " << num2 << " = " << num1 * num2;
        else
            cout << "Error! you cannot divide by 0";
        break;    
    default:
        cout << "invalid operator given";
        break;
    }

    return 0; 

}
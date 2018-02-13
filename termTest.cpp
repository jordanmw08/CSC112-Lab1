#include "termmanip.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    cout << clearScreen << cursorPosition(1,1);
    
    // general mode test
    cout << normal << "Normal" << endl;
    cout << underline << "Underline" << normal << endl;
    cout << bold << "Bold" << normal << endl;
    cout << blink << "Blink" << normal << endl;
    cout << reverseVideo << "Reverse" << normal << endl;
    cout << black << "Black" << endl;
    cout << red << "Red" << endl;
    cout << green << "Green" << endl;
    cout << yellow << "Yellow" << endl;
    cout << blue << "Blue" << endl; 
    cout << magenta << "Magenta" << endl;
    cout << cyan << "Cyan" << endl;
    cout << white << "White" << endl;
    
    //stack test
    cout << bold << yellow << magentaBackground << "Hello, blinded world!"
        << normal << endl;
    
    //cursor movement test
    cout << saveCursor << cursorPosition(10, 7) << "Hello";
    cout << cursorDown(2) << cursorForward(1) << "World";
    cout << restoreCursor << cursorDown(1) << normal << endl;
    
    return 0;
}
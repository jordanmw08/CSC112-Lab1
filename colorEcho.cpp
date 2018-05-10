#include <iostream>
#include <vector>
#include <string>
#include "termmanip.h"

using namespace std;

vector<string> getCommandLine(int argc, char **argv);

int main(int argc, char **argv)
{
    vector<string> args = getCommandLine(argc, argv);
    
    cout << "I received the following arguments:" << endl;
    for(auto itr=args.begin(); itr!=args.end(); itr++) {
        cout << *itr << endl;
    }
   
    //print the colorful message

        
        // set color 
        if (args[1] == "red"){
       cout << endl << endl;
       cout <<  red << args[2] << endl;
        }
        if (args[1] == "blue"){
            cout << endl << endl;
    
            cout << blue << args[2] << endl;
        }
    if (args[1] == "black"){
            cout << endl << endl;
            
            cout << black << args[2] << endl;
        }
    if (args[1] == "magenta"){
            cout << endl << endl;
           
            cout << magenta << args[2] << endl;
        }
    if (args[1] == "cyan"){
            cout << endl << endl;
            
            cout << cyan << args[2] << endl;
        }
    if (args[1] == "green"){
            cout << endl << endl;
       
            cout << green << args[2] << endl;
        }
    if (args[1] == "yellow"){
            cout << endl << endl;
      
            cout << yellow << args[2] << endl;
        }
    if (args[1] == "white"){
            cout << endl << endl;
       
            cout << white << args[2] << endl;
        }
     if (args[1] == "underline"){
            cout << endl << endl;
        
            cout << underline << args[2] << endl;
        }
     if (args[1] == "reverse"){
            cout << endl << endl;

            cout << reverseVideo << args[2] << normal << endl;
        }
    if(args[1] == "greenBackground"){
        cout << endl << endl;
        
        cout << greenBackground << args[2] << normal << endl;
    }
    
    
        if(args.size() == 2) {
        //make some room  
        cout << endl << endl;
        
        //set the color
            cout << red;
        
        //print the message
        cout << args[1] << endl;
    }
    
    }




//convert argc and argv into a vector of strings
vector<string> getCommandLine(int argc, char **argv)
{
    vector<string> result;
    
    for(int i=0; i<argc; i++) {
        result.push_back(argv[i]);
    }
    
    return result;
}
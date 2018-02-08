## Introduction

Welcome back\! When last we met, for those of you whom I did meet, we
were studying the wonderful world of computer programming. Now that you
have a little bit of programming under your belt, we can move into
writing more interesting programs, explore exciting structures, conjure
up amazing algorithms, and gain full control of our UNIX environment.

This first lab is intended to be a gentle prod to help you get back up
to speed with coding. I expect that if you haven't done any programming
in the last couple of months, you could be a little bit rusty.

In this lab, we are going to explore ANSI escape sequences, which is
what will let us do some cool things with the terminal. It is structured
to include many of the control structures presented in the previous
class. In the challenge section of the lab, you'll have an opportunity
to show me that you can still craft loops, branches, and get around in a
UNIX system.

Good luck, and enjoy\!

## Getting Started with git
The first order of business is to get set up with github, so you can
submit your assignments!  This will be a relatively painless
process. Note that these instructions are intended for Maryville
College students.  If you are some other person, then you will not be
doing the class participating things outlined here.

1. Go to github.com and sign up for a free account.
2. Verify your email address.
3. **MC Students Only** Fill in your username and password on the
shared worksheet on the classroom projector.
4. Follow the [GitHub SSH Key
Tutorial](https://help.github.com/articles/connecting-to-github-with-ssh/)
to get your account set up for ssh keys.
5. **MC Students Only** Wait to receive an invite to your private
repository for your assignment.  This will come via email.  If you are
not an MC student, you proably just want to fork the CSC112-Lab1
repository.
6. Now you need to clone your repository to your local machine.  To do
this you will use a command of this form:
`git clone git@github.com:--repo-url--`

Your repo-url will be of the form --username--/--repo--. For example,
it could be pngwen/CSC112-Lab1-pngwen if it were created by my
assignment invite script.

Congraulations!  You now have a revision controlled assignment, with a
starter file (termanip.h)!


## A (somewhat simplified) History of Telecommunications

Several thousand years ago, mankind communicated primarily by hitting
each other with things. This proved to be inefficient, and somewhat
limiting, and so we came up with grunting at each other. The grunts took
on more and more order, and then language was born. The trouble is, we
had to remember everything. So then someone else came up with the notion
of writing. At first we wrote on caves, trees, bathroom walls, and so
on. Eventually someone invented paper, followed by the printing press.
This remained the state of affairs for a very long time.

Paper was really a wonderful thing. You could communicate with people,
even over vast distances. Unlike word of mouth, paper would convey
information with high fidelity. However, one problem remained. Namely,
if you are standing at point A, and your recipient is standing at point
B, then you have to transport that paper to him. If there was more than
a few miles between you, people in between would revert to more
primitive forms of communication and hit your courier with something
large and your message would be lost.

So then, a solution had to be found. The first answer was telegraphy.
Wires would stretch the vast distances, and because wires were not human
no one had any interest in hitting them. A message was written down, and
then an operator would push a button in a rhythm which would cause the
operator at the other end to write down the message and take it to the
nearby receiving party. The trouble is, this was laborious, and mistakes
could be made.

Another attempt to solve the problem came in the form of the telephone,
which allowed people to talk over vast distances using wires. This
reverted back to the original problem, in that it depended on human
memory, and so there seemed to be no way to send an indelible message
without employing someone or getting hit over the head, and so the
problem remained.

And then came a man who had been hit and telegraphed enough to do
something about it. His name was Emile Baudot. He invented a digital
encoding scheme, where each letter would be represented by 5 1's and
0's. This, when combined with the best of late 19th century technology,
allowed a machine to send and reproduce paper documents. Because the
machine did the work, and the work took place at a distance, this was
called "teleprinting". Thus was the age of modern telecommunications
born. It wasn't until the rise of the Internet that mankind would learn
how to hit each other using the new medium. In honor of Baudot, we still
refer to the rate which we can transmit symbols as a "baud rate".

In time, the teleprinter gave rise to the teletype. By the early 1910's,
teletypes were transmitting news stories across the world as quickly as
operators could type them. Stock ticker teleprinters churned out stock
quotes as rapidly as the traders could enter them. Mankind could know
what was going on and how much everything cost at the drop of a hat, and
so more and bloodier wars were fought during this era than any other in
history.

But there remained one problem. It was easy to send a string of
characters, but what about the formatting of a document? The answer came
in the form of special characters. There were characters for line feeds,
characters for carriage returns, and characters to advance the printer
backwards and forwards. The trouble is, with all these controls, it
didn't fit into a 5-bit alphabet, and so 7-bit ASCII (American Standard
Code for Information Interchange) was born, and became the standard for
all teletype devices.

Then came the rise of the computer. Teletypes where used to talk to
computers, and people were using paper at an alarming rate. Your average
programmer consumed somewhere in the neighborhood of 1 deciduous forest
per year, and that was just when he wasn't playing Star Trek\! (man
trek) So then people moved to a less permanent way of painting text.
Instead of paper, it was displayed on a screen, and thus the visual
terminal was born\!

Now visual terminals offered a lot more control than paper did. For
instance, you could erase it. You could color it, you could save it to
disk, or send it to printers to be made permanent. So naturally, more
control codes had to be invented. The trouble is, they didn't fit into 7
bits. Rather than extend the character set, sequences of characters were
designated for this use.

Eventually, computers became smaller and cheaper, and so the physical
terminal died and was replaced by a terminal emulator. The terminal you
are presently using is one of these, but it still responds to the same
escape sequences as the physical devices of yesterday. Thus we came the
current state of the art of teleprinter control, the escape sequence\!

\*phew\* Now are are you ready to code?

## Messing with Terminals

So why were they called escape sequences? Well, the reason is they begin
with a character called the "escape" character. The escape character is
a non-printable ASCII character which has decimal value 27 (1B in hex,
or 33 in octal). To try your hand at this, enter, compile and execute
the following program:

**ansiExample.cpp**

``` cpp
   #include <iostream>
   
   using namespace std;
   
   int main(void) {
     cout << "\033[36m" << "Hello World" << endl;
   }
```

That mess in line 6 is the escape sequence. The pattern is:

` \033 (the escape character) followed by [36m.`

All ANSI escape sequences begin with \\033\[. The m at the end means
this is a mode command. 36 is the mode for cyan color.

When you run this program, you'll probably notice that your terminal
remains in cyan mode. (NOTE: You can't run these things inside Emacs
shell. You'll have to leave Emacs or have another window open in order
for this to work). Terminal modes are persistent. That is, they continue
until something tells them otherwise. To clear this mode, you have to
send "\\033\[0m". The number 0 is the mode command for "normal mode". go
ahead and try that out. Add "\\033\[0m" to the end of line 6, so it
reads:

`  cout << "\033[36m" << "Hello World" << "\033[0m" << endl;`

You'll see "hello world" in cyan, but your prompt will have returned to
the original color. So now, there a lot of mode commands. Some of these
follow:

` \033[#m - the generic mode change pattern`

` #    Meaning`  
` --   -------`  
` 0    Normal Mode`  
` 1    Bold`  
` 4    Underline`  
` 5    Blink`  
` 7    Reverse Video`  
` 30   Set Foreground Color to Black`  
` 31   Set Foreground Color to Red`  
` 32   Set Foreground Color to Green`  
` 33   Set Foreground Color to Yellow`  
` 34   Set Foreground Color to Blue`  
` 35   Set Foreground Color to Magenta`  
` 36   Set Foreground Color to Cyan`  
` 37   Set Foreground Color to White`  
` 40   Set Background Color to Black`  
` 41   Set Background Color to Red`  
` 42   Set Background Color to Green`  
` 43   Set Background Color to Yellow`  
` 44   Set Background Color to Blue`  
` 45   Set Background Color to Magenta`  
` 46   Set Background Color to Cyan`  
` 47   Set Background Color to White`

There are also several terminal commands, which cause the terminal to do
things. These follow the pattern of:

` \033[*`

Some values for \* are:

` *      Meaning`  
` ----   -------`  
` 2J     Clear the screen`  
` 2K     Clear the current line`  
` s      Save the cursor position`  
` u      Move the cursor to the saved position`  
` xA     Where x is some number.  This moves the cursor up x lines`  
` xB     Move the cursor down x lines`  
` xC     Move the cursor forward x characters`  
` xD     Move the cursor backward x characters`  
` y;xH   Move the cursor to position (x,y) (1,1 is the upper left`  
`        corner).`

Go ahead and take a moment to play with these commands. To get full
credit for the guided part of the lab, your ansiExample.cpp needs to
have a few additional commands entered.

Note that blink, mercifully, does not work in most terminal emulators\!

Also, you may see differences in the expected color output. This is
because what you are really doing is selecting from a 7 color pallet.
That pallet is decided by the terminal emulator software.

Ok, so now you can make the cursor do anything. You can overwrite text,
you can highlight stuff, you can do anything you want. The trouble is,
it's a pain\! Wouldn't it be great if we could do something like:

` cout << red << "Hello world" << normal << endl;`

Well it turns out with just a little bit of work, we can do that\! In
fact, I have. Check out my header file at
[media:termmanip.h](media:termmanip.h "wikilink"). Look the file over,
and see if there is any C++ syntax that you have not seen before. We'll
discuss elements of this file as the class goes on.

Your Lab1 folder already contains termmanip.h
Let's write a little sample program:

**termTest.cpp**

``` cpp
   #include "termmanip.h"
   #include <iostream>
   #include <iomanip>
    
   using namespace std;
    
   int main(int argc, char** argv) {
     //start on a fresh screen
     cout << clearScreen << cursorPosition(1,1);
    
      
    //general modes test
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
```

Go ahead and type it all in, and then compile and run it with the
commands:

` g++ termTest.cpp -o termTest`  
` ./termTest`

Now, let's take a look at some of the things that may seem odd in the
header file. First, there is the word "inline" sprinkled all over the
place. You may not have seen that before. Basically what that is is it
tells the compiler to attempt to duplicate the function instead of
calling it. See, those functions are tiny one liners and so the overhead
of invoking the code is greater than the cost of running the function.
Marking them inline gives the optimizer the hint that it may be better
to simply duplicate these functions than it is to call them. This makes
the generated executable slightly larger, but it runs a little faster.

Another thing of note is that it appears we are printing functions\! We
are not. What is happening is that ostream has an overloaded insertion
operator which accepts as its left argument an ostream and as its right
argument a pointer to a function which takes an ostream as an argument
and returns an ostream. It's not as bad as it sounds, and we'll be
seeing more of this in the future.

Note that we have a small class produced here in the .h file. This is a
necessity for providing an ostream modifier which takes an argument. We
overload the () operator on our class to allow it to be invoked as a
function, and then we provide an overloaded insertion operator to handle
the final insertions. Try thinking through what happens when we call the
functions and pay close attention to what the functions return. If you
don't get this just yet, that's ok. It's the subject of several
discussions yet to come\!

So now, we have a nifty little header file which lets us do basic
terminal manipulations. You can now make much more colorful programs. So
let's try your hand at using our creation\!

## A Colorful Message

Take a look at the code you typed in the previous section. Notice
anything you haven't seen before in it? Like, perhaps, did someone put
arguments in the main function?

` int main(int argc, char **argv)`

Worse\! One of those things is a pointer to a pointer\! Oh the
humanity\! Ok, actually what's going on here is not really so bad. This
is how you get command line arguments in your program. The previous
program did not use them, but I kind of snuck them under your radar.
(I'm tricky so long as you don't pay careful attention.) Command line
arguments are those things you type along with a program name. For
instance, consider the echo command:

` echo hello`

"echo" is the program and "hello" is its command line argument. The
parameters passed into the main function represent the command line as
follows:

  - argc : The argument count. This is an integer set to the number of
    arguments.  
    argv : The argument values, stored as C-Strings.

This second one is an array of C-Strings. C-Strings are null-terminated
arrays of characters. For instance, the string "Hello, world" is really
stored as "Hello, world\\0" Where "\\0" is a binary 0. As we covered in
class, pointers can point to the first item in an array. This would have
a data type of "char \*". However, in this case, we have an array of
multiple C-strings. This means we must store an array of character
pointers, and hence the data type of "argv" becomes "char \*\*". This
means we can access the command line arguments as an array of c-strings:

` argv[0]   //the first command line argument `  
` argv[1]   //the second command line argument`

Of course, this has its own problems, most notably that these are
C-strings so we can't do a lot with them very easily. For instance, if
we want to compare them or concatenate them, we would have to use the
library functions from contained in the cstring header.

We want to avoid that though, because we are modern C++ programmers\! So
we could write a little function to convert the old format of argv into
a nice nifty vector of string objects. The next program has such a
function, one which you are welcome to copy into your future coding
projects.

Let's type it in and play around with it. Type the following code into a
file named "colorEcho.cpp" in your lab1 folder.

**File:** colorEcho.cpp

``` cpp
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
    if(args.size() > 1) {
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
```

Compile the program, and let's play around with it. Try running it in
the following ways:

` ./colorEcho`  
` ./colorEcho hello world`  
` ./colorEcho 'hello world'`

You should take note that a program always has one command line
argument. The string argv\[0\], or in our new vector args\[0\], always
contains the name of the program as typed on the terminal. The other
arguments follow it. Notice how when we typed "hello world" without the
single quotes, it was treated as 2 arguments, but when we did "'hello
world'", it was treated as 1 argument.

Now, here is your code contribution to today's lab. Modify colorEcho.cpp
so that it allows the user to optionally specify the color. These colors
should be the names of colors that we have in termmanip.h. For instance,
if I were to run:

` ./colorEcho 'hello world'`

It would display "hello world" in the default red color, but if I typed

` ./colorEcho blue 'hello world'`

The program will display "hello world" in blue.

For the sake of simplicity, you are welcome to assume that the command
line will contain either a string to print or a color followed by a
string to print. This has some implications for the number of arguments
you receive. What are these implications? Ponder hard, and code away\!

Once you've done that, play with termmanip a little more to add a little
pizazz to this little program. You could add boxes drawn in characters,
or maybe some reverse video or something. Just add enough so I can see
you've played around with termmanip and maybe some other command line
arguments.

Most of all, have fun\!

## Turning it In
Now, we need to commit and push our changes back to github.  To do
this, first we need to make sure that all of our code is added to the
repository.  The first command to run is:

`git status`

Look at the list of untracked files.  If any of those are source
files, you need to add them.  Use commands like this:

`git add filename(s)`

For example, to add termTest.cpp and colorEcho.cpp we execute the
command:

`git add termTest.cpp colorEcho.cpp`

Now to commit the changes to the repository, simply execute:

`git commit -a`

If git complains at this step about configuration issues, go ahead and
do what it says to do and try the command again.  Eventually it will
spawn a text editor.  Here you'll type a message indicating what you
have done, for instance you could type "Finished Lab 1".

Now to push the changes to github, simply execute:

`git push`

That's it! You've completed your first git workflow!  For more
information on how to use git, take a look at "the book"
https://git-scm.com/book/en/v2.

## Closing Remarks

In this lab, we looked at ANSI escape sequences. Because of the vast
array of terminals and terminal emulator software on the market, this is
not a universal set of controls. The ones I have elected to present here
are a small subset of terminal control. These are the ones supported by
most terminals.

In order to alleviate the difficulties in programming serious terminal
applications, several services were created on UNIX machines. The first
was TERMCAP which listed the terminal capabilities of the presently
attached tty port (which stands for teletype, by the way). Termcap was
later supplanted by a library called curses, and a free version of
curses was created called ncurses. ncurses provides a good abstraction
layer for doing more advanced terminal work. If you are interested in
what ncurses can do, check out the ncurses programming howto at:

<http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html>

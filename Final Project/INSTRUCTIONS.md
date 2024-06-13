
# CPSC 120 - Final Exam (Coding Portion)

Welcome to the final coding task of the semester!

## Overview

The coding portion of your final exam will be conducted similarly to a lab assignment. You should make commits to your local repository as you work, and push your changes regularly as you make progress, making sure not to push code that doesn't compile along the way.

Your job here will be to read a description of a program (below), and implement it from scratch. Except where specified, you're free to implement your program however you wish, with the following constraints:

* You should only use concepts we've covered throughout this semester.

* You must make sure to push all your code before the final exam time window is over; As with labs, no commits will be counted past the cutoff.

* You should try to utilize functions and hierarchical calls.

* Don't worry about coding style; Just focus on code that works properly.

## Allowed Materials / Academic Integrity

* This part of your final is *open notes*, *open book*, *open labs*, but ***closed internet***. This means you are allowed to reference the following while you work:

    * The textbook we've been using this semester
    * The slideshows we've been using this semester
    * Any notes you've personally created this semester
    * Any lab work you've personally done this semester

* You are ***not*** permitted to:

    * Use the internet to find information, solutions, or code snippets
    * Use materials provided by other students or people
    * Collaborate with other students or other people in any way

Please be very careful about this. Plagiarism detection software will be used on all submissions. If plagiarism is detected, it can result in a zero on the final, in the class, or worse.

## Program Description

Your job is to implement the following program.

### Basic Details

The basic details of how your program should build are as follows:

* The default Makefile target should both build ***and execute*** your program, providing the file name *out.txt* as the first command line argument.

* The default Makefile target should be named ***final***

* Your executable should be named ***final.bin***

* Your source file should be named ***main.cpp***

### Execution Flow

Your program should do the following:

1. Grab the first command line argument and consider it the name of an output file.

    * Do not hard-code this value in your *main.cpp* source file. The user should be able to enter any file name on the command line. (yes, you can hard-code this value in your Makefile, though).

    * If the user hasn't provided input, complain and exit the program.

2. Ask the user how many items of data they'd like to enter. Consider this number *n_items* for the rest of these steps.

3. If the user has entered 0 or less items, complain and exit the program.

4. Do the following *n_items* times

    1. Ask the user for the next data item, and keep it as a ```double```

    2. Transform the data item to a new value, using the formula from the image below

    3. Show the user both the inputted value and the transformed result.

    4. Store the transformed data item into a vector of ```double``` values.

5. Loop through every item in your vector, and write it to the output file on its own line.

6. Thank the user for entering their data, and print the following:

    1. The lowest value found in your vector

    2. The highest item found in your vector

    3. The sum of all items found in your vector

7. Let execution fall through to the ```return 0;``` statement at the end of your ```main``` function.

### The Formula

Use the following formula when transforming the user's input to a new value:

![Formula](images/t.png "Formula")

In the above, *x* is an input value to a function, and *y* is its return value.

You may define *e* as the following global constant:

```cpp
const double EULERS_NUMBER = 2.71828;
```

If you wish, you may instead use the more precise constant exposed as ```M_E``` from the *cmath* header by adding the following to the top of your program:

```cpp
#define _USE_MATH_DEFINES
#include <cmath>
```

### Hints

* ```push_back```


### Sample Output

To help clarify your task, here is some sample output from a winning program:

```text
Building final.bin
g++ -Wall -pedantic -std=c++17 -g main.cpp -o final.bin
Launching executable
./final.bin "out.txt"
How many items of data do you wish to enter? 3
Okay, will receive 3 data items
Please enter the next data item: -1.1
Received -1.1 and converted to ==> -0.800499
Please enter the next data item: 0.25
Received 0.25 and converted to ==> 0.244919
Please enter the next data item: 2.5
Received 2.5 and converted to ==> 0.986614
Thank you for entering your data.

Lowest converted value: -0.800499
Highest converted value: 0.986614
Sum of all converted values: 0.431034
```






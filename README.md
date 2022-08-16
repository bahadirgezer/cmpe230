# CMPE230 - SYSTEMS PROGRAMMING

| **Term** | **Instructor** |
| --- | --- |
| Spring 2022  | Can Özturan  |

### [Project 1:](https://github.com/bahadirgezer/cmpe230/tree/master/project1) Transpiler From a Psuedolang Using C

### [Project 2:](https://github.com/bahadirgezer/cmpe230/tree/master/project2) Postfix Evaluation Using A86 Assembly 

### [Project 3:](https://github.com/bahadirgezer/cmpe230/tree/master/project3) Simple Hex Calculator Using QT

---

## Project 1

> # CMPE230 SYSTEMS PROGRAMMING SPRING 2022
>
> ## PROJECT 1 DOCUMENTATION
>
> * Bahadır Gezer
> * Simar Achmet Kechagia
>
>
> ### Summary:
>
> Our program behaves like a real compiler. The program reads the input file line by line.
> Every line is then tokenized, parsed and then translated.
>
> We have implemented our own vector and stack header files. The vector is like the
> resizable vector in C++ and the stack is the standard stack data structure. Since we don’t know how many Token structs there are the vector is used to hold tokens. This important Vector is called ‘tokens’. Each token is a struct Token structure. This struct holds the type and value of the token. The value char array is the string which the token is named after, and the type is the type which we arbitrarily assigned. The lookup table for types are below.
>
> For every line, after tokenization, tokens Vector is filled with Token structs and these structs does not change places while the current line being read.
>
> ### Important Notes:
>
> Both compilations must be done with the -lm option. This is to ensure that the <math.h>
> library is linked properly.
>
> ### Important Functions:
>
>* **void tokenizer();**
> This function tokenizes the expressions. No attribute is given to the tokens, that is
>  done by the **parser()** function.
>
>* **void parser();**
>  This function parses the expression. It gives meaning to the tokens. More
>  explicitly it will assign types to tokens. It calls **get_expression()** to get the index of the expected expression. Then it calls **expression()** to check if the expression syntax is correct. This **expression()** function uses infix to postfix conversion to check the syntax. This is done with the help of our stack header file.
>
>* **void output_generator(File \*out);**
>  This function takes the **Vector tokens**, which was attributed in the **parser()**
>  function, and translates the tokens to appropriate C functions. It behaves just like the **parser()** in its recursive calls.
>
>### Token Types Lookup Table:
>- 0 -> scalar keyword
>- 1 -> vector keyword
>- 2 -> matrix keyword
>- 3 -> function keyword (tr, sqrt, choose)
>- 4 -> for keyword
>- 5 -> left paranthesis
>- 6 -> right paranthesis
>- 7 -> left square brace
>- 8 -> right square brace
>- 9 -> left curly brace
>- 10 -> right curly brace
>- 11 -> equals
>- 12 -> multiplication
>- 13 -> addition
>- 14 -> subtraction
>- 15 -> comma
>- 16 -> colon
>- 17 -> undetermined
>- 18 -> comment
>- 19 -> scalar variable
>- 20 -> vector variable
>- 21 -> matrix variable
>- 22 -> for variable
>- 23 -> print function keyword (print, printsep)
>- 24 -> in keyword
>- 25 -> indexed matrix
>- 26 -> indexed vector
>- 27 -> scalar function keyword (choose, sqrt, tr) 28 -> matrix function keyword (tr)

---

## Project 2

># Project 2: Postfix Evaluation with Assembly CmpE 230, Systems Programming, Spring 2022
>
>#### Students
>* Bahadır Gezer
>* Simar Achmet Kechagia
>
>### 1. INTRODUCTION
>In this project we used the A86[^1] assembler and D86 debugger to write a program which evaluates a postfix expression of hexadecimal numbers with arithmetic and bitwise operators.
>
>[^1]: [eji.com/a86](https://eji.com/a86/)
>
>### 2. OVERVIEW
>
>The program starts with reading the input. If the input is an operand, this string is first converted to the appropriate hexadecimal value. This value is then pushed to the stack. Otherwise, if the input is an operator, then it pops two operands from the stack and does the necessary operation. The result is then pushed back to the stack.
>When the program reads a newline character, then, the program pops the result value from the stack -leaving the stack empty- and converts it to the output string. This output string is then displayed to the console.
>
>### 3. IMPLEMENTATION DETAILS
>
>The program starts with the ‘start’ label. Which assigns some initial flags and variables which will be used inside the program. The inputs are read character by character under the ‘getnum’ label. If the current character is a whitespace, then the program can put an end to the number it was reading and process it. After a whitespace, the programs jump back to the ‘start’ label and loop again. If the current character is not a whitespace, then the program jumps back to ‘getnum’ in order to read the next character.
>
>This loop continues until a newline character is read. If a newline is read, then the program jumps to the output section.
>If the character read was an operator, then the program jumps to the appropriate label to perform the arithmetic operation. The labels arithmetic operation labels are named clearly. The result from an arithmetic operation is pushed to the stack. The program will jump back to ‘getnum’ label to continue reading the input.
>When the program enters the ‘output’ label, the last result is popped from the stack, leaving the stack empty. Then, the program jumps to the ‘printer’ label which converts each digit of the resulting hexadecimal value to the corresponding ASCII character. Thus, forming the output string. Before displaying the output string the program first prints a newline -with carriage return. Finally, the output string is displayed and the program exits with code zero.
>
>### 4. INPUT & OUTPUT
>
>To run the program, first you need to compile it using the A86 assembler. Write `a86 main.asm` to the command prompt. Now, the compiled program can be run with a given input. The input should be a postfix expression of hexadecimal numbers, which are at most 16 bits, delimited with whitespaces and there should be a newline character at the end of the input. The input should not contain any syntax errors. To take the input from a file, you should write the input file name after the redirect with the operator ‘<’, which redirects stdin.
>The output is a 4 digit hexadecimal number which is printed in a newline to the console. If you want to redirect the output to a file, you should write the file name after the redirect operator ‘>’, which redirects stdout.

---

## Project 3

>## Project 3: Hexadecimal Calculator GUI App CmpE 230, Systems Programming, Spring 2022
>
>#### Students :
>
>* Simar Achmet Kechagia
>* Bahadır Gezer
>
>### 1. INTRODUCTION
>In this project we used QT to create a hexadecimal calculator application with a graphical user interface.
>
>### 2. OVERVIEW
>The internals of calculator operations work in a similar manner to old calculators. We used the online-calculator1 as a reference point for our app. The only difference is that our buttons have hexadecimal values. Also, only multiplication, addition, clear and equals operations are implemented.
>
>### 3. IMPLEMENTATION DETAILS
>
>There are two internal variables where the calculator stores values. These are both C++ ‘long long’ integer types. One is the inputNumber variable and the other is the internal register, where the operation solutions are held.
>
>The equal button conducts the operation which was clicked most recently. This way you can change the operation by clicking sum and subtract buttons. The most recent press will be registered as the operation for the equal button.
>
>The sum and subtraction buttons work the same way for the most part. The only difference they have is the operation they register. If the equal button or any other operation button was pressed before the sum or subtraction button press, then the input number loads the value in the internal register. Otherwise the button press for sum and subtraction buttons will first load the internal register and the input number with the solution of the operation, then it displays the solution on the screen.
>
>The clear button works with two presses. On the first press the input number will be reset. On the second press the calculator is reset fully to its initial state.
>
>Each hex button press will update the display and the input number. The input number is a standard decimal integer value which is stored internally. Each hex button press converts and adds the corresponding hex value to this decimal register.


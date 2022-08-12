## Project 3: Hexadecimal Calculator GUI App CmpE 230, Systems Programming, Spring 2022

#### Students :

* Simar Achmet Kechagia 
* Bahadır Gezer 

### 1. INTRODUCTION
In this project we used QT to create a hexadecimal calculator application with a graphical user interface.

### 2. OVERVIEW
The internals of calculator operations work in a similar manner to old calculators. We used the online-calculator1 as a reference point for our app. The only difference is that our buttons have hexadecimal values. Also, only multiplication, addition, clear and equals operations are implemented.

### 3. IMPLEMENTATION DETAILS

There are two internal variables where the calculator stores values. These are both C++ ‘long long’ integer types. One is the inputNumber variable and the other is the internal register, where the operation solutions are held.

The equal button conducts the operation which was clicked most recently. This way you can change the operation by clicking sum and subtract buttons. The most recent press will be registered as the operation for the equal button.

The sum and subtraction buttons work the same way for the most part. The only difference they have is the operation they register. If the equal button or any other operation button was pressed before the sum or subtraction button press, then the input number loads the value in the internal register. Otherwise the button press for sum and subtraction buttons will first load the internal register and the input number with the solution of the operation, then it displays the solution on the screen.

The clear button works with two presses. On the first press the input number will be reset. On the second press the calculator is reset fully to its initial state.

Each hex button press will update the display and the input number. The input number is a standard decimal integer value which is stored internally. Each hex button press converts and adds the corresponding hex value to this decimal register.

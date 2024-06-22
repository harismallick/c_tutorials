This directory is for testing examples and performing exercises shown in the book "The C Programming Language" by Ritchie and Kernighan.

### Notes from the book:

#### Chapter 1

- Integer division truncates in C. Anything after the decimal is discarded.
    - This means that 5/9 would output as 0. It will NOT be rounded up to 1, or automatically converted to a floating point number.

- printf is a general-purpose output formatting function in C. 
- There are other output functions that can be used, like putc() and puts().
- In an operation involving a float and an integer, the integer is always type-casted to a float.
- Symbolic constant declarations with the #define keyword are not followed by a semicolon.

What is a text stream?
- It is a sequence of characters divided into lines.
- Each line consists of zero or more characters and the newline character "\n".
- getchar() and putchar() are used to print one-at-a-time, characters from the input stream.

Comparion operator precedence
- In C, the "!=" comparison has precedence over assignment via "=".

```C
while ((c = getchar()) != EOF)

// Using proper parenthesis, assignment is done before comparison

while (c = getchar() != EOF)

// This is actually equivalent to:
while (c = (getchar() != EOF))
```
Send EOF (end-of-file) signal in UNIX terminal:<br>
***Ctrl + D***

Precedence of logical operators in C:
- Logical comparisons are performed from left to right.
- The AND operator is given higher precedence than the OR operator.
- Evaluation will stop as soon as truth or falsehood is known.

Functions:
- Number and character arguments are pass-by-value in C.
    - this means that a copy of the passed arguments is made in the local scope of the function.
- Arrays, including char-strings, are pass-by-reference. 
    - This means that the memory address of the first element in the array.

- Local variables are also known as ***automatic*** variables.
- Authors will use the term automatic variable throughout the book.
- Automatic variables must be assigned values on function invocation. If they are not, they will contain garbage values.

Global variables:
- These must be declared at the beginning of the file.
- If they are not declared at the beginning, before function prototypes, then to access these variables, the 'extern' keyword should be used.
```C
int test_num

void func_1(void)
{
    extern test_num = 5;
    // extern informs compiler to look for a global "test_num" declaration.
}
```
- If the global variable is declared in file1, and needs to be accessed in other files, then the extern keyword is required.
- The usual practice is to create an extern declaration of functions and variables in one file, called the ***header*** file.
- These header files end with a ".h" extension.

Difference between defining and declaring a variable:
- Declaration refers to places where the nature of the variable is stated, but no storage is allocated.
- Definition refers to the place where the variabe is created and assigned storage.

#### Chapter 2 - Types, Operators and Expressions

Variable names
- Traditional C standard is to use lowercase letters for variables and uppercase for symbolic constants.
- In C, every variable name must start with a letter, and can contain letters, digits. Underscore counts as a letter, but it should never be the first letter in a variable/constant name.
- Basic data types in C:
    - char: single byte capable of storing one character.
    - int: an integer, representing the natural size of integers on the host machine.
    - float: single-precision floating point
    - double: double-precision floating point.
- You can also use qualifiers with these data types:
    - short: half the size of int.
    - long: twice the size of int or double datatypes.
    - signed: store both positive and negative values.
    - unsigned: only store positive values.

Constant
- We learnt that constants can be declared using #define.
- The datatype of the constant can be declared by adding specific letter suffixes.

```C
#define NUM_INT 1234
#define NUM_LONG -123456789L
#define NUM_LONG_UNSIGNED 123456789L
#define NUM_DOUBLE 123.4
#define NUM_FLOAT 123.4F
#define NUM_LONG_DOUBLE 123567.4678L

```
- Character constants are declared in single quotes.
- String constants are declared in double quotes. The compiler automatically adds '\0' at the end of a string.
- Multiple strings next to eachother are concatenated at compile time.
```C
"Hello, " "world";
// Is the same as:
"Hello, world";
```
- This is a useful feature to breakup long strings across multiple source lines.

Enumeration
- The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the
last specified value, as the second of these examples:
```C
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };
```
- Names in different enumerations must be distinct. Values need not be distinct in the same enumeration.

- The keyword ***const*** is used to declare values that cannot be changed throughout the execution of the program.

Arithmetic operators:
- Binary + and - operators have the same precedence, which is lower than the precedence of *, / and %, which is in turn lower than unary + and -. Arithmetic operators associate left to
right.

Relational operators:
- &gt;, >=, <, <= all have the same precedence.
- Below them in precedence is == and !=.
- Relational operators have lower precedence than arithmetic operators.
```C
i < lim - 1
// is the same as:
i < (lim -1)
```

Logical operators:
- && and || are evaluated from left to right.
- Evaluation stops as soon as the truth or falsehood of the result is known.
- && has higher precedence than ||.

Unary negation operator '!':
- The unary negation operator ! converts a non-zero operand into 0, and a zero operand in 1. A common use of ! is in constructions like: <br>
if (!valid) <br>
rather than: <br>
if (valid == 0)

Type conversion:
- In an operation between an integer and a float. the integer is always typecasted to a float.
- The "ctype" library has many useful functions for typeconversions.
- Converting to boolean datatype:
    - Standard logical operators and comparison will return "1" for true and "0" for false.
    - Some functions, like isdigit(), can return any non-zero value for true. 
    - This is fine because the test portion of if, while, for, etc equate "true" to any non-zero number.
- For function arguments, char and short are converted to int. Floats are converted to double.
- Rules for converting signed data types is as follows:
    •If either operand is long double, convert the other to long double.
    •Otherwise, if either operand is double, convert the other to double.
    •Otherwise, if either operand is float, convert the other to float.
    •Otherwise, convert char and short to int.
    •Then, if either operand is long, convert the other to long.
- For unsigned datatypes, the value on the right side of an operand is converted to the datatype of the value on the left.

Type casting:
- This is an explicit way of converting one data type to another. The method is as follows:
```C
// (type) expression
int x = 5;
float y = 2;

float z = (float) x / y;
```

Increment & decrement operators:
- ++n performs the increment before its value is used.
- n++ performs the increment after n's value is used.
- Knowing this difference can lead to writing more concise code:
```C
int i, c;
s[i] = c;
++i;

// This can be written as:
s[i++] = c;
```
Bitwise operators:
There are 6 bitwise operators in C:
    &   bitwise AND
    |   bitwise inclusive OR
    ^   bitwise exclusive OR
    <<  left shift
    >>  right shift
    ~   one's complement (unary)

- These can only be applied to integral operands: char, short, int and long.

#### Chapter 3 - Control Flow

- It specifies the order in which computations are to be performed.
- What is a statement?
    - It is a sequence of code that ends with a semicolon.
    - Multiple lines of code, or a single line of code can be a statement, depending on where the semicolon is implemented.
    - Code encapsulated inside curly braces is known as a code block, or compound statement.
    - The right curly brace of a code block is not to be terminated with a semicolon.
    
- If else statements:
    - An expression is evaluated as part of the if statement.
    - The expression returns a numerical value. If the value is non-zero, its true, otherwise its false.
    - There is no need to write an expression as: ***if (expression != 0)***.
    - This can be shortened to ***if (expression)***.

- Switch case statements:
    - Each of the cases should be followed by a break clause. This prevents rolling through to downstream cases for evaluation.

- While and for loops:
    - Using either is a matter of personal choice in most cases.
    - How to create an infinite loop in C:<br>***for (;;) {}***
    - Such infinite loops reply on break or return clauses to be terminated.

- Comma operator in for loops:
    - A pair of expressions separated by a comma is evaluated left to right, and the type and value of the result are the type and value of the right operand. Thus in a for statement, it is possible to place multiple expressions in the various parts, for example to process two indices in parallel.
    - Here's an example of its use:

```C
#include <string.h>
/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
// This can also be written as:

for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
```

- "goto &gt;label&lt;" statements:
    - These should be used sparingly, only when it makes sense.
    - One example of its use could be to exit out of the inner most loop in nested loops; to avoid using multiple break statements to exit the nest.

#### Chapter 4 - Functions and Program Structure

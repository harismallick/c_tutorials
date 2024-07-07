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

- Functions break large computing tasks into smaller ones, and enable people to build on what others have done instead of starting over from scratch.
- Appropriate functions hide details of operation from parts of the program that don't need to know about them, thus clarifying the whole, and easing the pain of making changes.
- For functions designed to output the index of an element (or set of elements) in an array, -1 should be used to signify that no such item was found in the array. This is because most programming laguages are 0-indexed. So if the output is a negative number, this naturally means that the searched element in not in the given array.
- If no return type is declared for a function, ***int*** type is assume by default.
- An empty function can be declared in C as follows:
```C
    function() {}

// A dummy function is useful for program development.
```
- Communication between the functions is by arguments and values returned by the functions, and through external variables.
- The functions can occur in any order in the source file, and the source program can be split into multiple files, so long as no function is split.
- Typecasting can be performed in the return expression of a function. Here is an example:
```C
    /* atoi: convert string s to integer using atof */
    int atoi(char s[])
    {
        double atof(char s[]);
        return (int) atof(s);
    }
```
###### - Standard C does not allow for nested functions.
- Function prototype declarations can be made inside another function, but the definition must always be outside.
- The one good use case for external variable:
```
    Automatic variables are internal to a function; they come into existence when the function is entered, and disappear when it is left. External variables, on the other hand, are permanent, so they can retain values from one function invocation to the next. Thus if two functions must share some data, yet neither calls the other, it is often most convenient if the shared data is kept in external variables rather than being passed in and out via arguments.
```
- Scope of variables and parameters in a function
    - Any variable declared inside a function is confined to the function. Therefore, variables with the same name can be declared inside multiple functions inside the same source file.
    - This rule holds true for function parameters as well.

- Within one source file, the code is read and compiled top-to-bottom. This means that if a global variable is declared after a function, like main(), then main() will not be able to access it.
- To access variables across the whole file, and other source files, the extern keyword must be used.
- This will allow for global variables to be declared in one file (like the header file), and be defined/initialised in another file.
- Difference between declaration and definition:
    - Declaration does not allocate any memory.
    - Definition actually assigns memory for the data type that has been declared/defined.
    - A variable can be declared multiple times, without any issues to code execution.
    - However, a variable or function should only be defined ***once***. Otherwise, the compiler won't know which defition of the variable to use and 'link' to.

- Header files:
    - A file containing all extern variable declarations and function prototypes.
    - These can be imported into individual source files.
    - For smaller projects, one header file would be sufficient. But as projects get bigger and more complex, multiple header files might be needed for better organisation.

- Static Variables:
    - If you want to ensure that certain external variables are not accessed outside their source file, then the ***static*** keyword can be used in their declaration.
    ```C
        static char buf[BUFSIZE];
        static int bufp = 0;
    ```
    - Functions can also be declared using the static declaration. These functions will be invisible outside of their source file.
    - Internal static variables: Variables declared inside functions can also be declared using static. What's the benefit?<br>Typically, function variables do not persist after function execution is completed. The variable initialisation is reset at every function call. However, static internal variables persist, and act like permanent internal storage.

- Register Variables
    - These are variables declared using the ***register*** reserve word.
    - This tells the compiler that the variable in question will be used heavily, so it should be stored on a machine (CPU) register.
    - Modern compilers are much smarter and don't need to be told that heavily used variable should be stored in CPU registers.
    - Therefore, the use of this reserve word should typically be avoided for modern C programmes. Only exception being, when you are working on a brand new CPU, for which the compiler has not yet been optimised.

- Variable initialisation:
    - extern and static variable are guaranteed to be initialised to zero, if no explicit initialisation is done.
    - Automatic and register variables are guaranteed to contain garbage initial values.
    - For external and static variables, the initializer must be a constant expression; the initialization is done once, conceptionally before the program begins execution. For automatic and register variables, the initializer is not restricted to being a constant: it may be any expression involving previously defined values, even function calls.
    - String array initialisation:
    ```C
    char pattern = "ould";
    // is a shorthand for the longer but equivalent for:
    char pattern[] = { 'o', 'u', 'l', 'd', '\0' };
    ```
###### The C Preprocessor

- It is a separate first step in the compilation of C code.
- The two most frequently used features are #include, to include the contents of a file during compilation, and #define, to replace a token by an arbitrary sequence of characters.
- The other features of the preprocessor are:
    - Conditional compilation
    - Macros with arguments.

- File inclusion:
```C
    #include <filename>
    #include "filename"
```
- The preprocessor replaces the #include statements with the contents of the file(s) to be included.
- If the file is mentioned in quotes, searching for the file typically begins where the source program was found.
- if it is not found there, or if the name is enclosed in < and >, searching follows an implementation-defined rule to find the file.
- Naturally, when an included file is changed, all files that depend on it must be recompiled.

- Macros:
```C
    #define name replacement text
```
- Normally the replacement text is the rest of the line, but a long definition may be continued onto several lines by placing a \ at the end of each line to be continued.
- The scope of a name defined with #define is from its point of definition to the end of the source file being compiled.
- Substitutions are made only for tokens, and do not take place within quoted strings. For example, if YES is a defined name, there would be no substitution in printf("YES") or in YESMAN.
- It is possible to define macros with arguments, so the replacement text is different for differnt calls of the macro:

```C
    #define max(A, B) ((A) > (B) ? (A) : (B))
```
- So long as the arguments are treated consistently, this macro will serve for any data type; there is no need for different kinds of max for different data types, as there would be with functions.
- "##" is a preprocessor operator for concatenating arguments for a macro during macro expansion:
```C
    #define paste(front, back) front ## back
    // so paste(name, 1) creates the token name1
```
- Conditional inclusion:
    - As the name suggests, certain header files can be included during compilation based on passing certain conditions.
    - These conditions are defined using ***#if***, ***#elif***, ***#else*** and ***#endif***.
```C
    #if SYSTEM == SYSV
        #define HDR "sysv.h"
    #elif SYSTEM == BSD
        #define HDR "bsd.h"
    #elif SYSTEM == MSDOS
        #define HDR "msdos.h"
    #else
        #define HDR "default.h"
    #endif
    #include HDR
```
    - Conditional inclusion can be used to avoid including the same file multiple times:
    - This is done using the ***#ifndef*** keyword, which is the same as ***#if !defined(file)***.
```C
    #ifndef HDR
    #define HDR
    /* contents of hdr.h go here */
    #endif
```


#### Chapter 5 - Pointers and Arrays

- A pointer is a variable that contains the memory address of another variable.
- Except for the void pointer, every other pointer points to a particular datatype.
- Each datatype occupies a specific number of bits/bytes in contiguous memory.
- char is 1 byte, short int is 2 bytes, long int (or simply int) is 4 bytes. long long is 8 bytes.
- A space occupied by a pointer depends on the OS and the implementation.
- In a modern 64-bit linux machine, a pointer occupies 8 bytes, ie, 64-bits of space.
- See [link](./pointer_sizes.c) for pointer sizes test.
- The unary "&" operator is used to assign a memory address to a pointer.
- The "*" is used to dereference a pointer to access the data value being stored in the memory address the pointer was pointing to.
```C
char c = 'C';
char *pC = &c; // assignment
*pC = 'A'; // dereferencing
```
- Pointers can only point to objects -- variables and arrays.
- They cannot point to expressions, register variables or constants.
- Unary operators associate right to left. This means (*p)++ with increment the value the pointer points to, while *p++ will increment the pointer itself.
- Understanding pointer arithmetic for arrays:
    - For an array 'a' with 'i' elements:
        - The i-th element can be accessed by: a[i] or *(p + i).
        - Where int *p is a pointer to the first element array 'a'.
    - In short, an array-and-index expression is equivalent to one written as a pointer and offset.

- Array names and pointers behave identically for the most part. The one key different is that an array name is NOT a variable, so a = pa and a++ are illegal operations.
- Passing arrays as arugments to functions:
    - Using strlen() function as an example:
    ```C
    /* strlen: return length of string s */
    int strlen(char *s)
    {
        int n;
        for (n = 0; *s != '\0', s++)
            n++;
        return n;
    }

    // Valid arguments for this function:
    strlen("hello, world"); /* string constant */
    strlen(array);  /* char array[100]; */
    strlen(ptr);    /* char *ptr; */
    ```
    - Functions create local copies of pointers/variable names.
    - So, in the scope of the function that called strlen() array++ is an illegal operation.
    - But, s++ in strlen() is legal as *s is a pointer in the local scope of the function.
- Declaring arrays as "char s[]" and "char *s" are functinally equivalent.
- Memory allocation (discussed in detail in chapter 8) can be done using funcitons like alloc, malloc and calloc.
- Each of these functions work slightly differently.
- Alloc allocates memory as a stack, applying LIFO. Its complementary function afree() frees memory using the LIFO principle.
- In C, zero can never be a valid memory address. So, returning 0 from memory allocation functions can be used to signal an abnormal event. In this case, the lack of heap memory.
- We know that char and int datatypes are interchangeable in C. This is ***NOT*** the case for pointers and integers.
- The only exception to this rule is zero. Zero can be assigned to a pointer, and a pointer can be compared to zero. More specifically, a pointer can be set to and compared to ***NULL***, defined in <stdio.h>.
- Comparison operators on pointers:
    - If two pointers p and q point to elements in the same array, then operators like ==, !=, <, >=, etc can be used to compare the two pointers.
    - Example, p < q is true if p is a pointer to an earlier element in the array than q.
    - EXCEPTION: The first memory address past the end of the array can be used for pointer arithmetic. I'm assuming for end-of-array checks.
- Legal pointer arithmetic:
    The valid pointer operations are assignment of pointers of the same type, adding or subtracting a pointer and an integer, subtracting or comparing two pointers to members of the same array, and assigning or comparing to zero. All other pointer arithmetic is illegal.
- Illegal pointer arithmetic:
    It is not legal to add two pointers, or to multiply or divide or shift or mask them, or to add float or double to them, or even, except for void *, to assign a pointer of one type to a pointer of another type without a cast.

- Two pointers can be used to copy characters from one string to another. Here's the simplest string copy function using pointer arithmetic:
    ```C
        /* strcpy: copy t to s; pointer version 3 */
        void strcpy(char *source, char *destination)
        {
        while (*destination++ = *source++)
            ;
        }
    ```

***Array of pointers***

- Using an array of pointers to sort alphabetically a collection of strings:
    - Algorithm:
    ```
    read all the lines of input
    sort them
    print them in order
    ```
    - ***Coding design tip***: it's best to divide the program into functions that match this natural division, with the main routine controlling the other functions.

***Multi-dimensional arrays***

- A 2D array, for example, is declared using two sets of square brackets: int arr[n][m], where n is the number of rows and m is the number of columns.
- To pass a 2D array an a function argument, the function declaration must provide the number of columns to be passed. Number of rows is irrelevant.
```C
    // Three ways to pass multidimensional array as argument to a function:

    void func(int arr[2][13]); // declare row and column
    void func(int arr[][13]); // declare columns only, rows are irrelavant to 2D array argument declaration
    void func((*arr)[13]); // Pointer to an array of 13 integers

```
- Declarations of 2D arrays like: int a[10][20] allocates contiguous memory for 200 ints. Each of the 10 subarrays can have a max of 20 elements.
- Pointer arrays allow for the creation of dynamic 2D arrays. Declarations like: int *b[10] allocates 10 integer pointers. These integer pointers can be assigned to subarrays of varying lengths.
- Pointer arrays are most useful for storing char-strings of varying lengths in an array.
```C
    char *months[] = {"Illegal Month", "Jan", "Feb", "Mar"};
```

***Command line arguments***

- In the main function of a file, arguments can be passed from the command line, to alter the behaviour of the C code.
- The two arguments are called argc and argv:
    - argc is an integer count of the number of arguments passed.
    - argv is an array of strings. argv is a pointer to an array of pointers.
- printf format arguments can be expressions.
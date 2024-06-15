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

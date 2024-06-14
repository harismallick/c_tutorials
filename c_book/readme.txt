This directory is for testing examples and performing exercises shown in the book "The C Programming Language" by Ritchie and Kernighan.

Notes from the book:

- Integer division truncates in C. Anything after the decimal is discarded.
    - This means that 5/9 would output as 0. It will NOT be rounded up to 1, or automatically converted to a floating point number.

- printf is a general-purpose output formatting function in C. 
- There are other output functions that can be used, like putc() and puts().
- In an operation involving a float and an integer, the integer is always type-casted to a float.

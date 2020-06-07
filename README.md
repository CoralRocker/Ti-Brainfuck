# Ti-Brainfuck
Have you ever worked on your calculator and lamented the lack of diverse programming languages available on it? LAMENT NO MORE! This program for your Ti-84 allows you to program in Brainfuck right in your calculator!

# Installation
This program is written in C using the toolchain available at https://github.com/CE-Programming/toolchain. In order to use it on your calculator, you will need the C Libraries installed on your calculator. They are available [here](https://github.com/CE-Programming/libraries/releases/tag/v8.8).

Once you have the C libraries installed, simply use TI-Connect or TILP2 to send the program over to your calculator.

# Usage
> Asm(prgmTIBF)

`Asm(` can be reached by `2nd + 0` and scroll to `Asm`. `prgmTIBF` is the program called `TIBF` in the `prgm` screen.

Currently, the interpreter will only read from a program called `OP`. Simply create a new program called `OP` and write your brainfuck code in there. 

# Language

Because the `>` and `<` symbols are hard to type on the Ti-84, they have been replaced by `)` and `(` respectively as shift operators.

| Brainfuck Command | C Equivalent | Description |
|:-:|:-:|:--|
|+|*p++|Increment cell by one|
|-|*p--|Decrement cell by one|
|[|while(*p){|Open loop while cell is not 0|
|]|}|End loop|
|)|p++|Increment pointer by one. In normal brainfuck, this is the `>` sign|
|(|p--|Decrement pointer by one. In normal brainfuck, this is the `<` sign|
|.|putc(*p)|Print current cell|
|,|scanf("%c\n",&p)|Read one character from the terminal to the cell|

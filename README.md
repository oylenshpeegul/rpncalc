# rpncalc

This is a RPN Calculator written in C.

(http://github.com/simonsolnes/rpncalc/screenshot.png)

## Basics of RPN

[Istead of writing one myself, I'm just gonna link to a tutorial.](http://www.lehigh.edu/~sgb2/rpnTutor.html)

## The program

The program takes two types of input:

1. Numbers
2. Operations

* Add numbers to the stack by typing a number, and then enter.
* Do operations by pressing a numerical key.

Operators can do three things:

1. Operations between Buffer x and Buffer y
2. Operations on Buffer x
3. Manipulations of the stack

## Example

**2 + 5:**  
`2 enter 5 enter a enter`  
Since all operations and number pushes are divided by an enter, it's usually written like this:  
`2 5 a`

**3 / -1:**  
`3 1 c d`

**sqrt(9)^cos(3.4):**  
`9 t 3.4 u p`

## Operators

* a: add
* s: subtract
* m: multiply
* d: divide
* c: change sign
* r: roll stack
* x: swap Buffer X and Buffer Y
* t: squareroot
* p: Buffer Y to the power of Buffer X
* u: cos
* i: sin
* o: tan
* q: quit the program

## Compiling

`gcc rpncalc.c -o rpncalc`

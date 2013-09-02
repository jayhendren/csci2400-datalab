/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
   "hendrenj", 
   /* Student name 1: Replace with the full name of first team member */
   "Jay Hendren",
   /* Login ID 1: Replace with the login ID of first team member */
   "hendrenj",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
//
// 15 problems, 40 points
// 2 - rating 1
// 3 - rating 2
// 7 - rating 3
// 3 - rating 4

// rating 1

/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {

  /* !<value> returns 1 if value == 0 and 0 if value != 0 */

  return !x;

}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

  /* x | y returns 1 only when x and y are both false, while x & y
  returns 0 only when x and y are both true, so to get x & y, we will
  need to invert both x and y, then get x | y, then invert that result */

  return ~(~x | ~y);
}
// rating 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* if x can be represented in n bits, then the first 32 - n + 1 bits will be identical
   * (either all 0s or all 1s)
   */
  // step zero: convert n to n - 1
  int m = n + ( ~0 ) ;
  // first, get the sign (either 1 or 0)
  int sign = ( x >> 31 ) & 1;

  // second, convert the sign into a "mask" (all bits either 0 or 1)
  int mask = ~(sign + ~0); 

  // then xor with x, all leading bits will go away 
  x = x ^ mask;

  // now shift right n - 1 times
  x = x >> (m);

  // the result will be zero unless we can't fitbits
  return !x;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* shift right by the appropriate # of bytes until the desired byte is in LSB
   * then get rid of all leading bytes
   */
  int num_shifts = n << 3; //multiply n by 8 to chnage from # of bits to # of bytes
  int result = x >> num_shifts; //shift x right by the correct # of bytes
  return result & 0xFF; //and finally get rid of all leading bytes
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  /* xor will return 0 if two numbers are equal and some non-zero number
  if they are unequal, so testing the result of xor against ! twice will
  preserve the zero and turn all non-zero values into 1 */

  return !(!(x ^ y));
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {

  /* Xor means two things must NOT be true: x & y and ~x & ~y. */

  return ~(x & y) & ~(~x & ~y);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
   * get rid of all bits except LSB so value is only either 1 or 0
   * then transform the 1 or the 0 into 0 (00000000...) 
   * or -1 (11111111....) in order to populate the other bits
   */

  // get rid of all bits except the LSB
  x = x & 1;
  // get the opposite of x
  // this makes x all ones if the LSB was zero
  // and all ones except the LSB if the LSB was one
  x = ~x;
  // add one. 
  // if x is all ones, then it rolls over to all zeros
  // if x has a trailing zero, then it becomes all ones
  return x + 1;
}
// rating 3
/* 
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}
int sum3(int x, int y, int z) {
  int word1 = 0;
  int word2 = 0;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     without using any '+' operations 
  ***************************************************************/

  /* word1 holds the sum of each digit, word2 holds the carry value */
  word1 = x ^ y ^ z;
  word2 = ( (x&y) | (x&z) | (y&z) ) << 1;

  /* Do I understand the problem? This seems trivial... */

  // word1 = sum(x, y);
  // word2 = z;
  /**************************************************************
     Don't change anything below here
  ***************************************************************/
  return sum(word1,word2);
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /* it is easy to swap bytes when we know that the integer is 4 bytes long.
   * just grab each byte manually, then reconstruct a reversed bytestring
   */

  // grab the first 4 bytes, reverse their positions
  int byte1 = ((x >> 24) & 0xFF);
  int byte2 = ((x >> 16) & 0xFF) << 8;
  int byte3 = ((x >> 8) & 0xFF) << 16;
  int byte4 = (x & 0xFF) << 24;
  // put 'em back together 
  return byte1 + byte2 + byte3 + byte4;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNegative(int x) {
  /*
   * simply test to see if the leading bit is 0 or 1.
   */

  // grab the leading bit
  x = (x >> 31) & 1;
  return x;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  /*
   * this one is really tricky because of possible overflow. 
   * There are two cases in which x < y:
   *  * x is negative and y is positive;
   *  * x and y share a sign and y - x - 1 is positive ( i.e. >= 0 )
   * in any other cases, y must be <= x.
   * so simply test for these 2 cases, then or them together
   */

  // naive way:
  // return (!((y + ~x) >> 31));
  // return ((x + ~y) >> 31) & 1;

  // // subtract y from x
  // // get -y
  // int negy = ~y + 1;
  // // add it to x
  // int diff = negy + x;
  // // diff >= 0 iff y <= x
  // // diff < 0 iff y > x
  // // check to see if the leading bit is zero
  // int lead_bit = (diff >> 31) & 1;
  // return lead_bit;

  // // 4 cases: ++, +-, -+, -- test each one in turn
  // int signx = (x >> 31) & 1;
  // int signy = (x >> 31) & 1;
  // // ++: x - y - 1 has a positive sign
  // int pp = (signx & signy) & ~((x + (~y + 1) + ~0) >> 31 ) & 1;
  // // +-: always return false
  // int pn = !(signx & !signy);
  // // -+: always return true
  // int np = (!signx) & signy;
  // // --: (-x) - (-y) - 1 has a positive sign
  // int nn = (!signx & !signy) & ~(((~x + 1) + y + ~0) >> 31 ) & 1;
  // return pp | pn | np | nn;

  // get the result of y - x - 1
  int diff = y + (~x);

  // sign is 1 iff x and y have opposite signs
  int sign = ((x ^ y) >> 31 ) & 1;

  // iniialize result to be 1 iff x and y have same signs
  int result = ~sign;

  // now sign is 1 iff x is negative and y is positive
  sign = sign & (( x >> 31 ) & 1);

  // get the oppositive of the sign of the difference
  diff = ((~diff >> 31 ) & 1);
  
  // x is < y if the difference is positive and x and y have the same sign
  result = result & diff;
  // x could also be < y if x is negative and y is positive
  result = result | sign;

  return result;  
}
// rating 4
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  /*
   * except for zero, the complement of every number has the opposite
   * sign (that is, leading bit). So just or the leading bits
   * of x and ~x, and only if x is zero will the result be 0.
   */

  // make the leftmost bit 1
  // the complement x + 1 = -x (~x + 1 = -x)
  // the complement of 0 + 1 = 0 (~0 + 1 = 0)
  // so the first bit of either x or ~x + 1 must be 1
  // unless x is 0
  int y = x | (~x + 1);
  // put the leading bit into the rightmost position
  y = y >> 31;
  // eliminate all leading bits
  return y & 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int result = 0;

  /* 
   * compute the sum of each bit with its neighbor, then find the sum
   * of the first two bits with the second two bits, then the first 4 bits
   * with the second four bits, eventually collapsing the whole value into
   * one sum.
   */

  // some magic numbers

  int ones = 0x55 + (0x55 << 8) + (0x55 << 16) + (0x55 << 24); // 01010101...
  int twos = 0x33 + (0x33 << 8) + (0x33 << 16) + (0x33 << 24); // 00110011...
  int fours = 0x0f + (0x0f << 8) + (0x0f << 16) + (0x0f << 24); // 00001111...
  int eights = 0xff + (0xff << 16); // 0000000011111111...
  int sixteens = 0xff + (0xff << 8); // 00000000000000001111111111111111

  // the basic idea here is to add zeros in groups
  // so &-ing then shifting right and &-ing again will give # of
  // zeros in right and left halves of group, respectively
  result = (x & ones) + ( (x >> 1) & ones );
  result = (result & twos) + ( ( result >> 2 ) & twos );
  result = (result + ( result >> 4 )) & fours ;
  result = (result + ( result >> 8 )) & eights ;
  result = (result + ( result >> 16 )) & sixteens ;
  // result = (result & fours) + ( ( result >> 4 ) & fours );
  // result = (result & eights) + ( ( result >> 8 ) & eights );
  // result = (result & sixteens) + ( ( result >> 16 ) & sixteens );

  return result;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* same as isNonZero but return opposite result */
  // make the leftmost bit 1
  // the complement x + 1 = -x (~x + 1 = -x)
  // the complement of 0 + 1 = 0 (~0 + 1 = 0)
  // so the first bit of either x or ~x + 1 must be 1
  // unless x is 0
  int y = x | (~x + 1);
  // flip the leading bit
  y = ~y;
  // put the leading bit into the rightmost position
  y = y >> 31;
  // eliminate all leading bits
  return y & 1;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  /*
   * similar approach to bitCount. xor preserves parity, so just xor
   * bits 1 & 2, then the first two bits with the second two, etc. until
   * there is just one parity bit left.
   */

  // xoring two bits returns # of 1s % 2 in those two bits
  // so just xor every bit with the bit to its right
  // then those bits with the 2nd bit to the right
  // then the 4th to the right etc.
  // until you xor a bit with the 16th to its right
  // then the result is stored in the LSB
  x = x ^ (x >> 1);
  x = x ^ (x >> 2);
  x = x ^ (x >> 4);
  x = x ^ (x >> 8);
  x = x ^ (x >> 16);
  return x & 1;
}

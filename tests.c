/* Testing Code */

#include <limits.h>
//
// 15 problems, 40 points
// 2 - rating 1
// 3 - rating 2
// 7 - rating 3
// 3 - rating 4

// rating 1
int test_isZero(int x) {
  return x == 0;
}
int test_bitAnd(int x, int y)
{
  return x&y;
}
// rating 2
int test_fitsBits(int x, int n)
{
  int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
}
int test_getByte(int x, int n)
{
  union {
    int word;
    unsigned char bytes[4];
  } u;
  int test = 1;
  int littleEndian = (int) *(char *) &test;
  u.word = x;
  return littleEndian ? (unsigned) u.bytes[n] : (unsigned) u.bytes[3-n];
}
int test_isNotEqual(int x, int y)
{
  return x != y;
}
int test_bitXor(int x, int y)
{
  return x^y;
}
int test_copyLSB(int x)
{
  return (x & 0x1) ? -1 : 0;
}
// rating 3
int test_sum3(int x, int y, int z)
{
  return x+y+z;
}
int test_reverseBytes(int x)
{
  union U {
    int result;
    char byte[4];
  };
  union U u;
  int temp;
  u.result = x;
  temp = u.byte[0];
  u.byte[0] = u.byte[3];
  u.byte[3] = temp;
  temp = u.byte[1];
  u.byte[1] = u.byte[2];
  u.byte[2] = temp;
  return u.result;
}
int test_isNegative(int x) {
  return x < 0;
}
int test_isLess(int x, int y)
{
  return x < y;
}
// rating 4
int test_isNonZero(int x)
{
  return x!=0;
}
int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}
int test_bang(int x)
{
  return !x;
}
int test_bitParity(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result ^= (x >> i) & 0x1;
  return result;
}

//Author information
//  Author name: Floyd Holliday
//  Author email: holliday@fullerton.edu
//Course information
//  Course number: CPSC240
//  Assignment number: 11
//  Due date: 2014-Jan-17
//Project information
//  Project title: High performance summation
//  Purpose: Add 4 doubles in a single ymm register using a minimal number of instuction.
//  Status: No known errors
//  Project files: computeymmsumdriver.cpp, computeymmsum.asm, debug.inc, debug.asm
//Module information
//  This module's call name: sumymm .  This module is invoked by the user
//  Language: X86-64
//  Syntax: Intel
//  Date last modified: 2014-Jan-15
//  Purpose: This module is the top level driver: it will call computeymmsum
//  File name: computeymmsumdriver.cpp
//  Status: In production.  No known erros.
//  Future enhancements: None planned
//Translator information
//  Gnu compiler: g++ -c -m64 -Wall -l computeymmsumdriver.lis -o computeymmsumdriver.o computeymmsumdriver.cpp
//  Gnu linker:   g++ -m64 -o sumymm.out computeymmsumdriver.o computeymmsum.o debug.o
//References and credits
//  No references: this module is standard C++
//Print information
//  Page width: 136 columns
//  Begin comments: 61
//  Optimal print specification: Landscape, 9 points or smaller, monospace, 8½x11 paper
//
//===== Begin code area =============================================================================================================

#include <stdio.h>
#include <stdint.h>
#include <ctime>
#include <cstring>

extern "C" double computeymmsum();

int main(){

  double return_code = -99.99;

  printf("%s","Welcome to a high performance demonstration of summing 4 quads in residing in the same register. \n");
  return_code = computeymmsum();
  printf("%s%1.18lf%s\n","The value returned to the driver is. ",return_code,
         ".  The driver will now return 0 to the operating system.  Bye.");

  return 0;

}//End of main


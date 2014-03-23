//Author information
//  Author name: Floyd Holliday
//  Author email: holliday@fullerton.edu
//Course information
//  Course number: CPSC240
//  Assignment number: 6
//  Due date: 2014-Feb-17
//Project information
//  Project title: Floating Point Input and Output
//  Purpose: Demonstrate to the Cpsc240 class the operations of input and output of 64-bit floating point numbers.
//  Status: No known errors.
//  Project files: fp-io-driver.cpp, fp-io.asm
//Module information
//  This module's call name: fpio.  This module is invoked by the user
//  Language: C++
//  Date last modified: 2014-Jan-14
//  Purpose: This module is the top level driver: it will call floating_point_io
//  File name: computeymmsumdriver.cpp
//  Status: In production.  No known erros.
//  Future enhancements: None planned
//Translator information
//  Gnu compiler: g++ -c -m64 -Wall -l fp-io-driver.lis -o fp-io-driver.o fp-io-driver.cpp
//  Gnu linker:   g++ -m64 -o fpio.out fp-io-driver.o fp-io.o 
//References and credits
//  No references: this module is standard C++
//Format information
//  Page width: 139 columns
//  Begin comments: 61
//  Optimal print specification: Landscape, 9 points or smaller, monospace, 8½x11 paper
//
//===== Begin code area ===================================================================================================================

#include <stdio.h>
#include <stdint.h>
#include <ctime>
#include <cstring>

extern "C" double floating_point_io();

int main(){

  double return_code = -99.99;

  printf("%s","Welcome to Floating Point Input/Output. \n");
  return_code = floating_point_io();
  printf("%s%1.18lf%s\n","The driver received return code ",return_code,
         ".  The driver will now return 0 to the OS.  Bye.");

  return 0;

}//End of main


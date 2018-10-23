//*****************************************************************
// FILE:      assign2.cpp
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Wednesday, 9/27/2017 by 11:59 pm
// 
// PURPOSE:   main program, but is small since most of our code is
//            embedded in the classes we wrote
//*****************************************************************

#include "ProviderDB.h"
#include <cstring>
#include <string>

int main() {
  char fileName[] = "providerdb";
  ProviderDB providers(fileName);
  
  providers.print();

  providers.sortByProviderNumber();
  providers.print();

  providers.sortBySpecialty();
  providers.print();

  providers.sortByName();
  providers.print();

  return 0;
}

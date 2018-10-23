//*****************************************************************
// FILE:      assign3.cpp
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Tuesday, 10/10/2017 by 11:59 pm
// 
// PURPOSE:   main program, but is small since most of our code is
//            embedded in the classes we wrote
//*****************************************************************

#include "ProviderDB.h"
#include <cstring>
#include <string>

int main() {
  char fileName[] = "providerdb";
  char transFileName[] = "transactions.txt";
  
  ProviderDB providers(fileName);

  providers.processTransactions(transFileName);
  
  return 0;
}

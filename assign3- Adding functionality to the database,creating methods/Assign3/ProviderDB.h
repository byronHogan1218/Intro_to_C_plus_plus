//*****************************************************************
// FILE:      ProviderDB.h
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Tuesday, 10/10/2017 by 11:59 pm
// 
// PURPOSE:   Declaration for the ProviderDB class, which represents 
//            a database of Provider objects
//*****************************************************************
#ifndef PROVIDERDB_H
#define PROVIDERDB_H

#include "Provider.h"

class ProviderDB {
  //Data Members
  private:
    Provider providers[40];
    int numProviders;
  
  public:
    ProviderDB();
    ProviderDB(char*);

    void print() const;

    void sortByProviderNumber();
    void sortBySpecialty();
    void sortByName();
    void sort(bool (*compare)(const Provider&, const Provider&));
    
    void processTransactions(char*);
    void processSpecialty(char*);
    void processNumber(char*);

    int searchForProviderNumber(char*);
};

#endif

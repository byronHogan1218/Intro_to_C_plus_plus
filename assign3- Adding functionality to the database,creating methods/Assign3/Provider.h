//*****************************************************************
// FILE:      Provider.h
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  day, 10/10/2017 by 11:59 pm
// 
// PURPOSE:   header file for the Provider class, which represents 
//            information about a health care provider.
//*****************************************************************
#ifndef PROVIDER_H
#define PROVIDER_H

class Provider {
  //Data Members
  private:
    // C Strings
    char pNumber[7]{};
    char specialty[41]{};
    char name[41]{};
    char address1[41]{};
    char address2[31]{};
    char city[21]{};
    char state[3]{};
    char zip[6]{};
    char phoneNum[15]{};

  public:
    //Class Method Initialization
    Provider();
    void set_values (char *, char *, char *,
                     char *, char *, char *,
                     char *, char *, char *);
    void print() const;
    const char* getProviderNumber() const;
    const char* getSpecialty() const;
    const char* getName() const;
};

#endif

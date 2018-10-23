 #ifndef PROVIDERDB_H
   #define PROVIDERDB_H
#include"provider.h"
   //*****************************************************************
   // FILE:      ProviderDB.h
   // AUTHOR:    Byron Hogan
   // LOGON ID:  z1825194
   // DUE DATE:  9-26-17
   // 
   // PURPOSE:   Declaration for the Provider class database, which represents 
   //            information about a health care provider.
   //*****************************************************************



   class providerDB
      {
	private:
	provider providerArray[40];
	int size;
	public:
	providerDB();
	providerDB(const char*);
	void  print()const;
	void sortByProviderNumber();
	void sortBySpecialty();
	void sortByName();
    };

   #endif

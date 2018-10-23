   #ifndef PROVIDER_H
   #define PROVIDER_H

   //*****************************************************************
   // FILE:      provider.h
   // AUTHOR:    Byron Hogan
   // LOGON ID:  Z1825194
   // DUE DATE:  9/26/17
   // 
   // PURPOSE:   Declaration for the Provider class, which represents 
   //            information about a health care provider.
   //*****************************************************************
	#include<cstring>

   class provider
      {
        private:
                char providerNum[7]={'\0'};
                char specialty[41]={'\0'};
		char name[41]={'\0'};
                char addressP1[41]={'\0'};
                char addressP2[31]={'\0'};
                char city[21]={'\0'};
                char state[3]={'\0'};
                char zip[6]={'\0'};
                char phoneNum[15]={'\0'};

        public:
                provider();
                void printFile() const;
		const char* getProviderNum();
		const char* getSpecialty();
		const char* getName();


};


   #endif

#include <Windows.h>
#include <winnt.h>
#include <iostream>

using namespace std;

void methodCall(long accessMask){

    int permList[] = {DELETE,READ_CONTROL,WRITE_DAC,WRITE_OWNER,SYNCHRONIZE,STANDARD_RIGHTS_REQUIRED,STANDARD_RIGHTS_READ,STANDARD_RIGHTS_WRITE,STANDARD_RIGHTS_EXECUTE,STANDARD_RIGHTS_ALL,SPECIFIC_RIGHTS_ALL};
    string permListString[] = {"DELETE","READ_CONTROL","WRITE_DAC","WRITE_OWNER","SYNCHRONIZE","STANDARD_RIGHTS_REQUIRED","STANDARD_RIGHTS_READ","STANDARD_RIGHTS_WRITE","STANDARD_RIGHTS_EXECUTE","STANDARD_RIGHTS_ALL","SPECIFIC_RIGHTS_ALL"};
        
    for(int iter=0;iter<11;iter++){
        if((accessMask & permList[iter]) == permList[iter])
            cout<<permListString[iter]<<endl;
    }
}

void listAccess(long accessMask){
            methodCall(accessMask);
}



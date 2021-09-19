#include <iostream>
#include <fileapi.h>
#include <aclapi.h>
#include <strsafe.h>

using namespace std;

int main(){

//Create handle for object access
 string path = "E:\\Folder";
 LPCSTR filePath = &path[0];
 HANDLE hFile = CreateFileA(filePath,GENERIC_READ|GENERIC_WRITE,0,0,OPEN_ALWAYS,0,0);

//returns security info DACL
 PSECURITY_DESCRIPTOR psd=NULL; 
 PACL pacl=NULL;
 DWORD getSecurityInfoStatus = GetSecurityInfo(hFile,SE_FILE_OBJECT,DACL_SECURITY_INFORMATION,NULL,NULL,&pacl,NULL,&psd);

 cout<<(*pacl).AceCount<<endl;

ACCESS_ALLOWED_ACE* pace =NULL;

for(int i=0;i<pacl->AceCount;i++){
    //ACE info
    if(!GetAce(pacl,i,(LPVOID*)&pace)){
        cout<<"Getace failed"<<endl;
    }

    //SID to account Name Lookup
    LPWSTR accountName = new WCHAR[256*sizeof(DWORD)];
    unsigned long int cchNameVal = 256UL;
    LPDWORD cchName = &cchNameVal;
    LPWSTR referencedDomainName = new WCHAR[256*sizeof(DWORD)];
    unsigned long int cchReferencedDomainNameVal = 256UL;
    LPDWORD cchReferencedDomainName = &cchReferencedDomainNameVal;
    SID_NAME_USE peUse;

    if(!LookupAccountSidW(NULL,&pace->SidStart,accountName,cchName,referencedDomainName,cchReferencedDomainName,&peUse)){
        cout<<"SID lookup failed"<<endl;
    }
    
    wcout<<accountName<<endl;
    wcout<<referencedDomainName<<endl;

    }
}



}
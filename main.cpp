#include <iostream>
#include <string.h>

using namespace std;

void vocalic(const char s[101], char *sv)
{
    char v[]="aeoiu";
    int l=strlen(s);
    strcpy(sv,s);
    int i=0;
    while(i<strlen(sv))
    {
        if((strchr(v,sv[i])!=0)&&(strchr(" ",sv[i])==0))
            strcpy(sv+i, sv+i+1);
        else
            i++;
    }
}
int idem(char *c)
{
    char *p, cuv[101][35];
    int nrc=0;
    p=strtok(c," ");
    while(p)
    {
        strcpy(cuv[nrc],p);
        p=strtok(NULL, " ");
        nrc++;
    }
    for(int i=0; i<nrc;i++)
        for(int j=i+1; j<=nrc;j++)
            if((i!=j)&&strcmp(cuv[i],cuv[j])==0)
                return 1;
    return 0;
}
int main()
{
    char sir[101], sv[101];
    cin.getline(sir,101);
    vocalic(sir,sv);
    if (idem(sv))
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}

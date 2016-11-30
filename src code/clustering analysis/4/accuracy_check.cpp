#include<bits/stdc++.h>
using namespace std;

map<string,int>M;

int main()
{
cout<<fixed;
cout.precision(2);
FILE *fp1,*fp2;
fp1=fopen("ansfile.txt","r");
fp2=fopen("outputfile.txt","r");
char s[10000];
int found=0,notfound=0;
int t=0;
for(int i=1;i<=2800;i++)
{
++t;
fscanf(fp1,"%s",s);
string A(s);
fscanf(fp2,"%s",s);
string B(s);
//cout<<A<<" "<<B<<endl;
if(A==B)
found++;
else
{
cout<<t<<endl;
notfound++;
}
//memset(s,'\0',sizeof(s));
}
int total=found+notfound;
//assert(t==total);
//cout<<"fuckyou"<<endl;
cout<<"found : "<<found<<", not found : "<<notfound<<", total : "<<total<<endl;
double accuracy=100.00*(double)found/(double)total;
cout<<accuracy<<"%"<<endl;
return 0;
}

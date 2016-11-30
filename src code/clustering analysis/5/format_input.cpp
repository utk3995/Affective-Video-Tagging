#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,vector<double> > >ANS;

int main()
{
FILE *fp1=fopen("featurefile.txt","w");
FILE *fp2=fopen("tagfile.txt","w");
FILE *fp3=fopen("testfile.txt","w");
FILE *fp4=fopen("ansfile.txt","w");
FILE *fp5=fopen("feature_vector_our_11.txt","r");
FILE *fp6=fopen("cluster.txt","r");
FILE *fp7=fopen("filename.txt","w");
for(int i=0;i<9800;i++)
{
int d;
fscanf(fp6,"%d",&d);
vector<double>temp;
for(int i=1;i<=11;i++)
{
double d;
fscanf(fp5,"%lf",&d);
temp.push_back(d);
}
ANS.push_back(make_pair(make_pair(d,i),temp));
}
random_shuffle(ANS.begin(),ANS.end());
assert(ANS.size()==9800);
for(int i=0;i<ANS.size();i++)
if(i<7000)
{
fprintf(fp7,"%d\n",ANS[i].first.second);
fprintf(fp2,"%d\n",ANS[i].first.first);
vector<double>temp=ANS[i].second;
for(auto j:temp)
fprintf(fp1,"%lf ",j);
fprintf(fp1,"\n");
}
else
{
fprintf(fp7,"%d\n",ANS[i].first.second);
fprintf(fp4,"%d\n",ANS[i].first.first);
vector<double>temp=ANS[i].second;
for(auto j:temp)
fprintf(fp3,"%lf ",j);
fprintf(fp3,"\n");
}
return 0;
}

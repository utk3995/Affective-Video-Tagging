#include<bits/stdc++.h>
using namespace std;

const int MAX=2500;
const int win_sz=3;
const double alpha=.7;
int image[MAX][MAX];
bool binary_image[MAX][MAX];
pair<double,int>loglikelihod[MAX][MAX];
unordered_map<int,int>M1,M2;
int l[52][MAX][MAX];
const int dx[]={1,-1};
const int dy[2][1]={{1},{-1}};
int conv1[MAX][MAX],conv2[MAX][MAX];
double ux[MAX],uy[MAX],X1,X2,Y1,Y2;
double temp[MAX][MAX],Temp[MAX][MAX];
double f1[MAX*10],f2[MAX*10],f00[MAX*10],f01[MAX*10];
#define inf 1000000000
double dof;
int conv00[MAX][MAX],conv01[MAX][MAX];
int global;
double yyy;
double maxii;

bool valid(int x,int y,int n,int m)
{
if(x<0||x>=n||y<0||y>=m)
return false;
return true;
}

double pxk(int i)
{
double x=f2[i];
double y=X2*Y2;
return x/y;
}

double pyk(int i)
{
double x=f1[i];
double y=X1*Y1;
return x/y;
}

double px1(int i)
{
double x=f01[i];
double y=X2*Y2;
return x/y;
}

double py1(int i)
{
double x=f00[i];
double y=X1*Y1;
return x/y;
}

double KLx(int x,int y)
{
if(conv2[x][y]==0)
return 0;
double p=pxk(conv2[x][y]);
double q=px1(conv01[x][y]);
double kl=p*(log10(p)-log10(q));
maxii=max(maxii,log10(p)-log10(q));
return kl;
}

double KLy(int x,int y)
{
if(conv1[x][y]==0)
return 0;
double p=pyk(conv1[x][y]);
double q=py1(conv00[x][y]);
double kl=p*(log10(p)-log10(q));
maxii=max(maxii,log10(p)-log10(q));
return kl;
}

void generate_loglikelihood(int n,int m,int k)
{
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
{
temp[i][j]=0;
Temp[i][j]=0;
for(int dx=-2;dx<=2;dx++)
for(int dy=-2;dy<=2;dy++)
{
int nx=i+dx;
int ny=j+dy;
if(!valid(nx,ny,n,m))
continue;
temp[i][j]+=log10(pxk(conv1[nx][ny]))+log10(pyk(conv2[nx][ny]));
Temp[i][j]+=KLx(nx,ny)+KLy(nx,ny);
}
if(temp[i][j]>loglikelihod[i][j].first)
loglikelihod[i][j]=make_pair(temp[i][j],k);
dof+=Temp[i][j];
}
}

///conv1 : I*fk*dy
///conv2 : I*fk*dx
///conv00 -> conv1
///conv01 -> conv2
void convolve(int n,int m,int k)
{
int Ma=n;
int Na=m;
int Mb=2;
int Nb=1;
for(int m=0;m<Ma;m++)
for(int n=0;n<Na;n++)
for(int i=m;i<Mb+m;i++)
for(int j=n;j<Nb+n;j++)
conv1[i][j]=conv1[i][j]+image[m][n]*dy[i-m][j-n];
X1=Ma+Mb;
Y1=Na+Nb;
for(int i=0;i<Ma+Mb;i++)
for(int j=0;j<Na+Nb;j++)
{
conv1[i][j]=abs(conv1[i][j]);
M1[conv1[i][j]]++;
if(k==1)
conv00[i][j]=abs(conv1[i][j]);
}
Mb=1;
Nb=2;
for(int m=0;m<Ma;m++)
for(int n=0;n<Na;n++)
for(int i=m;i<Mb+m;i++)
for(int j=n;j<Nb+n;j++)
conv2[i][j]=conv2[i][j]+image[m][n]*dx[j-n];
X2=Ma+Mb;
Y2=Na+Nb;
for(int i=0;i<Ma+Mb;i++)
for(int j=0;j<Na+Nb;j++)
{
conv2[i][j]=abs(conv2[i][j]);
if(k==1)
conv01[i][j]=abs(conv2[i][j]);
M2[conv2[i][j]]++;
}
for(auto j:M1)
{
if(k==1)
f00[j.first]=j.second;
f1[j.first]=j.second;
}
for(auto j:M2)
{
if(k==1)
f01[j.first]=j.second;
f2[j.first]=j.second;
}
generate_loglikelihood(n,m,k);
}

pair<int,int>get_range(int m,double *u)
{
vector<int>x;
vector<int>y;
double E=accumulate(u,u+m,0);
double req=E*(1.00-alpha)/2.00;
for(int i=0,sum=0;i<m;i++)
{
sum+=u[i];
x.push_back(sum);
}
for(int i=m-1,sum=0;i>=0;i--)
{
sum+=u[i];
y.push_back(sum);
}
reverse(y.begin(),y.end());
int x1,x2;
for(int i=0;i<x.size();i++)
if(x[i]<=req)
x1=i;
for(int i=y.size()-1;i>=0;i--)
if(y[i]<=req)
x2=i;
return make_pair(x1,x2);
}

double calculate_composition(double n,double m,pair<int,int>X,pair<int,int>Y)
{
pair<double,double>centroid=make_pair((double)(X.first+X.second)/2.00,(double)(Y.first+Y.second)/(2.00));
double cmp=inf;
double cx[5],cy[5];
cx[1]=cx[2]=m/3.00;
cx[3]=cx[4]=2.00*cx[1];
cy[1]=cy[3]=n/3.00;
cy[2]=cy[4]=2.00*cy[1];
for(int i=1;i<=4;i++)
cmp=min(cmp,sqrt((cx[i]-centroid.first)*(cx[i]-centroid.first)/(m*m)+(cy[i]-centroid.second)*(cy[i]-centroid.second)/(n*n)));
return cmp;
}

double magic(int n,int m)
{
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
if(loglikelihod[i][j].second==1)
binary_image[i][j]=true;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
ux[i]+=binary_image[i][j];
for(int j=0;j<m;j++)
for(int i=0;i<n;i++)
uy[j]+=binary_image[i][j];
pair<int,int>X=get_range(m,uy);
pair<int,int>Y=get_range(n,ux);
return calculate_composition(n,m,X,Y);
///cout<<"X1 : "<<X.first<<" X2 : "<<X.second<<endl;
///cout<<"Y1 : "<<Y.first<<" Y2 : "<<Y.second<<endl;
}

int main()
{
FILE *fpr,*fpw;
fpr=fopen("datafile.txt","r");
fpw=fopen("features.txt","a+");
for(int i=0;i<MAX;i++)
for(int j=0;j<MAX;j++)
loglikelihod[i][j].first=-inf;
int c;
int y=0;
clock_t tStart=clock();
int n,m;
//while(cin>>c)
while(fscanf(fpr,"%d",&c)!=EOF)
{
y++;
M1.clear();M2.clear();
int k=c;
fscanf(fpr,"%d%d",&n,&m);
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
fscanf(fpr,"%d",&image[i][j]);
convolve(n,m,y);
}
//cout<<maxii<<endl;
//printf("Time taken: %.2fs\n",(double)(clock()-tStart)/CLOCKS_PER_SEC);
double composition=magic(n,m);
fprintf(fpw,"%lf %lf\n",composition,dof);
cout<<"Depth Of Field is : "<<dof/1000.0<<endl;
fclose(fpr);
fclose(fpw);
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){

 string line;
ofstream dome("ss_0-9000.txt");
for(int i=0;i<9001;i++){
string name;
 name="ACCEDE0"+to_string(i)+".wav.spectralslope.csv";
ifstream myfile (name);
double cnt=0,cnt1;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
      getline (myfile,line);
     	cnt++;
  }
    myfile.close();
cout<<i;
ifstream myfile(name);
double sum=0,x;
cnt1=cnt;
while(cnt>0){
myfile>>x;
sum+=x;
cnt--;
}	
sum/=cnt1;
dome<<sum<<endl;
}
}

ofstream dome1("sf_0-9000.txt");
for(int i=0;i<9001;i++){
string name;
 name="ACCEDE0"+to_string(i)+".wav.spectralflatness.csv";
ifstream myfile (name);
double cnt=0,cnt1;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
      getline (myfile,line);
     	cnt++;
  }
    myfile.close();
cout<<i;
ifstream myfile(name);
double sum=0,x;
cnt1=cnt;
while(cnt>0){
myfile>>x;
sum+=x;
cnt--;
}	
sum/=cnt1;
dome1<<sum<<endl;
}
}

ofstream dome2("zcr_0-9000.txt");
for(int i=0;i<9001;i++){
string name;
 name="ACCEDE0"+to_string(i)+".wav.zcr.csv";
ifstream myfile (name);
double cnt=0,cnt1;
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
      getline (myfile,line);
     	cnt++;
  }
    myfile.close();
cout<<i;
ifstream myfile(name);
double sum=0,x;
cnt1=cnt;
while(cnt>0){
myfile>>x;
sum+=x;
cnt--;
}	
sum/=cnt1;
dome2<<sum<<endl;
}
}


}

/*alexok2006*/
#include <bits/stdc++.h>

//#include <conio.h>

#define all(x) x.begin(),x.end()
#define ll long long
#define LLM (ll)(10e17)
#define ld long double
#define pp pair<int,int>
using namespace std;

int noteq(string a1,string a2)
{
string p1,p2;
for(int i=0;i<a1.size();i++)
 if(a1[i]=='\n') a1[i]=' ';

for(int i=0;i<a2.size();i++)
 if(a2[i]=='\n') a2[i]=' ';

for(int i=0;i<a1.size();i++)
 if(a1[i]==' ')
  {
   if(!i||a1[i-1]!=' ') p1+=' ';
  }
 else p1+=a1[i];

for(int i=0;i<a2.size();i++)
 if(a2[i]==' ')
  {
   if(!i||a2[i-1]!=' ') p2+=' ';
  }
 else p2+=a2[i];

return p1!=p2;
}

signed main(int argv, char* argc[])
{
if(argv<=3) {cout<<"need more args!";return 0;}

int QTEST = 20;
cin>>QTEST;

string gen = argc[1];
string stu = argc[2];
string umn = argc[3];

//  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

srand(time(0));

for(int i=0;i<QTEST;i++)
{
cout<<"#"<<i<<endl;

int seed=rand();
system( ("./"+gen+" "+to_string(seed)+" >test").c_str() );
system( ("./"+stu+" >out1 <test").c_str() );
system( ("./"+umn+" >out2 <test").c_str() );

string ans_stu,ans_umn;
ifstream fstu("out1"),fumn("out2");

string pl;
while(fstu>>pl) ans_stu+=pl+'\n'; fstu.close();
while(fumn>>pl) ans_umn+=pl+'\n'; fumn.close();


if( noteq(ans_stu,ans_umn) )
{
FILE* f = fopen("test","r");
string test;
char tmp[128];

while(fgets(tmp,128,f))
 test+=string(tmp);
fclose(f);

//SetConsoleTextAttribute(hConsole, 11);
//////////////////////////////////////////system("color 11");
cout<<test<<endl;

//SetConsoleTextAttribute(hConsole, 10);
/////////////////////////////////////////system("color 10");
cout<<"good:\n"<<ans_stu<<endl;;
//SetConsoleTextAttribute(hConsole, 11);
///////////////////////////////////system("color 11");
cout<<"--------"<<endl;;

//SetConsoleTextAttribute(hConsole, 12);
///////////////////////////////////////////////system("color 12");
cout<<"bad:\n"<<ans_umn<<endl;

return 0;
} 

}

//SetConsoleTextAttribute(hConsole,26);
///////////////////////////////////////system("color 26");

cout<<endl<<endl<<"              |OK. All tests accepted|"<<endl<<endl;
}

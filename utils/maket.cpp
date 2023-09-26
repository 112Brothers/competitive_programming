#include <bits/stdc++.h>


using namespace std;

int main(int argv,char *argc[])
{
if(argv<2) {cout<<"Few args"<<endl;return 0;}

string name = argc[1];
name+=".cpp";

FILE *in=fopen("THIS IS PATH TO TO YOUR TEMPLATE","r");
string f;
char temp[1024];
while(fgets(temp,1023,in)) f+=temp;
fclose(in);
FILE *out=fopen(name.c_str(),"w");
fprintf(out,"%s",f.c_str());
fclose(out);
}

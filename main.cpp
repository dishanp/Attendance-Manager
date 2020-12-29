#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include<algorithm>
int main()
{   char rno[8];
    char ch[200];
    long int present[100]={0};
    long int all[100]={0};
    char prev[8];
    int j=0;
    ofstream fout;
    //FIRST,STORING ALL ROLL NOS IN AN ARRAY all:
    ifstream fin1;
    fin1.open("ALL.txt");
    while(fin1)
    {
        fin1>>ch;
        if(ch[0]=='1' && ch[1]=='9')
        {
            for(int i=0;i<8;i++)
            {
                if((int)ch[i]>=48 && (int)ch[i]<=57)
                {
                rno[i]=ch[i];
                }
            }
            if(strcmp(rno,prev))
            {
            all[j]=atoi(rno);
            j++;
            }
            strcpy(prev,rno);
            continue;
        }
}
    sort(all,all+100);
    fin1.close();
    //All roll nos stored in array all
    ifstream fin;
    fin.open("ZOOM.txt");
    fout.open("ATTENDANCE.txt");
    j=0;
    while(fin)
    {
        fin>>ch;
        if(ch[0]=='1' && ch[1]=='9')
        {
            for(int i=0;i<8;i++)
            {
                if((int)ch[i]>=48 && (int)ch[i]<=57)
                {
                rno[i]=ch[i];
                }
            }
            if(strcmp(rno,prev))
            {
            present[j]=atoi(rno);
            j++;
            }
            strcpy(prev,rno);
            continue;
        }
}
sort(present,present+100);
fout<<endl<<endl;fout<<endl<<endl;
fout<<"------------------------------ TODAY'S ATTENDANCE REPORT: -------------------------------"<<endl;
fout<<endl<<endl;
fout<<"------------------------------------ ABSENTEES: -----------------------------------------"<<endl;
int check;
int ab=0;
for(int i=0;i<100;i++)
{
    check=-1;
    for(int j=0;j<100;j++)
    {
        if(all[i]==present[j])
        check=1;
    }
    if(check==-1)
    {
    ab++;
    fout<<all[i]<<endl;
    }
}
fout<<endl<<endl;
fout<<"------------------------------------ SUMMARY: -----------------------------------------"<<endl;
fout<<"TOTAL: "<<84<<endl;
fout<<"PRESENT: "<<(84-ab)<<endl;
fout<<"ABSENT: "<<ab<<endl;
    fin.close();
    fout.close();
    return 0;
}
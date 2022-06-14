#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
static int p=0;
class resv
{
char busn[10],driver[20],arrival[5],depart[5],from[20],to[20],
seat[8][4][10];
public:
void install();
void reservation();
void empty();
void show();
void available();
void position(int i);
void print();
}bus[15];
void vline(char ch)
{
for (int i=80;i>0;i--)
cout<<ch;
}
void resv::install()
{
clrscr();
cout<<"Enter bus no: ";
gets(bus[p].busn);
cout<<"Enter Driver's name: ";
gets(bus[p].driver);
cout<<"Departure: ";
gets(bus[p].depart);
cout<<"Arrival time: ";
gets(bus[p].arrival);
cout<<"From: ";
gets(bus[p].from);
cout<<"To: ";
gets(bus[p].to);
bus[p].empty();
p++;
}
void resv::reservation()
{
clrscr();
int seat;
char number[5];
top:
cout<<"===============\n";
cout<<"Bus no: \n";
cout<<"===============\n";
gotoxy(9,2);cin>>number;
int n;
for(n=0;n<=p;n++)
{
if(strcmp(bus[n].busn,number)==0)
break;
}
while(n<=p)
{
clrscr();
position(n);
cout<<"\nSeat number: ";
cin>>seat;
if (seat>32)
{
cout<<"There are only 32 seats available in this bus.";
}
else
{
if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
{
cout<<"Enter passanger's name: ";
cin>>bus[n].seat[seat/4][(seat%4)-1];
break;
}
else
cout<<"The seat no. is already reserved.\n";
}
}
if (n>p)
{
cout<<"Enter correct bus no.\n";
goto top;
}
}
void resv::empty()
{
for(int i=0;i<8;i++)
{
for(int j=0;j<4;j++)
{
strcpy(bus[p].seat[i][j],"Empty");
}
}
}
void resv::show()
{
clrscr();
int n;
char number[5];
cout<<"Enter bus no: ";
cin>>number;
for(n=0;n<=p;n++)
{
if(strcmp(bus[n].busn,number)==0)
break;
}
while (n<=p)
{
vline('-');
cout<<"Bus no: "<<bus[n].busn
<<"\nDriver: "<<bus[n].driver<<"\nDeparture time: "
<<bus[n].depart<<"\nArrival time: "<<bus[n].arrival
<<"\nFrom: "<<bus[n].from<<"\nTo: "<<
bus[n].to<<"\n";
vline('-');
bus[0].position(n);
int a=1;
for (int i=0;i<8;i++)
{
for(int j=0;j<4;j++)
{
a++;
if(strcmp(bus[n].seat[i][j],"Empty")!=0)
cout<<"\nThe seat no "<<a-1<<" is reserved for "<<bus[n].seat[i][j]<<".";
}
}break;
}	if(n>p)
cout<<"Enter correct bus no.";
getch();
}
void resv::position(int l)
{
int s=0,p=0;
for(int i=0;i<8;i++)
{
cout<<"\n";
for(int j=0;j<4;j++)
{
s++;
if(strcmp(bus[l].seat[i][j],"Empty")==0)
{
cout.width(5);
cout.fill(' ');
cout<<s<<".";
cout.width(10);
cout.fill(' ');
cout<<bus[l].seat[i][j];
p++;
}
else
{
cout.width(5);
cout.fill(' ');
cout<<s<<".";
cout.width(10);
cout.fill(' ');
cout<<"RESERVE";
}
}
}
cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void resv::available()
{
for(int n=0;n<p;n++)
{
vline('-');
cout<<"Bus no: "<<bus[n].busn<<"\nDriver: "<<bus[n].driver<<"\nArrival time: "<<bus[n].arrival<<"\nDeparture Time: "<<bus[n].depart<<"\nFrom: "<<bus[n].from<<"\nTo: "<<bus[n].to<<"\n";
vline('-');
vline('.');
}
getch();
}
void resv::print()
{
int seat,j;

char number[5];
char filename[12]={"TB"};
top:
cout<<"\nBus no: ";
cin>>number;
int n;
for(n=0;n<=p;n++)
{
if(strcmp(bus[n].busn,number)==0)
break;}
if(n>p)
{
cout<<"Enter correct bus no.\n";
goto top;}
else{
FILE*stream;
strcat(filename,number);
strcat(filename,".txt");
	if((stream=fopen(filename,"w"))==NULL)
	{
		printf("\nError-cannot create file.");
		getch();
		exit(1);
	 }
for(int u=1;u<=50;u++){
	fprintf(stream,"-");}
fprintf(stream,"\nBus no: \t%s",bus[n].busn);
fprintf(stream,"\n Driver: \t%s",bus[n].driver);
fprintf(stream,"\n Departure time:%s",bus[n].depart);
fprintf(stream,"\n Arrival time:\t%s",bus[n].arrival);
fprintf(stream,"\n From:\t%s",bus[n].from);
fprintf(stream,"\n To:\t%s\n",bus[n].to);
for(int r=1;r<=50;r++)
		{fprintf(stream,"-");}
int a=1;
for (int i=0;i<8;i++)
{
for(int j=0;j<4;j++)
{
a++;
if(strcmp(bus[n].seat[i][j],"Empty")!=0){
fprintf(stream,"\n The seat no: %d",a-1);
fprintf(stream,"\n Reserved by: %s\n",bus[n].seat[i][j]);
}
}
}
	for(int e=1;e<=50;e++) {
	fprintf(stream,"-");}
	fclose(stream);
	cout<<"Reserved Ticket has been Printed in a Text File.";
	getch();
}
}
int main()
{
clrscr();
int ch;
while(1)
{clrscr();
vline('~');
cout<<"=======================\n";
cout<<"BUS EASY TRANSPORTATION\n";
cout<<"=======================\n";
cout<<"\n1.Install\n2.Reservation\n3.Show \n4.Buses Available. \n5.Print Ticket \n6.Exit\n";
cout<<"\n=======================";
cout<<"\nEnter your choice: ";
cout<<"\n=======================";
gotoxy(20, 14);cin>>ch;
switch(ch)
{
case 1:
bus[p].install();
break;
case 2:
bus[p].reservation();
break;
case 3:
bus[0].show();
break;
case 4:
bus[0].available();
break;
case 5:
bus[0].print();
break;
case 6:
exit(0);
}
}
}

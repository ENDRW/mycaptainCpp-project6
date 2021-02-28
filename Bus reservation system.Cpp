#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
static int p=0;
class a
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
}

bus[10];
void vline(char ch)
{
    for(int i=50;i>0;i--)
    cout<<ch;
}
void a::install()
{
    cout<<"Enter bus no: ";
    cin>>bus[p].busn;
    cout<<"\nEnter driver's name: ";
    cin>>bus[p].driver;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture: ";
    cin>>bus[p].depart;
    cout<<"\nFrom: \t\t\t";
    cin>>bus[p].from;
    cout<<"\nTo: \t\t\t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat;
    char number[5];
    top;
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn, number)==0)
        break;
    }
    while(n<=p)
    {
        cout<<"\n Seat Number: ";
        cin>>seat;
        if(seat>32)
        {
            cout<<"\nThere are ony 32 seats avaiable in this bus: ";
        }
        else
        {
            if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
            {
                cout<<"Enter passenger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            }
            else
                cout<<"The seat is already reserved. \n";
        }
    }
    if (n>p)
    {
        cout<<"Enter correct bus number. \n";
        goto top;
    }
}
void a::empty()
{
    for(int i=0; i<8;i++)
    {
        for(int j=0; j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void a::show()
{
    int n;
    char number[5];
    cout<<"Enter bus number:";
    cin>>number;
    for(int n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn, number)==0)
        break;
    }
    while(n<=p)
    {
        vline('*');
        cout<<"Bus number: \t"<<bus[n].bus
        <<"\nDriver: \t"<<bus[n].driver<<"\t\t Arrival time: \t"<<bus[n].arrival<<"\t\t Departure time: \t"<<bus[n].depart<<"\t\t From: \t"<<bus[n].from<<"\t\t To: \t"<<bus[n].to<<"\n";
        vline('*');
        bus[0].position(n);
        int a=1;
        for(int i=0; i<8;i++)
        {
            for(int j=0; j<4;j++)
            {
                a++;
                if(strcpy(bus[n].seat[i][j], "Empty")!=0)
                cout<<"The seat is reserved;"
            }
        }
        break;
    }
    if (n>p)
        cout<<"Enter correct bus no."; 
}
void a::position(int 1)
{
    int s=0;p=0;
    for(int i=0; i<8;i++)
    {
        cout<<"\n";
        for(int j=0; j<4;j++)
        {
            s++;
            if(strcpy(bus[n].seat[i][j], "Empty")==0)
            {
                cout.width[5];
                cout.fill(' ');
                cout<<s<<".";
                cout.width[10];
                cout.fill(' ');
                cout<<=bus[1].seat[i][j];
                p++;
            }
            else
            {
                cout.width[5];
                cout.fill(' ');
                cout<<s<<".";
                cout.width[10];
                cout.fill(' ');
                cout<<=bus[1].seat[i][j];
                p++;
            }
        }
    }
    cout<<"There are "<<p<<"seats available"<<bus[1].busn;
}
void a::avail()
{
    for(int n=0;n<=p;n++)
    {
        vline('*');
        cout<<"Bus number: \t"<<bus[n].bus
        <<"\nDriver: \t"<<bus[n].driver<<"\t\t Arrival time: \t"<<bus[n].arrival<<"\t\t Departure time: \t"<<bus[n].depart<<"\t\t From: \t"<<bus[n].from<<"\t\t To: \t"<<bus[n].to<<"\n";
        vline('*');
    }
}
int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout<<"Enter choice: \n\n\t1. Install\n\t2. Reservation\n\t3. Show\n\t4. Buses Available\n\t5. Exit";
        cin>>w;
        switch(w)
        {
            case 1: bus[p].install();
                break;
            case 2: bus[p].allotment();
                break;
            case 3: bus[p].show();
                break;
            case 4: bus[p].avail();
                break;
            case 5: bus[p].exit(0);
                break;
        }
    }

    return 0;
}

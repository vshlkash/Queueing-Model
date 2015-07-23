#include<iostream>
#include<iomanip>
using namespace std;

int customers = 10;
int clock = 0;
char custList[10] = {'A','B','C', 'D', 'E', 'B', 'E' , 'C', 'D', 'A'};
char custQueue[10];

bool inService = false;
int fronte = -1;
int rear = -1;
char eventInService;
//int arrivalTime;
int departureTime = 0;
//int interArrivalTime = 1;
int serviceTime = 2;
//int eventsCount = 0;


void serviceFromQueue()
{
    fronte++;
    eventInService = custQueue[fronte];
    inService = true;
    departureTime = clock + serviceTime;
}

void serviceAtArrival(char eventArrived)
{
    eventInService = eventArrived;
    inService = true;
    departureTime = clock + serviceTime;
}

void enterInQueue(char event)
{
    custQueue[++rear] = event;
}

void arrival(char event)
{
    if(inService == false)
        serviceAtArrival(event);
    else
        enterInQueue(event);
}

void showQueue()
{
    char q[10];
    int j = 0;
    for(int i = fronte + 1; i <= customers - 1; i++) {
        //cout<<custQueue[i];
        q[j] = custQueue[i];
        j++;
    }
    cout<<q;
}

int main()
{
    int stoppingTime = 20;
    int eventsCount = 0;
    int arrivalTime;
    int interArrivalTime = 1;
    //int serviceTime = 2;
    cout<<"Inter Arrival Time: 1  Service Time: 2  Total Customers: 10  Simulation Stop: 20"<<endl<<endl;
    cout<<"Enter arrival Time of first event: ";
    cin>>arrivalTime;
    cout<<endl;
    cout<<left<<setw(4)<<"Clk"<<setw(11)<<"QueueEvent"<<setw(12)<<"NextArrival"<<setw(12)<<"ArrivalTime"<<setw(15)<<"EventInService"<<setw(12)<<"DepartTime"<<endl;

    while(clock <= stoppingTime)
    {
        // Departure
        if(rear == 10 && fronte == rear)
            break;

        if(clock == departureTime && departureTime != 0)
        {
            inService = false;
            if(rear != fronte && rear != -1)
            {
                serviceFromQueue();
            }
        }

        // Arrival

        if(clock == arrivalTime && rear != 10)
        {

            arrival(custList[eventsCount]);
            arrivalTime += interArrivalTime;
            eventsCount++;
        }
        cout<<setw(4)<<clock<<setw(11);
        showQueue();
        if(eventsCount >= customers)
           cout<<setw(12)<<"-"<<setw(12)<<"-"<<setw(15)<<eventInService<<setw(12)<<departureTime<<endl;
        else {
            cout<<setw(12)<<custList[eventsCount]<<setw(12)<<arrivalTime<<setw(15)<<eventInService<<setw(12);
            if(departureTime == 0)
                cout<<"-"<<endl;
            else
                cout<<departureTime<<endl;
        }
        clock += 1;
    }
}

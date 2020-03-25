#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define SIZE 10

typedef struct Process
{	
	int id;
	int arrivalTime;
	int burstTime;
	int remIO;
	int remCPU;
	// int cycle;
	// int state;
}Process;

typedef struct IOqueue
{
	Process* p;
	struct IOqueue* next;
}IOqueue;

typedef struct Readyqueue
{
	Process* p;
	struct Readyqueue* next;
}Readyqueue;

void initialArrive();
int randomGenerator();
Process* createProcess(int id);
void longSchedular();
void showAllProcesses();
void showReadyQueue();
void showIOQueue();
void isArrived();
int minimum(int minTime[],int k);
void decremenTime();
void longSchedular();
void shortSchedular();
void schedule();


void deIOqueue()
{

}

void enIOqueue()
{

}

void deReadyqueue()
{

}

void enReadyqueue()
{

}


int timeLine = 0;
int curIO = -1;
int curCPU = -1;
Process* processes[SIZE];
Process* parrive[SIZE];
// Implementing queue using linked list
Readyqueue *readyqueue;
IOqueue *ioqueue;

void initialArrive()
{
	int i;
	for(i=0;i<SIZE;i++)
		parrive[i]=NULL;
}

int randomGenerator()
{
	int lower = 1;
	int upper = SIZE;
	int num = (rand()%upper+lower)*4;
	return num;
}

Process* createProcess(int id)
{
	Process* p = (Process*)malloc(sizeof(Process*));
	p->id = id;
	p->arrivalTime = randomGenerator();
	p->burstTime = randomGenerator();
	p->remCPU = p->burstTime/2;
	p->remIO = p->burstTime/2;
		// p->cycle = 0;
	return p;
}

void showAllProcesses()
{
	int i;
		printf("PID\tAT\tBT\tCPU\tIO\n");
		for(i=0;i<SIZE;i++)
			{
				printf("%d\t",processes[i]->id);
				printf("%d\t",processes[i]->arrivalTime);
				printf("%d\t",processes[i]->burstTime);
				printf("%d\t",processes[i]->remCPU);
				printf("%d\t",processes[i]->remIO);
				printf("\n");
			}

}

void showReadyQueue()
{
	printf("Ready Queue - \t");
	Readyqueue *temp = readyqueue;
	do{
		printf("%d ",temp->p->id);
		temp = temp->next;
	}while(temp);
	printf("\n");
}

void showIOQueue()
{

}

void longSchedular()
{
	int i=0;
	for(i=0;i<SIZE;i++)
		processes[i] = createProcess(i);
}

Readyqueue* insertReadyqueueItem(Process *p)
{
	Readyqueue *temp = (Readyqueue*)malloc(sizeof(Readyqueue*));
	temp->p = p;
	temp->next = NULL;
	return temp;
}

void addProcessToReadyQueue(Process *p)
{
	Readyqueue *temp = readyqueue;
 	// Creating for first
	if(temp->p==NULL)
	{
		temp->p = p;
		temp->next = NULL;
	}
	else
	{
		while(temp->next)
			temp = temp->next;
		temp->next = insertReadyqueueItem(p);
	}
}

int getProcessFromReadyQueue()
{
	showReadyQueue();
	int count = 0;
	Readyqueue *temp = readyqueue;
	do{
		count++;
		temp = temp->next;
	}while(temp);

	int minTime[count];
	
	int k=0;
	Readyqueue *let = readyqueue;
	do{
		minTime[k++] = let->p->remCPU;
		let = let->next;
	}while(let);

	int candidate = minimum(minTime,k);

	k = 0;
	int newid = -1;
	Readyqueue *loan = readyqueue;
	do{
		newid = loan->p->id;
		loan = loan->next;
	}while(k<candidate);

	printf("%d \n",newid);
	return newid;
}

void isArrived()
{
	int k=0;
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(processes[i]->arrivalTime==timeLine)
			parrive[k++] = processes[i];
	}
	
	if(k>0) // Process has arrived
	{
		int minTime[k];
		for(i=0;i<k;i++)
			{
				printf("Process %d has arrived \n",parrive[i]->id);
				minTime[i] = parrive[i]->remCPU;
			}

		int candidate = minimum(minTime,k);
		printf("%d\n",parrive[candidate]->id);

		for(i=0;i<k;i++)
		{
			if(i!=candidate)
				addProcessToReadyQueue(parrive[i]);
		}
		showReadyQueue();
		// Initial Stage
		if(curCPU==-1)
			curCPU = parrive[candidate]->id;

		if(curCPU!=-1)
		{
			if(processes[curCPU]->remCPU > processes[candidate]->remCPU)
				{
					printf("%d preemptive and scheduled to %d\n",processes[curCPU]->id,parrive[candidate]->id);
					//addProcessToIOQueue(processes[curCPU]);
					curCPU = parrive[candidate]->id;
				}
		}

		initialArrive();
	}
}

int minimum(int minTime[],int k)
{
	int index = 0;
	int i;
	for(i=0;i<k;i++)
	{
		if(minTime[i]<minTime[index])
			index = i;
	}
	return index;
}

void decrementTime()
{
		if(curCPU!=-1)
			{
				processes[curCPU]->remCPU--;
			}

		if(curIO!=-1)
			{
				processes[curIO]->remIO--;
			}
}


void schedule(int newCPU,int curCPU)
{

}

void shortSchedular()
{
	readyqueue = (Readyqueue*)malloc(sizeof(Readyqueue*));
	readyqueue->p = NULL;

	while(1)
	{
		printf("TimeLine - %d\n",timeLine);
		isArrived();

		decrementTime();
		printf("Current CPU - %d\n",curCPU);

		if(curCPU!=-1 && processes[curCPU]->remCPU==0)
		{
			// addProcessToIOQueue(processes[curCPU]);
			printf("Process %d is terminated\n",processes[curCPU]->id);
			curCPU = getProcessFromReadyQueue();
		}

		if(curIO!=-1 && processes[curIO]->remIO==0)
		{
				//getProcessFromIOQueue();
				//addProcessToReadyQueue();
		}
		showAllProcesses();
		timeLine++;
		sleep(1);
	}
}

int main()
{
	longSchedular(); // It will create all processes
	showAllProcesses();
	shortSchedular();
}

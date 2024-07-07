#include<stdio.h>
#define SIZE 20

int queue[SIZE];

int front=0,rear=-1;

int X[2];

typedef struct process {
	int bt,no,at,ct,tat,wt,rbt,p,tempBT;
}pro;





pro p[10],temp;
int temp1[10];

void fcfs(void);
void sjf(void);
void rr(void);
void pri(void);
int init();
int* initRR(void);

void sort(int n){
	int i ,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}




void cl(int n)
{
    p[0].wt = 0;
    p[0].ct = p[0].bt + p[0].at;
    p[0].tat = p[0].ct - p[0].at;


    for (int i = 1; i < n; i++)
    {
        if (p[i - 1].ct > p[i].at)
        {
            p[i].wt = p[i - 1].ct - p[i].at;
            p[i].ct = p[i - 1].ct + p[i].bt;

        }
        else
        {
            p[i].wt = 0;
            p[i].ct = p[i].at + p[i].bt;
        }
        p[i].tat = p[i].ct - p[i].at;
    }
}

void avg(int n){
	float totalwt=0,totaltat=0;
	float avgwt=0,avgtat=0;
	for(int i=0;i<n;i++){
		totaltat+=p[i].tat;
		totalwt+=p[i].wt;
	}
	avgwt = totalwt/n;
	avgtat= totaltat/n;
	printf("\nAverage Waiting time: %f",avgwt);
	printf("\nAverage Turnaround time: %f",avgtat);

}




void display(int n){
	
	printf("\nprocess|Burst time|Arrival time|Waiting time|Turnaround time\n");
	int i;
	for(i=0;i<n;i++){
		printf("%d\t  %d\t  %d\t  %d\t  %d\t \n",p[i].no,p[i].tempBT,p[i].at,p[i].wt,p[i].tat);
	}
	avg(n);
}

void displayPri(int n){
	
	printf("\nprocess|Burst time|Arrival time|Priority|Waiting time|Turnaround time\n");
	int i;
	for(i=0;i<n;i++){
		printf("%d\t  %d\t  %d\t  %d\t  %d\t  %d \n",p[i].no,p[i].tempBT,p[i].at,p[i].p,p[i].wt,p[i].tat);
	}
	avg(n);
}





int init(){
	printf("Enter no of Process: ");
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++){
                printf("Enter the burst time, arrival time of process %d: ",i+1);
                scanf("%d %d",&p[i].bt,&p[i].at);
                p[i].no = i + 1;
				p[i].tempBT=p[i].bt;
        }
	return n;
}

int initPri(){
	printf("Enter no of Process: ");
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++){
                printf("Enter the burst time, Priority of process and Arrival time %d: ",i+1);
                scanf("%d %d %d",&p[i].bt,&p[i].p,&p[i].at);
                p[i].no = i + 1;
				p[i].tempBT=p[i].bt;
        }
	return n;
}


int* initRR(){
	printf("Enter no of Process: ");
        int n;
	scanf("%d",&n);
	printf("Enter time quantum: ");
        int t;
        scanf("%d",&t);
        int i;
        for(i=0;i<n;i++){
                printf("Enter the burst time, arrival time of process %d: ",i+1);
                scanf("%d %d",&p[i].bt,&p[i].at);
                p[i].no = i + 1;
				p[i].tempBT=p[i].bt;
        }
	X[0] = n;
	X[1] = t;
	return X;
}



void fcfs(){
	int n = init();
	sort(n);
	cl(n);
	display(n);
}

void sjf(){
	int n = init();
	sort(n);

	int count=0;
    p[9].bt = 1000000;
    int sp;
    for (size_t t = 0; count!=n; t++)
    {
        sp=9;
        for (size_t j = 0; j < n; j++)
        {
            if(p[sp].bt>p[j].bt && p[j].at<=t && p[j].bt>0){
                sp=j;
            }
        }

        p[sp].bt--;
        if(!p[sp].bt){
            count++;
            p[sp].tat = t+1-p[sp].at;
            p[sp].wt = p[sp].tat-p[sp].tempBT;
        }
    }
	display(n);
}

void rr(){
	int *x = initRR();
	int n = x[0];
	int t = x[1];
	int y = n;
	int i,j,sum=0,count=0;
	sort(n);
	printf("\n Process No \t\tBurst Time \t\t TAT \t\t Waiting Time");
	for(sum=0,i=0;y!=0;){
		if(p[i].tempBT<=t && p[i].tempBT>0){
			sum+=p[i].tempBT;
			p[i].tempBT=0;
			count = 1;
		}else if(p[i].tempBT>0){
			p[i].tempBT-=t;
			sum+=t;
		}
		if(temp1[i]==0 && count==1){
			y--;
			p[i].tat = sum-p[i].at;
            p[i].wt = p[i].tat-p[i].bt;
			printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d",p[i].no,p[i].bt,p[i].tat,p[i].wt);
			count=0;
		}
		if(i==n-1){
			i=0;
		}else if(p[i+1].at<=sum){
			i++;
		}else{
			i=0;
		}
	}
	avg(n);
}

void pri(){
	int n = initPri();
	sort(n);
	int i ,j,smallest,count=0,time=0,end=0;
	p[9].p=1000;
	for(time=0;count!=n;time++){
		smallest=9;
		for(i=0;i<n;i++){
			if(p[i].at<=time && p[i].p<p[smallest].p && p[i].bt>0){
				smallest=i;
			}	
		}
		p[smallest].bt--;
		if(p[smallest].bt==0){
			count++;
			end=time+1;
			p[smallest].ct=end;
			p[smallest].tat=end-p[smallest].at;
			p[smallest].wt=p[smallest].tat-p[smallest].tempBT;
		}
	}
	displayPri(n);	
}


void menu(){

	int c;
	do{
	printf("\nChoose any Scheduling algorithm\n1)FCFS\n2)SJF\n3)Round Robin\n4)Priority\n0)End Program :(\nEnter choice: ");
	scanf("%d",&c);
	switch(c){
		case 1: fcfs();break;
		case 2: sjf();break;
		case 3: rr();break;
		case 4: pri();break;
		case 0: break;
		default: "Wrong Input\n"; 
	}
	}while(c!=0);
}


int main(){
	menu();
}

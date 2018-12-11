#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int state[16];
    int step;
    int num;
};
node mynode[100];
int visit[100]= {0};
char ch;
void scan();
bool finalstate(node a);
void bfs();

void scan()
{
    int cnt = 0;
    while(cnt != 16)
    {
        cin>>ch;
        if(ch == '\n')            continue; //initial
        if(ch == 'b')
            mynode[0].state[cnt++] = 1;
        if(ch == 'w')
            mynode[0].state[cnt++] = 0;
    }
    mynode[0].step = 0;
    mynode[0].num = -1;
}

bool finalstate(node a)
{
    int tot = 0;
    for(int i=1; i<16; i++)
    {
        if(a.state[i]==a.state[0])
        {
            tot++;
        }
        else break;
    }

    if(tot == 15) //final state
        return 1;
    else return 0;
}

void bfs()
{
    int front = 0;
    int rear = 0;
    int judge;
    //judge final stat
    while(1)
    {
        judge = finalstate(mynode[front]);
        if(judge == 1)
        {
            cout<<mynode[front].step<<endl;
            break;
        }
        for(int i=0; i<16; i++)
        {
            if(mynode[front].num == i)
                continue;

            rear++;

            int row;
            int col;
            row=i/4;
            col=i%4;
            for(int j=0; j<16; j++)
            {
                mynode[rear].state[j]=mynode[front].state[j];
            }
            mynode[rear].state[i]=!mynode[front].state[i];
            if(row < 3)
                mynode[rear].state[i+row] =! mynode[front].state[i+row];
            if(row > 0)
                mynode[rear].state[i-row] =!mynode[front].state[i-row];
            if(col < 3)
                mynode[rear].state[i+1] =! mynode[front].state[i+1];
            if(col > 0)
                mynode[rear].state[i-1] =! mynode[front].state[i-1]; //filp 4 cases
            mynode[rear].step = mynode[front].step + 1;
            mynode[rear].num = i;


            if(visit[mynode[rear].num] == 1)
                rear--;
            visit[mynode[rear].num] = 1;

            judge = finalstate(mynode[rear]);
            if(judge == 1)
                break;
        }
        if(front == rear)
        {
            cout<<" Impossible"<<endl;
            break;
        }
        front++;
      //  cout<<"ff"<<front<<endl;
    }
}

int main()
{
    scan();
    bfs();
    return 0;
}


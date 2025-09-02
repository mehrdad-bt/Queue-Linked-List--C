#include <stdio.h>
#include <stdlib.h>


/*Global variables and Typedefs*/

typedef struct Queue{
    int data;
    struct Queue *next;
}Queue;

Queue *front = NULL;
Queue *rear = NULL;
Queue *record;




/*Function Prototypes*/

void Start();
void Enqueue();
void Dequeue();
void PrintQueue();
void Save();
void Menu();
void freeMemory();

void (*Op[2])(void)=
{
    Enqueue,
    PrintQueue

};

void Menu(int choice, void(*Op[])(void)){
    Op[choice]();
}


int main(){
    
    int choice=0;
    do{
    printf("Enter an option:\n1=Enqueue\n2=PrintAll\n3=Exit\n");
    scanf("%d", &choice);
    Menu(choice-1, Op);
    void Enqueue();
    void PrintAll();
    }while(choice != 3);
    freeMemory();

    
    return 0;
}

/*function Definitions*/






void Start(){

    Queue temp;
    int data_nums;

    FILE *fp = fopen("data.hex","rb");
    if(fp != NULL)
    {
    fread(&data_nums, sizeof(data_nums), 1, fp);
    for(int i = 0; i < data_nums; i++)
    {
        record = (Queue*)malloc(sizeof(Queue));
        if(record == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        fread(&temp, sizeof(Queue), 1, fp);
        record->data = temp.data;
        if(front == NULL)
        {
            front = record;
            rear = record;
        }
        else
        {
            
            rear->next = record;
            rear = record;
        }
        rear->next = NULL;
    }

    }





}


void Enqueue(){
    
    int data;
    record =(Queue*)malloc(sizeof(Queue));
    if(record == NULL)
    {
        printf("Memory allocation faile!\n");
        return;
    }
    printf("Enter your Data:\n");
    scanf("%d", &data);
    record->data = data;

    if(front == NULL)
    {
        front = record;
        rear = record;
    }
    else
    {
        rear->next = record;
        rear = record;
    }
    rear->next = NULL;

}


void PrintQueue(){

    Queue *tmp = front;
    if(tmp == NULL)
    {
        printf("No Data to Print !\n");
        return;
    }
    while(tmp != NULL)
    {
    printf("Data is:%d \n", tmp->data);
    tmp = tmp->next;
    }
}

void freeMemory(){
    Queue *tmp = front;
    while(tmp != NULL)
    {
        front = tmp;
        tmp = front->next;
        free(front);
    }
}
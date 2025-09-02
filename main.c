#include <stdio.h>
#include <stdlib.h>


/*Global variables and Typedefs*/

typedef struct Queue{
    int data;
    struct Queue *next;
}Queue;

typedef struct NonePointerQueue{
    int data;
}NonePointerQueue;

Queue *front = NULL;
Queue *rear = NULL;
Queue *record;
int data_nums;



/*Function Prototypes*/

void Start();
void Enqueue();
void Dequeue();
void PrintQueue();
void Save();
void Menu();
void freeMemory();

void (*Op[4])(void)=
{
    Enqueue,
    Dequeue,
    PrintQueue,
    Save

};

void Menu(int choice, void(*Op[])(void)){
    Op[choice]();
}


int main(){
    
    
    int choice=0;
    Start();
    do{
    printf("Enter an option:\n1=Enqueue\n2=Dequeue\n3=PrintAll\n4=Save\n5=Exit\n");
    scanf("%d", &choice);
    Menu(choice-1, Op);
    void Enqueue();
    void PrintAll();
    }while(choice != 5);
    freeMemory();

    
    return 0;
}

/*function Definitions*/






void Start(){

    NonePointerQueue temp;

    FILE *fp = fopen("database.hex","rb");
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
        fread(&temp, sizeof(NonePointerQueue), 1, fp);
        record->data = temp.data;
        record->next = NULL;
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
    printf("\t\t\t\t\tDatabase has been successfuly loaded !\n");
    }
    fclose(fp);
    

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
    data_nums++;
}

void Dequeue(){
    
    Queue *task = front;

    if(front== NULL)
    {
        printf("No data to Dequeue!\n");
        return;
    }
    front = front->next;
    free(task);



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

void Save(){
    NonePointerQueue temp;
    Queue *current = front;


    FILE *fp = fopen("database.hex","wb");
    if(fp == NULL)
    {
        printf("File save failed!\n");
        return;
    }

    if(fwrite(&data_nums, sizeof(data_nums), 1, fp) != 1)
    {
        printf("File save failed!\n");
        return;
    }
    for(int i = 0; i < data_nums; i++){
        printf("Data sving...\n");
        temp.data = current->data;
        fwrite(&temp, sizeof(NonePointerQueue), 1, fp);
        current = current->next;

    }
    fclose(fp);
    printf("New Datas has been saved !\n");
}
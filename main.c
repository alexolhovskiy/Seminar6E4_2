#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word{
    int num;
    char letters[20];
    struct word*next;
    struct word*prev;
}word;


void wordsPrint(word*begin){
    while(begin->next!=NULL){
        printf("%s ",begin->letters);
        begin=begin->next;
    }
    printf("\n");
}

void wordsPrintReverse(word*end){
    end=end->prev;
    while(end!=NULL){
        printf("%s ",end->letters);
        end=end->prev;
    }
    printf("\n");
}

word*push(word*begin,char*str){
    word*p=(word*)malloc(sizeof(word));
    p->letters[0]='\0';
    strcat(p->letters,str);
    p->num=begin->num+1;
    p->next=begin;
    p->prev=NULL;
    begin->prev=p;
    begin=p;
    return begin;
}

word*findOdd(word*begin){
    if(begin==NULL){
        return NULL;
    }
    word*o,*ptr=begin;
    while(ptr->next!=NULL){
        if(ptr->num%2!=0){
            if(ptr->prev!=NULL){
                o=ptr;
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                ptr=ptr->prev;
            }else{
                o=ptr;
                ptr=ptr->next;
                ptr->prev=NULL;
            }
            o->next=NULL;
            free(o);
        }
        ptr=ptr->next;
    }
    return begin;
}



int main()
{
    printf("Hello world!\n");
    char str[80]={0};
    int flag=1,size=0;

    word*begin=(word*)malloc(sizeof(word));
    begin->next=NULL;
    begin->prev=NULL;
    strcat(begin->letters,"end");
    begin->num=-1;
    word*end=begin;

    printf("Enter string\n");
    while(flag==1){
        scanf("%s",str);
        //printf("While: %s\n",str);
        size=strlen(str);
        if(str[size-1]=='.'){
            flag=0;
            str[size-1]='\0';
        }
        begin=push(begin,str);
    }
    wordsPrint(begin);
    begin=findOdd(begin);
    wordsPrintReverse(end);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char* url;
    struct Node* prev;
    struct Node* next;
}node;

char* duplicate(char* str){
    char* copy=(char*)malloc(strlen(str)+1);
    strcpy(copy,str);
    return copy;
}

node* createnode(char* url){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->url=duplicate(url);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

typedef struct{
    node* current;
}BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage){
    BrowserHistory* browser=(BrowserHistory*)malloc(sizeof(BrowserHistory));
    browser->current=createnode(homepage);
    return browser;
}

void browserHistoryFree(BrowserHistory* browser){
    node* current=browser->current;
    while(current->prev!=NULL){
        current=current->prev;
    }
    while(current!=NULL){
        node* nextnode=current->next;
        free(current->url);
        free(current);
        current=nextnode;
    }
    free(browser);
}
void deleteForwardHistory(node* current){
    node* temp=current->next;
    while(temp!=NULL){
        node* nextnode=temp->next;
        free(temp->url);
        free(temp);
        temp=nextnode;
    }
    current->next=NULL;
}

void browserHistoryVisit(BrowserHistory* browser,char* url){
    node* newnode=createnode(url);
    deleteForwardHistory(browser->current);
    newnode->prev=browser->current;
    browser->current->next=newnode;
    browser->current=newnode;
}

char* browserHistoryBack(BrowserHistory* browser,int steps){
    while(steps>0&&browser->current->prev!=NULL){
        browser->current=browser->current->prev;
        steps--;
    }
    return browser->current->url;
}

char* browserHistoryForward(BrowserHistory* browser,int steps){
    while(steps>0&&browser->current->next!=NULL){
        browser->current=browser->current->next;
        steps--;
    }
    return browser->current->url;
}
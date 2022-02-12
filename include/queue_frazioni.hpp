#ifndef QUEUE_STRUCT_H
#define QUEUE_STRUCT_H

// dichiarazioni per la gestione della coda di interi

#include <string>

using std::string;

struct node
{
    string val;
    int index;
    node *next;
};

struct queue
{
    node *tail;
    node *head;
};

void init(queue &);
void deinit(queue &);
bool enqueue(string, int, queue &);
int first(string &, const queue &);
bool dequeue(queue &);
void print(const queue &);

#endif

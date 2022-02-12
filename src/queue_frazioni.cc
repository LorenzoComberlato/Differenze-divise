#include "../include/queue_frazioni.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::nothrow;
using std::string;

static bool emptyp(const queue &Q)
{
    return (Q.head == NULL);
}

void init(queue &Q)
{
    Q.head = NULL;
}

bool enqueue(string val, int index, queue &Q)
{
    node *np = new (nothrow) node;
    if (np == NULL)
        return false;

    np->val = val;
    np->index = index;
    np->next = NULL;
    if (emptyp(Q))
        Q.head = np;
    else
        Q.tail->next = np;
    Q.tail = np;
    return true;
}

int first(string &str, const queue &Q)
{
    if (emptyp(Q))
        return -1;

    str = Q.head->val;
    return Q.head->index;
}

bool dequeue(queue &Q)
{
    if (emptyp(Q))
        return false;

    node *first;
    first = Q.head;
    Q.head = Q.head->next;
    delete first;
    return true;
}

void print(const queue &Q)
{
    if (!emptyp(Q))
    {
        node *first = Q.head;
        do
        {
            cout << "Q[" << first->index << "] : " << first->val << endl;
            first = first->next;
        } while (first != NULL);
    }
}

void deinit(queue &Q)
{
    while (!emptyp(Q))
        dequeue(Q);
}

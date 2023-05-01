#include <iostream>
using namespace std;

class IntQueue{
    private:
        static const int QUEUE_SIZE = 10;
        int queueArray[QUEUE_SIZE];
        int front;
        int rear;
        int numItems;
    public: 
        IntQueue();
        void enqueue(int);
        int dequeue();
        bool isFull() const;
        bool isEmpty() const;
        int size() const;
};
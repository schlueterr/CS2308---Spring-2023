#include <iostream>
#include <cassert>

using namespace std;
class IntQueue{
    private: 
        static const int QUEUE_SIZE = 100;
        int queueArray[QUEUE_SIZE];
        int front;
        int rear; 
        int numItems;

    public:
        IntQueue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
        bool isFull() const;
        void clear();
        void display();
        double average();
};

IntQueue::IntQueue(){
    front = 0;
    rear = -1;
    numItems = 0;
}

void IntQueue::enqueue(int num){
    assert(!isFull());
    rear = (rear + 1) % QUEUE_SIZE;
    queueArray[rear] = num;
    numItems++;
}

int IntQueue::dequeue(){
    assert(!isEmpty());
    int num = queueArray[front];
    front = (front + 1) % QUEUE_SIZE;
    numItems--;
    return num;
}

bool IntQueue::isEmpty() const{
    return numItems == 0;
}

bool IntQueue::isFull() const{
    return numItems == QUEUE_SIZE;
}

void IntQueue::display(){
    for(int i = 0; i < numItems; i++){
        cout << queueArray[i] << " ";
    }
    cout << std::endl;
}

double IntQueue::average(){
    double sum = 0;
    for(int i = 0; i < numItems; i++){
        sum += queueArray[i];
    }
    return sum / numItems;
}


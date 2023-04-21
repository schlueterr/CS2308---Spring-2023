class LinkedList{
    private:
        struct Node{
            int data;
            Node* next;
        };
        Node* head;

    public:
        LinkedList() {head = nullptr;}
        void insertAfter(int target, int value){
            Node* temp = head;
            while (temp != nullptr && temp->data != target){ // go through the list until the target is found
                temp = temp->next;
            }
            if (temp != nullptr){ // if the target is found then insert the new node
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }


};

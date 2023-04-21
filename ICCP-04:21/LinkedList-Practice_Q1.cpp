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
            while (temp != nullptr && temp->data != target){
                temp = temp->next;
            }
            if (temp != nullptr){
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }


};

struct Node{
    int data;
    Node* next;
};

void concentrateLinkedList(Node* list1, Node* list2){
    if(list1 == nullptr || list2 == nullptr){
        return;
    }
    Node *temp = list2;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = list1;
}
struct Node {
    int data;
    Node* next;
};

void concatenateLists(Node* list1, Node* list2) {
    // traverse to the end of list2
    Node* temp = list2;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    // link the last node of list2 to the first node of list1
    temp->next = list1;
}

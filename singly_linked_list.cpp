#include <iostream>
using std::cerr;
using std::endl;

// List有头节点
typedef int DataType;
typedef struct ListNode{
    DataType value;
    ListNode* next;
    ListNode(DataType value1) {
        value = value1;
        next = nullptr;
    }
} ListNode;

// 将value插入到第i个数的位置
void Insert(ListNode* head, int index, DataType value) {
    ListNode* predecessor = head;

    if (index <= 0) {
        cerr << "i is invalide" << endl;
    }
    //predecessor是指向新节点的直接前驱
    for (int i = 0; i < index - 1; i++) {
        predecessor = predecessor->next;
        if (predecessor == nullptr) {
            cerr << "index is invalide" << endl;
        }
    }
    // 插入
    ListNode* newNode = new ListNode(value);
    ListNode* successor = predecessor->next;
    predecessor->next = newNode;
    newNode->next = successor;
}

// 插入升序List，使得List保持升序
void Insert(ListNode* head, DataType value) {
    ListNode* predecessor = head;

    //predecessor是指向新节点的直接前驱
    while (predecessor->next != nullptr && predecessor->next->value < value) {
        predecessor = predecessor->next;
    }

    // 插入
    ListNode* newNode = new ListNode(value);
    ListNode* successor = predecessor->next;
    predecessor->next = newNode;
    newNode->next = successor;
}

void Remove(ListNode* head, int index) {
    ListNode* predeccessor = head;
    for (int i = 0; i < index - 1; i++) {
        predeccessor = predeccessor->next;
        if (predeccessor == nullptr) {
            cerr << "index is invalide" << endl;
        }
    }

    ListNode* node = predeccessor->next;
    if (node != nullptr) {
        ListNode* successor = node->next;
        predeccessor->next = successor;
        delete node;
    }
}

void Remove(ListNode* head, DataType value) {
    ListNode* predeccessor = head;
    while (predeccessor->next != nullptr && predeccessor->next->value != value) {
        predeccessor = predeccessor->next;
    }
    
    ListNode* node = predeccessor->next;
    ListNode* successor = node->next;
    predeccessor->next = successor;
    delete node;
}

void InitList(ListNode* head) {
    head = new ListNode(0);
}

void ClearList(ListNode* head) {
    ListNode* node = nullptr;
    while (head->next != nullptr) {
        node = head->next;
        head->next = node->next;
        delete node;
    }
}

int Length(ListNode* head) {
    int count = 0;
    while (head->next != nullptr) {
        count++;
    }
    
    return count;
}

bool isEmpty(ListNode* head) {
    return head->next == nullptr;
}

ListNode* Search(ListNode* head, DataType value) {
    ListNode* ptr = head;
    while (ptr != nullptr && ptr->value != value) {
        ptr = ptr->next;
    }
    if (ptr == nullptr) {
        cerr << "value is invalide" << endl;
    }
    return ptr;
}

ListNode* Search(ListNode* head, int index) {
    ListNode* ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
        if (ptr == nullptr) {
            cerr << "index is invalide" << endl;
        }
    }

    return ptr;
}

// 返回倒数第index个数
ListNode* SearchReverse(ListNode* head, int index) {
    ListNode* node = head;
    ListNode* lastNode = head;
    for (int i = 0; i < index; i++) {
        lastNode = lastNode->next;
        if (lastNode == nullptr) {
            cerr << "index is invalide" << endl;
        }
    }

    while (lastNode != nullptr) {
        node = node->next;
        lastNode = lastNode->next;
    }

    return node;
}

void Copy(ListNode* destination_head, ListNode* source_head) {
    ListNode* destination_node = destination_head;
    ListNode* source_node = source_head;

    while (source_node != nullptr) {
        destination_node->next = new ListNode(source_node->value);

        destination_node = destination_node->next;
        source_node = source_node->next;
    }
}
#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next; // pointer to the next node

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

// 1. Inserting at the end of LL
void insertAtTail(Node *&head, int val)
{
  // create a new node in which data field
  // will have value and next will point NULL

  Node *n = new Node(val);

  // if there's no element in the LL
  if (head == NULL)
  {
    head = n;
    return;
  }

  Node *temp = head;

  // go till the last node, i.e. to the node which points to null
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
  n->next = NULL;
}

// 3. Inserting at beginning of LL
void insertAtHead(Node *&head, int val)
{

  Node *n = new Node(val);
  // pointing new node towards head
  n->next = head;
  // moving the head on new node
  head = n;
}

// 2. Prints the LL
void display(Node *&head)
{

  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  cout << "NULL" << endl;
}

// 4. Search in LL
bool search(Node *head, int key)
{

  Node *temp = head;

  while (temp != NULL)
  {
    // check if key exists
    if (temp->data == key)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

// 5. delete the node where value is given.
void deletion(Node *&head, int val)
{

  // case when there are no nodes
  if (head == NULL)
  {
    return;
  }

  Node *temp = head;
  // reach till the node just before the value to delete
  while (temp->next->data != val)
  {
    temp = temp->next;
  }

  // create a pointer for the node to be deleted
  Node *toDelete = temp->next;
  // point the next pointer to the node after the value to be deleted
  temp->next = temp->next->next;
  delete toDelete;
}

// 6. delete the head of LL
void deleteAtHead(Node *&head)
{
  Node *nodeToDelete = head;
  head = head->next;
  delete nodeToDelete;
}

// 7. Reverse a LL
Node *reverse(Node *&head)
{

  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  // head = prev;
  cout << "Head is " << head->data << endl;
  return prev;
}

Node *kReverse(Node *head, int k)
{

  if (head == NULL)
  {
    return NULL;
  }

  // reverse first k nodes
  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;
  int count = 0;

  // it'll only reverse K nodes in each itertion
  while (curr != NULL && count < k)
  {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
    count++;
  }

  // recursion for remaining LL
  if (next != NULL)
  {
    head->next = kReverse(next, k);
  }

  return prev;
}

int main()
{
  Node *head = NULL;

  insertAtHead(head, 5);
  insertAtHead(head, 4);

  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 9);
  insertAtTail(head, 10);
  insertAtTail(head, 11);
  display(head);

  // cout << search(head, 99) << endl;

  // deletion(head, 5);
  // deleteAtHead(head);

  display(head);
  Node *rev = reverse(head);
  // Node *rev = kReverse(head, 3);

  display(rev);
}
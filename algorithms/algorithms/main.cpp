#include <iostream>
#include <chrono>
//#include <Windows.h>

using namespace std;

struct treeNode {
  int data;
  treeNode* left = NULL;
  treeNode* right = NULL;
};

struct listNode {
  int data;
  listNode* next = NULL;
};

treeNode* newNode (int data) {
  treeNode* n = new treeNode;
  n->data = data;
  return n;
}

void printTreeLayers (treeNode* root) {
  cout << root->data;
  if (root->right != NULL || root->left != NULL) {
    cout << endl;
  }
  if (root->left != NULL) {
    printTreeLayers(root->left);
  }
  if (root->right != NULL) {
    cout << " ";
    printTreeLayers(root->right);
  }
}

void deleteTree (treeNode* root) {
  if (root->left != NULL) {
    deleteTree(root->left);
  }
  if (root->right != NULL) {
    deleteTree(root->right);
  }
  delete root;
}

void printLinkedList (listNode* node) {
  cout << node->data;
  while (node->next != NULL) {
    node = node->next;
    cout << " " << node->data;
  }
}

void deleteLinkedList (listNode* nodePtr) {
  listNode* next;
  if (nodePtr->next == NULL) {
    delete nodePtr;
    return;
  }
  while (nodePtr->next != NULL) {
    next = nodePtr->next;
    delete nodePtr;
    nodePtr = next;
  }
  delete nodePtr;
}

void printArr (float* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void prepareArray (float* arr, int len) {
  int i;
  cout << "preparing array..." << endl;
  srand(chrono::steady_clock::now().time_since_epoch().count());
  for (i = 0; i < len; i++) {
    arr[i] = rand() % 100;
  }
  cout << "radnomized array:" << endl;
  printArr(arr, len);
}

void insertionSort (float* arr, int len) {
  int i, j;
  float current;
  auto now = chrono::steady_clock::now();
  for (i = 1; i < len; i++) {
    current = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > current; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = current;
  }
  cout
    << "insertionSort() took(ns): "
    << chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - now).count()
    << endl;
}

void selectionSort (float *arr, int len) {
  auto now = chrono::steady_clock::now();
  int i, j, minIdx, tmp;
  for (i = 0; i < len - 1; i++) {
    minIdx = i;
    for (j = i + 1; j < len; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    tmp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = tmp;
  }
  cout
    << "selectionSort() took(ns): "
    << chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - now).count()
    << endl;
}

void bubbleSort (float *arr, int len) {
  int i, j;
  float tmp;
  auto now = chrono::steady_clock::now();
  for (i = 0; i < len; i++) {
    for (j = len - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
  cout
    << "bubbleSort() took (ns): "
    << chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - now).count()
    << endl;
}

void sortArr (int* arr, int len) {
  int i, j, tmp;
  int minIdx;
  for (i = 0; i < len - 1; i++) {
    minIdx = i;
    for (j = i + 1; j < len; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    tmp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = tmp;
  }
}

void insertionSortP (int* a, int len) {
  int i, j, k;
  for (i = 0; i < len - 1; i++) {
    k = a[i + 1];
    j = i;
    while (j >= 0 && a[j] > k) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = k;
  }
}

int main () {
  listNode* first = new listNode;
  first->data = 111;
  listNode* second = new listNode;
  second->data = 222;
  listNode* third = new listNode;
  third->data = 333;
  first->next = second;
  second->next = third;
  printLinkedList(first);
  deleteLinkedList(first);


  treeNode* root = newNode(123);
  root->left = newNode(111);
  root->right = newNode(333);
  root->left->left = newNode(555);
  root->right->left = newNode(777);
  printTreeLayers(root);
  deleteTree(root);
  char dataLen[4] = { 'a', 'b', 'c', 'd' };
  float a[10];
  prepareArray(a, 10);
  insertionSortP((int*)a, 10);
  printArr(a, 10);
  prepareArray(a, 10);
  sortArr((int*)a, 10);
  printArr(a, 10);


  insertionSort(a, 10);
  printArr(a, 10);
  cout << endl;
  prepareArray(a, 10);
  bubbleSort(a, 10);
  printArr(a, 10);
  cout << endl;
  prepareArray(a, 10);
  selectionSort(a, 10);
  printArr(a, 10);
  cout << endl;
  return 0;
}

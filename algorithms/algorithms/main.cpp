#include <iostream>
#include <chrono>
//#include <Windows.h>

using namespace std;

struct node {
  int data;
  node* left;
  node* right;
};

node* newNode (int data) {
  node* n = new node;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void printTreeLayers (node* root) {
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

void deleteTree (node* root) {
  if (root->left != NULL) {
    deleteTree(root->left);
  }
  if (root->right != NULL) {
    deleteTree(root->right);
  }
  delete root;
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
    j = i + 1;
    k = a[j];
    while (j > 0 && k < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = k;
  }
}

int main () {
  node* root = newNode(123);
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

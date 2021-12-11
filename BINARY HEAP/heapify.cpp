
// C++ program for building Heap and heapsort from Array
 
#include <iostream>
 
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    
    if (l < n && arr[l] > arr[largest])// If left child is larger than root
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])// If right child is larger than largest so far
        largest = r;
 
    
    if (largest != i) // If largest is not root
    {
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);// Recursively heapify the affected sub-tree
    }
}
 
// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = ((n-1) - 1)/2;
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
 
// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    cout << "Array :";
 
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
     void Delete_root(int ar[],int s)
    {
        int x,i,j;
        x=ar[0];
        ar[0]=ar[s];
        i=0;
        j=2*i+1;
        while(j < s)
        {
            if(ar[j+1]>ar[j])
            {
                j=j+1;
            }
            if(ar[i]<ar[j])
            {
                swap(ar[i],ar[j]);
                i=j;
                j=2*j+1;
            }
            else
            {
                break;
            }
        }
        ar[s]=x;
    }
    void heapsort(int ar[],int n)
    {
        int i=n-1;
        for(;i>=0;i--)
        {
            Delete_root(ar,i);
        }
    }

// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    //              1
    //           /     \
    //         3         5
    //      /    \     /  \
    //     4      6   13  10
    //    / \    / \
    //   9   8  15 17
    int arr[] = {5, 10, 20, 25, 30, 35, 40};
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    buildHeap(arr, n);
    cout<<"\nbinary heap:\n";
    printHeap(arr, n);
    // Final Heap:
    //                 17
    //           /      \
    //             15         13
    //       /    \      /  \
    //         9      6    5   10
    //     / \    /  \
    //       4   8  3    1
    heapsort(arr, n);
    cout<<"\nheapsorted:\n";
    printHeap(arr,n);
    return 0;
}
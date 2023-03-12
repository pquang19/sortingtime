#include <chrono>
#include <fstream>
#include <algorithm>
#include <string>

#define n 1000000

using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr.
// n is size of heap
void heapify(long arr[], long N, long i)
{
    // Find largest among root, left child and right child

    long largest = i; // Initialize largest as root
    long left = 2 * i + 1; // left = 2*i + 1
    long right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest]) { 
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < N && arr[right] > arr[largest]) { 
        largest = right; 
    }

    // Swap and continue heapifying if root is not largest
    if (largest != i) { // If largest is not root
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest); // Recursively heapify the affected sub-tree
    }
}

// Main function to do heap sort
void heapSort(long arr[], long N)
{
    // Build max heap
    for (long i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }

    // Heap sort
    for (long i = N - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // Heapify root element to get highest element at root again
    }
}

int main() {
    string filename = "testx.txt"; // test number x

    // Open the report file
    ofstream fo;
    fo.open("HeapSort_report.txt");

    // Loop through every single test
    for (char i = '0'; i < ':'; i++) { // i is the test index
        // array to store the numbers in test i
        long *numarr = new long[n] ;

        // Open test i and read the numbers
        filename[4] = i;
        ifstream fi;
        fi.open(filename);
        for (long j = 0; j < n; j++) {
            fi >> numarr[j];
        }
        fi.close();

        // Measure the time
        auto start = chrono::high_resolution_clock::now(); // start time
        heapSort(numarr, n); // sorting
        auto end = chrono::high_resolution_clock::now(); // end time 
        chrono::duration<double> duration = end - start; // calculate duration 

        // Write the result
        fo << duration.count() << std::endl;

        // Free up memory
        delete[] numarr;
    } 

    fo.close();
    return 0;
}
 104  

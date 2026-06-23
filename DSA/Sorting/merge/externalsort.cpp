#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//when dataset is too large to fit the memory


struct minheapnode{
    //th element to be stored
    int element;
    //index of the array from which 
    //the element is taken
    int i;
};

//prototype of a utility function
//swap two min heap nodes
void swap(minheapnode* x, minheapnode* y);

//a class for min heap
class minheap{
    //pointer to array of elements in heap
    minheapnode* harr;
    //size of min heap
    int heap_size;

    public: 
    /*external sorting is a term for a class of sortng algorithms that can handle massive amounts of data. enternal sorting is required when the data being sorted does not fit into the main memory of a computing device[usually RAM] and instead, must reside in the slower external memory[usually a hard drive]
    
    external sorting typically uses a hybrid sort merge strategy. in the sorting phase, chunks of data small enough to fit in the main memory are read, sorted and written out to the temporary file. in the merge phase, the sorted sub files are combined into a single larger file.
    
    why do we need external sorting?
    1. when the unsorted data is too large to perform sorting in computer internal memory then we use external sorting
    2. in external sorting we use the secondary device. in a secondary storage device we use the tape disk array.
    3. when data is large like in merge sort and quick sort
    4. quick sort - best average runtime
    5. merge sort - best worse case time
    6. to perform sort merge join operation on data
    7. to perform order by the query
    8. to select the duplicate element
    9. where we need to take large input from the user.
    
    exampels of external sorting arrays are 
    merge sort, tape sort, polyphase sort, external radix, external merge.*/
    //constructor creates a main
    //heap of given size
    minheap(minheapnode a[], int size);

    //to heapify a subtree with 
    //root at given index
    void minheapify(int);

    //to get index of left chil
    //of node at index
    int left(int i){ return (2*i +1 ); }

    //to get index of right child
    //of node at index i
    int right(int i) { return (2*i +2);}

    //to get the root
    minheapnode getmin(){ return harr[0];}

    //to replace root with new node 
    //x and heapigy new root
    void replacemin(minheapnode x){
        harr[0] = x;
        minheapify(0);
    }
};

minheap::minheap(minheapnode a[], int size){
    heap_size = size;
    harr = s;
    int i = (heap_size-1)/2;
    while(i>=0){
        minheapify(i);
        i--;
    }
}

void minheap::minheapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[l].element < harr[i].element){
        smallest = l;
    }
    if(r < heap_size && harr[r].element < harr[smallest].element){
        smallest = r; 
    }
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        minheapify(smallest);
    }
}

void swap(minheapnode* x, minheapnode* y){
    minheapnode temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    
    int L[n1], R[n2];

    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
}

/*j is for left index and r is right index of the sub array of arr to be sorted*/

void mergesort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

FILE* openFile(char* fileName, char* mode){
    FILE* fp = fopen(fileName, mode);
    if(fp==NULL){
        perror("error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void mergeFiles(char* output_file, int n, int k){
    FILE* in[k];
    for(int i=0;i<k;i++){
        char fileName[2];

        snprintf(fileName, sizeof(fileName), %d, i);

        in[i] = openFile(fileName, "r");
    }

    FILE* out = openFile(output_file, "w");

    minheapnode* harr = new minheapnode[k];
    int i;
    for(i=0l i<k;i++){
        if(fscanf(in[i], "%d", &harr[i].element)!=1){
            break;
        }
        harr[i].i = i;
    }
    minheap hp(harr, i);

    int count = 0;

    while (count != i){
        minheapnode root = hp.getmin();
        fprintf(out, "%d", root.element);

        if(fscanf(in[root.i],"%d ", &root.element)!=1){
            root.element = INT_MAX;
            count++;
        }

        hp.replacemin(root);
    }

    for(int i=0; i<k;i++){
        fclose(in[i]);
    }
    fclose(out);
}

void createinitialruns(char* input_file, int run_size, int num_ways){
    FILE* in = openFile(input_file, "r");
    FILE* out[num_ways];
    char fileName[2];
    for(int i =0;i<num_ways;i++){
        snprintf(fileName, sizeof(fileName), "%d", i);

        out[i]= openFile(fileName, "w");
    }

    int* arr = (int*)malloc(run_size * sizeof(int));
    bool more_input = true;
    int next_output_file = 0;

    int i;
    while(more_input){
        for(i = 0;i<run_size;i++){
            if(fscanf(in, "%d ", &arr[i])!=1){
                more_input = false;
                break;
            }
        }

        mergesort(arr, 0 , i-1);

        for(int j = 0; j<i;j++){
            fprintf(out[next_output_file],"%d ", arr[j]);
        }
        next_output_file++;
    }

    for(int i = 0; i<num_ways; i++){
        fclose(out[i]);
    }
    fclose(in);
}

/*a recursive method to heapify. a subtree with roo. at give index. this method assumes that the subtrees are already heapified*/

void externalsort(char* input_file, char* output_file, int num_ways, int run_size){
    createInitialRuns(input_file, run_size, num_ways);
    mergeFiles(output_file, run_size, num_ways);
}

int main(void){
    int num_ways = 10;
    int run_size = 1000;
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    FILE* in = openFile(input_file, "w");
    srand(time(NULL));

    for(int i =0;i<num_ways * run_size;i++){
        fprintf(in,"%d ", rand());
    }
    fclose(in);
    externalSort(input_file, output_file, num_ways, run_size);
    return 0;
}
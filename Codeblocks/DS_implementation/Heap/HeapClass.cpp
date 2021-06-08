#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

class Heap {
private:
    unsigned arr_size;   /// real size of allocked memory = heap_size + 1
    int * arr;           /// arr[0] = heap_size, arr[1] --> root
public:
    
    Heap(const int * x = NULL, unsigned n = 0);
    
    unsigned Parent(unsigned i) {
        return i / 2;
    }
    unsigned Left  (unsigned i) {
        return i * 2;
    }
    unsigned Right (unsigned i) {
        return i * 2 + 1;
    }
    
    void BuildHeap();
    int ExtraxtMax();
    void HeapInsert(int x);
    void Heapify(unsigned i = 1);
    void HeapSort();
    void print();
    
    ~Heap() {
        delete [] arr;
    }
};

Heap::Heap(const int * x, unsigned n) : arr_size(n + 1),  arr(new int[n + 1]()) {
    if (x != NULL && n == 0) {
        cout << "Wrong initialisation" << endl;
        return;
    }
    arr[0] = n; /// heap_size = arr_size - 1 = n;
    for (unsigned i = 1; i <= n; ++i) {
        arr[i] = x[i - 1];
    }

    /// immediately make a heap from the array
    BuildHeap();
}

void Heap::BuildHeap() {
    /// Left(i), Right(i) --> obvious : n/2, ..., n --> leaves
    for (unsigned i = 1 + (arr[0]) / 2; i; --i) { /// "1 + ..." because indexes from 1
        Heapify(i);
    }
}

int Heap::ExtraxtMax() {
    if (arr[0] == 0) {
        //cout << "ExtractMax : heat is empty" << endl;
        return INT32_MAX;
    }
    int max = arr[1];
    arr[1] = arr[arr[0]];
    --arr[0];
    Heapify();
    return max;
}

void Heap::HeapInsert(int x) {
    ++arr_size;
    int * b = new int[arr_size];
    for (unsigned i = 0; i < arr_size - 1; ++i) {
        b[i] = arr[i];
    }
    ++b[0];
    unsigned i;
    for (i = arr_size - 1; i > 0 && arr[Parent(i)] < x; i = Parent(i)) {
        b[i] = b[Parent(i)];
    }
    b[i] = x;
    delete [] arr;
    arr = b;
}

void Heap::Heapify(unsigned i) {
    
    if (i > (unsigned) arr[0]) { /// i > heap_size
        return;
    }
    
    unsigned left  = Left(i);
    unsigned right = Right(i);
    unsigned max_child = i;
    /// remember : maybe left, right don't exist (left > arr[0])
    /// arr[0] = arr_size = heap_size + 1 ---> indexes from 1 to arr[0] = heap_size
    /// also remember ---> left <= arr[0] <=> left <= heap_size
    if (left <= (unsigned) arr[0] && arr[left] > arr[max_child]) {
        max_child = left;
    }
    if (right <= (unsigned) arr[0] && arr[right] > arr[max_child]) {
        max_child = right;
    }

    /// if one of children is bigger then i(parent) ---> heapify
    if (i != max_child) {
        
        int buf = arr[i];
        arr[i] = arr[max_child];
        arr[max_child] = buf;

        Heapify(max_child);
    }
}

void Heap::HeapSort() {
    if (arr_size == 1) {
        cout << "HeapSort : heap is empty" << endl;
        return;
    }
    BuildHeap();
    /// arr[0] = heap_size;
    int buf;
    for (unsigned it = arr[0]; it >= 1; --it) {
/*
	cout << std::setw(2) << it << " : ";
	for (unsigned j = 1; j < arr_size; ++j) {
            cout << std::setw(3) << std::setfill('0') << arr[j] << " " ;
	}
	cout << endl;
*/
        
        buf = arr[1];                 /// swap the greatest element with
        arr[1] = arr[it];             /// the last in array and decrease
        arr[it] = buf;                /// heap_size = arr[0] - 1
        --arr[0];                     /// --heap_size;
        
        
/*
	cout << "     ";
	for (unsigned j = 1; j < arr_size; ++j) {
            cout << std::setw(3) << std::setfill('0') << arr[j] << " " ;
	}
	cout << endl << endl;
*/
        
        
        
        Heapify();                    /// get the largest as a root
    }
    arr[0] = arr_size - 1;
}

void Heap::print() {
    if (arr[0] == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    for (unsigned i = 1; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main () {
    unsigned n, k;
    cin >> n >> k;
    
    int * a = new int[n];
    for (unsigned i = 0; i < n; ++i) {
        cin >> a[i];
//	a[i] = a[i] % 200;
    }

    Heap heap(a, n);
    //heap.BuildHeap();
    //heap.HeapSort();
    //heap.print();
    
    heap.HeapInsert(k);
    heap.print();

    delete [] a;
    return 0;
}

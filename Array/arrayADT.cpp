#include <iostream>
#include <algorithm>

using namespace std;

// Array Class with its variables and operations
class Array {
public:
    int *A;
    int size;
    int length;
    
    Array(int size, int length) {
        this->size = size;
        this->length = length;
        A = new int[size];
    }
    
    ~Array() {
        delete[] A;
    }

    // Method Declarations
    void Display();
    void Append(int number);
    void Insert(int index, int value);
    void Delete(int index);
    void SearchResult(int index);
    void Sort(); // Method Declaration Pending
    int LinearSearch(int key);
    int TranspositionLinearSearch(int key);
    int MoveToHeadLinearSearch(int key);
    int IterativeBinarySearch(int key);
    int RecursiveBinarySearch(int key,int low, int high);
    void GetElement(int index);
    void SetElement(int index, int key);
    int MaximumElement();
    int SortedMaximumElement();
    int MinimumElement();
    int SortedMinimumElement();
    void Reverse();
    void LeftShift();
    void LeftRotate();
    void RightShift();
    void RightRotate();
};
// Method Definations
void Array::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl; // Add this line to move to the next line after displaying all elements
}

void Array::Append(int number) {
    if (length < size) { // Check to prevent out-of-bounds access
        A[length] = number;
        length++;
    } else {
        cout << "Array is full. Cannot append the number." << endl;
    }
}

void Array::Insert(int index, int value){
    if(length < size && index >= 0 && index <=  length){
        for(int i = length; i > index; i--){
            A[i] = A[i-1];
        }
    A[index] = value;
    length++;
    }else{
        cout<<"Array is full or index is out of bounds. Cannot insert the number."<< endl;
    }

}

void Array::Delete(int index){
    if(index >= 0 && index < length){
        for(int i = index;i < length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
    }else{
        cout<<"Index is out of bounds.\n";
    }
}

void Array::SearchResult(int index){
    if(index == -1){
        cout<<"Key is not present."<<endl;
    }else{
        cout<<"Key present at index["<<index<<"]."<<endl;
    }
}

void Array::Sort(){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int Array::LinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            return i;
        }
    }return -1;
}

int Array::TranspositionLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            if (i > 0){
                swap(A[i],A[i-1]);
                return i-1;
            }else{
                return i;
            }
            
        }
    }
    return -1;
}

int Array::MoveToHeadLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            if (i > 0) {
                swap(A[i], A[0]);
                return 0;
            } else {
                return i;
            }
        }
    }
    return -1;
}

int Array::IterativeBinarySearch(int key){
    int low = 0;
    int high = length - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(key == A[mid]){
            return mid;
        }else if(key < A[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int Array::RecursiveBinarySearch(int key,int low,int high){
    if(low <= high){
        int mid = low + (high - low) / 2;
        if(key == A[mid]){
            return mid;
        }else if(key < A[mid]){
            return RecursiveBinarySearch(key,0,mid-1);
        }else{
            return RecursiveBinarySearch(key,mid+1,high);
        }
    }
    return -1;
}

void Array::GetElement(int index){
    if(index >=0 && index < length){
        cout<<"Element at index"<<"["<<index<<"]: "<<A[index]<<endl;
    }else{
        cout<<"Index out of bounds."<<endl;
    }
}

void Array::SetElement(int index,int key){
    if(index >=0 && index < length){
        A[index] = key;
    }else{
        cout<<"Index out of bounds."<<endl;
    }
}

int Array::MaximumElement(){
    int max = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::SortedMaximumElement(){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
    int max = A[length -  1];
    return max;
}

int Array::MinimumElement(){
    int min = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::SortedMinimumElement(){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
    int min = A[0];
    return min;
}

void Array::Reverse(){
    for(int i = 0, j = length - 1; i < j; i++,j--){
        swap(A[i],A[j]);
    }
}

void Array::LeftShift(){
    for(int i = 0;  i < length; i++){
        A[i] = A[i+1];
    }
    A[length - 1] = 0;
}

void Array::LeftRotate(){
    A[length - 1] = A[0];
    for(int i = 0;  i < length; i++){
        A[i] = A[i+1];
    }
}

void Array::RightShift(){
    for(int i = length - 1;i > 0;i--){
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

void Array::RightRotate(){
    int temp = A[length - 1];
    for(int i = length - 1; i > 0; i--){
        A[i] = A[i - 1];
    }
    A[0] = temp;
}


/* ************************************************************************** */

int main() {
    int size, length;
    cout << "Enter size of Array: ";
    cin >> size;
    cout << "Number of elements to be filled: ";
    cin >> length;
    if(length > size) {
        cout << "Length cannot be greater than size." << endl;
        return 1;
    }
    Array arra(size,length);
    for (int i = 0; i < arra.length; i++) {
        arra.A[i] = rand() % 50;
    }

    // Display Array
    arra.Display();
    // Example of appending a number
    // arra.Append(50);
    // arra.Display();
    // arra.Insert(5,50);
    // int searchResult = arra.LinearSearch(5);
    //arra.SearchResult(searchResult);
    // arra.Display();
    // arra.Sort();
    // arra.Display();
    // int key;
    // cin>>key;
    // int r = arra.RecursiveBinarySearch(key,0,length--);
    // arra.SearchResult(r);
    // int index;
    int T;
    cin>>T;
    while (T--)
    {
        // cin >> index;
        // arra.RightShift();
        arra.Display();
        arra.LeftRotate;
        arra.Display();
        arra.RightRotate();
        arra.Display();
    }
    
    return 0;
}

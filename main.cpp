#include<iostream>
#include<fstream>
#include<string>
#include "functions.h"
using namespace std;

bool getArray(int arr[], int *length) // 
{
ifstream fp("integers.txt"); // txt file to open

if(!fp.is_open())
{
cout<<"file could not open"; // if already open error check 
return false;
}

*length = 0;

while(fp >> arr[*length]) // loop and add to array
{
*length = *length + 1;
}

fp.close();

return true;
}

void printArray(int arr[], int length) // function to print the array 
{
cout<<endl<<"the array is:"; // telling the user the array is as follows

for(int i=0; i<length; i++) // looping
cout<<arr[i]<<" ";

cout<<endl;
}

int searchInteger(int arr[], int length, int key) // function to search the array for an integer 
{
int i;

for(i = length - 1; i >= 0 ; i--) // looping through 
if(arr[i] == key)
return i;

return i;
}

int modifyArray(int arr[], int index) // function to change a value inside the array
{
int key;
try {
cout<<"Enter new value to be changed: "; // asking user for a value to be changed inside array 
cin>>key;
  if (key <=100 ) {
    arr[index] = key;
    return key;
  } else {
    cout<<"Please enter an integer between 0 and 100: "; cin >> key;
  }
  } 
catch (int key) {
  cout << "Must enter an integer";
  }

}

void addInt(int arr[], int *length) // function to add int 
{
int element;
string st;
try {
cout<<endl<<"enter a new integer:"; // asking user to enter item 
cin>>element;
if (element <=100 ) {
    arr[*length] = element;

*length = *length + 1;

cout<<"integer added";
} else {
    cout<<"Please enter an integer between 0 and 100 "; cin >> element;
  }
  } 
catch (int element) {
  cout << "Must enter an integer";
  }

}
  
void removeInt(int arr[], int *length)
{
int index;

cout<<endl<<"enter int to be removed:"; // asking user to enter item 
cin>>index;

for(int i = index; i < *length - 1; i++) // looping
arr[i] = arr[i+1];

*length = *length - 1;

}
int main()
{
int arr[50], length, index, key; // initiliazing array 

if(!getArray(arr, &length))
return 0;

printArray(arr, length); // calling on print fn

///////////////searching////////////////////
cout<<"Enter the element to be searched: ";
cin>>key;

index = searchInteger(arr, length, key); //

if(index == -1)
cout<<"Element not found";

else
cout<<key<<" is present at index "<<index;


cout<<endl<<endl<<"Enter the index to be modified: ";
cin>>index;

key =modifyArray(arr, index);

cout<<arr[index]<<" Value changed to "<<key;

cout<<endl<<"New Array";
printArray(arr, length);


addInt(arr, &length); //adding an int 

cout<<endl<<"New Array"; 
printArray(arr, length);


removeInt(arr, &length); // removing an int this is causing an error I cant figure out????????

cout<<endl<<"New Array:"; // print the final array at the end 
printArray(arr, length);

return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

int count =0;
int main(int argc,char*argv[]){

if(argc ==2){
ifstream ab("input.txt");
string s;
while(getline(ab,s)){
count++;
}

int n =count;
int** arr = new int*[n];
for(int i = 0; i < n;i++){
    arr[i] = new int[n];
}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  arr[i][j]=0;
	}
}

ifstream is("input.txt");
string a;
int x=0;
while(getline(is,a)){
	stringstream ss(a);
	string d;
	int i=1;
	int y=0;
	while(getline(ss,d,',')){
             arr[x][y]=atoi(d.c_str());
              //cout<<arr[x][y]<<",";
	y++;
	}
	x++;
}

 for (int k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < n; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of arr[i][j]
                if (arr[i][k]+ arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
 
    // Print the shortest arrance matrix
    //printSolution(arr);
    
    cout<<"Following matrix shows the shortest distances between every pair of vertices"<<endl;
    for (int i = 0; i < n; i++)
    { int a =500;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] ==a)
               cout<< a<<" ";
            else
               cout<< arr[i][j]<<" ";
        }
cout<<endl;
    } 

}
//cout<<"count is"<<count<<endl;
return 0;
}


#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
using namespace std;

void main()
{
  int Value[20];
  int i, j, k, N;
  int temp;
  bool swap;
  cout<<"Enter multiple numbers : ";
  cin>>N;
  for(i=0; i<N; i++)
  {
    cout<<"Element "<<i<<" : ";
    cin>>Value[i];
  }
}
//Print out before sorted
cout<<"\nData before sorted : ";
for(i=0; i<N; i++)
  cout<<setw(3)<<Value[i];
  
//Sorting process
i=0;
swap = true;
while ((i<=N-2) && (swap))
{
  swap = false;
  for(j=N-1; j>=i+1; j--)
  {
    if(Value[j] < Value[j-1])
    {
      {
        temp = Value[j];
        Value[j] = Value[j-1];
        Value[j-1] = temp;
        swap = true;
        cout<<"\nFor j = " <<j<<" : ";
        for(k=0; k<N; k++)
          cout<<set(3)<<Value[k];
      }
    }
    i++;
  }
  
  //Output after sorted
  cout<<"\nData after sorted : ";
  for(i=0; i<N; i++)
    cout<<setw(3)<<Value[i];
  getch();
}
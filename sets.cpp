#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void InputSet(int Set[],int& brSet)
{
	cout<<"Enter elements number:";
	cin>>brSet;
	cout<<"Enter set elements:";
	for (int i=0; i<brSet; i++) 
	 { cout<<"Element "<<i+1<<":";
	   cin>>Set[i];
	 }
}

void ViewSet(int arr[], int count)             
{
  system("cls");
  if (count==0) { cout<<"\nEmpty set!\n";
                     return;
                   }
  cout<<"LIST OF ELEMENTS:\n";

  for (int i=0; i<count; i++)
  { 
    cout<<setw(5)<<arr[i];
  }
  cout<<endl; 
}

bool Present(int Set1[], int brSet, int el)
{
	for (int i=0; i<brSet; i++)
	   if (Set1[i]==el) return true;
	return false;   
}

void UnionSet(int Set1[], int brSet1, int Set2[], int brSet2)
{
	int Union[brSet1+brSet2];
	int UnionCount=0;
	for (int i=0; i<brSet1+brSet2; i++) Union[i]=0;
	
	for (int i=0; i<brSet1; i++)
	   if (!Present(Union,UnionCount, Set1[i])) 
	   { Union[UnionCount]= Set1[i];
	     UnionCount++;
	   }
	  
	for (int i=0; i<brSet2; i++)
	   if (!Present(Union,UnionCount, Set2[i])) 
	   { Union[UnionCount]= Set2[i];
	     UnionCount++;
	   } 
	cout<<"\nUnion:\n" ;  
	ViewSet(Union, UnionCount) ;  
}

void SectSet(int Set1[], int brSet1, int Set2[], int brSet2)
{
	int Sect[brSet1+brSet2];
	int SectCount=0;
	
	for (int i=0; i<brSet1+brSet2; i++) Sect[i]=0;
	
	for (int i=0; i<brSet1; i++)
	   if (Present(Set2,brSet2, Set1[i]) and !Present(Sect,SectCount,Set1[i])) 
	   { Sect[SectCount]= Set1[i];
	     SectCount++;
	   }
	  
	for (int i=0; i<brSet2; i++)
	   if (Present(Set1,brSet1, Set2[i]) and !Present(Sect,SectCount,Set2[i])) 
	   { Sect[SectCount]= Set1[i];
	     SectCount++;
	   }
	cout<<"\nSection:\n" ;  
	ViewSet(Sect, SectCount) ;  	
}
void DiffSet(int Set1[], int brSet1, int Set2[], int brSet2)
{
	int Diff[brSet1+brSet2];
	int DiffCount=0;
	
	for (int i=0; i<brSet1+brSet2; i++) Diff[i]=0;
	
	for (int i=0; i<brSet1; i++)
	   if (!Present(Set2,brSet2, Set1[i]) and !Present(Diff,DiffCount,Set1[i])) 
	   { Diff[DiffCount]= Set1[i];
	     DiffCount++;
	   }
	  
	cout<<"\nDifference:\n" ;  
	ViewSet(Diff, DiffCount) ;  	
}


//Main menu
void ShowMenu(int Set1[], int& brSet1, int Set2[], int& brSet2)
{ 
  int c;
  do{ 
  	
  cout<<"\nMain menu\n\n";
  cout<<"1 - Enter set 1\n";
  cout<<"2 - Enter set 2\n";
  cout<<"3 - Union\n";
  cout<<"4 - Section\n";
  cout<<"5 - Difference\n";
  cout<<"6 - View set\n";
  cout<<"7 - Quit program\n";
  cout<<"Your choice:";
  cin>>c;
  
  switch(c){
  	 case 1: InputSet(Set1,brSet1); break;
  	 case 2: InputSet(Set2,brSet2); break;
  	 case 3: UnionSet(Set1, brSet1, Set2, brSet2); break;
  	 case 4: SectSet(Set1, brSet1, Set2, brSet2); break;
  	 case 5: DiffSet(Set1, brSet1, Set2, brSet2); break;
  	 case 6: int a;
  	         cout<<"Enter the number of set:";
  	         cin>>a; 
  	         if (a==1) ViewSet(Set1,brSet1); 
  	          else ViewSet(Set2,brSet2); 
  	         break;		   
  	}
  } while (c!=7);
}

int main()	//main function
{ 
 int Set1[100], Set2[100];
 int brSet1=0, brSet2=0;
  
 show_menu(Set1, brSet1, Set2, brSet2);
   
 cout<<"\nEnd of program!";
}


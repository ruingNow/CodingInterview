/****************************************
摘苹果
***************************************/
#include <iostream>
using namespace std;

int a[100005] = {0};
int q[100005] = {0};
int main(void)
{
 int n, Q;
 cin >> n;
 int number = 0;
  for(int k = 0; k < n; ++k)
  {
	  int temp = 0;
    cin >> temp;
	number += temp;
	a[k] = number;
  }
  
  cin >> Q;
 

  int i = 0;
  for(i = 0; i < Q; ++i)
  {
    cin >> q[i];  
	
  }

  for(i = 0; i < Q; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      if(a[j] >= q[i])
      {
        q[i] = j + 1;
        break;
      }
      
    }
  }
  
  for(int l = 0; l < Q; ++l)
  {
   cout << q[l] << endl;  
  }
  
  return 0;
}
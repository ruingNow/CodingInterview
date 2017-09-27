#include <iostream>

using namespace std;

int main(void)
{
  int n, a[105], b;
  cin >> n;
  cin >> a[0];
  n--;
  
  int aLen = 1;
  while(n--)
  {
    cin >> b;
    int i = 0;
    for(; i < aLen; ++i)
      if(b <= a[i])
        break;
    
    if(b < a[i])
    {
     for(int j = aLen - 1; j >= i; --j)
       a[j+1] = a[j];
      
      a[i] = b;
      aLen++;
    }
    else if(b >a[i])
    {
     a[aLen] = b;
      aLen++;
    }
  }
  cout << aLen << endl;
  int p = 0;
  for(p = 0; p < aLen - 1; ++p)
   cout << a[p] << " ";
  
  cout << a[p] << endl;

  return 0;
}
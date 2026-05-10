#include<iostream>
#include<vector>
using namespace std;

int Sum(int n){
      if (n <= 0) return 0;
      if (n == 1) return 1;
      return Sum(n-1)+ n;

}

int mySeries1(int n){
  if ( n<=0) return 0;
  if (n==1) return 1;
  return mySeries1(n-3)+n;

}

int mySeries2 (int n){
  if (n<=0) return 0;
  if (n==1) return 2;
  return mySeries2(n-1) + (4*n -2);

}
int FindNthTerm (int n){
   if (n<=0) return 0;
   if (n==1 || n==2) return n;
   return FindNthTerm (n-1)+3;


}

int main (){
  int n = 10;
  int s = Sum (n);
  cout << "sum of 1 to " << n << ": " << s << endl;
  s = mySeries1(n);
  cout << "sum of myseries1: " << s << endl;
  s = mySeries2 (n);
  cout << "sum of myseries2: " << s << endl;
  int t = FindNthTerm(4);
  cout << "nth Term : " << t << endl;

}

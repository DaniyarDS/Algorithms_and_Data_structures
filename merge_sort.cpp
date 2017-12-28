#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>v){
  for(int i = 0 ; i < v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

vector<int>merge(vector<int>a, vector<int>b){
  vector<int>d;
  //reverse arrayList for O(1) access and delete
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  
  while(!a.empty() && !b.empty()){
    int a_value = a.back();
    int b_value = b.back();
    if(a_value > b_value){
      d.push_back(b_value);
      b.pop_back();
    }  
    else{
      d.push_back(a_value);
      a.pop_back();
    }
  }

  d.insert(d.end(), a.rbegin(), a.rend());
  d.insert(d.end(), b.rbegin(), b.rend());
  
  print(d);
  
  return d;
}


vector<int>merge_sort(vector<int>v){
  if(v.size()==1){
    return v;
  }
  int m = v.size()/2;
  
  vector<int> a(v.begin(), v.begin()+m);
  vector<int> b(v.begin()+m, v.end());
  vector<int>A,B,C;

  A = merge_sort(a);
  B = merge_sort(b);
  C = merge(A,B);

  return C;
}

int n,x;
int main() {
  
  cin >> n;
  
  vector<int> v(n);
  
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  vector<int> res;
  res = merge_sort(v);
  
  for(int i = 0; i < res.size(); i++){
    cout<<res[i]<<" ";
  }


  return 0;  
}


    
    
    
    
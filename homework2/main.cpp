#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define g 9.81

double h0;
double vx;
double vy;

double y(double x){
  return (-(g/(2*pow(vx,2)))*pow(x,2) + (vy/vx)*x + h0);}

int ans(int n, set<int> s){
  for (int i = 0; i < n; i++){
    if (s.count(i) == 0){
      return i;
    }
  }
  return 0;}

int solve(vector<vector<double>> bars){
  int zones = bars.size()+1;
  set <int> forbid; 
  int i = 0;
  bool right = true; 
  while (i < bars.size()){ 
      
    if (y(bars[i][0]) <= bars[i][1]){ 
    
      if (right){
        for (int j=i; j < bars.size(); j++){
          forbid.insert(int(bars[j][2]));}
      }else{
        forbid.insert(0);
        for (int j=i+1; j < bars.size(); j++){
          forbid.insert(int(bars[j][2]));}
      }
      
      right = !right; 
      if (zones - forbid.size() == 1){ 
        return ans(zones, forbid);} 
        
      vector<vector<double>> bars1 = bars;
      for (int j=0; j < bars.size(); j++){
        bars1[j][0] = 2*bars[i][0] - bars[j][0];}
      reverse( bars1.begin(), bars1.end() );
      bars = bars1;
      i = bars.size()-i-1;
    }
    i += 1;
  }
  
  if (!right){ 
    return int(0); 
  }else{ 
    return bars.size(); // ответ - последняя зона
  }
  return 0;
}


int main(int argc, char** argv) {
  if(argc == 2){
      
  }else{
      
  }
  

  ifstream file (argv[1]);
  file >> h0;
  file >> vx >> vy;
  vector<vector<double>> bars;
  double x = 0;
  double h = 0;
  double n = 1; 
  while (file >> x){
    file >> h;
    bars.push_back({x,h,n});
    n++;
  }
  file.close();

  cout << solve(bars);
  return 0;
}

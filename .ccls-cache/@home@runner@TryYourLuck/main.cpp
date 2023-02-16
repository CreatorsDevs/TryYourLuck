#include <iostream>
#include <limits>
using namespace std;

enum Box{
R = 10,
B = 20
};

string RandomString(){
  const int ch_MAX = 2;
  char alpha[ch_MAX] = {'R', 'B'};

  int ch = (rand() % 5) + 1;
  
  string result = "";
  for(int i=0; i<ch; i++){
    result += alpha[rand() % ch_MAX];
  }
  return result;
}

int main() {
  srand(time(0));
  int n;
  Box box;
  int sum = 0;
  char restart;
  
  cout << "\nTry your luck!\nPress enter to continue";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string str = RandomString();
  cout << "String: " << str <<endl;

  int count = 1;
  for(int i=0; i < str.size(); ++i){
    if(str[i] == 'R'){
      box = R;
      if(str[i] == str[i+1]){
        int temp = box;
        temp = count*temp;
        sum += temp;
        count++;
      }
      else
        count = 1;
    }
    else if(str[i] == 'B'){
      box = B;
      if(str[i] == str[i+1]){
        int temp = box;
        temp = count*temp;
        sum += temp;
        count++;
      }
      else
        count = 1;
    }
    sum += box;
  }
  cout << "Score: " << sum <<endl;

  return 0;
}
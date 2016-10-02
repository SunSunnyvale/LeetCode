#include <iostream>

using namespace std;
class PGObject{
  public:
  
  void swap(char& char1,char& char2 ){
    char temp;
    temp=char1;
    char1=char2;
    char2=temp;
  }
  
  void sortByColor(string a){
    int size=a.size();
    cout<<"\n Size::"<<size;
    uint16_t currentBlue=size-1;
    uint16_t currentPtr=0;
    char currentColor='a';
    
      
      for(int i=0;i<size;i++){
        while(a[currentPtr] == currentColor && currentPtr < size ){
          cout<<" a[currentPtr]"<< a[currentPtr];
          currentPtr++;
        }
        
        
        int nextPtr=currentPtr;
        while(a[nextPtr]!= currentColor && nextPtr < size){
          if(a[nextPtr]=='c'){
            if(currentBlue > nextPtr){
              swap(a[currentBlue], a[nextPtr]);
              cout<<"\n String::"<< a;
              currentBlue--;
            }
            if(a[nextPtr]==currentColor){
              break;
            }
            
          }
          nextPtr++;
        }

        if(nextPtr!=size ){
          swap(a[currentPtr], a[nextPtr]);
          currentPtr++;
          i=currentPtr;
        }else{
          break;
        }      
        cout<<"\nSorted String::"<<a;
        cout<<"\ncurrentPtr::"<<currentPtr;
      }
      cout<<"\nSorted String::"<<a;
            
    }
  
};

int main() {
  PGObject obj;
  //obj.sortByColor("abccbba");
  obj.sortByColor("cba");
  // obj.sortByColor("ccccbbbaaaa");
  // obj.sortByColor("aabcbbaa");
  // obj.sortByColor("cccbbb");
  ///obj.sortByColor("ccccccc");
  //obj.sortByColor("aaaaaaa");
  return 0;
}

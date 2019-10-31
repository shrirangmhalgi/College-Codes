#include "iostream"
#include "map"
using namespace std;

int main() {
  map<string,string> m;
  map<string,string> :: iterator it;
  pair<string,string> p;
  int op;

  do{
    cout<<"1.Enter a Word\n2.Search a Meaning\n3.Delete a Word\n4.Display\n5.Exit\n";
    cin>>op;
    switch(op) {
      case 1: {
      cout<<"Enter the Word : ";
      cin>>p.first;
      it= m.find(p.first);
      if(it==m.end()) {
        cout<<"Enter the Meaning for this Word : ";
        cin>>p.second;
        m.insert(p);
      }
      else cout<<"Word Already Present..!!\n";
      break;
    }
      case 2: {
        string word;
        cout<<"Enter the Word to be Searched : ";
        cin>>word;
        it=m.find(word);
        if(it!=m.end()) {
          cout<<"Word Found !!\nWord : "<<it->first<<"; Meaning : "<<it->second<<";\n";
        }
        else cout<<"Word not Present\n";
        break;
      }
      case 3 : {
        string word;
        cout<<"Enter the Word to be Deleted : ";
        cin>>word;
        it=m.find(word);
        if(it!=m.end()) {
          m.erase(it);
          cout<<"Word Deleted ..!!\n";
        }
        else cout<<"Word Not Present or Already Deleted ..!!\n";
        break;
      }
      case 4: {
        cout<<"Contents of your Dictionary are ---\n";
        for(it=m.begin();it!=m.end();it++) {
          cout<<"Word : "<<it->first<<"; Meaning : "<<it->second<<";\n";
        }
        break;
      }
      default : return 0;
    }
  }while(1);


  return 0;
}

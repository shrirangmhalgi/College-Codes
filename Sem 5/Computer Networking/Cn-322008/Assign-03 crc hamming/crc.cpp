#include<iostream>
using namespace std;

class CRC{
   int frameSize;
   int generatorSize;
   int totalSize;
   int *frame;
   int *tempFrame;
   int *generator;
   
   public :
      CRC(){
         cout<<"enter the frame size"<<endl;
         cin>>frameSize;
         cout<<"enter the generator size"<<endl;
         cin>>generatorSize;
         
         totalSize = frameSize + generatorSize - 1;
         
         frame = new int[totalSize];
         tempFrame = new int[totalSize];
         generator = new int[generatorSize];
      }
      
      int accept();
      void sender();
      void receiver();

};


int main(){
   CRC crc;
   if(crc.accept() == 0){
      return 0;
   }
   crc.sender();
   crc.receiver(); 
}

int CRC :: accept(){
   //accepting the frame from the sender
   cout<<"enter the frame bit by bit:-"<<endl;
   for(int i = 0; i < frameSize; i++){
      cin>>frame[i];
      tempFrame[i] = frame[i];
   }
   
   //appending 0s to the frame
   for(int i = frameSize; i < totalSize; i++){
      frame[i] = 0;
      tempFrame[i] = 0; 
   }
   
   //accepting the generator
      cout<<"enter the generator bit by bit:-"<<endl;
   for(int i = 0; i < generatorSize; i++){
      cin>>generator[i];
      if(generator[0] == 0){
         cout<<"error in entering the generator exitting the system";
         return 0;
      }
   }
}

void CRC :: sender(){
   //displying the sender frame and tempframe
   cout<<"frame = ";
   for(int i = 0; i < totalSize; i++){
      cout<<frame[i];
   }
   
   cout<<"\nbefore division tempframe = ";
   for(int i = 0; i < totalSize; i++){
      cout<<tempFrame[i];
   }
   
   cout<<"\ngenerator = ";
   for(int i = 0; i < generatorSize; i++){
      cout<<generator[i];
   }
   
   //performing the division
   for(int i = 0; i < frameSize; i++){
      if(tempFrame[i] == 0)
         continue;
      
      for(int j = 0; j < generatorSize; j++){
         if(tempFrame[i + j] == generator[j]){
            tempFrame[i + j] = 0;
         }
         else{
            tempFrame[i + j] = 1;
         }
      }
   }
   
   cout<<"\nremainder after division = ";
   for(int i = frameSize; i < totalSize; i++){
      cout<<tempFrame[i];
   }   
   
   //appending the remainder to the frame
   for(int i = frameSize; i < totalSize; i++){
      frame[i] = tempFrame[i];
   }
   
   //display the final frame
   cout<<"\nframe sent after appending the crc is = ";
   for(int i = 0; i < totalSize; i++){
      cout<<frame[i];
   }
}

void CRC :: receiver(){ 
   //initializing the tempFrame
   for(int i = 0; i < totalSize; i++){
      tempFrame[i] = frame[i];
   }
   
   //introducing error
   int choice;
   cout<<"\ndo you want to introduce error? 0 : no \n1 : yes"<<endl;
   cin>>choice;
   if(choice != 0){
      cout<<"enter the position you want to insert error (should be less than totalsize of the frame)"<<endl;
      cin>>choice; //using choice to accept error as well as choice
      if(tempFrame[choice] == 1){
            tempFrame[choice] = 0;
      }
      else{
         tempFrame[choice] = 1;
      }
      
   }
   
   //performing division
   for(int i = 0; i < frameSize; i++){
      if(tempFrame[i] == 0)
         continue;
      
      for(int j = 0; j < generatorSize; j++){
         if(tempFrame[i + j] == generator[j]){
            tempFrame[i + j] = 0;
         }
         else{
            tempFrame[i + j] = 1;
         }
      }
   }
   
   cout<<"\nremainder after division = ";
   for(int i = frameSize; i < totalSize; i++){
      cout<<tempFrame[i];
   }
   
   //checking the crc
   bool flag = false;
   for(int i = frameSize; i < totalSize; i++){
      if(tempFrame[i] != 0){
         flag = true;
         break;
      }
   }
   
   if(flag){
      cout<<"\nerror present in crc "<<endl;
   }
   else{
   cout<<"\nnoerror present in crc "<<endl;
   }
}



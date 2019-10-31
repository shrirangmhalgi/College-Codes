#include<iostream>
#include<math.h>
using namespace std;

class Hamming{
   int sender[12];
   int parity[5];
   int receiver[12];
   
   public:
      Hamming(){
         for(int i = 11; i > 0; i--){
            sender[i] = 0;
            receiver[i] = 0;
         }
      }
      
      void input();
      void calculate();
};

int main(){
   Hamming hamming;
   hamming.input();
   hamming.calculate();
}

void Hamming :: input(){

   //accept 7 bit data to be sent
   cout<<"\nenter the 7 bit data to be sent bit by bit"<<endl;
   for(int i = 11; i > 0; i--){
      if(i == 1 || i == 2 || i == 4 || i == 8){
         continue;
      }
      cin>>sender[i];
   }
   
   //calculate and append the parity bits
   sender[1] = sender[1] ^ sender[3] ^ sender[5] ^ sender[7] ^ sender[9] ^ sender[11];
   sender[2] = sender[2] ^ sender[3] ^ sender[6] ^ sender[7] ^ sender[10] ^ sender[11];
   sender[4] = sender[4] ^ sender[5] ^ sender[6] ^ sender[7];
   sender[8] = sender[8] ^ sender[9] ^ sender[10] ^ sender[11];
   
   //display the sender data
   cout<<"\ndata sent to the sender is"<<endl;
   for(int i = 11; i > 0; i--){
      cout<<sender[i];
   }  
}

void Hamming :: calculate(){

   //accept the 11 bit received data
   cout<<"\nenter the 11 bit data received bit by bit"<<endl;
   for(int i = 11; i > 0; i--){
      cin>>receiver[i];
   }
   
   //display the sent data
   cout<<"\ndata received is"<<endl;
   for(int i = 11; i > 0; i--){
      cout<<receiver[i];
   }
   
   //calcuate the parity bits
   parity[1] = receiver[1] ^ receiver[3] ^ receiver[5] ^ receiver[7] ^ receiver[9] ^ receiver[11];
   parity[2] = receiver[2] ^ receiver[3] ^ receiver[6] ^ receiver[7] ^ receiver[10] ^ receiver[11];
   parity[3] = receiver[4] ^ receiver[5] ^ receiver[6] ^ receiver[7];
   parity[4] = receiver[8] ^ receiver[9] ^ receiver[10] ^ receiver[11];
   
   //calculate the error
   if(parity[1] == 0 && parity[2] == 0 && parity[3] == 0 && parity[4] == 0){
      cout<<"\nno error present in the data"<<endl;
   }
   else{
      cout<<"\nerror present in the data in binary = "<<endl;
      for(int i = 4; i > 0; i--){
         cout<<parity[i];
      }
      
      int pos = 0;
      
      for(int i = 4; i > 0; i--){
         int p = i - 1;
         if(parity[i] != 0){
            pos = pos + pow(2, p);
         }
      }
      cout<<"\nerror position in decimal = "<<pos<<endl; 
   }  
}


#include <iostream>

#include <stdlib.h>

#include <math.h>

#include <time.h>

using namespace std;





class Players {public :
   
   
   
   char  player1 [30] ;
   
   char  player2 [30] ;
   
   int hitpointplayer1 = 100 ;
   
   int hitpointplayer2 = 100 ;
   
   int estimateplayer1 ;
   
   int estimateplayer2 ;
    
};



class Hit {
    public:

    int damageplayer1 ;
    int damageplayer2 ;
    
Hit(){
    srand(time(0));
     }

int getDamagePlayer1(){
return   rand() % 10 ;

}
int getDamagePlayer2(){
return   rand() % 10 ;

}

    

};

class startWar : public Hit , public Players  {
    
    public: 

    Hit player1Hit;
    
    Hit player2Hit;
   
    Players Player1Health;

    Players Player2Health;

    Players player1;
    
    Players player2;
    
    Players guessplayer1;
   
    Players guessplayer2;
    
    int p1gs , p2gs ;
   
   int takeNumbers(Players* namesPlayer1, Players* namesPlayer2){
   
    Players guessingplayer1 ;
    
    Players guessingplayer2 ;
    
 
    
    int p1gs = 0 , p2gs = 0 ;
    Bracket1: 
    if ( p1gs == p2gs ){
    
    cout << "Enter a number between 1-100 " << endl << namesPlayer1->player1 << endl ;
    
    cin >>  guessingplayer1.estimateplayer1 ;
   
    cout <<  namesPlayer2->player2 << endl;

    cin >> guessingplayer2.estimateplayer2;
   
    int guessingNumber ;
   
    guessingNumber = rand() % 100 + 1;
   
    
    p1gs = std::abs (guessingNumber - guessingplayer1.estimateplayer1   ); 
   
    p2gs = std::abs (guessingNumber - guessingplayer2.estimateplayer2 );
        goto Bracket1;
    }
    
    else if ( p1gs < p2gs ){

        cout << "First Striker " << namesPlayer1->player1 << endl ;
    }
    else {

        cout << " First Striker " << namesPlayer2->player2 << endl ;
    }
    
    return 0;
}

int takeNames(Players* Player1TakeName,Players* Player2TakeName){
     
     
    
     cout << "What is your Names " << endl;
     
     cout << "Player 1 " << endl;        
     
     cin >> Player1TakeName->player1 ;

     cout << "Player 2" << endl;
     
     cin >> Player2TakeName->player2;



    return 0;
}
 int startedwars(Players* namePlayer1,Players* namePlayer2){   
   

         Hit players1Hit;


    
    while(Player1Health.hitpointplayer1 > 0 && Player2Health.hitpointplayer2 > 0){


                int damage1= players1Hit.getDamagePlayer2();
                                        int damage2= players1Hit.getDamagePlayer1();



    if ( damage1 == 0 || damage2 == 0 ){
       
        cout << "Miss" << endl ;
    
    }


      if  ( p1gs < p2gs  ) {
        
        
         
        if(Player1Health.hitpointplayer1 > 0 ){


         cout << namePlayer1->player1  << "    health:      " <<Player1Health.hitpointplayer1 - damage2   << endl ;
         
         Player1Health.hitpointplayer1  = Player1Health.hitpointplayer1 -  damage2;
         
         
        
        }

        else if (Player1Health.hitpointplayer1 < 0){return 0;}

        if(Player2Health.hitpointplayer2 > 0){



        cout << namePlayer2->player2  <<"    health:      " << Player2Health.hitpointplayer2 -  damage1  << endl ;
        
        Player2Health.hitpointplayer2 = Player2Health.hitpointplayer2 -  damage1;
    
        
        

        }

        else if (Player2Health.hitpointplayer2 < 0){return 0;}

      }
      
      else  {
        
         
         if(Player1Health.hitpointplayer1 > 0 && Player2Health.hitpointplayer2 > 0){ 
         
          cout << namePlayer2->player2 << "    health:      " <<Player1Health.hitpointplayer1 - damage2 << endl ;
         
          Player1Health.hitpointplayer1 = Player1Health.hitpointplayer1 -  damage2;
          
         }
          
          if(Player1Health.hitpointplayer1 > 0 && Player2Health.hitpointplayer2 > 0){ 
          
          cout << namePlayer1->player1  << "    health:      " << Player2Health.hitpointplayer2 -  damage1  << endl ;
          
          Player2Health.hitpointplayer2 = Player2Health.hitpointplayer2 -  damage1;
        
          }

         

        
      }
    }
    return 0;

 }  
    

 int WriteWinners(Players* Player1Health,Players* Player2Health){

     if (Player1Health->hitpointplayer1 > Player2Health->hitpointplayer2){

         cout << Player1Health->player1 << "Win!" << endl;
     }

    else if (Player1Health->hitpointplayer1 == Player2Health->hitpointplayer2){

        cout  << "Tie!" << endl;

    }
    
    else {

        cout << Player2Health->player2 << "Win!" << endl;
    }
    return 0;
 }

};



 int main()
 
 {
    startWar st;

    Players player1;
    Players player2;
    
    st.takeNames( &player1, &player2  );
        
    st.takeNumbers(&player1, &player2 );
    
    st.startedwars(&player1,&player2);
    
    st.WriteWinners(&player1,&player2);

        return 0;

      }
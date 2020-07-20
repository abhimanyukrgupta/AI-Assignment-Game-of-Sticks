#include <bits/stdc++.h>
#include <math.h>
#include <windows.h>

using namespace std;
int tossFunc()
	{
	cout<<"Ready to toss!..."<<endl;
    srand(time(0));
	return rand()%2;	
	}
struct resStruct{
  int dpth;
  int value;
  int move;
};

resStruct minimax(int n,int depth,bool player,int alpha,int beta)
{  int i;
   resStruct a,b;
   b.value=0;b.dpth=0;b.move=0;
   if(n==1)
    {
        if(player)
        {
             a.value = -10;
             a.dpth = depth;
             a.move = 0;
             return a;
        }
        else
         {
             a.value = 10;
             a.dpth = depth;
             a.move =0;
             return a;
        }
    }
    
    if(player)
    {  int mx=-999;
       int m=999;
        for(i=3;i>=1;i--)
        {  if(n-i>=1)
            {
            b= minimax(n-i,depth+1,false,alpha,beta);
            if(b.value>=mx && b.value!=0)
            {  if(b.value==mx)
                { if(b.dpth<m)
                    {
                    a.value=b.value;
                    a.dpth=b.dpth;
                    a.move = i;
                    }
                }
               else
                   {
                    mx=b.value;
                    a.value=b.value;
                    a.dpth=b.dpth;
                    a.move = i;
                   }
            }
            alpha=max(alpha,b.value);
            if(beta<alpha)
                break;
           }
        }
     return a;
    }
    else
    {
       int m =999;
       int mx=999;
        for(i=3;i>=1;i--)
        { if(n-i>=1)
            {
              b= minimax(n-i,depth+1,true,alpha,beta);
           if(b.value<=mx && b.value!=0)
            {  if(b.value==mx)
                { if(b.dpth<m)
                    {
                    a.value=b.value;
                    a.dpth=b.dpth;
                    a.move = i;
                    }
                }
               else
                   {
                    mx=b.value;
                    a.value=b.value;
                    a.dpth=b.dpth;
                    a.move = i;
                    }

            }
            beta=min(beta,b.value);

            if(beta < alpha )
                break;

           }
        }

     return a;
    }
}


void humanVShuman(int n)
{   
    
    int pOneMove,pTwoMove;
    int toss = tossFunc();

    if(toss==0)
        cout<<"Player 1 won toss"<<endl;
    else
        cout<<"Player 2 won toss"<<endl;

    
    while(1){

    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==1)
               cout<<"Winner: Player 2 "<<endl;
          else
               cout<<"Winner: Player 1 "<<endl;
      }
      if(n==1){
        if(toss==0)
           cout<<"Winner: Player 2 "<<endl;
        else
           cout<<"Winner: Player 1 "<<endl;
      }
    break;
    }
  labelOne: if(toss==0)
       cout<<"Chance: Player 1"<<endl;
    else
       cout<<"Chance: Player 2 "<<endl;

    cin>>pOneMove;
    if(pOneMove<4 && pOneMove>=1)
    n=n-pOneMove;
    else
    { cout<<"Invalid move"<<endl;
      goto labelOne;
    }
     cout<<"Sticks left : :  "<<n<<endl;
    ;

    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==0)
               cout<<"Winner: Player 2 "<<endl;
          else
               cout<<"Winner: Player 1 "<<endl;
      }
      if(n==1){
        if(toss==1)
           cout<<"Winner: Player 2 "<<endl;
        else
           cout<<"Winner: Player 1 "<<endl;
      }
    break;
    }

   labelTwo: if(toss==1)
       cout<<"Chance: Player 1 "<<endl;
    else
       cout<<"Chance: Player 2 "<<endl;

    cin>>pTwoMove;
    if(pTwoMove<4 && pTwoMove>=1)
    n=n-pTwoMove;
    else
    { cout<<"Invalid move"<<endl;
      goto labelTwo;
    }

     cout<<"Sticks left :  "<<n<<endl;
}
cout<<"---------GAME--OVER---------"<<endl;
}



void humanVSai(int n)
{
    
    int pOneMove,pTwoMove,cpu,toss = tossFunc();

    if(toss==0)
        cout<<"Player won toss"<<endl;
    else
        cout<<"CPU won toss"<<endl;

    cout<<"--------start--------"<<endl;

 while(1){
    ;
    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==1)
               cout<<"Winner: CPU "<<endl;
          else
               cout<<"Winner: Player "<<endl;
      }
      if(n==1){
        if(toss==0)
           cout<<"Winner: CPU "<<endl;
        else
           cout<<"Winner: Player "<<endl;
      }
    break;
    }
    if(toss==0)
     {
        l:cout<<"Chance: Player "<<endl;
        cin>>pOneMove;
        if(pOneMove<4 && pOneMove>=1)
        n=n-pOneMove;
        else
        { cout<<"Invalid move"<<endl;
          goto l;
        }
     }
     else
       {
        resStruct res;
        cout<<"Chance: CPU "<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU's move : "<<res.move<<endl;
        n=n-res.move;
       }

     cout<<"Sticks left :  "<<n<<endl;
    ;
    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==0)
               cout<<"Winner: CPU "<<endl;
          else
               cout<<"Winner: Player "<<endl;
      }
      if(n==1){
        if(toss==1)
           cout<<"Winner: CPU "<<endl;
        else
           cout<<"Winner: Player "<<endl;
      }
    break;
    }


   if(toss==1)
     {
        k:cout<<"Chance: Player "<<endl;
        cin>>pTwoMove;
        if(pTwoMove<4 && pTwoMove>=1)
        n=n-pTwoMove;
        else
        { cout<<"Invalid move"<<endl;
          goto k;
        }
     }
     else
       {
        resStruct res;
        cout<<"Chance: CPU "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU's move : "<<res.move<<endl;
        n=n-res.move;
       }

        cout<<"Sticks left :  "<<n<<endl;
  }

cout<<"---------GAME--OVER---------"<<endl;
}


void aiVSai(int n)
{
   
    int pOneMove,cpu,toss = tossFunc();

    if(toss==0)
        cout<<"CPU 1 won toss"<<endl;
    else
        cout<<"CPU 2 won toss"<<endl;

    cout<<"----------GOOD--LUCK--------"<<endl;

 while(1){

    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==1)
               cout<<"Winner: CPU 2 "<<endl;
          else
               cout<<"Winner: CPU 1 "<<endl;
      }
      if(n==1){
        if(toss==0)
           cout<<"Winner: CPU 2 "<<endl;
        else
           cout<<"Winner: CPU 1 "<<endl;
      }
    break;
    }
    if(toss==0)
     {
        cout<<"Chance: CPU 1 "<<endl;
        resStruct res;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.move<<endl;
        n=n-res.move;
        cout<<"Sticks left :  "<<n<<endl;
     }
     else
       {
        resStruct res;
        cout<<"Chance: CPU 2 "<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.move<<endl;
        n=n-res.move;
         cout<<"Sticks left :  "<<n<<endl;
       }


    ;
    if(n==1 || n==0)
    { if(n==0)
      {
          if(toss==0)
               cout<<"Winner: CPU 2 "<<endl;
          else
               cout<<"Winner: CPU 1 "<<endl;
      }
      if(n==1){
        if(toss==1)
           cout<<"Winner: CPU 2 "<<endl;
        else
           cout<<"Winner: CPU 1 "<<endl;
      }
    break;
    }


   if(toss==1)
     {
           resStruct res;
        cout<<"Chance: CPU 1 "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.move<<endl;
        n=n-res.move;
         cout<<"Sticks left :  "<<n<<endl;
     }
     else
       {
        resStruct res;
        cout<<"Chance: CPU 1 "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.move<<endl;
        n=n-res.move;
         cout<<"Sticks left :  "<<n<<endl;
       }
  }
cout<<"---------GAME--OVER---------"<<endl;
}


int main()
{ int choice,n,play=1;
  cout<<"****************************"<<endl;
  cout<<"---------STICK--GAME--------"<<endl;
  cout<<"****************************\n"<<endl;
  while(play){
  
  cout<<"Great! Now enter number of Sticks"<<endl;
  cin>>n;
  cout<<"\nChoose a Mode:\n"<<endl;
  cout<<"1. HUMAN  VS HUMAN"<<endl;
  cout<<"2. HUMAN VS AI"<<endl;
  cout<<"3. AI vs AI"<<endl;
  cin>>choice;
  
  switch(choice){
 	case 1:
     humanVShuman(n);
     break;
    
    case 2:
     humanVSai(n);
     break;

    case 3:
     aiVSai(n);
     break;
    
}
cout<<"\nInput 1 to play again and 0 to exit\n";
cin>>play;
}
  return 0;
}


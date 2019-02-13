// Markovs Chain Algorithm
// This algorithm generates words according to the prefix

//required header files
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <time.h>


using namespace std;

const int MAX_SIZE=500;


void build(char*[], ifstream &);  //This function contains two word prefixes followed by a list of possible suffix words
void add(char*[] ,char* );//This function pairs prefix word with the corresponding suffix word


int main()
{

    ifstream infile;       //creating an object for reading txt file
    infile.open("final.txt");

    while(!infile )
    {
      cout<<"Error opening file!"<<endl;
      return 0;
    }


    char*prefix[MAX_SIZE];  // array of pointers

    build(prefix,infile); //calling build function and passing the parameters


}


void build(char*prefix[], ifstream &FILE)
{


  string word;
  char *arr=nullptr;
  int x=0;

  cout<<endl;

  while(FILE>>word){


  arr=new char;   //dynamically allocating memory


  strcpy(arr,word.c_str());


 prefix[x]=arr;
 cout<<prefix[x]<<" ";
 x++;

  }

     cout<<endl;
     cout<<endl;

     string word1;
     string word2;
     string word3;

     cout<<"Prefix"<<setw(30)<<"Suffix";
     cout<<endl;
     cout<<endl;


        for(int i=0;i<x-2;i++)    //This nested for loop is used for finding the suffix of the two word prefix

        {



                    word1=prefix[i];
                    word2=prefix[i+1];
                    word3=word1+word2;


            cout<<prefix[i]<<" "<<prefix[i+1]<<setw(30);
            string word4,word5,word6;

            for(int j=0;j<x-2;j++){

                word4=prefix[j];
                word5=prefix[j+1];
                word6=word4+word5;


                    if(word3==word6)
                    {

                        cout<<prefix[j+2]<<" ";


                     }

              }

           cout<<endl;

                   }


            char *suffix=prefix[x-1];
            string a=suffix;
            string b=a+"(end)";
           strcpy(prefix[x-1],b.c_str());


           add(prefix,suffix); //calling the function add to generate words based on the prefix


}


   void add(char* prefix[MAX_SIZE],char* suffix)// this function randomly add the suffix to their prefix
   {

    int z=0;

    string word1=prefix[z];
    string word2=prefix[z+1];


    cout<<endl;
    cout<<endl;


    cout<<"First two words: "<<word1<<" "<<word2<<endl;
    cout<<endl;

    cout<<"Randomly chosen words: "<<endl;

   string test;

    do{

     test=prefix[z];
     z++;

    }

    while(test!=suffix);

    int i=z;

    string word4;
    string word5;
    string word6;


     for(int j=1;j<i-1;j++)// This for loop executes as long as j < 20 or when the suffix generated is the last word
     {


          string word3=word1+word2;

          string w1=prefix[i-2];
          string w2=prefix[i-1];

          string w3=w1+w2;

        if(word3==w3)   // exits the loop when the last word of the text is generated as suffix
         {

          cout<<endl;
          cout<<"End of File!"<<endl;
          break;


           }

                string poss[MAX_SIZE];
                int p=0;
                int k=0;

                 srand(time(0));
                    for( int jj=0;jj<i-1;jj++){


                word4=prefix[jj];
                word5=prefix[jj+1];
                word6=word4+word5;

                         if(word3==word6){

                         poss[k]=prefix[jj+2];
                         k++;

                         }

                     }


                   if(k==1) //  if the prefix have only one possible suffix then this if statement is excuted
                   {


                  cout<<poss[0]<<endl;// displays the one and only suffix
                   word1=word2;
                   word2=poss[0];
                }

                      else   // if the prefix have more than one possible suffix then else statement is executed by randomly selecting the suffix form possible suffixes
                      {

                      int a;
                       for(int x=0;x<150000000;x++)// This loop is used to generate different random numbers inside the outer loop
                       {
                         a=rand();//  generates random number
                       }

                       int ran=a%(k);//generating random index for selecting the suffix


                     cout<<poss[ran]<<endl;// displays the randomly selected suffix
                       word1=word2;
                       word2=poss[ran];


                                      }



                                              }

                                                          }




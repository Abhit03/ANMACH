#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>

class answers
{

  char ans[1000];
  public:
  char name[20];
  void getdet()
  { cout<<"\nName: "; cin>>name;
	 cout<<"\nAnswer: ";gets(ans); }
  void showdet()
  { cout<<"\nName: "<<name;
	 cout<<"\nAnswer: ";puts(ans); }
  void showans()
  { puts(ans); }

};

void stringtowords(char str[],char words[][20],int &count);
void nofromstring(char str[],float &num1,float &num2);
void symbolex(char str[],char &sym);
void functionextractor(char word[][20],char func[]);
void funcvalret(float num1,float num2, char func[],float &val);
void simplevaluereturner(float numbe1, float numbe2, char symb, float &final);

void main()
{
 char que[400],pass[8],check[20],allword[20][20],fun[20],se[30],symbol,mchoice,ch,c1,q,r;
 int i,j,k,m,clear,clear1,wcount=0;
 float number1=0,number2=0,ansval=0,ansval2=0;
 answers A,a1,mp;
 fstream f; ofstream fout; ifstream fin,fin2;


mmenu:
clrscr();
cout<<"\n                                 MAIN MENU ";
cout<<"\n1.Adminstrator";
cout<<"\n2.Enter ANMACH ";
cout<<"\n3.User Instructions";
cout<<"\n4.About ANMACH";
cout<<"\n5.EXIT";
cout<<'\n'<<'\n'<<"\nPlease enter your choice: ";
cin>>mchoice;



		 if(mchoice=='1')
		 {
					 clrscr();
					 cout<<"Enter password ";
					 gets(pass);

			if(!strcmp(pass,"iamgood"))

			 {
			  menu:
			  clrscr();
			  cout<<"Engine editor";
			  cout<<"\n1.All records ";cout<<"\n2.Add info "<<"\n3.Main menu";
			  cout<<"\nEnter choice: ";cin>>ch;


						if(ch=='1')
						{

							clrscr();
							cout<<"\nAll records: ";
							fin.open("fileans.dat",ios::binary);
							fin.seekg(0);
							while(fin.read((char*)&a1,sizeof(a1)))
							a1.showdet();
							fin.close();

							cout<<"\nGo to Editor menu?(y/n):- ";cin>>c1;
							if(c1=='y')
							goto menu;
							else
							goto mmenu;

						}

						else if(ch=='2')
						{
							fout.open("fileans.dat",ios::binary|ios::app);
							do{
							A.getdet();
							fout.write((char*)&A,sizeof(A));
							cout<<"\nEnter more?(y/n) ";
							}while(r=='y');
							fout.close();
							cout<<"\nPress any key to go to menu: ";
							getch();
							goto menu ;
						}



						else if(ch=='3')
						goto mmenu;


						else
						{

						clrscr();
						cout<<"\nWRONG INPUT!!!";
						cout<<"\nPress any key to go to menu: ";
						getch();
						goto menu;

						}

			}


                                        else
			{
			clrscr();
			cout<<"WRONG PASSWORD ";
			cout<<"\nPress any key: ";
			getch();
			goto mmenu;
			}

		}






		else if(mchoice=='2')
		{
		 start:

				  for(clear=0; clear<20; clear++)
				  {
				  for(clear1=0; clear1<20; clear1++)
				  allword[clear][clear1]='\0' ;
				  }
				  for(clear=0; clear<400; clear++)que[clear]='\0';
				  for(clear=0; clear<20; clear++)fun[clear]='\0';
				  for(clear=0; clear<30; clear++)se[clear]='\0';
				  symbol='\0';
				  q='\0';

					 clrscr();




					cout<<"                      ANMACH -> An Educational & computational machine ";

		  cout<<"\nEnter what you you want to know or calculate->: ";
		  gets(que);
		  nofromstring(que,number1,number2);
		  stringtowords(que,allword,wcount);
		  functionextractor(allword,fun);
		  symbolex(que,symbol);
		  simplevaluereturner(number1, number2, symbol, ansval);
		  funcvalret(number1,number2,fun,ansval2);



		  for(m=0; m<wcount; m++)
			{
				fin2.open("fileans.dat",ios::binary);
				fin2.seekg(0);

					while(fin2.read((char*)&mp,sizeof(mp)))
					 {

					 if(!strcmp(mp.name,allword[m]))
					 strcat(se,mp.name);

					 }

				  fin2.close();
			 }


			if(symbol!='\0')
			cout<<"The result is "<<ansval;
			else if(fun[0]!='\0')
			cout<<"The result is "<<ansval2;

			else
			{
			fin2.open("fileans.dat",ios::binary);
			fin2.seekg(0);

					while(fin2.read((char*)&mp,sizeof(mp)))
					 {

					 if(!strcmp(mp.name,se))
					 mp.showans();

					 }
				  fin2.close();
			 }

			cout<<"\nAnother question(y/n): ";
			cin>>q;

			if(q=='y')
			goto start;
			if(q=='n')
			goto mmenu;


		}




		else if(mchoice=='3')
		{

				  clrscr();
				  cout<<"Please read these instructions carefully to get best results."<<endl;
				  cout<<"\nIf the Administrator wishes to manipulate the records administration menu should be opted which includes inserting, deleting, searching and an option to go to main menu."<<endl;
				  cout<<"\nIf the user wishes to use the main program he should opt for 'Enter ANMACH' option.If the student wishes to see instructions he should opt for 'instructions' option."<<endl;
				  cout<<"\nIf the user wants to know about the program he should opt for 'About ANMACH' option. "<<endl;
				  cout<<"\nThe last option in the main menu is 'exit' to quit the program. "<<endl;

				  cout<<"\n________________________________________________________________________________ "<<endl;
				  cout<<"\nPress key to go to main menu: ";
				  getch();
				  goto mmenu;

		}


                          else if(mchoice=='4')
		{

				 clrscr();
				 cout<<"\n----------------------------About this program----------------------------------";
				 cout<<"\nThis program is a computational and a knowledge engine. "<<endl;
				 cout<<"\nWhat does it do? ";
				 cout<<"\nIt answers to the questions,definition and calculations asked in a natural language."<<endl;
				 cout<<"\nHow does it work? ";
				 cout<<"\nIt considers various points including context of search, intent, variation of words, synonyms, generalized and specialized queries, concept matching and naturallanguage queries to provide relevant search results. "<<endl;
				 cout<<"\nIt improves search accuracy by understanding searcher intent and the contextual meaning of terms to generate more relevant results."<<endl;
				 cout<<"\nWhy is it important? ";
				 cout<<"\nWhile studying students come across complex calculations, definitions, difficultwords for which they will have to use scientific calculator, dictionaries, reference books etc. So to study the will have to use lots of recources which is veryannoying. "<<endl;
				 cout<<"\nThis program is built make their study simple and systematic. "<<endl;

				 cout<<"\n________________________________________________________________________________ "<<endl;
				 cout<<"\nPress any key to go to main menu: ";
				 getch();
				 goto mmenu;

		}

		else if(mchoice=='5')
		exit(0);

                         else
		{

				clrscr();
				cout<<"\nWRONG INPUT!!!";
				cout<<"\nPress any key to go to menu: ";
				getch();
				goto mmenu;
		}

}                                                                                             //END

//This is a function which converts string to words
 void stringtowords(char str[400],char words[20][20],int &count)                    //FUNCTIONS
{
	 int j,k,i,l;     int a=0,m=0,num=0;

		for(i=0; i<=strlen(str); i++)                         //loop to separate words
		{
			if((str[i]==' '||str[i]=='\0')&&(str[i+1]!=' '))
			{
				k=i;
				for(m; m<k; m++)
					{
							if(str[m]!=' ')
							{ words[num][a]=str[m];  a++; }
					}
				a=0; m=k+1; num++;
			}
		}

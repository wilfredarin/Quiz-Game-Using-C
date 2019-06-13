#include <stdio.h>
#include <stdlib.h> /*for system()*/
#include <ctype.h> //for toupper
#include <time.h> 







void display_score();
void update_score(int score,char nm[]);
int highest_score();

//set number of Questions in this Quiz
int problems = 5;

//update this if you add more question to the question bank
int total_problems = 25;

int score = 0;
void main()
{


    char ch,ch1;
    char nm[100];

    
    printf("Enter your First Name\n");
    scanf("%s",nm);


    Home:
         system("clear");
         printf("\t\t\t C PROGRAM QUIZ GAME\n");
         printf("\n\t\t________________________________________");

         printf("\n\t\t\t   WELCOME %s",nm);
         
         printf("\n\t\t________________________________________");
         
         printf("\n\t\t > Press S to start the game");
         printf("\n\t\t > Press V to view the highest score  ");
         printf("\n\t\t > press Q to quit          \n ");
         scanf(" %c",&ch);// left a space in starting --otherwise it wasn't reading input
         ch = toupper(ch);
    	 
         if (ch =='V')
        	 { 
                display_score();

        	 goto Home;}

    	 else if (ch == 'Q')
    	 	exit(1);

    	 else if (ch == 'S')
    	
        {

        	system("clear");
            printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",nm);
            printf("\n\n Here are some tips you might wanna know before playing:");
            printf("\n -------------------------------------------------------------------------");
            printf("\n    total of %d questions. Each right answer will be awarded 20",problems);
            
            printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
            printf("\n    right option.");
            printf("\n >> No negative marking for wrong answers!");
            printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
            printf("\n\n\n Press Y  to start the game!\n");
            printf("\n Press any other key to return to the main menu!\n");
            scanf(" %c",&ch1);// left a space in starting --otherwise it wasn't reading input
            ch1 = toupper(ch1);
        
            
            if (ch1 =='Y')
        	
            {  
                
                system("clear");   
                FILE *f;
                FILE *g;
                char question[100];
                char ans;
                char correct_ans[150];
                // Random Questions 
                srand(time(0));
                int number[31];
                for(int i=0;i++;i<30)
                    number[i]=0;
                int num;
                int count_questions = 0;
                char answer;
                
                while(count_questions<problems)
                {
                    num = (rand() % (total_problems-1));
                    if(number[num] == 0)
                    { 
                        count_questions++;
                        number[num] = 1;
                        //file
                        f = fopen("quiz_question.txt","r");
                        g = fopen("quiz_ans.txt","r");
                        int count_line = 0 ;
                        while(!feof(g))
                        {
                            fgets(correct_ans,150,g);
                            if(count_line == num)
                                {answer = correct_ans[0];
                                break;}
                            
                            count_line++;
                        }



                        count_line =0;
                        while(!feof(f))
                        {   fgets(question,150,f);

                            if (count_line == num)
                            {   

                           
                                system("clear");
                                
                                printf("%d\n",count_questions);//remove
                                printf("%s\n",question);
                                printf("\n");
                                printf("Enter your Answer:");
                                scanf(" %c",&ans);
                                printf("your Answer:%c correct_ans:%c \n",ans,correct_ans[0]);
                                char c;
                                
                                if(toupper(ans)== answer)
                                {
                                    system("clear");
                                    score+=20;
                                    printf("\t\t\t\tCongratulations!!,You Nailed it !!\n");
                                    printf("\tEnter any key\n");
                                    scanf(" %c",&c);
                                        //if(!c)
                                        //{    system("clear");
        
                                        //} 
                                    //getch();
                                
                                }
                                else
                                    {

                                        system("clear");
                                        printf("\t\t\t\tYou Got it Wrong this time!\n");
                                        printf("\n");
                                        printf("%s\n",question);
                                        printf("The correct answer is %c\n",answer);
                                        printf("\tEnter any key\n");
                                        scanf(" %c",&c);
                                        //if(!c)
                                        //{    system("clear");
                                             
                                        //} 
                                        //getch();
                                
                                    }


                            break;
                            }

                         
                            
                            count_line++;
                                     
                                

                        }

    	            }
                }
                if(score >= highest_score())
                {   
                    
                    update_score(score,nm);
                }
  
                system("clear");
                printf("\t\t\tCongratulations . You have completed the quiz!!\n");
                printf("Your Score is: %d\n",score);


                display_score();
                printf("\n\t\t > Press H for home screen \n");
                printf("\n\t\t > press any other key to quit          \n ");
                scanf(" %c",&ch1);// left a space in starting --otherwise it wasn't reading input
                
                ch1 = toupper(ch1);
                if(ch1=='H')
                    goto Home;
                else
                    exit(1);
            }

        

        else
            goto Home;
        
        }
    }












void display_score()

{
	FILE *f;
	char nm[100];
	char ch;
	int sc;
	f = fopen("highestScore.txt","r");
	fscanf(f,"%s%d",nm,&sc);
	printf("%s has the highest score of %d!\n",nm,sc);
	fclose(f);

	
   printf("Enter any key and hit Enter !!\n");
   scanf(" %c",&ch);// left a space in starting --otherwise it wasn't reading input

}

int highest_score()
{   
    int sc;
    char nm[100];
    FILE *f;
    f = fopen("highestScore.txt","r");
    fscanf(f,"%s%d\n",nm,&sc);
    fclose(f);
    return sc;
}

void update_score(int sc ,char nm[100])
{

	FILE *f;
	f = fopen("highestScore.txt","w");
	fprintf(f,"%s %d\n",nm,sc);
	fclose(f);
}







//this is coded by wilfredarin

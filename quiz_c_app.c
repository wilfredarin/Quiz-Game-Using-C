#include <stdio.h>
#include <stdlib.h> //for system()
#include <ctype.h> //for toupper
#include <time.h> 


/*I have coded it for gcc */

void display_score();
void update_score(char nm[100],int sc);
int highest_score();


int score = 0;

int main()
{

    char user_asnwer;
    char start_option,ch1;
    char name[100];

    
    printf("Enter your First Name\n");
    scanf("%s",name);


    Home:
    system("clear");
    printf("Welcome %s to C Quiz\n",name);
    printf("\n> RULES:-\n");
    printf(">total of 10 questions. Each right answer will be awarded 20 points\n");
    printf(">You will be given 4 options and you have to press A, B ,C or D.\n");
    printf(">No negative marking for wrong answers!\n\n\n");

    

    printf("\n\t\t > Press S to start the game");
    printf("\n\t\t > Press V to view the highest score  ");
    printf("\n\t\t > press Q to quit          \n ");
    scanf(" %c",&start_option);// left a space in starting --otherwise it wasn't reading input
    start_option = toupper(start_option);

    if(start_option == 'V'){
        display_score();
        goto Home;
    }

    else if(start_option == 'S'){

        srand(time(0));
        int check_repeat[30];
        for(int i=0;i<30;i++){
            check_repeat[i]=0;
        }

        char question[200];
        char answer[4];
        char category[20];
        char user_answer;
        int sports =0;
        int gk = 0;
        int current_affairs = 0;

        int counter = 0;
        int score=0;
        char hold;

        while (counter<10){
            int line_counter = 0;
            int rand_line = rand()%24;
            
            if(check_repeat[rand_line]==0){
                check_repeat[rand_line]=1;

                FILE *f;
                f = fopen("quiz_bank_c.txt","r");
                while(rand_line!=line_counter){
                    fgets(question,200,f);
                    fgets(answer,4,f);
                    fgets(category,20,f);
                    line_counter++;
                }

                fgets(question,200,f);
                fgets(answer,4,f);
                fgets(category,20,f);

                system("clear");
                printf("Question Category:%sQuestion Number: %d\n",category,counter+1);
                printf("%s\n",question);
                scanf(" %c",&user_asnwer);
                user_asnwer = toupper(user_asnwer);
                if(answer[0]==user_asnwer){
                    system("clear");
                    printf("\t\t  Congratulation You Nailed it!!!\n");
                    score+=20;
                    scanf(" %c",&hold);
                    if (category=="SPORTS")
                        sports++;
                    else if (category=="GK")
                        gk++;
                    else
                        current_affairs++;
                }
                else{
                    system("clear");
                    printf("Question Category: %s Question Number: %d\n",category,counter+1);
                    printf("%s",question);
                    printf("Correct Answer : %s\n",answer);
                    scanf(" %c",&hold);
                }

            
            counter++;
            }

        }

        system("clear");
        printf("\t\tCongratulations . You have completed the quiz!!\n\n");
        if(score>=highest_score()){
            printf("\t\tYeppi! You did it!! You are the highest Scorer!!\n\n");
            update_score(name,score);
        }
        printf("Your Score is: %d\n",score);
        printf("\n\n");
        printf("Category Wise Score -:\n");
        printf("\tSports  : %d\n",sports*20);
        printf("\tGK  : %d\n",gk*20);
        printf("\tCurrent Affairs : %d\n",current_affairs*20);

        printf("To play again press S to Quit press anyother Key \n");
        scanf(" %c",&start_option);
        start_option = toupper(start_option);
        if(start_option=='S'){
            goto Home;
        }

        else
            exit(1);


    }
    else
        exit(1);


    return 0;

}




           





void display_score()

{
	FILE *f;
	char nm[100];
	char ch;
	int sc;
	f = fopen("highest_c_score.txt","r");
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
    f = fopen("highest_c_score.txt","r");
    fscanf(f,"%s%d\n",nm,&sc);
    fclose(f);
    return sc;
}

void update_score(char nm[100],int sc )
{

	FILE *f;
	f = fopen("highest_c_score.txt","w");
	fprintf(f,"%s %d\n",nm,sc);
	fclose(f);
}
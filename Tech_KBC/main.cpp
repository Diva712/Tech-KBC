#include <iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>

using namespace std;

string player_name;
bool pay_half_skip = true;
bool skip = true;
long cash = 0;
long question_price = 100;
int consecutive = 0;
int right_answer = 0;
int wrong_answer = 0;
int question_num = 1;


// result;
void result();

//game_rules;
void game_rules();

//question;

void ask_random_question();

// answer;

void check_answer(char ans , char correct_ans);


struct Question{

    string question;
    string option_a;
    string option_b;
    string option_c;
    string option_d;

    char answer;
    bool available ;
};


Question questions [10];

int main()
{
    system("cls");
    questions[0] = {"Loop within a loop is called? " , "nested loop" , "complex loop" , "infinite loop" , "none" , 'b' , true};
    questions[1] = {"Which of the following is a correct identifier in C++" , "VAR_1234" , "$var_name" , "7VARNAME" , "7var_name" , 'a',true};
    questions[2] = {"Which of the following is not a type of Constructor in C++?" , "Default constructor" , "Parameterized constructor" , "Copy constructor" , " Friend constructor" , 'd' , true};
    questions[3] = {"Which of the following approach is used by C++?" , "Left-right" , " Right-left" , "Bottom-up" , "Top-down" , 'c' , true};
    questions[4] = {"What of the following allow you to access you structure members ? " , "Dot operator" , "this->" , "loop" , "*" , 'a' , true};
    questions[5] = {"Variable that holds a large group of similar type of data is called ?" , "constant" , "scalar value" , "array" , "multiple variable" , 'c' , true};
    questions[6] = {"Which of the following is correct about this pointer in C++?" , "this pointer is passed as a hidden argument in all static variables of a class" , "this pointer is passed as a hidden argument in all the functions of a class" , "this pointer is passed as a hidden argument in all non-static functions of a class" , "this pointer is passed as a hidden argument in all static functions of a class" , 'c' , true};
    questions[7] = {"The index of first element of the array is always?" , "0" , "-1" , "1" , "2" , 'a' , true};
    questions[8] = {"Which of the following correctly declares an array in C++?" , "array{10};" , "array array[10];" , "int array[10];" , "int array;" , 'd' , true};
    questions[9] = {"Which is more effective while calling the C++ functions?", "call by object" , "call by pointer" , "call by value" , "call by reference" , 'd' , true};

    cout<<"=============================================================================="<<endl;
    cout<<"===========================WELCOME TO THE====================================="<<endl;
    cout<<"===================KAUN BANEGA KARORPATI GAME SHOW============================"<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"Enter Your Name: ";
    getline(cin, player_name);
    system("cls");
    game_rules();
    while(true){

        if(question_num > 10)
            break;
        ask_random_question();
    }
    result();
    return 0;
}

void ask_random_question(){
    //for sting a random number for us
    srand(time(0));
    while(true){
        system("cls");
        int number = rand()%10;
        if(questions[number].available){

            questions[number].available = false;
            cout<<"=============================================================================="<<endl;
            cout<<"===================KAUN BANEGA KARORPATI GAME SHOW============================"<<endl;
            cout<<endl;
            cout<<"This Question No: "<<question_num<<" Is For $"<< question_price<<"\t\t\t\tBalance Is $"<<cash<<endl<<endl;
            cout<<"Life Lines: ";
            if(pay_half_skip == true){
                cout<<"\th=>PAY HALF AND SKIP";
            }

            if(skip == true){
                cout<<"\tl=>LEAVE QUESTION";
            }

            cout<<endl<<endl;
             cout<<"=============================================================================="<<endl;
             cout<<"==========================CHOSE YOUR ANSWER==================================="<<endl<<endl;

            cout<<questions[number].question<<endl<<endl;
            cout<<"a) "<< questions[number].option_a<<"\t\tb) "<<questions[number].option_b<<endl<<endl;
            cout<<"c) "<< questions[number].option_c<<"\t\td) "<<questions[number].option_d<<endl<<endl;
            char answer = _getche();
            answer = tolower(answer);
            cout<<endl;
            question_num++;
            check_answer(answer , questions[number].answer);
            break;

        }
    }

}


void check_answer(char ans , char correct_ans){

    if(ans == correct_ans){

        cout<<"Congratulations...! Your answer is right"<<endl;
        cout<<endl;
        cout<<"You earned $"<<question_price<<endl;
        cout<<"Press any key to continue..."<<endl;
        _getch();
        right_answer++;
        consecutive++;
        cash = cash + question_price;

    }
    else if((ans=='h') && (pay_half_skip)){
        cout<<"You chose the life line 'PAY HALF AND SKIP'"<<endl;
        cout<<"You lose $"<<question_price/4<<endl;
        cout<<"Press any key to continue..."<<endl;
        _getch();
        cash = cash - (question_price/4);
        pay_half_skip = false;
    }
     else if((ans=='l') && (skip)){
        cout<<"You chose the life line 'LEAVE QUESTION'"<<endl;
        cout<<"You lose $ 0"<<endl;
        cout<<"Press any key to continue..."<<endl;
        _getch();
        //cash = cash - (question_price/2);
        skip = false;
    }
    else{
        cout<<"Sorry... Your answer is wrong..."<<endl;
        cout<<"You lose $"<<question_price/2<<endl;
        cout<<"Press any key to continue..."<<endl;
        _getch();
        wrong_answer++;
        consecutive=0;
        cash = cash - question_price/2;
    }

    question_price = question_price*2;

    if(consecutive == 3){
        pay_half_skip = true;
    }

    if(consecutive == 5){
        skip = true;
    }
}


void result(){

    double percentage;
    percentage = right_answer*10;
    system("cls");
     cout<<"=============================================================================="<<endl;
     cout<<"=================================Result======================================="<<endl;
     cout<<"=============================================================================="<<endl;
     cout<<"Player Name: \t\t\t"<<player_name<<endl<<endl;
     cout<<"Right Answers: \t\t\t"<<right_answer<<endl<<endl;
     cout<<"Wrong Answers: \t\t\t"<<wrong_answer<<endl<<endl;
     cout<<"Average: \t\t\t"<<percentage<<"%"<<endl<<endl;
     if(cash>=0){
        cout<<"Wining Amount: \t\t\t$"<<cash<<endl<<endl;

     }
     else{
        cout<<"Loosing Amount: \t\t\t"<<cash<<endl<<endl;
     }
          cout<<"=============================================================================="<<endl;

          cout<<"=============================================================================="<<endl;

          cout<<"========================THANKS FOR PLAYING THIS GAME=========================="<<endl;

          cout<<"=============================================================================="<<endl;

          cout<<"==============================@TECH_KBC======================================="<<endl<<endl;
          cout<<"========================PRESS ANY KEY TO CONTINUE============================="<<endl;
          _getch();
}

void game_rules()
{

     cout<<"=============================================================================="<<endl;
     cout<<"========================RULES AND REGULATIONS================================="<<endl;
     cout<<"=============================================================================="<<endl;

     cout<<"01. There are total 10 questions in this game."<<endl<<endl;
     cout<<"02. There only two life lines which you can use at any stage of the game."<<endl<<endl;
     cout<<"03. Pay Half & Skip means you have to pay of 1/4 of current question price."<<endl<<endl;
     cout<<"04. Leave question means you can leave a question without any deduction."<<endl<<endl;
     cout<<"05. If you attempt 3 consecutive right answer pay half & skip will rescued."<<endl<<endl;
     cout<<"06. If you attempt 5 consecutive right answer leave question will rescued."<<endl<<endl;
     cout<<"07. After every question the amount of question price will be double."<<endl<<endl;
     cout<<"08. If the answer if wrong half amount of question price deduct from the your balance."<<endl<<endl;
     cout<<"09. Press H for Pay Half & Skip life line and Press L for leave question life line."<<endl<<endl;
     cout<<"10. Press A , B , C or D to answer any question."<<endl<<endl;
     _getch();
}

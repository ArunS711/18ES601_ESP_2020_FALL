#include <stdio.h>
#include <string.h>

//#define STR_5

//#define STR_arg
//#define STR_arg_ref
//#define STR_access_reference
#define STR_ACCESS_DYNMC


#ifdef STR_1
struct Books
{
char title[50];
char author[50];
char subject[100];
int book_id;
};


int main( )
{
struct Books Book1; /* Declare Book1 of type Book */
struct Books Book2; /*Declare Book2 of type Book */
/* book 1 specification */
strcpy( Book1.title, "C Programming");
strcpy( Book1.author, "ABC");
strcpy( Book1.subject, "Embedded System Programming");
Book1.book_id = 20;
/* book 2 specification */
strcpy( Book2.title, "C tutorial");
strcpy( Book2.author, "XYZ");
strcpy( Book2.subject, "ESP");
Book2.book_id = 30;




/* print Book1 info */
printf( "Book 1 title : %s\n", Book1.title);
printf( "Book 1 author : %s\n", Book1.author);
printf( "Book 1 subject : %s\n", Book1.subject);
printf( "Book 1 book_id : %d\n", Book1.book_id);
/* print Book2 info */
printf( "Book 2 title : %s\n", Book2.title);
printf( "Book 2 author : %s\n", Book2.author);
printf( "Book 2 subject : %s\n", Book2.subject);
printf( "Book 2 book_id : %d\n", Book2.book_id);

Book1=Book2;
printf( "Book 1 title : %s\n", Book1.title);
printf( "Book 1 author : %s\n", Book1.author);
printf( "Book 1 subject : %s\n", Book1.subject);
printf( "Book 1 book_id : %d\n", Book1.book_id);
return 0;
}
#endif STR_1

#ifdef STR_2
#include <stdio.h>
typedef struct
{
    int feet;
    float inch;
} Dis;

int main()
{
    //struct Distance ; //messy
    Dis dist1, dist2,sum;  // more compact
    printf("1st distance\n");

    // Input of feet for structure variable dist1
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);

    // Input of inch for structure variable dist1
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("2nd distance\n");

    // Input of feet for structure variable dist2
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);

    // Input of feet for structure variable dist2
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    if (sum.inch > 12)
    {
        //If inch is greater than 12, changing it to feet.
        ++sum.feet;
        sum.inch = sum.inch - 12;
    }

    // printing sum of distance dist1 and dist2
    printf("Sum of distances = %d\'-%.1f\"", sum.feet, sum.inch);
    return 0;
}
#endif // STR_2
#ifdef STR_3
void main()
{
struct complex
{
float real;
float cmplex;
} a, b, c;
printf("enter real and imaginary for first number\n");
scanf ("%f %f", &a.real, &a.cmplex);
printf("enter real and imaginary for Second number\n");
scanf ("%f %f", &b.real, &b.cmplex);
c.real = a.real + b.real;
c.cmplex = a.cmplex + b.cmplex;
printf ("\n %f + %f j", c.real, c.cmplex);
}

#endif // STR_3

#ifdef STR_4

typedef struct{
float real;
float imag;
} COMPLEX;

void swap (COMPLEX a, COMPLEX b){
COMPLEX tmp;
tmp = a;
a = b;
b = tmp;
printf("inside swap\n");
print(a);
print(b);

}
void print (COMPLEX a){
printf("(%f, %f) \n",a.real,a.imag);
}
void main(){
COMPLEX x={4.0,5.0}, y={10.0,15.0};
print(x);
print(y);
swap(x,y);
print(x);
print(y);
}



#endif // STR_


#ifdef STR_5
#include<stdio.h>

struct student
{
    char *name; // pointer
    int age;
    char *program; // pointer
    char *subjects[5];  // array of pointer to char
};

int main()
{

    struct student stu = {
                             "XYZ",
                             25,
                             "EBS",
                             {"ESP", "SIP", "MATHS", "RM", "ARM" }
                         };

    struct student *ptr_stu = &stu;
    int i;

    printf("Accessing members using structure variable: \n\n");

    printf("Name: %s\n", stu.name);
    printf("Age: %d\n", stu.age );
    printf("Program enrolled: %s\n", stu.program);

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d : %s \n",i+1, stu.subjects[i]);
    }

    printf("\n\nAccessing members using pointer variable: \n\n");

    printf("Name: %s\n", ptr_stu->name);
    printf("Age: %d\n", ptr_stu->age);
    printf("Program enrolled: %s\n", ptr_stu->program);

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d :  %s \n", i+1,ptr_stu->subjects[i]);
    }

    // signal to operating system program ran fine
    return 0;
}

#endif


#ifdef STR_arg
#include <stdio.h>
struct student
{
    char name[50];
    int roll;
};

void display(struct student stu);
// function prototype should be below to the structure declaration otherwise compiler shows error

int main()
{
    struct student stud;

    printf("Enter student's name: ");
    scanf ("%s", &stud.name);

    printf("Enter roll number:");
    scanf("%d", &stud.roll);

    display(stud);   // passing structure variable stud as argument
    return 0;
}
void display(struct student stu){
  printf("\nOutput\nName: %s",stu.name);
  printf("\nRoll: %d",stu.roll);
}
#endif // STR_arg

#ifdef STR_arg_ref
#include <stdio.h>
struct distance
{
    int feet;
    float inch;
};
void add(struct distance d1,struct distance d2, struct distance *d3);

int main()
{
    struct distance dist1, dist2, dist3,*dist;

    printf("First distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("Second distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);
    dist=&dist3;

    add(dist1, dist2, &dist3);
  //  add(dist1, dist2, dist);

    //passing structure variables dist1 and dist2 by value whereas passing structure variable dist3 by reference
    printf("\nSum of distances = feet=%d\'- inch =%.1f\"", dist3.feet, dist3.inch);

    return 0;
}
void add(struct distance d1,struct distance d2, struct distance *d3)
{
     //Adding distances d1 and d2 and storing it in d3
     d3->feet = d1.feet + d2.feet;
     d3->inch = d1.inch + d2.inch;

     if (d3->inch >= 12) {     /* if inch is greater or equal to 12, converting it to feet. */
         d3->inch -= 12;
         ++d3->feet;
    }
}
#endif // STR_arg_ref


#ifdef STR_access_reference

#include <stdio.h>
typedef struct
{
   int age;
   float weight;
}person;

int main()
{
    person *personPtr, person1;
    personPtr = &person1;            // Referencing pointer to memory address of person1

    printf("Enter Age : ");
    scanf("%d",&person1.age);

    printf("Enter Weight: ");
    scanf("%f",&person1.weight);

    printf("Displaying: ");
    printf("Age=%d \tWeight=%f",(*personPtr).age,personPtr->weight);

    return 0;
}

#endif // STR_access_reference



#define str3



#ifdef str1
#include <stdio.h>
#include <string.h>

struct name {
    char first[24];
    char last[24];
    };

int main()
{

    struct name me;

    strcpy(me.first,"Sarath");
    strcpy(me.last,"TV");

    printf("Hello, %s %s!\n",me.first,me.last);

    return(0);
}
#endif // str1

#ifdef str2
/*For a pointer version of the code, you have several options:
pointer structure, pointer members, or both pointer structure and pointer members*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char first[24];
        char last[24];
    };
    struct name *me;

    me = (struct name *)malloc(1 * sizeof(struct name));
    if( me==NULL )
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me->first,"SARATH");
    strcpy(me->last,"TV");

    printf("Hello, %s %s!\n",
            me->first,
            me->last);

    return(0);
}
#endif // str2

#ifdef str3
/*Now consider this code, where the members are pointers, but the structure isn’t*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char *first;
        char *last;
    };
    struct name me;

    me.first = (char *)malloc( sizeof(char) * 24 );
    me.last = (char *)malloc( sizeof(char) * 24 );
    if( me.first==NULL || me.last==NULL)
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me.first,"SARATH");
    strcpy(me.last,"TV");

    printf("Hello, %s %s!\n",
            me.first,
            me.last);

    return(0);
}
#endif // str3

#ifdef str4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char *first;
        char *last;
    };
    struct name *me;

    me = (struct name *)malloc( sizeof(struct name) * 1);
    if( me==NULL )
    {
        puts("Unable to allocate memory");
        return(1);
    }
    me->first = (char *)malloc( sizeof(char) * 24 );
    me->last = (char *)malloc( sizeof(char) * 24 );
    if( me->first==NULL || me->last==NULL)
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me->first,"SARATH");
    strcpy(me->last,"Tv");

    printf("Hello, %s %s!\n",
            me->first,
            me->last);

    return(0);
}
#endif // str4





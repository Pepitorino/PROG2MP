#include "types.h"

int
validateDate(int m, int d, int y)
{
    switch(m)
    {
        case 1: //31
        case 3: //31
        case 5: //31
        case 7: //31
        case 8: //31
        case 10: //31
        case 12: 
            if (d>31||d<1) return 1;//31 
        case 4: //30
        case 6: //30
        case 9: //30
        case 11: 
            if (d>30||d<1) return 1;//30
        case 2: 
            if ((y%4 == 0&&y%100!= 0)||(y%400==0))
            {
                if (d>29||d<1) return 1;
            }
            else if (d>28||d<1) return 1;
            break;
        default: return 1;
    }

    return 0;
}

int
inputDate(str_t text)
{
    str_t temp;
    int m, d, y;

    if(strlen(text)>10) return 1;
    if(text[2]!='/'||text[5]!='/') return 1;

    temp[0]=text[0];
    temp[1]=text[1];
    temp[2]='\0';
    m=atoi(temp);
    
    temp[0]=text[3];
    temp[1]=text[4];
    temp[2]='\0';
    d=atoi(temp);

    temp[0]=text[6];
    temp[1]=text[7];
    temp[2]=text[8];
    temp[3]=text[9];
    temp[4]='\0';
    y=atoi(temp);

    return validateDate(m,d,y);
}

void 
inputRating()
{

}

int
InputValidation(str_t text, int n)
{
    if (strlen(text)>n) return 1;
    return 0;
}

int shortNameValidationDestination(destination* data, 
                        str_t temp, 
                        int *n)
{
    int i=0;
    for (i=0;i<*n;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

int shortNameValidationGoal(goal* data, 
                        str_t temp, 
                        int *n)
{
    int i=0;
    for (i=0;i<*n;i++)
    {
        if (!strcmp(data[i].shortName, temp)) return 1;
    }
    return 0;
}

int shortNameValidationTrip(travelPlan* trips,
                            str_t temp,
                            int *n)
{

}

int checkYesOrNo(char c)
{
    switch(c)
    {
        case 'y':
        case 'Y':
        return 1;
        case 'n':
        case 'N':
        return -1;
    }
    return 0;
}
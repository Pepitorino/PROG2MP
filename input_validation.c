/*Checks if date is a real, valid date
@param m - month of date
@param d - day of date
@param y - year of date
Precondition: no precondition
*/
int
validateDate(int m, 
            int d, 
            int y)
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

/*Checks if the inputted date string is valid
@param text - date
Precondition: no precondition
*/
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

/*Checks if the inputted rating is valid
@param f - float value to be checked
Precondition: no precondition
*/
int
inputRatingValidation(float f)
{
    if (f<=5&&f>=0)
        if (!(((int)(f*100))%50)) return 1;
    return 0;
}

/*Checks if the inputted string is not too long
@param text - string to be checked
@param n - character limiit
Precondition: no precondition
*/
int
inputValidation(str_t text, 
                int n)
{
    if (strlen(text)>n) return 1;
    return 0;
}

/*Checks if shortName is already in array given
@param data - array to be checked
@param temp - shortName to be checked if it already exists in data
@param n - number of elements in array
Precondition: no precondition
*/
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

/*Checks if shortName is already in array given
@param data - array to be checked
@param temp - shortName to be checked if it already exists in data
@param n - number of elements in array
Precondition: no precondition
*/
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

/*Checks if shortName is already in array given
@param data - array to be checked
@param temp - shortName to be checked if it already exists
@param n - number of elements in array
Precondition: no precondition
*/
int shortNameValidationTrip(travelPlan* data,
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

/*Checks if startDate is already in array given
@param data - array to be checked
@param temp - shortName to be checked if it already exists in data
@param n - number of elements in array
Precondition: no precondition
*/
int startDateValidationTrip(travelPlan* data,
                            str_t temp,
                            int *n)
{
    int i=0;
    for (i=0;i<*n;i++)
    {
        if (!strcmp(data[i].startDate, temp)) return 1;
    }
    return 0;
}

/*Checks if character entered is yes or no
@param c - char to be checked
Precondition: no precondition
*/
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
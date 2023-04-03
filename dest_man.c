void
shortDisplay(destination* dest, 
            int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", dest[i].longName);
        printf("\n- %s",  dest[i].shortName);
    }
    return;
}

void
longDisplay(destination* dest, 
            int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s", dest[i].longName);
        printf("\n- %s",  dest[i].shortName);
        printf("\n- %s",  dest[i].country);
        printf("\n- %s",  dest[i].geoGroup);
        printf("\n- %s",  dest[i].toDo);
    }
    return;
}

void
addDestination(destination* dest,
            int n)
{
    
}

void
deleteDestination(destination* dest,
            int n)
{

}

void
editDestination(destination* dest,
            int n)
{

}

void
destMenu(destination* dest,
        int n)
{

}
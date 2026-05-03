int f(int x)
{
    int n = x;
    int count = 0;
    while(n != 0)
    {
        n/=10;
        count++;
    }
    return (x%(int)pow(10, count-2));
}

int isPrime(int x)
{
    if(x <= 0) return 0;
    if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(int i = 3; i <= sqrt(x); i+=2)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}
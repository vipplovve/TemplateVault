#include <stdio.h>
int main()
{

    int amount,_2000,_500,_100,_50,_20,_10,_5,_2,_1;
    printf("Enter amount:" );
    scanf("%d",&amount);
    if(amount%2000==0)
    {
        _2000=amount/2000;
        printf("%d Rs.2000 notes will be enough.",_2000);
    }
    else
    {
        _2000=amount/2000;
        amount%=2000;
        if(amount%500==0)
        {
            _500=amount/500;
            printf("%d Rs.2000 notes, %d Rs. 500 notes will be enough.",_2000,_500);
        }
        else
        {
            _500=amount/500;
            amount=amount%500;
            if(amount%100==0)
            {
                _100=amount/100;
                printf("%d Rs.2000 notes, %d Rs 500 notes, %d Rs. 100 notes will be enough.",_2000,_500,_100);
            }
            else
            {
                _100=amount/100;
                amount=amount%100;
                if(amount%50==0)
            {
                _50=amount/50;
                printf("%d Rs.2000 notes, %d Rs. 500 notes, %d Rs. 100 notes, %d Rs. 50 notes will be enough.",_2000,_500,_100,_50);
            }
                else
                {
                    _50=amount/50;
                    amount=amount%50;
                    if(amount%10==0)
                    {
                        _10=amount/10;
                        printf("%d Rs.2000 notes, %d Rs. 500 notes, %d Rs. 100 notes, %d Rs. 50 notes, %d Rs. 10 notes will be enough.",_2000,_500,_100,_50,_10);

                    }
                    else
                    {
                    _10=amount/10;
                    amount=amount%10;
                    if(amount%5==0)
                        {
                        _5=amount/5;
                        printf("%d Rs.2000 notes, %d Rs. 500 notes, %d Rs. 100 notes, %d Rs. 50 notes, %d Rs. 10 notes, %d Rs. 5 notes will be enough.",_2000, _500,_100,_50,_10,_5);

                        }
                    else
                        {
                            _5=amount/5;
                            amount=amount%5;
                            if(amount%2==0)
                            {
                                _2=amount/2;
                                printf("%d Rs.2000 notes, %d Rs. 500 notes, %d Rs. 100 notes, %d Rs. 50 notes, %d Rs. 10 notes, %d Rs. 5 notes, %d Rs.2 notes will be enough.",_2000,_500,_100,_50,_10,_5,_2);
                            }
                            else
                            {
                                _2=amount/2;
                                amount=amount%2;
                                printf("%d Rs.2000 notes, %d Rs. 500 notes, %d Rs. 100 notes, %d Rs. 50 notes, %d Rs. 10 notes, %d Rs. 5 notes, %d Rs.2 notes, %d Rs. 1 notes will be enough.",_2000,_500,_100,_50,_10,_5,_2,amount);
                            }

                        }
                    }


                }
            }
        }
    }
    return 0;
}




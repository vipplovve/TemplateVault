#include <iostream>
#include <algorithm>

using namespace std;

class item
{
    public:

    int W;
    int P;
};

bool PtoWRatioSort(item a, item b)
{
    float x = a.P/(1.0*a.W);
    float y = b.P/(1.0*b.W);

    return x > y;
}

float FractionalKnapsack(item data[], int Capacity, int size)
{
    sort(data, data + size, PtoWRatioSort);
    float ans = 0;

    for(int x = 0 ; x < size ; x++)
    {
        if(Capacity > data[x].W)
        {
            Capacity = Capacity - data[x].W;
            ans = ans + data[x].P;
        }

        else
        {
            ans = ans + data[x].P*(Capacity*1.0/(data[x].W));
        }
    }

    return ans;
}

int main()
{
    int size;
    cin>>size;

    int C;
    cin>>C;

    item arr[size];

    for(int x = 0 ; x < size ; x++)
        cin>>arr[x].P>>arr[x].W;

    float profit = FractionalKnapsack(arr,C,size);

    cout<<"Maximum Profit is : "<<profit<<endl;

    return 0;
}
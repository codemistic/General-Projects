/* Coded by:
							Manasij Haldar, B.E.-3rd Year, CSE_AIML, Chandigarh University.
							Language used: C++, Concept Used: Greedy Algorithm.
*/

#include<iostream>
#include<list>
using namespace std;
struct items
{
    int value;
    int weight;
};

void sort( items item[], int n)
{
    items t;

    for( int i = 0; i < n;i++)
    {
        for( int j = 0; j < n-1;j++)
        {
            if ((double(item[j].value)/double(item[j].weight))<(double(item[j+1].value)/double(item[j+1].weight)))
            {
                t=item[j];
                item[j]=item[j+1];
                item[j+1]=t;
            }
        }
    }
}

main()
{
    int n;
    cout<<"\nEnter number of items: ";
    cin>>n;
    items item[n];
    cout<<"\nEnter weights of "<<n<<" items in Value-Weight Pair...\n";
    for(int i=0; i<n; i++)
    {
        int v,w;
        cin>>item[i].value>>item[i].weight;
    }
    sort(item,n);

    cout<<"\n\tTotal in List.\n\tVALUE\tWEIGHT\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\t$ "<<item[i].value<<"\t"<<item[i].weight<<" kg"<<endl;
    }

    int buck;
    cout<<"\n\nEnter the load capacity of the Sack: ";
    cin>>buck;

    items sack[n];
    items t;
    int count=0;
    for(int i=0; i<n && buck>0; i++)
    {
        if (item[i].weight<=buck)
        {
            sack[i] = item[i];
            buck -= item[i].weight;
            count++;
        }
        else
        {
            t = item[i];
            t.weight = buck;
            sack[i]=t;
            buck=0;
            count++;
        }
    }

    cout<<"\n\tItems in Sack.\n\tVALUE\tWEIGHT\n";
    for(int i=0; i<count; i++)
    {
        cout<<"\t$ "<<sack[i].value<<"\t"<<sack[i].weight<<" kg"<<endl;
    }

    cout<<"\n\n\n";
}

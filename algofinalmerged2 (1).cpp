#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<stdlib.h>
#include <time.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>

#define RADIUS 15
#define BX 639
#define BY 100

using namespace std;

#define ll long long
#define mxn 100005

struct Item
{
    int profit, time;
    string name;
    int totalcap;


};

int graph[1000][1000];

void radiopairing()
{
    int lang[mxn],time[mxn],freq[mxn],aud[mxn];
    int n;
    cout<<"Enter the number of advertisement requests "<<endl<<endl;
    cin>>n;
    cout<<"The criterias for advertisement allocation are :"<<endl;
    cout<<endl;
    cout<<"1.Language"<<endl;
    cout<<endl;
    cout<<"2.Time of the day"<<endl;
    cout<<endl;
    cout<<"3.Frequency"<<endl;
    cout<<endl;
    cout<<"4.Target Audience"<<endl;
    cout<<endl;
    cout<<"Criteria : Language"<<endl;
    cout<<endl;
    cout<<"Enter 0 for Hindi/Regional:"<<endl;
    cout<<endl;
    cout<<"Enter 1 for English"<<endl;
    cout<<endl;

    for(int i=1;i<=n;i++)
    {
    cin>>lang[i];
    }

        cout<<"Criteria : Time of the day"<<endl;
        cout<<endl;
        cout<<"Enter 0 for Morning/Afternoon:"<<endl;
        cout<<endl;
        cout<<"Enter 1 for Evening/Night"<<endl;
        cout<<endl;


    for(int i=1;i<=n;i++)
    {

        cin>>time[i];
    }
        cout<<"Criteria : Frequency"<<endl;
        cout<<endl;
        cout<<"Enter 0 for High:"<<endl;
        cout<<endl;
        cout<<"Enter 1 for Low"<<endl;
        cout<<endl;

            for(int i=1;i<=n;i++)
            {
            cin>>freq[i];
            }


    cout<<"Criteria : Target Audience"<<endl;
    cout<<"Enter 0 for Mature Audience:"<<endl;
    cout<<"Enter 1 for Audience below 17"<<endl;


        for(int i=1;i<=n;i++)
        {
        cin>>aud[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(lang[i]==1&&lang[j]==1)
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if((lang[i]==0)&&(lang[j]==0))
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if(time[i]==1&&time[j]==1)
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if((time[i]==0)&&(time[j]==0))
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if(freq[i]==1&&freq[j]==1)
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if((freq[i]==0)&&(freq[j]==0))
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
                if(aud[i]==1&&aud[j]==1)
                {
                    graph[i][j]++;
                    graph[j][i]++;}
                if((aud[i]==0)&&(aud[j]==0))
                {
                    graph[i][j]++;
                    graph[j][i]++;
                }
            }
        }
    cout<<"The Weight Matrix incorporating the given advertisement request is:"<<endl;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }

    vector<pair<int,int> >ans;

    map<int,int>mp;

    while(1)
    {
      int maximum=-1;
      int s1,s2;
      for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
               {
                 if(graph[i][j]> maximum&&i!=j)
                 {
                    maximum = graph[i][j];
                    s1=i;
                    s2=j;
                  }
               }
        }
            for(int j=1;j<=n;j++)
            {
                graph[s1][j]=-1;
                graph[s2][j]=-1;
            }

            for(int i=1;i<=n;i++)
            {
                graph[i][s2]=-1;
                graph[i][s1]=-1;
            }
            if(maximum==-1)
            break;
            mp[s1]=1;
            mp[s2]=1;
        ans.push_back({s1,s2});
    }

  cout<<"The advertisement ids to be broadcasted together are :";
  cout<<endl;

        for(int i=1;i<=n;i++)
        if(mp.find(i)==mp.end())
        ans.push_back({i,i});

        for(int i=0;i<ans.size();i++)
         cout<<ans[i].first<<" "<<endl<<ans[i].second;
         cout<<endl;

}
    bool cmp(struct Item a, struct Item b)
    {
    double r1 = (double)a.profit / a.time;
    double r2 = (double)b.profit / b.time;
    return r1 > r2;
    }

   double finalsequence(int W, struct Item arr[], int n)
   {

    sort(arr, arr + n, cmp);
    int sum1=0;
    srand (time(NULL));


 /*    int v1=rand();
    if(v1!=1)
    {
    int w2=rand()%60;
    cout<<"\n"<<"there is interuption at"<<w2<<"\n";
    }
    for (int i = 0; i < n; i++)
    {
        if(sum1<arr[i].time)
        {
               if(sum1+arr[i].time<W)
               {
                   if(arr[i].time<=arr[i].time)
                   {
                    cout << arr[i].name<<" ("<<arr[i].profit << "  " << arr[i].time<< ") : "
             << ((double)arr[i].profit / arr[i].time) << ":"<<arr[i].totalcap<<endl;
                arr[i].totalcap=arr[i].totalcap-arr[i].time;
              sum1=sum1+arr[i].time;
              }
    }
    }*/

    int v1=rand()%3+0;
    if(v1!=1)
    {
    int w2=rand()%60+120;

    cout<<"\n"<<"there is interuption at"<<w2<<"\n";

    W=w2;
    }
    for (int i = 0; i < n; i++)
    {
        if(sum1<W)
        {
               if(sum1+arr[i].time<W)
               {
                   if(arr[i].time<=arr[i].totalcap)
                   {
                    cout << arr[i].name<<" ("<<arr[i].profit << "  " << arr[i].time<< ") : "

                   << ((double)arr[i].profit / arr[i].time) << ":"<<arr[i].totalcap<<endl;

                   arr[i].totalcap=arr[i].totalcap-arr[i].time;

                  sum1=sum1+arr[i].time;
                  cout<<sum1<<endl;
                  Sleep(600);
              }
              else
              {
                  cout<<"channel advertisement"<<"   "<<arr[i].time<<"\n";
                  sum1=sum1+arr[i].time;
              }
        }
      }
    }


    int curtime = 0;
    double finalprofit = 0.0;

/*
  for (int i = 0; i < n; i++)
    {
        if (curtime + arr[i].totalcap <= 180)
        {
            curtime += arr[i].time;
            finalprofit += arr[i].profit;
        }
        else
        {
            int remain =  - curtime;

            finalprofit += arr[i].profit * ((double) remain / arr[i].time);
             cout << arr[i].name<<" ("<<arr[i].profit << "  " << arr[i].time<< ") : "
             << ((double)arr[i].profit / arr[i].time) << endl;

            cout << arr[i].name<<" ("<<arr[i].profit << "  " << remain<< ") : "
             << ((double)arr[i].profit / arr[i].time) << endl;
             cout<<sum1+arr[i].time<<endl;

            break;
        */

    for (int i = 0; i < n; i++)
    {
        if (curtime + arr[i].time <= W)
        {
            curtime += arr[i].time;
            finalprofit += arr[i].profit;
        }

        else
        {
            int remain = W - curtime;

             finalprofit += arr[i].profit * ((double) remain / arr[i].time);

             cout << arr[i].name<<" ("<<arr[i].profit << "  " << arr[i].time<< ") : "
             << ((double)arr[i].profit / arr[i].time) << endl;

             cout<<"Since we only need"<<" "<<remain<<" seconds therefore we take fractional part:"<<endl<<endl;

            cout << arr[i].name<<" ("<<arr[i].profit << "  " << remain<< ") : "
             << ((double)arr[i].profit / arr[i].time) << endl;

             cout<<sum1+remain<<endl;

            break;
        }

    }


    return finalprofit;
}


  int main()
  {

    int gdriver=DETECT ;
    int gmode;
    initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");

    int count=0 ;
    int i = 0 ;
    int x = 160 ;

    setbkcolor(BLACK);

    while(1)
    {
        setcolor(i);

        settextstyle(3,HORIZ_DIR,5);

        outtextxy(65,100,"Mclaren Advertisements");

        settextstyle(3,HORIZ_DIR,4);

        outtextxy(360,230,"Made By:-");

        settextstyle(3,HORIZ_DIR,2);

        outtextxy(300,285,"1.Nikita Bansal (16104043)");
        outtextxy(300,330,"2.Umang Rastogi (16104037)");
        outtextxy(300,385,"3.Rushil khattar(16104002)");
        outtextxy(300,435,"4.Sahil Gumber  (161040  )");

        i++;
        if(i==14)
            i=0;
        line(x,30,x,280);
        delay(10);
        count++;
        x++;
        if(x==550)
            break;
 }
	clearviewport();
	i = 0 ;
	count = 0 ;
	x = 160 ;

	while(1)
    {
        setcolor(i);

        settextstyle(3,HORIZ_DIR,7);

        outtextxy(80,120,"-> Television");
        outtextxy(80,220,"-> Radio");
        i++;

        if(i==14)
            i=0;

        line(x,295,x,315);
        delay(10);
        count++;
        x++;

        if(x==450)
            break;
    }

    clearviewport();
    setcolor(WHITE);

    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    ///INTRO PAGE END


    int total =3;
    int totalprofit=0;

    int W = 180;
    Item arr[] =   {{6, 1,"lux",2}, {10, 2,"oreo",4},
                    {12, 3,"jio",3},{10, 2,"vodafone",4},
                    {13, 4,"airtel",8}, {15, 4,"idea",24},
                    {18, 5,"nike",15}, {20, 5,"vicks",10},
                    {22, 5,"aircel",10},{25, 6,"addidas",12},
                    {27, 6,"puma",5}, {30, 6,"reebok",12},
                    {14, 7,"myntra",2}, {17, 7,"amazon",27},
                    {43, 7,"flipkart",5},{98, 8,"jabong",32},
                    {74, 8,"snapdeal",16}, {85, 8,"timex",12},
                    {69, 9,"sonata",18}, {45, 9,"titan",36},
                    {76, 9,"tissot",18},{59, 10,"rolex",20},
                    {34, 10,"tag heuer",10}, {76, 10,"gschock",10},
                    {38, 11,"koovs",11}, {88, 11,"feviquick",22},
                    {95, 11,"fastrack",22},{100, 20,"zara",30}};

 int profit;

  int n = sizeof(arr) / sizeof(arr[0]);
   while(total>=0)
   {

        cout<<"\n"<<total<<"sequence of ads"<<"\n";
        profit =finalsequence(W, arr, n);

    cout << "Maximum profit we can obtain from current sequence of ads is = "<< profit;

    totalprofit+=profit;

    total--;
   }
       cout<<"\n"<<"total profit is"<<totalprofit<<endl;
       cout<<endl;

       cout<<"RADIO";
       cout<<"Now Pairing Our Radio Broadcasting Ads Together "<<endl;

       radiopairing();

}
//the end

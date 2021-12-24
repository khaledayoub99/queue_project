#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char car_in;
    char car_out;
    int num_ser;
    int cap;

}queueing;

int main()
{
    int Nt;
    int t;
    int n;
    int wqn;
    queueing q1;
    float arrival_rate;
    float service_rate;
    int arrival_time;
    int service_time;
    //=========================
    printf("Kendall Notation: ");
    scanf("%c",&q1.car_in);
    scanf("/D/%d",&q1.num_ser);
    scanf("/%d",&q1.cap);
    //=========================
    printf("arrival rate: ");
    scanf("%f",&arrival_rate);
    arrival_time=(float)1/(float)arrival_rate;
    printf("service_rate: ");
    scanf("%f",&service_rate);
    service_time=(float)1/(float)service_rate;
    printf("time: ");
    scanf("%d",&t);
    n=arrival_rate*t;
    //=========================
    if(q1.car_in=='D'){
        int ti;
        if(arrival_rate>service_rate){
                ti =((q1.cap-(service_rate/arrival_rate))/(arrival_rate-service_rate));
                while(1){
                    ti=ti-(1/arrival_rate);
                    Nt=(int)(arrival_rate*ti)-(int)((service_rate*ti)-(service_rate/arrival_rate));
                    if(q1.cap!=Nt){
                        ti=ti+(1/arrival_rate);
                        break;
                    }
                }
                printf("\nBy trial and error t(i)=%d\n",ti);
                if(t<(1/arrival_rate)){
                printf("\nn(t) = 0");
                }
                else if((1/arrival_rate)<=(t)&&(t)<ti){
                        Nt=(int)(arrival_rate*t)-(int)((service_rate*t)-(service_rate/arrival_rate));
                        printf("\nn(t) = %d",Nt);
                }
                else{
                    int compare=service_time%arrival_time ;
                    if(compare==0){
                    printf("\n n(t) = %d",(q1.cap)-1);
                    }
                    else{
                        printf("\n n(t) = %d  or %d",(q1.cap)-1,(q1.cap)-2);
                    }

                }
                if(n==0){
                    printf("\nwq(n) = 0");
                }
                else if(n>0&&n<arrival_rate*ti){
                    wqn=(service_time-arrival_time)*(n-1);
                    printf("\nwq(%d) = %d",n,wqn);
                }
        }
        else if(arrival_rate>service_rate){

        }

    }
    if(q1.car_in=='M'){
        printf("\n    MAR    \n");
    }

    return 0;
}

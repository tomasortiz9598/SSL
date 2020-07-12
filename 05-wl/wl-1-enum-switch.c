#include<stdio.h>

// int main(){
//     typedef enum state {OUT, IN} state;
//     int c;
//     state State = IN;
//     while ((c=getchar())!= EOF){
//         switch (State){
//             case OUT:
//                 printf("\n");
//                 putchar(c);
//                 State=IN;
//                 break;
//             case IN:
//                 putchar(c);
//                 if ( ' ' == c || '\n' == c || '\t' == c)
//                     State = OUT;
//                 break;
//         }
//     }
// }

 
int enumSwitch(){
    typedef enum state {OUT, IN} state;
    int c, nl, nw, nc;
    state State = OUT;
    nl = nw =nc =0;
    while ((c=getchar())!= EOF){
        ++nc;
        switch (State){
            case OUT:
                State=IN;
                ++nw;
                break;
            case IN:
                if(c=='\n')
                    ++nl;
                if(c == ' ' || c == '\n' || c == '\t')
                    State = OUT;
                break;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}

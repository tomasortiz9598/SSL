#include<stdio.h>
int main(){
    int c, nl, nw, nc;
    nl = nw =nc =0;
    WHILE:
        if ((c=getchar())!= EOF){
            goto IN;
        }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
    OUT:
        ++nw;
        goto WHILE;
    IN:
        ++nc; 
        if(c=='\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            goto OUT;
        goto WHILE;
}

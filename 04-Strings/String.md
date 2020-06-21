
## getLength
getLength : Σ* → |N / getLength(string) =  { 0   si string='/0'
                                           { getLength(string) +1    si string = string * w AND w ∈ Σ*

## isEmpty
isEmpty : Σ* → |N / isEmpty(string) =  { 1   si String = '/0'
                                       { 0  si String != '/0'

## strcmp
strcmp : Σ* X Σ* → |N / strcmp(string1,string2) = {1      si String1=String2
                                                  {0 si String1!=String2
                                  
## power

power : Σ* x |N → Σ* / power(string1,n) = { '/0'                          si n=0
                                          {string                         si n=1
                                          {string1*power(string1, n-1)    si string!= null
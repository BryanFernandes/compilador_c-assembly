#define TESTE 3
#define ABCDEF 10
#define BRYANHF 5

int main(){
 
    int x = 3;
    int y;
    
    if(x==3){
        y=4;
        if (y==4) {
            x=5;
        }
    }
    
    do {
        x=y;
    } while (y<1);

    return 0;
}
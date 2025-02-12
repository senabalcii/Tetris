#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n,m,i,j;
    char start;
    int skor,best;
    best=0;
    for(j=0;j<=2;j++){
        for(i=0;i<=50;i++){
            printf("-");
        }
        printf("\n");}
    printf("\t \t \t \t   T E T R İ S \n");
    for(j=0;j<=1;j++){
        for(i=0;i<=50;i++){
            printf("-");
        }
        printf("\n");
    }
    printf("\t \t  Başlamak için 's' tuşuna basınız\n");
    for(i=0;i<=50;i++){
        printf("-");
    }
    printf("\n");
    
    printf("\t \t Oyun içinde menüye girmek için 'm'\n \t \toyundan çıkmak için 'o' tuşuna basınız\n");
    
    for(j=0;j<=1;j++){
        for(i=0;i<=50;i++){
            printf("-");
        }
        printf("\n");}
    
    scanf("%c",&start);
    
    while(start=='s' || start=='S') {
        
        skor=0;
        
        
        printf("tahtanın boyutlarını giriniz:");
        scanf("%d",&n);
        scanf("%d",&m);
        
        
        
        
        getchar();
        char tahta[1000][1000];
        int a,b= 0;
        char parca[5][5];
        int col,s,k,l;
        int enust=0;
        char islem;
        int turn[3][3];
        int doluluk,patladı = 0;
        
        
        for(i=0;i<=m+m+1;i++){
            printf("_");
        }
        printf("\n");
        
        for(i=0;i<=n-1;i++){
            printf("|");
            for(j=0;j<=m+m-2;j=j+2){
                tahta[i][j]=' ';
            }
            for(j=1;j<=m+m;j=j+2){
                tahta[i][j]='.';
            }
            for(j=0;j<=m+m;j++){
                printf("%c",tahta[i][j]);
            }
            
            printf("|");
            printf("\n");
        }
        for(i=0;i<=m+m+1;i++){
            printf("-");
        }
        
        printf("\n");
        do{
            
            for(i=0;i<=4;i++){
                for(j=0;j<=4;j++){
                    parca[i][j]=' ';
                }
            }
            
            srand(time(NULL));
            
            for(i = 0 ; i < 9 ; i++)
            {
                a = rand() % 3 + 1;
                b = rand() % 3 + 1;
                parca[a][b]= 'X';
            }
            
            printf("\n");
            
            //parçanın sağında solunda bir şey var mı
            for(i=1;i<4;i++){
                for(j=1;j<4;j++){
                    if(parca[i][j]=='X'){
                        if(parca[i-1][j]!='X' && parca[i+1][j]!='X' ){
                            
                            if(parca[i][j-1]!='X' && parca[i][j-1]!='X'){
                                parca[i][j]=' ';
                            }
                        }
                    }
                }
            }
            for(k=0;k<=1;k++){
                //sütun kaydırma
                for(j=1;j<=3;j++){
                    i=1;
                    doluluk=0;
                    while(doluluk==0 && i<=3){
                        if(parca[i][j]=='X'){
                            doluluk=1;
                        }
                        else{
                            i++;
                        }
                    }
                    if(doluluk==0){
                        for(i=1;i<=3;i++){
                            parca[i][j]=parca[i][j+1];
                            parca[i][j+1]=' ';
                        }
                    }
                }
                //satır kaydırma
                for(i=3;i>=1;i--){
                    j=1;
                    doluluk=0;
                    while(doluluk==0 && j<=3){
                        if(parca[i][j]=='X'){
                            doluluk=1;
                        }
                        else{
                            j++;
                        }
                    }
                    if(doluluk==0){
                        for(j=1;j<=3;j++){
                            parca[i][j]=parca[i-1][j];
                            parca[i-1][j]=' ';
                        }
                    }
                }
            }
            
            
            
            
            
            for(i=1;i<4;i++){
                for(j=1;j<4;j++){
                    printf("%c ", parca[i][j]);
                }
                printf("\n");
            }
            
            
            
            printf("çevirmek için r(rotate) ye yerleştirmek için p(place) ye basın\n");
            scanf(" %c",&islem);
            
            
            
            while(islem!='p' && islem!='o'){
                
                
                if(islem=='r'){
                    
                    for(i=0; i<3; ++i){
                        turn[i][0] = parca[3][i+1];
                        turn[i][1] = parca[2][i+1];
                        turn[i][2] = parca[1][i+1];
                    }
                    for(i=0;i<3;i++){
                        for(j=0;j<3;j++){
                            parca[i+1][j+1]=turn[i][j];
                        }
                    }
                    
                    //sütun kaydırma
                    for(j=1;j<=3;j++){
                        i=1;
                        doluluk=0;
                        while(doluluk==0 && i<=3){
                            if(parca[i][j]=='X'){
                                doluluk=1;
                            }
                            else{
                                i++;
                            }
                        }
                        if(doluluk==0){
                            for(i=1;i<=3;i++){
                                parca[i][j]=parca[i][j+1];
                                parca[i][j+1]=' ';
                            }
                        }
                    }
                    //satır kaydırma
                    for(i=3;i>=1;i--){
                        j=1;
                        doluluk=0;
                        while(doluluk==0 && j<=3){
                            if(parca[i][j]=='X'){
                                doluluk=1;
                            }
                            else{
                                j++;
                            }
                        }
                        if(doluluk==0){
                            for(j=1;j<=3;j++){
                                parca[i][j]=parca[i-1][j];
                                parca[i-1][j]=' ';
                            }
                        }
                    }
                    
                    
                    for(i=1;i<4;i++){
                        for(j=1;j<4;j++){
                            printf("%c ", parca[i][j]);
                        }
                        printf("\n");
                    }
                    printf("işlemi girin");
                    scanf(" %c",&islem);
                    
                }
                
                else if(islem=='m'){
                    printf("\n\n\n---MENÜ---\n");
                    printf("skor: %d\n",skor);
                    printf("en iyi skor: %d\n",best);
                    printf("devam etmek için cye çıkmak için o ya basın");
                    scanf(" %c",&islem);
                }
                
                else if(islem=='c'){
                    
                    for(i=0;i<=m+m+1;i++){
                        printf("_");
                    }
                    printf("\n");
                    for(i=0;i<=n-1;i++){
                        printf("|");
                        
                        for(j=0;j<=m+m;j++){
                            printf("%c",tahta[i][j]);
                        }
                        
                        printf("|");
                        printf("\n");
                    }
                    for(i=0;i<=m+m+1;i++){
                        printf("-");
                    }
                    printf("\n");
                    for(i=1;i<4;i++){
                        for(j=1;j<4;j++){
                            printf("%c ", parca[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\nskor: %d",skor);
                    printf("\nçevirmek için r(rotate) ye yerleştirmek için p(place) ye basın\n");
                    scanf(" %c",&islem);
                }
                
            }
            
            if(islem=='o'){
                printf("skor: %d\n",skor);
                printf("en iyi skor: %d\n",best);
                printf("yeniden oynamak için s ye basın çıkmak o ya basın\n");
                scanf(" %c",&start);
                enust=1;
            }
            
           else if(islem=='p'){
                printf("kaçıncı sütuna yerleşsin:");
                scanf("%d",&col);
                
               //çakışma
                i=n-1;
               while(tahta[i][col+col-2]=='X' && parca[3][1]=='X'){
                    i--;
                }
                for(j=3;j>=1;j=j-1){
                    s=col+col-2;
                    for(k=1;k<=3;k++){
                        if(tahta[i][s]!='X' && tahta[i-1][s]!='X'){
                            tahta[i][s]=parca[j][k];
                            s=s+2;}
                        else {
                            s=s+2;
                        }
                    }
                    i=i-1;
                }
                
               
                //tahtayı çıktı al
                for(i=0;i<=m+m+1;i++){
                    printf("_");
                }
                printf("\n");
                for(i=0;i<=n-1;i++){
                    printf("|");
                    
                    for(j=0;j<=m+m;j++){
                        printf("%c",tahta[i][j]);
                    }
                    
                    printf("|");
                    printf("\n");
                }
                for(i=0;i<=m+m+1;i++){
                    printf("-");
                }
                printf("\n");
                
                //en üst satırı kontrol et
                for(i=0;i<=m;i++){
                    if(tahta[0][i]=='X'){
                        enust=1;
                        printf("yeniden oynamak için s ye basın çıkmak o ya basın\n");
                        printf("skor: %d\n",skor);
                        printf("en iyi skor: %d\n",best);
                        scanf(" %c",&start);
                        if(start=='s'){
                            i=m;
                        }
                    }
                }
                
                //satırları patlat
                patladı=0;
                for(i=1;i<=n;i++){
                    j=0;
                    doluluk=1;
                    while(doluluk==1 && j<=m+m-2){
                        if(tahta[i][j]!='X'){
                            doluluk=0;
                        }
                        else{
                            j=j+2;
                        }
                    }
                    if(j>m+m-2){
                        patladı=1;
                        for(l=i;l>=1;l=l-1){
                            for(k=0;k<=m+m-2;k=k+2){
                                tahta[l][k]=tahta[l-1][k];
                            }}
                    }
                }
                
                //satır patladıktan sonra tahtayı çıktı al
                if(patladı==1){
                    skor=skor+m;
                    printf("patladı\n");
                    for(i=0;i<=m+m+1;i++){
                        printf("_");
                    }
                    printf("\n");
                    for(i=0;i<=n-1;i++){
                        printf("|");
                        
                        for(j=0;j<=m+m;j++){
                            printf("%c",tahta[i][j]);
                        }
                        
                        printf("|");
                        printf("\n");
                    }
                    for(i=0;i<=m+m+1;i++){
                        printf("-");
                    }}
               
               if(skor>best){
                   best=skor;
               }
                printf("\nskor: %d",skor);
               
                
                
            }}
        
    
        
        while(enust==0);}
    return 0;
}


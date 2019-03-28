#include "xpaint.h"

void desenha(int y, int x, int tamanho){
    if(tamanho < 5){
        return;
    }
    float ang = 90;
    for(int i = 0; i < 6; i++){
        int xF = x + tamanho * xm_cos(ang);
        int yF = y - tamanho * xm_sin(ang);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_circle(x, y, tamanho);
        x_step("circulo");
        desenha(yF, xF, tamanho / 3);
        ang += 60;
    }
}

int main(){

    int largura = 900;
    int altura = 900;
    x_open(largura ,altura);
    x_clear(BLACK);
    int x = largura / 2;
    int y = altura / 2;
    int tamanho = 254;

    desenha(y, x, tamanho);
    x_save("circulo");
    x_close();
    return 0;
}
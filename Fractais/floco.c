#include "xpaint.h"

void desenha(int y, int x, int tamanho){
    if(tamanho <= 0){
        return;
    }
    float ang = 270;
    for(int i = 0; i < 5; i++){
        int xF = x + tamanho * xm_cos(ang);
        int yF = y - tamanho * xm_sin(ang);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_thick_line(x, y, xF, yF, 1);
        x_step("neve");
        desenha(yF, xF, tamanho / 3);
        ang += 72;
    }
}

int main(){

    int largura = 2000;
    int altura = 2000;
    x_open(largura ,altura);
    x_clear(BLACK);
    int x = largura / 2;
    int y = altura / 2;
    int tamanho = 600;

    desenha(y, x, tamanho);
    x_save("neve");
    x_close();
    return 0;
}
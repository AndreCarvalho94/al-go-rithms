#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdbool.h>
#include "funçoes.h"









ALLEGRO_DISPLAY *janela = NULL;

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;


bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

    al_set_window_title(janela, "Testando allegro_primitives");

    return true;
}

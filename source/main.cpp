#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

int main(void)
{
    // Inicializamos una ventana de 800x450 píxeles con un título personalizado
    InitWindow(1920, 1080, "Camila Torres");

    // Configuramos el framerate deseado (opcional, pero recomendado)
    SetTargetFPS(60);

    Color fondo = { 110, 100, 215, 255 };//color violeta personalizado
    Color texto = BLACK;
    Color figura = { 28, 161, 82, 255 };

    // Estado del mensaje secundario 
    bool mensajeCambiado = false;

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Cambio el mensaje al presionar ESPACIO 
        if (IsKeyPressed(KEY_SPACE))
        { 
            mensajeCambiado = !mensajeCambiado; 
        }

        // Iniciamos la etapa de dibujo
        BeginDrawing();

        // Limpiamos la pantalla 
        ClearBackground(fondo);

        //Titulo
        const char* nombre = "Camila Torres";
        int tamanioNombre = 60;
        int anchoNombre = MeasureText(nombre, tamanioNombre); 
        DrawText(nombre, (1920 - anchoNombre) / 2, 400, tamanioNombre, texto);

        //Linea-Rectangulo
        DrawRectangle( 635, 480, 650, 40, figura);

        //Subtitulo
        const char* mensaje;
        if (mensajeCambiado) 
        {
            mensaje = "Estoy aprendiendo en MAVI!";
        }
        else
        {
            mensaje = "Hola mundo!";
        } 
        int tamanioMensaje = 30;
        int anchoMensaje = MeasureText(mensaje, tamanioMensaje);
        DrawText(
            mensaje,
            (1920 - anchoMensaje) / 2,
            560,
            tamanioMensaje, 
            WHITE
        );

        //Indicacion
        const char* indicacion = "Presiona ESPACIO para cambiar el mensaje"; 
        int tamanioIndicacion = 20;
        int anchoIndicacion = MeasureText(indicacion, tamanioIndicacion); 
        
        DrawText(
            indicacion, 
            (1920 - anchoIndicacion) / 2, 
            650, 
            tamanioIndicacion,
            LIGHTGRAY
        );

        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}


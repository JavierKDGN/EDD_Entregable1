/* Compilación: g++ -g -o img test.cpp
 * Ejecución: ./img
 *
 * Luego de la ejecución se generarán 3 imagines: imagen.png,
 * imagen_desplazada_500.png e imagen_desplazada_600.png
 */

#include "moving_image.h"
#ifdef _WIN32
#include<windows.h> // para Sleep (Windows). Usar  #include<unistd.h> para Linux
void sleep(int ms) {
	Sleep(ms);
}
#else
#include<unistd.h> // para sleep (linux). Usar  #include<windows.h> para Windows
#endif



int main() {
  moving_image im;

  //im.redo();
  //im.undo();
  //im.repeat();
  //im.repeat_all();

  im.draw("imagen.png");
  im.move_down(50);
  im.draw("imagen_desplazada_50abajo.png");
  im.undo();

  im.move_up(50);
  im.draw("imagen_desplazada_50arriba.png");
  im.undo();


  im.move_left(50);
  im.draw("imagen_desplazada_50izquierda.png");
  im.undo();

  im.move_right(50);
  im.draw("imagen_desplazada_50derecha.png");
  im.undo();

  im.rotate();
  im.draw("imagen_rotada_antihorario.png");
  im.undo();

  im.move_up(200);
  im.move_down(200);
  im.undo();
  im.repeat(); // deberia repetir el move_up()
  im.draw("imagen_desplazada_400arriba.png");
  im.undo();   // deshace el repeat()
  im.draw("imagen_desplazada_200arriba.png");

  im.move_left(300);
  im.rotate();
  im.repeat();
  im.undo();
  im.undo();
  im.redo();
  im.repeat_all();
  im.repeat_all();

  

  /* NOTA 1: Si usan el mismo nombre para las imágenes, entonces cada llamada al
  método draw() sobreescribirá a la imagen */

  /* NOTA 2: Si usan un ciclo while(1) y usan el mismo nombre de imagen,
  entonces se puede generar un efecto de desplazamiento continuo (algo así como
  un video =D ) */
  return 0;
}

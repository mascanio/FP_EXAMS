// Miguel Ascanio Gómez

#include <iostream>
using namespace std;

#include <fstream>
#include <iomanip>
#include <cmath>

int main()
{
   system("chcp 1252");

   const int Centinela = -1;

   ifstream lectura;
   ofstream escritura;

   int opcion, //Opcion seleccionada
      entrada, //Entrada de teclado (para opciones 1 y 3)
      leido,   //Numero leido de archivo
      j,       //Para divisores en 2 y contador de linea en 3
      cuadrado = 1000000;//Cuadrado para opcion 3
   cout << cuadrado << endl;
   //>>>>> ¿¿¿???

   bool primo = true, encontrado = false;

   do //while(opcion != 0);
   {
      //Menú
      cout << "1 - Crear la secuencia" << endl
         << "2 - Procesar la secuencia" << endl
         << "3 - Buscar en la secuencia" << endl 
         << "0 - Salir" << endl
         << "Opción: " ;      
      cin >> opcion;

      switch (opcion)
      {
      case 1: //Crear Secuencia
         escritura.open("datos.txt"); //Abrir archivo para escritura

         do //while (entrada != 0); pedir números hasta introduc. 0
         {
            cout << "Entero positivo (0 para terminar): " ;
            cin >> entrada;

            if (entrada >= 1 && entrada <= 1000) //escribir números entre 1 y 1000, otros los ignora
            //>>>>> Encierra las condiciones simples entre paréntesis: if ((entrada >= 1) && (entrada <= 1000))

               escritura << entrada << endl ;
         }while (entrada != 0);

         escritura << Centinela ; //Escribir centinela y cerrar
         escritura.close();

         break;

      case 2: //Procesar Secuencia
         lectura.open("datos.txt"); //Abrir archivo para lectura

         if(lectura.is_open()) //Comprobar si abre, si no mostrar error
         {
            do // while (leido != Centinela); leer de archivo hasta centinela Centinela
            {
               lectura >> leido;
               primo = true;

               if (leido != Centinela)
               {
                  cout << setw (4) << leido ; //Mostrar Número
                  for (int i = 2; i < leido; i++) //Buscar divisores, si se encuentra no es primo y se muestran
                  //>>>>> Basta llegar a leido / 2

                  {
                     if(leido % i == 0) //No es primo
                     {
                        primo = false;
                        cout << " no es primo (" ;
                        cout << i ; //Mostrar primer divisor

                        j = i + 1;
                        while (j < leido) //Mostrar divisores sucesivos
                        {
                           if(leido % j == 0)                            
                              cout << ", " << j ;
                           j++;
                        } 
                        cout << ")" << endl;
                        i = j;
                        //>>>>> ARGGG!!! No modifiques la variable contadora de un for NUNCA!!!!!

                     }                  
                  }
                  if (primo) //Es primo (no se han encontrado divisores)
                     cout << " es primo" << endl ;
               }
            } while (leido != Centinela);

            lectura.close();
         }
         else
            cout << "¡Error al abrir el archivo!" << endl ;

         break;

      case 3: //Buscar en la secuencia
         lectura.open("datos.txt"); //Abrir archivo para lectura

         if(lectura.is_open()) //Comprobar si abre, si no mostrar error
         {
            do
            {
               cout << "Cuadrado a buscar: " ;
               cin >> entrada;
            } while (!(entrada >= 1 && entrada <= 1000000)); //Pedir numero entre intervalo
            //>>>>> Mejor: while ((entrada < 1) || (entrada > 1000000));

            j = 1;
            encontrado = false;

            do // while (leido != Centinela); leer de archivo hasta centinela Centinela
            {
               lectura >> leido;
               //>>>>> Procesas el centinela final!!!

               cuadrado = pow (double (leido), 2);
               if ((abs(cuadrado - entrada) <= 10))
               {
                  cout << "Encontrado en la línea " << j << ": " << leido << " (cuadrado: " << cuadrado << ")" << endl;
                  encontrado = true;
               }
               j++;
            } while (leido != Centinela && !encontrado);
            //>>>>> while ((leido != Centinela) && !encontrado);

            if(!encontrado)
               cout << "No se ha encontrado" << endl ;

            lectura.close();
         }
         else
            cout << "¡Error al abrir el archivo!" << endl ;

         break;

      case 0: break; //Salir

      default: //Opcion no válida
         cout << "Opción incorrecta. Inténtalo de nuevo..." << endl;
         break;
      }

   } while(opcion != 0);

   return 0;
}
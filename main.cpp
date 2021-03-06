#include <iostream>
#include <cstring>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#include <usuario.h>


using namespace std;
////////////////Contraseña admin : AbCd
/*El siguiente programa representa la simulacion de un cajero electronico
 * El cual cuenta con dos perfiles de ingreso, cada uno con opciones distintas:
 * Administrador : cuenta con el metodo Registrar de la clase usuario
 * Usuario: Cuenta con 2 opciones :retirar saldo, consultar saldo
 *
 * ACLARACIONES:
 * La informacion se actualiza cada vez que se ingresa un nuevo usuario, se consulta saldo,
 *  y se retira dinero, en estos dos ultimos casos se retiran 1000 COP adicionales
 *  -En caso del usuario no contar con los 1000 pesos, no se le permitira realizar el retiro
 *  Ejemplo: Si tiene un saldo de 20000, y desea retirar 20000, no s ele permitira
 */


int main()
{
    usuario user;
    user.lectura();

    string documento;
    int op=0;

    string contrasena;

    cout<<"******     SU PERFIL    *****"<<endl;
    cout<<"*****************************"<<endl;
    cout<<endl;
    cout<<" 1. Administrador o 2.Usuario"<<endl;
    cout<<"--> ";cin>>op;

    if(op==1){

            cout<<"Ingrese la contrasena : ";cin>>contrasena;
            system("cls");
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            if(user.verificar(contrasena)){
               int opc=0;
               cout<<" Ingrese el numero de la opcion que desea realizar : "<<endl;
               cout<<" 1. Agregar nuevo usuario "<<endl;
               cout<<" 2.Salir "<<endl;
               cout<<"-->";cin>>opc;

               switch(opc)
               {     case (1):
                        user.Registar();
                        break;
                     case(2):
                         break;

                }
            }

            else{

            cout<<" Clave incorrecta ";

            }


    }

    else{

        string contrasena;
        cout<<" Ingrese su documento (7 digitos) :";cin>>documento;
        user.verificar_Usuario(documento);

        cout<<"Ingrese contrasena : ";cin>>contrasena;
        if((user.verificar_Contrasena(contrasena))==true){
            int menu=0;
            cout<<"  ========================== "<<endl;
            cout<<"   << Bienvenido usuario >> "<<endl;
            cout<<"       Que desea hacer :     "<<endl;
            cout<<" 1. Consultar saldo "<<endl;
            cout<<" 2. Retirar dinero "<<endl;
            cout<<" 3. Salir "<<endl;

            cout<<" Su opcion --> ";cin>>menu;

            if(menu==1){

                    user.Consultar_Saldo();
            }

            else if(menu==2){

                    user.Retirar_Dinero();

            }

            else{
                cout<<"Fin";
            }


         }

        else{
            cout<<"  Contraseña invalida :c  "<<endl;
        }

    }


    return 0;
}


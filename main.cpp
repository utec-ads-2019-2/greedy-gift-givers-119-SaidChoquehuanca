#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
int separacion = 1;
void imprimir(vector<string>array , map<string , int> personas , int cantidad){
    for (int i = 0; i < cantidad; ++i) {
        cout << array[i] << " " << personas[array[i]] << endl;
    }
}
int main() {
    unsigned int num_Personas;
    while(cin>>num_Personas){
        vector<string> nombres;
        map<string ,int> salida;
        for(int i = 0 ; i<num_Personas; i++){
            string name;
            cin>>name;
            nombres.push_back(name);
            salida[name] = {0};
        }
        for(int j=0 ; j<num_Personas;++j){
            int dinero, repartido,porcion;
            string name;
            cin>>name;
            cin>>dinero>>repartido;
            if(repartido==0){
                continue;
            }
            porcion = dinero/repartido;
            salida[name] -= porcion*repartido;
            for(int k=0;k<repartido;++k){
                cin>>name;
                salida[name]+= porcion;
            }
        }
        if (separacion++ >1) printf("\n");
        imprimir(nombres,salida,num_Personas);
    }
    return 0;
}

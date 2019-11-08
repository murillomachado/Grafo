#include <iostream>
#include "TGrafo.h"

using namespace std;

int main(){
   TGrafo* G;

   G = new TGrafo();
   G->settipo(true); //Grafo orientado
   cout << "Adicionando vertice A: " << G->AddVertice(188859.709932, 8253809.082146) << endl;
   cout << "Adicionando vertice B: " << G->AddVertice(188859.709933, 8253809.082146) << endl;
   cout << "Adicionando vertice C: " << G->AddVertice(188905.046973, 8253520.080854) << endl;
   cout << "Adicionando vertice D: " << G->AddVertice(189111.073925, 8253818.425694) << endl;
   cout << "Adicionando arestas A<->B, A<->D, A->C, B<->C, D->B, A<->E" << endl;

   cout << G->AddAresta(0, 1, "Aresta A<->B", 15.5, true) << endl;
   cout << G->AddAresta(0, 3, "Aresta A<->D", 17, true) << endl;
   cout << G->AddAresta(0, 2, "Aresta A->C", 3.141592654, false) << endl;;
   cout << G->AddAresta(1, 2, "Aresta B<->C", 8, true)<< endl;
   cout << G->AddAresta(3, 1, "Aresta D->B", 33.1, false) << endl;
   cout << G->AddAresta(0, 4, "Aresta A<->E", 33.1, true) << endl;
   G->Print();
   cout << "1================================================" << endl;

    //buscar Vertice como está sendo buscado metodo  addAresta da classe Grafo
    Vertice a = G->getLVertices()->getprim()->getinfo();
    cout << "2================================================" << endl;

    Vertice b = G->getLVertices()->getprim()->getprox()->getinfo();
    cout << "3================================================" << endl;

    cout << "ID DO A " <<a.getid() << endl;
    cout << "ID DO B "<<b.getid() << endl;


   if(a.isEqual(b)){
    cout << "iguais" << endl;
   }else{
    cout << "diferentes" << endl;
   }

    cout << "4================================================" << endl;



   cout << "Alterando o grafo..." << endl;
   cout << "Removendo o vertice C" << endl;
   G->RemVertice(2);
   cout << "Removendo a aresta A<->B" << endl;
   G->RemAresta(0, 1, true);
   G->Print();

   delete G;
}



#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include "Aresta.h"

using namespace std;

//--------------------------------------------------
//Classe Vertice - Protótipo
//--------------------------------------------------
class Vertice{
   int id;
   double x;
   double y;
   TLista<Aresta>* LArestas;
public:
   Vertice();
   int getid();
   double getX();
   double getY();
   void setX(double _x);
   void setY(double _y);
   void setid(int _id);
   TLista<Aresta>* getLArestas();
   void Add_Aresta(int _destino, string _name, double _peso);
   bool Rem_Aresta (int _id);
   bool isEqual(Vertice b);
};

//--------------------------------------------------
//Classe Aresta - Implementação
//--------------------------------------------------
Vertice::Vertice(){
   LArestas = new TLista<Aresta>();
}

int Vertice::getid(){
   return id;
}

double Vertice::getX(){
   return x;
}

double Vertice::getY(){
   return y;
}

void Vertice::setid(int _id){
   id = _id;
}

void Vertice::setX(double _x){
   x = _x;
}

void Vertice::setY(double _y){
   y = _y;
}

TLista<Aresta>* Vertice::getLArestas(){
   return LArestas;
}

void Vertice::Add_Aresta(int _destino, string _name, double _peso){
   Aresta *A;

   A = new Aresta(_destino, _name, _peso);
   LArestas->ins_fim(*A);
}

bool Vertice::Rem_Aresta (int _id){
   TNo<Aresta> *p = LArestas->getprim();
   int i = 0;
   bool achou = false;

   while ((p != nullptr) && (!achou)){
      if (p->getinfo().getid_dest() == _id) achou = true;
      else {
         p = p->getprox();
         ++i;
      }
   }

   if (achou) LArestas->rem(i);
   return(achou);
}

bool Vertice::isEqual(Vertice b){
    if(this->x == b.x){
        if(this->y == b.y){return true;}
    }
    return false;
}

#endif // VERTICE_H_INCLUDED

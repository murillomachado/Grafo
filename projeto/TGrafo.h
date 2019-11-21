#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <string>
#include "TLista.h"
#include "Vertice.h"
#include "TNo.h"

using namespace std;

//--------------------------------------------------
//Classe Grafo - Protótipo
//--------------------------------------------------
class TGrafo{
   bool tipo; //False = Grafo; True = Dígrafo, Orientado ou Dirigido
   int autoid;
   int ordem;
   int dimensao;
   TLista<Vertice>* LVertices;
public:
   TGrafo();
   TGrafo(int _ordem, int _dimensao, bool _tipo);
   bool gettipo();
   void settipo(bool _tipo);
   int getordem();
   int getdimensao();
   TLista<Vertice>* getLVertices();
   Vertice getVertice(int _id);
   int AddVertice(double _x, double _y);
   void RemVertice(int _id);
   bool AddAresta(int _origem, int _destino, string _name, double _peso, bool _bidir);
   void RemAresta(int _origem, int _destino, bool _bidir);
   void Print();
   ~TGrafo();
};

//--------------------------------------------------
//Classe Grafo - Implementação
//--------------------------------------------------
TGrafo::TGrafo(){
   tipo = false;
   ordem = 0;
   autoid = 0;
   dimensao = 0;
   LVertices = new TLista<Vertice>();
}

TGrafo::TGrafo(int _ordem, int _dimensao, bool _tipo = false){
   ordem = _ordem;
   dimensao = _dimensao;
   tipo = _tipo;
   autoid = 0;
   LVertices = new TLista<Vertice>();
}

bool TGrafo::gettipo(){
   return tipo;
}

void TGrafo::settipo(bool _tipo){
   tipo = _tipo;
}

int TGrafo::getordem(){
   return ordem;
}

int TGrafo::getdimensao(){
   return dimensao;
}

TLista<Vertice>* TGrafo::getLVertices(){
   return LVertices;
}

int TGrafo::AddVertice(double _x, double _y){
   Vertice V;
   V.setid(autoid);
   ++autoid;
   V.setX(_x);
   V.setY(_y);
   LVertices->ins_fim(V);
   ++ordem;
   return(autoid - 1);
}

Vertice TGrafo::getVertice(int _id){
   TNo<Vertice> *p = LVertices->getprim();
   int n = LVertices->getTamanho();
   int i = 0;

    while( i < n ){
        if(p->getinfo().getid() == _id ){
            return p->getinfo();
        }else {
                p = p->getprox();
                i++;
        }
    }
}

void TGrafo::RemVertice(int _id){
   int i, j;
   TNo<Vertice> *v1 = LVertices->getprim();
   TNo<Vertice> *v2 = LVertices->getprim();
   bool achou = false;

   i = 0;
   while ((v1 != nullptr) and (!achou)){
      if (v1->getinfo().getid() == _id) achou = true;
      else{
         ++i;
         v1 = v1->getprox();
      }
   }

   if (v1 != nullptr){
      for (j = 0; j < ordem; ++j){
         if (v1 == v2) continue;
         while(v2->getinfo().Rem_Aresta(_id)) --dimensao;
         v2 = v2->getprox();
      }
      dimensao -= v1->getinfo().getLArestas()->size();
      LVertices->rem(i);
      --ordem;
   }
}

bool TGrafo::AddAresta(int _origem, int _destino, string _name, double _peso, bool _bidir){
   TNo<Vertice> *v = LVertices->getprim();
   TNo<Vertice> *vOrig, *vDest;

   vOrig = nullptr;
   vDest = nullptr;

   while((v != nullptr) || ((vOrig == nullptr) && (vDest == nullptr))){
      if(v->getinfo().getid() == _origem) vOrig = v;
      if(v->getinfo().getid() == _destino) vDest = v;
      v = v->getprox();
   }

   if(vOrig == nullptr){
      cout << "Vertice de origem nao encontrado. Aresta nao pode ser inserida!" << endl;
      return(false);
   }

   if(vDest == nullptr){
      cout << "Vertice de destino nao encontrado. Aresta nao pode ser inserida!" << endl;
      return(false);
   }

   vOrig->getinfo().Add_Aresta(_destino, _name, _peso);
   ++dimensao;

   if (_bidir){
      vDest->getinfo().Add_Aresta(_origem, _name, _peso);
      ++dimensao;
   }
   return(true);
}

void TGrafo::RemAresta(int _origem, int _destino, bool _bidir){
   TNo<Vertice> *v = LVertices->getprim();
   TNo<Vertice> *vOrig, *vDest;

   vOrig = nullptr;
   vDest = nullptr;

   while((v != nullptr) || ((vOrig == nullptr) && (vDest == nullptr))){
      if(v->getinfo().getid() == _origem) vOrig = v;
      if(v->getinfo().getid() == _destino) vDest = v;
      v = v->getprox();
   }

   if((vOrig == nullptr) || (vDest == nullptr)){
      cout << "Aresta nao encontrada!" << endl;
      exit(1);
   }

   while(vOrig->getinfo().Rem_Aresta(_destino)) --dimensao;
   if (_bidir){
      while(vDest->getinfo().Rem_Aresta(_origem)) --dimensao;
   }
}

void TGrafo::Print(){
   TNo<Vertice> *NoV;
   TNo<Aresta> *NoA;
   Vertice V;
   Aresta A;

   cout << endl << "----------------------------------------------------" << endl;
   cout << "Lista de vertices: " << endl;
   NoV = getLVertices()->getprim();

   while (NoV != nullptr){
      V = NoV->getinfo();
      cout << V.getid() << endl;
      cout << "Este vertice possui " << V.getLArestas()->size() << " arestas." << endl;
      NoA = V.getLArestas()->getprim();

      while (NoA != nullptr){
         A = NoA->getinfo();
         cout << "Origem: " << V.getid() << " - Destino: " << A.getid_dest() << " - Nome: " << A.getname() << endl;
         NoA = NoA->getprox();
      }

      NoV = NoV->getprox();
   }

   cout << "----------------------------------------------------" << endl;
   cout << "O grafo possui ordem = " << getordem() << endl;
   cout << "            dimensao = " << getdimensao() << endl;
   cout << "                tipo = " << gettipo() << endl;
   cout << "----------------------------------------------------" << endl << endl;
}

TGrafo::~TGrafo(){
   TNo<Vertice> *V = LVertices->getprim();

   while (V != nullptr){
      delete(V->getinfo().getLArestas());
      V = V->getprox();
   }
   delete(LVertices);
}

#endif // GRAFO_H_INCLUDED

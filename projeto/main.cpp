#include <iostream>
#include "TGrafo.h"
#include <fstream>
#include <string>


#include <sstream>
#include <vector>


using namespace std;


void instanciaGrafo(){
    system("cls");
    string file;
    cout << "Digite o nome do arquivo:" << endl;
    cin >> file;


    TGrafo* G;
    int inicio;
    int fim;
    G = new TGrafo();
    G->settipo(true);
    string line;
    string id;
    double impPos, impNeg, demand, Xini, Yini, Xfim, Yfim;
    bool bidir;
    int suapi;

    ifstream myfile (file);

  if (myfile.is_open()){
        getline (myfile,line);
        getline (myfile,line);
        getline (myfile,line);
        getline (myfile,line);

        while (! myfile.eof()){
                for(int i = 0; i < 4; i++){
                    getline (myfile,line);
                    vector<string> tokens;
                    string token;
                    istringstream tokenizer { line };

                    while (getline(tokenizer, token, ' ')){
                        if(token != ""){
                            tokens.push_back(token);
                        }
                    }
                    if(i == 0){
                            id = tokens[0];
                            impPos = stod(tokens[1]);
                            impNeg = stod(tokens[2]);
                            demand = stod(tokens[3]);
                    }else if(i==1){
                            Xini = stod(tokens[0]);
                            Yini = stod(tokens[1]);
                    }else if(i==2){
                            Xfim = stod(tokens[0]);
                            Yfim = stod(tokens[1]);
                    }

                }

                //cout << "Adicionando vertice A: " << G->AddVertice(Xini, Yini) << endl;
                inicio = G->testInsert(Xini, Yini);
                fim = G->testInsert(Xfim, Yfim);

                cout << "Vertices: "<< endl;
                cout << "inicio " << inicio << endl;
                cout << "fim " << fim << endl << endl;

                if(impPos != -1 && impNeg != -1){
                    G->AddAresta(inicio, fim, id, impPos, true);
                }else if (impPos != -1){
                    G->AddAresta(inicio, fim, id, impPos, false);
                }else if(impNeg != -1){
                    G->AddAresta(fim, inicio, id, impNeg, false);
                }
                cout << "+++++++++++++++++++++++: "<< endl;

//                cout << "X_inicial: " << Xini << endl;
//                cout << "Y_Inicial: " << Yini << endl;
//                cout << "X_final: " << Xfim << endl;
//                cout << "Y_final: " << Yfim << endl;
//                cout << "id: " << id<< endl;
//                cout << "Impedancia_Positiva: " <<impPos << endl;
//                cout <<"Impedancia_negativa: " << impNeg << endl;
//                cout <<"Demanda: " << demand << endl;
        }

//                cout << "Alterando o grafo..." << endl;
//                cout << "Removendo o vertice 2" << endl;
//                G->RemVertice(2);
//                cout << "Removendo a aresta A<->B" << endl;
//                G->RemAresta(0, 1, true);
                G->Print();

    myfile.close();
    system("pause");
  }
  else{
    system("pause");
    cout << "Arquivo nao existe!" << endl;
  }

}
void about(){
    system("cls");
    cout << endl <<"NOME DO SOFTWARE" << endl << "Allan Cristian da Cunha, Eduardo L. R. Schaurich, Murillo Machado" << endl;
    cout << "Funcionalidades: Ler grafos de arquivos texto." << endl << "Realizar buscas de amplitude e profundidade em grafos"<< endl;
    cout << "Descobrir o caminho minimo de grafos" << endl;
    cout << "OBJETIVOS" << endl<< endl<< endl;
    system("pause");

}

void menu(){
    int AuxMenu=7;
    while(AuxMenu != 6){
    system("cls");
    cout << "1 - Ler grafo do arquivo texto" << endl;
    cout << "2 - Busca em Amplitude" << endl;
    cout << "3 - Busca em Profundidade" << endl;
    cout << "4 - Caminho Minimo" << endl;
    cout << "5 - About" << endl;
    cout << "6 - Sair" << endl;
    cin >> AuxMenu;
        switch (AuxMenu){
            case 1: instanciaGrafo();
                break;
            case 2: cout << "Busca em Amplitude" << endl;
                break;
            case 3: cout << "Busca em Profundidade" << endl;
                break;
            case 4: cout << "Caminho Minimo" << endl;
                break;
            case 5: about();
                break;
            default:
                cout << "Valor invalido, digite novamente!" << endl;

                }
    }
}

int main(){

    menu();


//   TGrafo* G;
//
//   G = new TGrafo();
//   G->settipo(true); //Grafo orientado
//   cout << "Adicionando vertice A: " << G->AddVertice(188859.709932, 8253809.082146) << endl;
//   cout << "Adicionando vertice B: " << G->AddVertice(188859.709933, 8253809.082146) << endl;
//   cout << "Adicionando vertice C: " << G->AddVertice(188905.046973, 8253520.080854) << endl;
//   cout << "Adicionando vertice D: " << G->AddVertice(189111.073925, 8253818.425694) << endl;
//   cout << "Adicionando arestas A<->B, A<->D, A->C, B<->C, D->B, A<->E" << endl;
//
//   cout << G->AddAresta(0, 1, "Aresta A<->B", 15.5, true) << endl;
//   cout << G->AddAresta(0, 3, "Aresta A<->D", 17, true) << endl;
//   cout << G->AddAresta(0, 2, "Aresta A->C", 3.141592654, false) << endl;;
//   cout << G->AddAresta(1, 2, "Aresta B<->C", 8, true)<< endl;
//   cout << G->AddAresta(3, 1, "Aresta D->B", 33.1, false) << endl;
//   cout << G->AddAresta(0, 4, "Aresta A<->E", 33.1, true) << endl;
//   G->Print();
//   cout << "1================================================" << endl;
//
//    //buscar Vertice como está sendo buscado metodo  addAresta da classe Grafo
//    Vertice a = G->getVertice(0);
//    cout << "2================================================" << endl;
//
//    Vertice b = G->getVertice(1);
//    cout << "3================================================" << endl;
//
//    cout << "ID DO A " <<a.getid() << " X: " << a.getX() << " Y: " << a.getY() << endl;
//    cout << "ID DO B "<<b.getid() << " X: " << b.getX() << " Y: " << b.getY() << endl;
//
//
//   if(a.isEqual(b)){
//    cout << "iguais" << endl;
//   }else{
//    cout << "diferentes" << endl;
//   }
//
//    cout << "4================================================" << endl;
//
//
//
//   cout << "Alterando o grafo..." << endl;
//   cout << "Removendo o vertice C" << endl;
//   G->RemVertice(2);
//   cout << "Removendo a aresta A<->B" << endl;
//   G->RemAresta(0, 1, true);
//   G->Print();
//
//   delete G;
}



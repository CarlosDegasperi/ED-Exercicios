/* Exercicio de Pilha-Estacionamento
 * Prof. Me. Orlando Saraiva Jr
 * Matéria: Estrutura de Dados
 * Aluno: Carlos Armindo Degasperi
*/
#include <iostream>
/* Define Total Vagas */
#define TOTAL_VAGAS 10
using namespace std;

struct carro {
    string placa;
    int ano;
};
struct pilha {
    carro data[TOTAL_VAGAS];
    int size;
};
/* Definir as funções */
void inicializar(pilha*);
void estacionar(pilha*, string, int);
void estacionar(pilha*, carro);
carro sair(pilha*);
void imprime_pilha(pilha*);
void imprime_tudo(pilha*);
int qtde_vagas(pilha);

int main() {
    pilha estacionamento;
    /* Inicializar a Pilha */
	inicializar(&estacionamento);
    /* Estacionar + 2 Carros */
    cout << "- Total de VAGAS do Estacionamento: " <<qtde_vagas(estacionamento) << "\n";
    estacionar(&estacionamento, "ABC-1234", 1999);
    estacionar(&estacionamento, "DOW-5782", 2004);
	/* Mostrar como está o Estacionamento */
	cout << "- Entrou 2 Carros...\n";
    cout << "- Vagas Disponíveis: " << qtde_vagas(estacionamento) << "\n";
    imprime_pilha(&estacionamento);
    /* Estacionar + 4 carros */
    estacionar(&estacionamento, "XYZ-3215", 2022);
    estacionar(&estacionamento, "WQT-2245", 2020);
    estacionar(&estacionamento, "GIN-3285", 2017);
    estacionar(&estacionamento, "HIX-5215", 2008);
    /* Mostrar como está o Estacionamento */
    cout << "- Entrou +4 Carros...\n"; 
	cout << "- Vagas Disponíveis:" << qtde_vagas(estacionamento) << "\n";
	imprime_pilha(&estacionamento);
    /* Sair do Estacionamento Carro HIX-5215 */
	carro carro_saida = {"HIX-5215", 2008};
	carro_saida = sair(&estacionamento);
    /* Mostrar como está o Estacionamento */
	cout << "- Saiu do Estacionamento o CARRO: " << carro_saida.placa << "\n";
    cout << "- Vagas Disponíveis:" << qtde_vagas(estacionamento) << "\n"; 
	imprime_pilha(&estacionamento);
    /* Imprimir TUDO */
    imprime_tudo(&estacionamento);
}
/* 1) Função inicializar */
void inicializar(pilha* e) {
    e->size = 0;
    /* Inicializar com AAA-000 e Ano 0 */
	for(int i = TOTAL_VAGAS-1; i >= 0; i--) {
        e->data[i] = {"AAA-0000", 0};
    }
}
/* 2) Funçao estacionar (recebe placa no segundo e ano no terceiro argumento) */
void estacionar(pilha* e, string placa, int ano) {
    e->data[e->size++] = {placa, ano};
}
/* 3) Funçao estacionar (recebe o carro no segundo argumento) */
void estacionar(pilha* e, carro carro_entrada) {
    e->data[e->size++] = carro_entrada;
}
/* 4) Funcao Sair (Atribuir placa "XXX-000" e ano 0 */
carro sair(pilha* e) {
    carro carro_saida = e->data[--e->size];
    e->data[e->size] = {"XXX-0000", 0};
    return carro_saida;
}
/* 5) Função Imprime_pilha  */
void imprime_pilha(pilha* e) {
    cout << "- Carros Estacionados (PILHA DE CARROS):\n";
    cout << "========================================\n";
    for(int i = e->size-1; i >= 0; i--) {
        cout << e->data[i].placa << "\t" << e->data[i].ano << "\n";
    }
}
/* 6) Função Imprime_tudo  */
void imprime_tudo(pilha* e) {
    cout << "- MOSTRAR TODA A PILHA:\n";
    cout << "=======================\n";
    for(int i = TOTAL_VAGAS -1; i >= 0; i--) {
        cout << e->data[i].placa << "\t" << e->data[i].ano << "\n";
    }
}
/* 7) Quantidade de Vagas no Estacionamento */
int qtde_vagas(pilha e) {
    return TOTAL_VAGAS - e.size;
}

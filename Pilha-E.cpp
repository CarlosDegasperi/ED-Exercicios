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
void INICIALIZAR(pilha*);
void ESTACIONAR(pilha*, string, int);
void ESTACIONAR(pilha*, carro);
carro SAIR(pilha*);
void IMPRIME_PILHA(pilha*);
void IMPRIME_TUDO(pilha*);
int QTDE_VAGAS(pilha);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
	pilha estacionamento;
    /* Inicializar a Pilha */
	INICIALIZAR(&estacionamento);
    /* Estacionar + 2 Carros */
    cout << "- Total de VAGAS do Estacionamento: " <<QTDE_VAGAS(estacionamento) << "\n";
    ESTACIONAR(&estacionamento, "ABC-1234", 1999);
    carro carro_entrada =      {"DOW-5782", 2004};
    ESTACIONAR(&estacionamento, carro_entrada);
	/* Mostrar como está o Estacionamento */
	cout << "- Entrou  2 Carros...\n";
    cout << "- Vagas Disponíveis: " << QTDE_VAGAS(estacionamento) << "\n";
    IMPRIME_PILHA(&estacionamento);
    /* Estacionar + 4 carros */
    ESTACIONAR(&estacionamento, "XYZ-3215", 2022);
    ESTACIONAR(&estacionamento, "WQT-2245", 2020);
    ESTACIONAR(&estacionamento, "GIN-3285", 2017);
    ESTACIONAR(&estacionamento, "HIX-5215", 2008);
    /* Mostrar como está o Estacionamento */
    cout << "- Entrou +4 Carros...\n"; 
	cout << "- Vagas Disponíveis:" << QTDE_VAGAS(estacionamento) << "\n";
	IMPRIME_PILHA(&estacionamento);
    /* Sair do Estacionamento Carro HIX-5215 */
	carro carro_saida = {"HIX-5215", 2008};
	carro_saida = SAIR(&estacionamento);
    /* Mostrar como está o Estacionamento */
	cout << "- Saiu do Estacionamento o CARRO: " << carro_saida.placa << "\n";
    cout << "- Vagas Disponíveis:" << QTDE_VAGAS(estacionamento) << "\n"; 
	IMPRIME_PILHA(&estacionamento);
    /* Imprimir TUDO */
    IMPRIME_TUDO(&estacionamento);
}
/* 1) Função inicializar */
void INICIALIZAR(pilha* e) {
    e->size = 0;
    /* Inicializar com AAA-000 e Ano 0 */
	for(int i = TOTAL_VAGAS-1; i >= 0; i--) {
        e->data[i] = {"AAA-0000", 0};
    }
}
/* 2) Funçao estacionar (recebe placa no segundo e ano no terceiro argumento) */
void ESTACIONAR(pilha* e, string placa, int ano) {
    e->data[e->size++] = {placa, ano};
}
/* 3) Funçao estacionar (recebe o carro no segundo argumento) */
void ESTACIONAR(pilha* e, carro carro_entrada) {
    e->data[e->size++] = carro_entrada;
}
/* 4) Funcao Sair (Atribuir placa "XXX-000" e ano 0 */
carro SAIR(pilha* e) {
    carro carro_saida = e->data[--e->size];
    e->data[e->size] = {"XXX-0000", 0};
    return carro_saida;
}
/* 5) Função Imprime_pilha  */
void IMPRIME_PILHA(pilha* e) {
    cout << "- Carros Estacionados (PILHA DE CARROS):\n";
    cout << "========================================\n";
    for(int i = e->size-1; i >= 0; i--) {
        cout << e->data[i].placa << "\t" << e->data[i].ano << "\n";
    }
}
/* 6) Função Imprime_tudo  */
void IMPRIME_TUDO(pilha* e) {
    cout << "- MOSTRAR TODA A PILHA:\n";
    cout << "=======================\n";
    for(int i = TOTAL_VAGAS -1; i >= 0; i--) {
        cout << e->data[i].placa << "\t" << e->data[i].ano << "\n";
    }
}
/* 7) Quantidade de Vagas no Estacionamento */
int QTDE_VAGAS(pilha e) {
    return TOTAL_VAGAS - e.size;
}

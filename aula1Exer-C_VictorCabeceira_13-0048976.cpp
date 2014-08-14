#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>

/* O código a seguir apresenta-se em C++, compilado com o gcc versão 4.6.3. Sistema Operacional Ubuntu 12.04
 * 
*/

using namespace std;

//Struct com as informações principais de uma pessoa
struct pessoa{
	string nome;
	string cpf;
	string rg;
	string dataNascimento;
	int quantidadeCarros;
	struct carro *automoveis;
};

//Struct com as informações principais de um carro
struct carro{
	string modelo;
	int motorizacao;
	string cor;
	string transmissao;
	int ano;
	int numOcupantes;
	string placa;
	int potencia;
	string renavan;
	string chassi;
	struct carro *prox;
	int *teste;
};

//Função para mostrar dados do aluno
void cabecalho()
{
	cout << "\t-------------------------------------------------------------------" << endl;
    cout << "\tUniversidade de Brasília - UnB" << endl ;
    cout << "\tFaculdade Gama - FGA" << endl ;
    cout << "\tSistemas de Banco de Dados" << endl ;
    cout << "\tProfessor Vandor Rissoli - Turma A" << endl ;
    cout << "\tAluno: Victor Fellipe Gonçalves Cabeceira - Matrícula 13/0048976" << endl ;
    cout << "\tExercício de Armazenamento de Dados" << endl ;
    cout << "\t-------------------------------------------------------------------" << endl;
}

//Função para apresentar no terminal as informações que foram cadastradas
void mostrar(pessoa pessoa[],int quantidade){
	for (int i=0; i<quantidade ; i++){
		
		cout << "----------------------------------------------" << endl;
		cout << "Nome: " << pessoa[i].nome << endl;
		cout << "CPF: " << pessoa[i].cpf.substr(0,9) << "-" << pessoa[i].cpf.substr(9,11) << endl;
		cout << "Rg: " << pessoa[i].rg << endl;
		cout << "Data de Nascimento: " << pessoa[i].dataNascimento.substr(0,2) <<"/"; 
		cout << pessoa[i].dataNascimento.substr(2,2) << "/" << pessoa[i].dataNascimento.substr(4,4) << endl;
		cout << "Quantidade de Carros que é proprietário: " << pessoa[i].quantidadeCarros << endl;
			
			if(pessoa[i].quantidadeCarros>0){

				for(int j=0; j<pessoa[i].quantidadeCarros; j++){
					cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "\tModelo do carro: " << pessoa[i].automoveis[j].modelo << endl;
					cout << "\tCilindrada do carro: " << pessoa[i].automoveis[j].motorizacao << " cm³" << endl;
					cout << "\tCor do carro: " << pessoa[i].automoveis[j].cor << endl;
					cout << "\tTransmissão do carro: " << pessoa[i].automoveis[j].transmissao << endl;
					cout << "\tAno do carro: "<< pessoa[i].automoveis[j].ano << endl;
					cout << "\tNúmero máximo de ocupantes do carro: " << pessoa[i].automoveis[j].numOcupantes << endl;
					cout << "\tPlaca do carro: " << pessoa[i].automoveis[j].placa.substr(0,3) << "-"
						 << pessoa[i].automoveis[j].placa.substr(3,4) << endl;
					cout << "\tPotencia do carro: " << pessoa[i].automoveis[j].potencia << "cv" << endl;
					cout << "\tRenavan do carro: " << pessoa[i].automoveis[j].renavan << endl;
					cout << "\tChassi do carro: " << pessoa[i].automoveis[j].chassi << endl;
				}
			}

		}
	cout << endl << "**********************************************************************************" << endl;
	cout << "Fim da lista de Cadastro" << endl;
	cout << "**********************************************************************************" << endl;
	cout << endl << "Aluno: Victor Fellipe G. Cabeceira" << endl;
	cout << "Matrícula: 13/0048976" << endl;
}

//Função para cadastrar as pessoas e seus respectivos carros (caso houver)
void cadastrar(pessoa pessoa[], int quantidade){


	//Obtenção das informações das pessoas
	for (int i=0; i<quantidade ; i++){
		
		cout << "Informe o nome da pessoa de número "<< (i+1) << "\n";
			
			//cin>>ws serve para limpar o buffer e assim não cortar a primeira letra da string a ser lida
			cin>>ws;
			getline(cin,(pessoa[i].nome));

		cout << "Informe o cpf da pessoa "<< (i+1) <<" somente em números" <<endl;
			cin>>pessoa[i].cpf;

		cout << "Informe o rg da pessoa "<< (i+1) <<" sem pontuação" << endl;
			cin>>pessoa[i].rg;

		cout << "Informe a data de nascimento da pessoa "<< (i+1) <<" com a seguinte formatação: DDMMAAAA" <<endl;
			cin>>pessoa[i].dataNascimento;
				 
		cout << "Informe a quantidade de Carros da Pessoa "<< (i+1) << endl;
			cin>>pessoa[i].quantidadeCarros;

		pessoa[i].automoveis=NULL;
		carro *carros;

		if(pessoa[i].quantidadeCarros>0){
			
			carros= new carro[pessoa[i].quantidadeCarros];

			//Obtenção das informações de cada carro que a pessoa "i" tiver
			for(int j=0; j<pessoa[i].quantidadeCarros; j++){

				cout << "Informe o modelo (completo) do carro: " << endl;
					cin>>ws;
					getline(cin,(carros[j].modelo));
					//cin>>carros[j].modelo;

				cout << "Informe a cilindrada do motor em cm³: " << endl;
					cin>>carros[j].motorizacao;

				cout << "Informe a cor do carro: " << endl;
					cin>>carros[j].cor;

				cout << "Informe o tipo da transmissão do carro: " << endl;
					cin>>carros[j].transmissao;
			
				cout << "Informe o ano de fabricação carro: " << endl;
					cin>>carros[j].ano;

				cout << "Informe o número de ocupantes que o veículo suporta: " << endl;
					cin>>carros[j].numOcupantes;

				cout << "Informe a placa do carro sem traço: " << endl;
					cin>>carros[j].placa;

				cout << "Informe a potência do carro em CV: " << endl;
					cin>>carros[j].potencia;

				cout << "Informe o renavan do carro: " << endl;
					cin>>carros[j].renavan;

				cout << "Informe o chassi do carro: " << endl;
					cin>>carros[j].chassi;
			}

		//Inicialização de Variável
		pessoa[i].automoveis = new carro[pessoa[i].quantidadeCarros];

		//"For" para fazer a associação entre os carros cadastrados para a devida pessoa
		for(int c=0; c<pessoa[i].quantidadeCarros;c++)
			pessoa[i].automoveis[c] = carros[c];
		}

	}
}

//Função para gravar as informações inseridas no terminal em um arquivo texto
void grava(pessoa pessoa[],int quantidade){

	//Criar arquivo
	ofstream arquivo("ListaCadastro.txt");

	//Caso ocorra algum problema, apresentará a mensagem de erro
	if(!arquivo){
		cout<<"Erro ao criar Arquivo!";
		return;
	}
	else
		arquivo<<"Lista de Cadastro de Proprietários "<<endl;
		for(int i=0; i<quantidade ; i++){
			arquivo<<"----------------------------------------------"<<endl;
			arquivo<<"Nome: "<<pessoa[i].nome<<endl;
			arquivo<<"CPF: " << pessoa[i].cpf.substr(0,9) << "-" << pessoa[i].cpf.substr(9,2) << endl;	
			arquivo<<"RG: "<<pessoa[i].rg<<endl;			
			arquivo<<"Data de Nascimento : " << pessoa[i].dataNascimento.substr(0,2) <<"/"<< pessoa[i].dataNascimento.substr(2,2) << "/" << pessoa[i].dataNascimento.substr(4,4) << endl;
			arquivo<<"Quantidade de Carros: "<<pessoa[i].quantidadeCarros<<endl;	

					
			if(pessoa[i].quantidadeCarros>0){
				for(int j=0; j<pessoa[i].quantidadeCarros; j++){
					arquivo << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					arquivo << "\tModelo do carro: " << pessoa[i].automoveis[j].modelo << endl;
					arquivo << "\tCilindrada do carro: " << pessoa[i].automoveis[j].motorizacao << " cm³" << endl;
					arquivo << "\tCor do carro: " << pessoa[i].automoveis[j].cor << endl;
					arquivo << "\tTransmissão do carro: " << pessoa[i].automoveis[j].transmissao << endl;
					arquivo << "\tAno do carro: "<< pessoa[i].automoveis[j].ano << endl;
					arquivo << "\tNúmero máximo de ocupantes do carro: " << pessoa[i].automoveis[j].numOcupantes << endl;
					arquivo << "\tPlaca do carro: " << pessoa[i].automoveis[j].placa.substr(0,3) << "-"
						 << pessoa[i].automoveis[j].placa.substr(3,4) << endl;
					arquivo << "\tPotencia do carro: " << pessoa[i].automoveis[j].potencia << "cv" << endl;
					arquivo << "\tRenavan do carro: " << pessoa[i].automoveis[j].renavan << endl;
					arquivo << "\tChassi do carro: " << pessoa[i].automoveis[j].chassi << endl;	

				}
			}	

		}
	arquivo << endl << "**********************************************************************************" << endl;
	arquivo << "Fim da lista de Cadastro" << endl;
	arquivo << "**********************************************************************************" << endl;
	arquivo << endl << "Aluno: Victor Fellipe G. Cabeceira" << endl;
	arquivo << "Matrícula: 13/0048976" << endl;
	//Fechar arquivo
	arquivo.close();
}



int main (){

	//Inicialização de variáveis
	int quantidadePessoas;

	//Chamada da Função "cabecalho"
	cabecalho();

	printf ("Quantas pessoas se deseja cadastrar?\n");
	scanf("%d", &quantidadePessoas);

	//Inicialização da variável do tipo da struct pessoa
	pessoa* pessoas = new pessoa[quantidadePessoas];

	cadastrar(pessoas,quantidadePessoas);
	mostrar(pessoas,quantidadePessoas);
	grava(pessoas,quantidadePessoas);
}

/** Data: 14/09/2026
 * 
 * Trabalho de fazer um banco
 
 */

#include <iostream>
#include <vector> 
#include <string> 
#include <limits>
using namespace std;

struct cliente 
{ 
    int numeroConta; 
    string nomeCliente; 
    string cpf;
    int tipoConta; //1== Corrente; 2==Poupança
    double saldo;
    bool contaAtiva;
    string senha;
    

};

void cadastrar(vector<cliente>& clientes)
{

    cliente novo;
        
        cout << "\n====== Cadastro =======\n";

        cout << "Nome: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, novo.nomeCliente);
        

        cout << "Digite seu CPF: " << endl;
        cin >> novo.cpf;
        
        
        cout << "Digite o tipo da sua conta (1 = Corrente; 2 = Poupança): " << endl;
        cin >> novo.tipoConta;

        do{

            cout << "Digite o numero da sua conta (Maior que 0): " << endl;
            cin >> novo.numeroConta;

            if (novo.numeroConta <= 0)
            {

                cout << "O numero da conta deve ser maior que 0." << endl;

            }
        } while (novo.numeroConta <= 0);

        for (int i = 0; i < clientes.size(); i++)
        {
            if(clientes[i].numeroConta == novo.numeroConta) 
            {
                cout << "Esse login já existe, insira outro." << endl;
                return;
            }
        }

    cout << "Senha: " << endl;
    cin >> novo.senha;

    novo.contaAtiva = true;

    novo.saldo = 0;

    clientes.push_back(novo);

    cout << "Cadastro realizado." <<endl;


        // Parei na parte de cadastro/login com o numeo da conta onde nao pode ter duplicidade
}

int fazerLogin(vector<cliente>& clientes){

    int login;
    string senhaLogin;

    cout << "\n====== Login =======" << endl;

    cout << "Digite o numero da sua conta: " << endl;
    cin >> login;

    cout << "Digite a senha da sua conta: " << endl;
    cin >> senhaLogin;

    for (int i = 0; i < clientes.size(); i++)

        if (clientes[i].numeroConta == login && senhaLogin == clientes[i].senha){

            return i;
            }

    

    return -1;


}

    
int main(){

    vector<cliente> clientes;

    int opcao;

        do{
            cout << "====== Menu =======" << endl;
            cout << "\n1- Cadastrar" << endl;
            cout << "2- Logar" << endl;
            cout << "3- Sair" << endl;
            cout << "Escolha: " << endl;
        
            cin >> opcao;
            if (opcao == 1){

                cadastrar(clientes);
            }
            else if (opcao == 2){


                int usuarioLogado = fazerLogin(clientes);
                

                if(usuarioLogado == -1){

                    cout << "Esse Login não existe" << endl;

                }else{
                    int acao;

                    cout << "====== Login realizado com sucesso =======" << endl;
                    cout << "\n Bem vindo ao banco, " << clientes[usuarioLogado].nomeCliente << endl;
                    cout << "\n Numero da conta: "<< clientes[usuarioLogado].numeroConta << endl;
                    cout << "Situação da conta: " << endl;
                        if (clientes[usuarioLogado].contaAtiva == true)
                        {
                            cout << "Ativa." << endl;
                        } else{

                            cout << "Inativa." << endl;
                        };
                        
                    cout << "Tipo da conta: " << endl;
                    if (clientes[usuarioLogado].tipoConta == 1)
                        {
                            cout << "Corrente." << endl;
                        } else{

                            cout << "Poupança.";
                        };

                    cout << "Saldo atual: " << clientes[usuarioLogado].saldo << endl;
                    cout << "CPF: " << clientes[usuarioLogado].cpf << endl;
                    

                    cout << "\n\nO que deseja fazer agora? " << endl;
                    cout << "1- Depósito" << endl;
                    cout << "2- Alterar o tipo da conta" << endl;
                    cout << "3- Desativar a conta"<< endl;
                    cout << "4- Sair" << endl;
                    cin >> acao;


                    if (acao == 1)
                    {
                        double deposito;

                        cout << "Digite o valor que deseja depositar: " << endl;
                        cin >> deposito;

                        clientes[usuarioLogado].saldo = (clientes[usuarioLogado].saldo + deposito);
                        
                        cout << "Depósito realizado!"<< endl << "\n";
                        
                    }else if (acao == 4){
                        
                    }
                    else if (acao == 2){

                        cout << "Qual conta deseja? "<<endl;
                        cout <<"1 = Corrente; 2 = Poupança"<<endl;
                        cin >> clientes[usuarioLogado].tipoConta;

                        cout << "Alteração realizada com sucesso" << endl;
                       

                    }else if (acao == 3){
                        if (clientes[usuarioLogado].contaAtiva == true)
                        {
                            clientes[usuarioLogado].contaAtiva = false;
                        } else{
                            clientes[usuarioLogado].contaAtiva = true;
                        };
                        
            
            
        
                    }
                }


            }
        }while (opcao != 3);
    
    cout << "\nPrograma encerrado.\n";
    
    return 0;
    
}
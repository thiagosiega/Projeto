#include <iostream>

using namespace std;

class Projeto

{
    public:
        Projeto(){
            float resposta ,num1 ,num2;
            int opera;

            cout << "Digite o primeiro numero!\n" << endl;
            cin >> num1;
            cout << "Digite o segundo numero!\n" << endl;
            cin >>num2;
            cout << "Qual operaçao\n"<< endl;
            cout << "1-> Soma\n2-> Subitraçao\n3-> Multiplicaçao\n4-> Divizao\n" << endl;
            cin >> opera;
            if (opera != 1 && opera != 2 && opera != 3 && opera != 4) {
                cout << "Resposta invalida!" << endl;
            }else{
                if(opera == 1){
                    resposta = (num1 + num2);
                    cout << "A resposta e: " << resposta << "\n" << endl;
                }
                else if (opera == 2)
                {
                    resposta = (num1 - num2);
                    cout << "A resposta e: " << resposta << "\n" << endl;
                }else if (opera == 3)
                {
                    resposta = (num1 * num2);
                    cout << "A resposta e: " << resposta << "\n" << endl;
                }else if (opera == 4)
                {   
                    resposta = (num1 / num2);
                    cout << "A resposta e: " << resposta << "\n" << endl;
                }               
                
            }

        }

};
    

int main(){
    cout << "Claculadora!" << endl;
    int a = 0;
    while (a == 0)
    {
        Projeto projeto;
        cout << "Digite 1 para sair ou 0 para continuar: ";
        cin >> a;
    }
    cout << "Atemais!"<< endl;
    
    return 0;
}
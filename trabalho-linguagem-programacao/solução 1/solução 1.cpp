// solução 1.cpp : HENRIQUE KUNIETAMA MIGUEL FILIPE

#include <iostream>
#include <string>
#include <limits>

class Funcionario {
private:
    std::string primeiroNome_;
    std::string sobrenome_;
    double salarioMensal_;

public:
    Funcionario(const std::string& primeiroNome, const std::string& sobrenome, double salarioMensal)
        : primeiroNome_(primeiroNome), sobrenome_(sobrenome), salarioMensal_(salarioMensal > 0.0 ? salarioMensal : 0.0)
    {
    }

    // Get
    const std::string& getPrimeiroNome() const { return primeiroNome_; }
    const std::string& getSobrenome() const { return sobrenome_; }
    double getSalarioMensal() const { return salarioMensal_; }

    // Set
    void setPrimeiroNome(const std::string& nome) { primeiroNome_ = nome; }
    void setSobrenome(const std::string& sobrenome) { sobrenome_ = sobrenome; }
    void setSalarioMensal(double salario) { salarioMensal_ = (salario > 0.0 ? salario : 0.0); }
};

static void limparEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static double lerDouble(const std::string& prompt) {
    double valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            limparEntrada();
            return valor;
        }
        std::cout << "ENTRADA INVALIDA, DIGITE UM NUMERO.\n";
        limparEntrada();
    }
}

int main()
{
    std::string primeiro, sobrenome;
    std::cout << "CRIE UM FUNCIONARIO INICIAL\n";
    std::cout << "PRIMEIRO NOME: ";
    std::getline(std::cin, primeiro);
    std::cout << "SOBRE NOME: ";
    std::getline(std::cin, sobrenome);
    double salario = lerDouble("SALARIO MENSAL: ");

    Funcionario f(primeiro, sobrenome, salario);

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1 - MOSTRAR DADOS\n";
        std::cout << "2 - ALTERAR SALARIO\n";
        std::cout << "3 - ALTERAR NOMES\n";
        std::cout << "4 - SAIR\n";
        std::cout << "POR FAVOR, ESCOLHA: ";

        int opc;
        if (!(std::cin >> opc)) {
            std::cout << "OPCAO INVALIDA.\n";
            limparEntrada();
            continue;
        }
        limparEntrada();

        if (opc == 1) {
            std::cout << "NOME: " << f.getPrimeiroNome() << " " << f.getSobrenome() << "\n";
            std::cout << "SALARIO MENSAL " << f.getSalarioMensal() << "\n";
        }
        else if (opc == 2) {
            double novo = lerDouble("NOVO SALARIO MENSAL: ");
            f.setSalarioMensal(novo);
            std::cout << "SALARIO ATUALIZADO PARA: " << f.getSalarioMensal() << "\n";
        }
        else if (opc == 3) {
            std::string novoPrimeiro, novoSobrenome;
            std::cout << "NOVO PRIMEIRO NOME: ";
            std::getline(std::cin, novoPrimeiro);
            std::cout << "NNOVO SOBRE NOME: ";
            std::getline(std::cin, novoSobrenome);
            f.setPrimeiroNome(novoPrimeiro);
            f.setSobrenome(novoSobrenome);
            std::cout << "NOMES ATUALIZADO\n";
        }
        else if (opc == 4) {
            std::cout << "APERTE ENTER PARA SAIR";
            std::cin.get();
            break;
        }
        else {
            std::cout << "ERRO.\n";
        }
    }

    return 0;
}
// solução 2.cpp : HENRIQUE KUNIETAMA MIGUEL FILIPE

#include <iostream>
#include <string>
#include <iomanip>

class Empregado {
private:
    std::string primeiroNome;
    std::string sobrenome;
    double salarioMensal;

public:
    Empregado(const std::string& primeiro = "", const std::string& sobre = "", double salario = 0.0)
        : primeiroNome(primeiro), sobrenome(sobre), salarioMensal((salario >= 0.0) ? salario : 0.0) {}

    std::string nomeCompleto() const {
        return primeiroNome + " " + sobrenome;
    }

    double obterSalarioMensal() const {
        return salarioMensal;
    }

    double obterSalarioAnual() const {
        return salarioMensal * 12.0;
    }

    // Aumenta o salário mensal por uma percentagem (ex: 10.0 = +10%)
    void aplicarAumentoPercentual(double percentual) {
        salarioMensal *= (1.0 + percentual / 100.0);
        if (salarioMensal < 0.0) salarioMensal = 0.0;
    }

    void setSalarioMensal(double salario) {
        salarioMensal = (salario >= 0.0) ? salario : 0.0;
    }
};

static double lerDoubleValido(const std::string& prompt) {
    double valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        } else {
            std::cout << "Entrada inválida. Digite um número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

static std::string lerLinha(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

 
    std::string nome1 = lerLinha("PRIMEIRO NOME DO EMPREGADO 1: ");
    std::string sobre1 = lerLinha("SOBRE NOME DO EMPREGADO 1: ");
    double salario1 = lerDoubleValido("SALARIO MENSAL DO EMPREGADO 1 (ex: 300000.00): ");

   
    std::string nome2 = lerLinha("PRIMEIRO NOME DO EMPREGADO 2: ");
    std::string sobre2 = lerLinha("SOBRE NOME DO EMPREGADO 2: ");
    double salario2 = lerDoubleValido("SALARIO MENSAL DO EMPREGADO 2 (ex: 450000.00): ");

    Empregado e1(nome1, sobre1, salario1);
    Empregado e2(nome2, sobre2, salario2);

  
    std::cout << "\nSALARIO ANUAL ANTES DO AUMENTO:\n";
    std::cout << e1.nomeCompleto() << ": Kz " << e1.obterSalarioAnual() << "\n";
    std::cout << e2.nomeCompleto() << ": Kz " << e2.obterSalarioAnual() << "\n\n";

    
    double aumento1 = lerDoubleValido("DIGITE O AUMENTO PERCENTUAL PARA " + e1.nomeCompleto() + " (ex: 10 para 10%): ");
    double aumento2 = lerDoubleValido("DIGITE O AUMENTO PERCENTUAL PARA " + e2.nomeCompleto() + " (ex: 10 para 10%): ");

    e1.aplicarAumentoPercentual(aumento1);
    e2.aplicarAumentoPercentual(aumento2);

    
    std::cout << "\nSALARIO ANUAL APOS AUMENTOS:\n";
    std::cout << e1.nomeCompleto() << ": Kz " << e1.obterSalarioAnual() << "\n";
    std::cout << e2.nomeCompleto() << ": Kz " << e2.obterSalarioAnual() << "\n";

    return 0;
}

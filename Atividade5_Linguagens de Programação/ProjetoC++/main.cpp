#include <iostream>
#include <iomanip>
using namespace std;

struct Funcionario {
    char nome[21];
    int departamento;
    float qntHorasTrab;
    float horasAdici;
    float horaExt;
    float insalubridade;
    float bonificacao;
    float inss;
    float impostoRenda;
    float salarioBase;
    float salarioBruto;
    float salarioLiquido;
    int planoSaude = 20;
};

void calculaHorasAdici(Funcionario funcionario[], int n) {
    funcionario[n].horasAdici = funcionario[n].qntHorasTrab - 40;
}

void calculaHoraExt(Funcionario funcionario[], int n) {
    if (funcionario[n].departamento == 1) {
        funcionario[n].horaExt = 22 * 2 * funcionario[n].horasAdici;
    } else
        funcionario[n].horaExt = 12 * 2 * funcionario[n].horasAdici;
}

void calculaInss(Funcionario funcionario[], int n) {
    funcionario[n].inss = funcionario[n].salarioBruto * 0.07;
}

void calculaImpostoDeRenda(Funcionario funcionario[], int n) {
    funcionario[n].impostoRenda = funcionario[n].salarioBruto * 0.12;
}

void calculaSalarioBruto(Funcionario funcionario[], int n) {
    funcionario[n].salarioBruto = funcionario[n].salarioBase + funcionario[n].horaExt +
                                  funcionario[n].insalubridade + funcionario[n].bonificacao;
}

void calculaSalarioLiquido(Funcionario funcionario[], int n) {
    funcionario[n].salarioLiquido = funcionario[n].salarioBruto - funcionario[n].inss -
                                    funcionario[n].impostoRenda - funcionario[n].planoSaude;
}

void departamentoAdministracao(Funcionario funcionario[], int n) {
    //valor hora trabalhada do departamento administracao = R$22,00
    //calculo salario base/horas adicionais/hora extra
    if (funcionario[n].qntHorasTrab > 40) {
        funcionario[n].salarioBase = 22 * 40;
        calculaHorasAdici(funcionario, n);
        calculaHoraExt(funcionario, n);
    } else {
        funcionario[n].salarioBase = funcionario[n].qntHorasTrab * 22;
        funcionario[n].horasAdici = 0;
        funcionario[n].horaExt = 0;
    }

    //insalubridade do departamento administracao = 0
    funcionario[n].insalubridade = 0;

    //bonificacao do departamento administracao
    if (funcionario[n].qntHorasTrab > 20 && funcionario[n].qntHorasTrab < 30) {
        funcionario[n].bonificacao = funcionario[n].salarioBase * 0.03;
    } else if (funcionario[n].qntHorasTrab > 30 && funcionario[n].qntHorasTrab < 40) {
        funcionario[n].bonificacao = funcionario[n].salarioBase * 0.05;
    } else if (funcionario[n].qntHorasTrab >= 40) {
        funcionario[n].bonificacao = funcionario[n].salarioBase * 0.1;
    }

    calculaSalarioBruto(funcionario, n); //calculo salario bruto

    calculaInss(funcionario, n); //calculo INSS

    calculaImpostoDeRenda(funcionario, n); //calculo Imposto de Renda

    calculaSalarioLiquido(funcionario, n); //calculo salario liquido
}

void departamentoProducao(Funcionario funcionario[], int n) {
    //valor hora trabalhada da producao = R$12,00
    //calculo salario base/horas adicionais/hora extra
    if (funcionario[n].qntHorasTrab > 40) {
        funcionario[n].salarioBase = 12 * 40;
        calculaHorasAdici(funcionario, n);
        calculaHoraExt(funcionario, n);
    } else {
        funcionario[n].salarioBase = funcionario[n].qntHorasTrab * 12;
        funcionario[n].horasAdici = 0;
        funcionario[n].horaExt = 0;
    }

    //insalubridade do departamento de producao = 15% do salario base
    funcionario[n].insalubridade = funcionario[n].salarioBase * 0.15;

    funcionario[n].bonificacao = 0; //bonificacao do departamento producao = 0

    calculaSalarioBruto(funcionario, n); //calculo salario bruto

    calculaInss(funcionario, n); //calculo do INSS

    //calculo imposto de renda
    calculaImpostoDeRenda(funcionario, n);

    //calculo salario liquido
    calculaSalarioLiquido(funcionario, n);
}

void imprimirSeparador(int largura) {
    cout << setfill('-') << setw(largura) << "-" << endl;
    cout << setfill(' ');
}

void imprimirLinhaTabela(string coluna1, float coluna2, float coluna3, float coluna4, float coluna5, float coluna6, float coluna7, float coluna8, float coluna9) {
    cout << setw(5) << left << coluna1 << " | " << setw(12) << right << fixed << setprecision(2) << coluna2 << " | "
         << setw(10) << coluna3 << " | " << setw(13) << coluna4 << " | " << setw(11) << coluna5 << " | "
         << setw(10) << coluna6 << " | " << setw(5) << coluna7 << " | " << setw(14) << coluna8 << " | " << setw(15) << coluna9 << endl;
}


void imprimir(Funcionario funcionario[], int n) {
    const int larguraTabela = 150;

    imprimirSeparador(larguraTabela);
    cout << setw(larguraTabela / 2 + 10) << "FOLHA DE PAGAMENTO" << endl;
    imprimirSeparador(larguraTabela);
    cout << setw(5) << left << "NOME" << " | " << setw(5) << "SALARIO BASE" << " | "
         << setw(5) << "HORA EXTRA" << " | " << setw(5) << "INSALUBRIDADE" << " | "
         << setw(5) << "BONIFICACAO" << " | " << setw(10) << "INSS" << " | "
         << setw(5) << "IR" << " | " << setw(5) << "PLANO DE SAUDE" << " | " << setw(5) << "SALARIO LIQUIDO" << endl;
    imprimirSeparador(larguraTabela);

    for (int i = 0; i < n; i++) {
        imprimirLinhaTabela(funcionario[i].nome, funcionario[i].salarioBase, funcionario[i].horaExt,
                            funcionario[i].insalubridade, funcionario[i].bonificacao, funcionario[i].inss,
                            funcionario[i].impostoRenda, funcionario[i].planoSaude, funcionario[i].salarioLiquido);
    }
    imprimirSeparador(larguraTabela);
}



int main() {
    Funcionario funcionario[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nFUNCIONARIO - " << i + 1 << "\n\n";
        cout << "Digite seu nome: ";
        cin.getline(funcionario[i].nome, 20);
        cout << "Digite seu departamento: \n(1) Administrativo \n(2) Producao \n";
        cin >> funcionario[i].departamento;
        cout << "Digite a quantidade de horas: ";
        cin >> funcionario[i].qntHorasTrab;
        cin.ignore();

        if (funcionario[i].departamento == 1) {
            departamentoAdministracao(funcionario, i);
        } else {
            departamentoProducao(funcionario, i);
        }
    }

    imprimir(funcionario, 5);

    return 0;
}

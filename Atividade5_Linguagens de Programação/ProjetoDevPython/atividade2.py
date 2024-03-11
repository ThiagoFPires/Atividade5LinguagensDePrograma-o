class Funcionario:
    def __init__(self):
        self.nome = ""
        self.departamento = 0
        self.qntHorasTrab = 0.0
        self.horasAdici = 0.0
        self.horaExt = 0.0
        self.insalubridade = 0.0
        self.bonificacao = 0.0
        self.inss = 0.0
        self.impostoRenda = 0.0
        self.salarioBase = 0.0
        self.salarioBruto = 0.0
        self.salarioLiquido = 0.0
        self.planoSaude = 20

def calculaHorasAdici(funcionario):
    funcionario.horasAdici = funcionario.qntHorasTrab - 40

def calculaHoraExt(funcionario):
    if funcionario.departamento == 1:
        funcionario.horaExt = 22 * 2 * funcionario.horasAdici
    else:
        funcionario.horaExt = 12 * 2 * funcionario.horasAdici

def calculaInss(funcionario):
    funcionario.inss = funcionario.salarioBruto * 0.07

def calculaImpostoDeRenda(funcionario):
    funcionario.impostoRenda = funcionario.salarioBruto * 0.12

def calculaSalarioBruto(funcionario):
    funcionario.salarioBruto = funcionario.salarioBase + funcionario.horaExt + \
                                funcionario.insalubridade + funcionario.bonificacao

def calculaSalarioLiquido(funcionario):
    funcionario.salarioLiquido = funcionario.salarioBruto - funcionario.inss - \
                                  funcionario.impostoRenda - funcionario.planoSaude

def departamentoAdministracao(funcionario):
    if funcionario.qntHorasTrab > 40:
        funcionario.salarioBase = 22 * 40
        calculaHorasAdici(funcionario)
        calculaHoraExt(funcionario)
    else:
        funcionario.salarioBase = funcionario.qntHorasTrab * 22
        funcionario.horasAdici = 0
        funcionario.horaExt = 0

    funcionario.insalubridade = 0

    if 20 < funcionario.qntHorasTrab < 30:
        funcionario.bonificacao = funcionario.salarioBase * 0.03
    elif 30 < funcionario.qntHorasTrab < 40:
        funcionario.bonificacao = funcionario.salarioBase * 0.05
    elif funcionario.qntHorasTrab >= 40:
        funcionario.bonificacao = funcionario.salarioBase * 0.1

    calculaSalarioBruto(funcionario)
    calculaInss(funcionario)
    calculaImpostoDeRenda(funcionario)
    calculaSalarioLiquido(funcionario)

def departamentoProducao(funcionario):
    if funcionario.qntHorasTrab > 40:
        funcionario.salarioBase = 12 * 40
        calculaHorasAdici(funcionario)
        calculaHoraExt(funcionario)
    else:
        funcionario.salarioBase = funcionario.qntHorasTrab * 12
        funcionario.horasAdici = 0
        funcionario.horaExt = 0

    funcionario.insalubridade = funcionario.salarioBase * 0.15
    funcionario.bonificacao = 0

    calculaSalarioBruto(funcionario)
    calculaInss(funcionario)
    calculaImpostoDeRenda(funcionario)
    calculaSalarioLiquido(funcionario)

def imprimir(funcionarios):
    largura_tabela = 150
    print("-" * largura_tabela)
    print(f"{'FOLHA DE PAGAMENTO':^{largura_tabela}}")
    print("-" * largura_tabela)
    print(f"{'NOME':<25} | {'SALARIO BASE':^15} | {'HORA EXTRA':^15} | {'INSALUBRIDADE':^15} | {'BONIFICACAO':^15} | {'INSS':^15} | {'IR':^10} | {'PLANO DE SAUDE':^15} | {'SALARIO LIQUIDO':^15}")
    print("-" * largura_tabela)
    for funcionario in funcionarios:
        print(f"{funcionario.nome:<25} | {funcionario.salarioBase:>15.2f} | {funcionario.horaExt:>15.2f} | {funcionario.insalubridade:>15.2f} | {funcionario.bonificacao:>15.2f} | {funcionario.inss:>15.2f} | {funcionario.impostoRenda:>10.2f} | {funcionario.planoSaude:>15} | {funcionario.salarioLiquido:>15.2f}")
    print("-" * largura_tabela)

def main():
    funcionarios = [Funcionario() for _ in range(5)]

    for i, funcionario in enumerate(funcionarios):
        print(f"\nFUNCIONARIO - {i + 1}\n")
        funcionario.nome = input("Digite seu nome: ")
        funcionario.departamento = int(input("Digite seu departamento:\n(1) Administrativo\n(2) Producao\n"))
        funcionario.qntHorasTrab = float(input("Digite a quantidade de horas: "))

        if funcionario.departamento == 1:
            departamentoAdministracao(funcionario)
        else:
            departamentoProducao(funcionario)

    imprimir(funcionarios)

if __name__ == "__main__":
    main()

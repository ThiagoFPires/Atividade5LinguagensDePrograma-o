def main():
    while True:
        try:
            dividendo = int(input("Digite o dividendo: "))
            divisor = int(input("Digite o divisor: "))
            resultado = dividendo / divisor
        except ValueError:
            print("Número digitado inválido. Por favor, insira um número inteiro.")
        except ZeroDivisionError:
            print("Divisão por zero não permitida. Por favor, insira um divisor diferente de zero.")
        else:
            print("Resultado da divisão:", resultado)
            break 
        finally:
            print("Tentativa de divisão concluída.")

    print("Programa encerrado.")

if __name__ == "__main__":
    main()

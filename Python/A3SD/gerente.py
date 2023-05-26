import re

from form_gerente import melhor_loja, melhor_vendedor, total_rede, total_vendedor
from validardados import ler_cpf


def tela_gerente():
    cpf = ler_cpf()

    print("gerente conectado: " + str(cpf))

    print("Escolha qual operação deseja executar:")
    print("1. Pesquisar total de vendas de um vendedor")
    print("2. Exibir melhor loja")
    print("3. Exibir melhor vendedor")
    print("4. Filtrar total de vendas de uma rede")

    message = []

    while True:
        opcao = input("\nEscolha uma opção: ")
        if re.match(r'^\d{1}$', opcao):
            opcao = int(opcao)
            if opcao == 1:
                message = total_vendedor()
                break
            elif opcao == 2:
                message = melhor_loja()
                break
            elif opcao == 3:
                message = melhor_vendedor()
                break
            elif opcao == 4:
                message = total_rede()
                break
            else:
                print("Opção inválida")
        else:
            print("digite um numero!")


    return message


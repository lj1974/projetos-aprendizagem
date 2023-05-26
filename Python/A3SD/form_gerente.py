
import re


def total_vendedor():

    # pega lista de vendedores do banco e lista

    vendedores = [[1, 'Claudio'], [2, 'Ana']]
    print("escolha o vendedor:")

    for pessoa in vendedores:
        print(f"{pessoa[0]}" + " " + f"{pessoa[1]}")

   #pede pra escolher dentre os listados
    id_vendedor =   None
    nome_vendedor = None

    while True:
        escolha = input("Digite o número do vendedor:")
        id_vendedor = escolha
        if re.match(r'^\d{1}$', escolha):
            id_vendedor = int(escolha)
            break
        else:     
            print("Opção inválida. Tente novamente")
    for pessoa in vendedores:
        if pessoa[0] == id_vendedor:
            nome_vendedor = pessoa[1]
    
    #logica no banco 
    print("O total de vendas do vendedor [%s] é: %.2f" % (nome_vendedor, 10.00))

    return "02", nome_vendedor


def melhor_loja():
    return "03", "loja A"


def melhor_vendedor():
    return "04", "Marcos"

def total_rede():
    return "05", "Mix"
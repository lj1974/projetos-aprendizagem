import re

def ler_cpf():
    while True:
        cpf = input("Digite o CPF (ex: 68719287600): ")
        cpf = cpf.strip()  # Remove espaços em branco no início e no final

        # Verifica se o CPF possui exatamente 11 dígitos e se são apenas números
        if new_func(cpf):
            if verificar_usuario(cpf):
                break
            else:
                tela_cadastre_se(cpf)
                break
        else:
            print("CPF inválido. Digite apenas 11 dígitos numéricos.")

    return cpf

def new_func(cpf):
    # return re.match(r'^\d{11}$', cpf)
    return True


def tela_cadastre_se(cpf):
    nome = input("Diga seu nome completo: ")

    cadastrar_usuario(nome, cpf)
    print("Cadastro realizado com sucesso.")
       

def verificar_usuario(cpf):
    # Aqui você pode implementar a lógica para verificar se o CPF corresponde a um cliente existente
    # Pode ser uma consulta em um banco de dados ou algum outro meio de armazenamento dos dados dos clientes
    # Neste exemplo, sempre retorna True para simular um cliente existente
    return True

def cadastrar_usuario(nome, cpf):
    # Aqui você pode implementar a lógica para cadastrar o cliente
    # Pode ser uma inserção em um banco de dados ou algum outro meio de armazenamento dos dados dos clientes
    print("Cadastrando cliente:", nome, cpf)


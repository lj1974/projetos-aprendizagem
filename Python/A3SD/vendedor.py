
from form_vendedor import exibe_form
from validardados import ler_cpf


def tela_vendedor():
    cpf = ler_cpf()

    print("cliente conectado: " + str(cpf))
    return exibe_form()


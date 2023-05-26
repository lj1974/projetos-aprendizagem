import datetime
# import sqlite3

def exibe_form():
    # # Conexão com o banco de dados
    # conn = sqlite3.connect('lojas.db')
    # cursor = conn.cursor()

    # # Recuperar a lista de lojas do banco de dados
    # cursor.execute('SELECT nome FROM lojas')
    # lojas = cursor.fetchall()

    # i = 1
    # lojas_enumeradas = []
    # for i, loja in enumerate(lojas):
    #     lojas_enumeradas.append([i, loja[0]])
    #     i += 1


    lojas_enumeradas = [[1, 'Loja A'], [2, 'Loja B'], [3, 'Loja C']]

    # Exibir o menu de seleção de lojas
    print("Selecione uma loja:")
    for lojas in lojas_enumeradas:
        print(f"{lojas[0]}" + " " + f"{lojas[1]}")

    while True:
        escolha = input("Digite o número da loja: ")
        id_loja = int(escolha)

        if not str(id_loja).isdigit():
            print("Opção inválida. Digite apenas números.")
        elif id_loja < 1 or id_loja > len(lojas_enumeradas):
            print("Loja inválida. Tente novamente.")
        else:
            for item in lojas_enumeradas:
                if item[0] == id_loja:
                    nome_loja = item[1]
                    break
            break

    # Fechar a conexão com o banco de dados
    # conn.close()

    # Obter o valor da venda
    while True:
        try:
            valor_venda = float(input("Digite o valor da venda: "))
            if valor_venda < 1 or valor_venda > 10000:
                raise ValueError
            break
        except ValueError:
            print("Valor inválido. Digite um número float entre 0.1 e 10000.")


    # Obter a data atual
    data = datetime.date.today()

    return ('01', nome_loja, data, valor_venda)

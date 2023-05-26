import socket

# Configurações do servidor
host = '192.168.100.21'  # Endereço IP do servidor
port = 3333  # Porta do servidor

# Cria o socket TCP/IP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Faz o bind do socket com o endereço e porta
server_socket.bind((host, port))

# Define o servidor para escutar conexões
while True:
    server_socket.listen(1)

    print('Aguardando conexões...')

    # Aceita uma nova conexão
    client_socket, client_address = server_socket.accept()
    print('Conexão estabelecida com:', client_address)

    # Recebe dados do cliente
    data = client_socket.recv(1024)

    #dados recebidos do gerente
    dados_recebidos = data.decode()
    data_array = array =dados_recebidos.split(",")
    print(data_array)

    if data_array[0] == '02':
        response = '10.00'
    else:
        response = 'mensagem recebida com sucesso'

    client_socket.send(response.encode())

    if data == '':
        break




# Encerra a conexão
client_socket.close()
server_socket.close()

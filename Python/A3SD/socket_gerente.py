import socket

from gerente import tela_gerente

# Configurações do cliente
host = '192.168.100.21'  # Endereço IP do servidor
port = 3333  # Porta do servidor

# Cria o socket TCP/IP
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Conecta ao servidor
client_socket.connect((host, port))


# retorno das funções
message = []

# rotina principal 
message = tela_gerente()

# Converter a lista em uma string separada por vírgulas
message_str = ','.join([str(item) for item in message])
# Enviar a string codificada pelo socket
client_socket.send(message_str.encode())

# Recebe a resposta do servidor
response = client_socket.recv(1024)
print(response.decode())

# Encerra a conexão
client_socket.close()

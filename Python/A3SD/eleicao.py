import threading
import time

class Server:
    def __init__(self):
        self.leader = None
        self.is_running = True
        self.clients = []

    def run(self):
        while self.is_running:
            # Realizar as operações do servidor

            # Verificar se o servidor está respondendo
            if not self.is_responding():
                print("Servidor não está respondendo. Iniciando eleição...")
                self.start_election()

            time.sleep(1)  # Aguardar um intervalo antes de verificar novamente

    def is_responding(self):
        # Lógica para verificar se o servidor está respondendo
        # Retorna True se o servidor está respondendo e False caso contrário
        pass

    def start_election(self):
        self.leader = None
        threads = []

        for client in self.clients:
            thread = threading.Thread(target=client.initiate_election)
            threads.append(thread)
            thread.start()

        for thread in threads:
            thread.join()

        if self.leader is not None:
            print("Eleição concluída. Novo líder: ", self.leader)
        else:
            print("Eleição concluída. Nenhum líder eleito.")

    def client_response(self, client):
        self.leader = client
        print("Novo líder temporário: ", self.leader)

    def stop_server(self):
        self.is_running = False

class Client:
    def __init__(self, server):
        self.server = server

    def run(self):
        while self.server.is_running:
            # Realizar as operações do cliente

            time.sleep(1)  # Aguardar um intervalo antes de verificar novamente

    def initiate_election(self):
        self.server.client_response(self)

# Criação do servidor e clientes
server = Server()
client1 = Client(server)
client2 = Client(server)

# Adicionar os clientes ao servidor
server.clients.append(client1)
server.clients.append(client2)

# Iniciar as threads do servidor e clientes
server_thread = threading.Thread(target=server.run)
client1_thread = threading.Thread(target=client1.run)
client2_thread = threading.Thread(target=client2.run)

server_thread.start()
client1_thread.start()
client2_thread.start()

time.sleep(10)  # Tempo de execução

# Encerrar o servidor e clientes
server.stop_server()
client1_thread.join()
client2_thread.join()
server_thread.join()

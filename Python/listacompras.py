# programa de lista de compras
from numpy import * 
import os

def parada():
  cont = 0
  while True :
    yield cont
    cont += 1
    
def cls():
  os.system("cls")


p = array([])
v = array([])

print('Lista de compras do mês.\n')
mes_str = input('Digite o mes que estamos:  ')

for y in parada() :
  print('Digite o nome do produto:  ')
  produto = input()
  p = append(p, produto)
  print('Digite o preço:   ')
  valor = float(input())
  v = append(v, valor)
  y = input('Continuar?(s/n):  ')
  if y == 'n' :
    break

cls()

print("Tabela de compras do mes ", mes_str, "\n")
print('{:<10}'.format('PRODUTO'), 'VALOR')
for i,j in zip(p, v):
 print('{:<10}'.format(i),'{:.2f}'.format(j))

# LJ
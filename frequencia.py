
N = int(input())
lista = {}
for i in range(N):
    nu = int(input())
    if(nu in lista):
        lista[nu] += 1
    else:
        lista[nu] = 1


sorteiu = lista.keys()
sorteiu = sorted(sorteiu)

for k in sorteiu:
    print("%d aparece %d vez(es)" %(k,lista[k]))

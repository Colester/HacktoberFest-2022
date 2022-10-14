
N = int(input())
for i in range(N):
  Qt,S = map(int, input().split())
  V = [int(i) for i in input().split()]
  pos = 0
  diferença = abs(S-V[0])
  for j in range (1, Qt):
     
    comparação = abs (S- V[j])
    if comparação < diferença:
      diferença = comparação
      pos = j
  print(pos+1)

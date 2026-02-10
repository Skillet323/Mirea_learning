from random import randint
import numpy as A
k = d = s = M = N = chislo = temp = 0
print("Введите размер матрицы М:")
M = int(input())
while ((not (1 < M < 9)) or (M % 2 != 0) or (int(M)!=M)):
    if ((not (1 < M < 9)) or (M % 2 != 0) or (int(M)!=M)):
        print("M должно быть четным числом в диапазоне от 2 до 8")
        print("Введите размер матрицы:")
        M = int(input())                              #Цикл не позволяющий установить неверное M
if (not ((not (1 < M < 9)) or (M % 2 != 0))):
    A = A.array([[0]*M for i in range(M)])              
    print("Заполнить массив случайными значениями ? 1 – да, 0 - нет ")
    N = int(input())
    while (N != 0 and N != 1):
        if (N != 0 and N != 1):  
            print("N - только 1 или 0\n")
            print("Заполнить массив случайными значениями ? 1 – да, 0 - нет ")
            N = int(input())                       #Цикл не позволяющий установить неверное N
    if (N == 1):
        for i in range(M):
            for j in range(M):
                A[i,j] = randint(1, 100)           #Заполнение матрицы А случайными целыми числами в диапазоне от 1 до 100
    elif (N == 0):
        print(f"Введите {M*M} целых чисел в диапазоне от 1 до 100 ")
        for i in range(M):
            for j in range(M): 
                chislo = int(input())
                if ((0 < chislo < 101) and int(chislo) == chislo):
                    A[i,j] = chislo                    #Заполнение матрицы А целыми числами в диапазоне от 1 до 100
                else:
                    print("Числа должны быть целыми и лежать в диапазоне от 1 до 100")
                    j -= 1
    s=[i for i in range(M*M)]         #Одномерный массив S для хранения значений матрицы
    for i in range(M):
        for j in range (M):
            s[i*M + j]=A[i,j]
    for i in range(M*M):
        for j in range(M*M):
            if s[i]>s[j]:
                s[i],s[j]=s[j], s[i]       #Сортировка элементов матрицы внутри массива s
    l=0
    for i in range(0, M-1):
        for j in range(0, M-1):
            A[i,j]=s[l]                #Возвращение отсортированных элементов в матрицу
            print(A[i,j], end=" ")      #Вывод отсортированной Матрицы
            l+=1
        print(" ")
         
                    
                
            

                  
              
          
      

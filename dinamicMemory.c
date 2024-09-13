#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* PrimerArray(int n)
{
    int *arr;
    
    arr = (int*) malloc(n * sizeof(int));
 
    if(arr == NULL) {
        printf("Error al asignar memoria");
        return NULL;
    }
 
    for(int i = 0; i < n; i++) {
        arr[i] = rand() %100 +1;
    }
 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return arr;
}

int* pares(int* arrayOriginal, int n, int* tamPares)
{
    int* arrayPares = (int*) malloc(n * sizeof(int));
    int j = 0;
    
    for(int i = 0; i < n ; i++)
    {
        if(arrayOriginal[i] % 2 == 0)
        {
            arrayPares[j] = arrayOriginal[i];
            j++;
        }
    }
    
    *tamPares = j; //Tamaño del array de pares
    
    arrayPares = (int*) realloc(arrayPares, j * sizeof(int)); //Redimención del primer array para que no se use memoria de mas
    
    for (int i = 0; i < *tamPares; i++) {
        printf("%d ", arrayPares[i]);
    }
    printf("\n");
    
    return arrayPares;
}

int* redimention(int* arrayOriginal, int n)
{
    int* arrayPlus = (int*) malloc(2 * n * sizeof(int));
    
    if(arrayPlus == NULL)
    {
        printf("Error al asignar memoria\n");
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        arrayPlus[i] = arrayOriginal[i];
    }
    
    for (int i = n; i < 2 * n; i++)
    {
        arrayPlus[i] = rand() % 100 + 101; // Valores aleatorios entre 101 y 200
    }
    
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", arrayPlus[i]);
    }
    printf("\n");
    
    return arrayPlus;
}

int main(int argc, const char * argv[]) {
    int tamPares;
    
    int n;
    printf("Ingrese la cantidad de números deseada:");
    scanf("%d", &n);
    
    srand(time(0)); // Semilla para que el número sea random en cada iteración
    
    printf("Primer array generado: ");
    int *arr1 = PrimerArray(n);
  
    printf("Segundo array con los pares del primero : ");
    int *arrPares = pares(arr1, n, &tamPares);
    
    printf("Primer array * 2: ");
    int *arrG = redimention(arr1, n);
    
    //Suma de los pares del segundo array
    int sumaArr2 = 0;
    for (int i = 0; i<tamPares; i++)
    {
        sumaArr2 += arrPares[i];
    }
    printf("Suma de los pares del segundo array: %d\n", sumaArr2);
    
    //Promedio de todos los números en el primer array
    float average = 0;
    for (int i = 0; i<2*n; i++)
    {
        average += arrG[i];
    }
    average /= 2*n;
    printf("Promedio de todos los números del primer array: %f\n", average);
    
    free(arr1);
    free(arrPares);
    free(arrG);
    
    return 0;
}

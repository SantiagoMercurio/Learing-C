#include <stdio.h>

struct Empleado
{
    char name[50];
    int age;
    float salary;
};

void ingresarDatosEmpleados(struct Empleado *empleados, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del empleado %d: ", i + 1);
        scanf(" %49[^\n]", empleados[i].name);  // Lee línea hasta el salto de línea

        printf("Ingrese la edad del empleado %d: ", i + 1);
        scanf("%d", &empleados[i].age);

        printf("Ingrese el salario del empleado %d: ", i + 1);
        scanf("%f", &empleados[i].salary);
    }
}

void calcularPromedios(struct Empleado *empleados, int cantidad) {
    float sumaEdades = 0.0;
    float sumaSalarios = 0.0;

    for (int i = 0; i < cantidad; i++) {
        sumaEdades += empleados[i].age;
        sumaSalarios += empleados[i].salary;
    }

    float promedioEdad = sumaEdades / cantidad;
    float promedioSalario = sumaSalarios / cantidad;

    printf("Promedio de edad: %.2f años\n", promedioEdad);
    printf("Promedio de salario: $%.2f\n", promedioSalario);
}

int main(int argc, const char * argv[])
{
    struct Empleado empleados[3] = {
        {"Luis Vargas", 20, 10000.1},
        {"Jorge Octavio", 20, 5000.4},
        {"Stephy Nuñez", 20, 3}
    };

    printf("Datos originales de los empleados:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s, %d años, $%f\n", empleados[i].name, empleados[i].age, empleados[i].salary);
    }

    // Llamar a la función para ingresar nuevos datos
    printf("\nPor favor, ingrese los datos actualizados de los empleados:\n");
    ingresarDatosEmpleados(empleados, 3);

    printf("\nDatos actualizados de los empleados:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s, %d años, $%.2f\n", empleados[i].name, empleados[i].age, empleados[i].salary);
    }

    // Calcular y mostrar los promedios de edad y salario
    calcularPromedios(empleados, 3);

    return 0;
}

# Ejercicios de programación en C

Repositorio con los ejercicios en C que resolví durante la tecnicatura de Analista Programador (UAI). Van de lo básico a programas con arreglos, matrices y funciones. Cada archivo incluye un comentario inicial con la descripción del problema y mi solución.

## Programas destacados

- **`05-matrices/horas_analistas_proyectos.c`** y **`06-funciones/horas_analistas_funciones.c`**: gestión de horas de 10 analistas en 15 proyectos con una matriz. Calcula totales por fila y por columna, sueldos, máximos y mínimos, y un ranking ordenado. La segunda es la misma lógica reescrita con funciones.
- **`04-arreglos/busqueda_secuencial_binaria.c`**: menú para buscar un valor con búsqueda secuencial o binaria (ordenando antes el vector).
- **`06-funciones/ordenamientos_menu.c`**: menú para ordenar un vector con burbuja o QuickSort, con una función por cada tarea.
- **`02-condicionales/tipo_triangulo.c`**: valida que tres lados formen un triángulo y lo clasifica.

## Contenido

### 01-basicos
- `comparar_numeros.c`: indica si dos números son iguales o distintos.
- `positivo_negativo.c`: indica si un número es positivo, negativo o cero.
- `resta_mayor_menor.c`: resta el menor al mayor de dos números.

### 02-condicionales
- `altura_mayor_edad.c`: muestra la altura de la persona de mayor edad.
- `tipo_triangulo.c`: clasifica un triángulo según sus lados.
- `calculadora_sueldo.c`: calcula un sueldo según horas y categoría, con `switch`.

### 03-bucles
- `carrera_ganador.c`: ganador y último de una carrera, con valor centinela.
- `contador_facturas.c`: acumula un total y cuenta facturas por tramo de importe.
- `contador_promedio.c`: promedio de positivos y de negativos, y cantidad de ceros.
- `suma_promedio_sueldos.c`: suma y promedio de una cantidad de sueldos.
- `promedio_pares_impares.c`: promedio total, de pares y de impares, y cantidad de mayores a 15.
- `promedio_25_numeros.c`: promedio de 25 números.
- `contar_signos.c`: cuenta positivos, negativos y ceros.

### 04-arreglos
- `recorrer_vector.c`: recorre un vector y muestra cada posición.
- `vector_orden_inverso.c`: carga un vector y lo muestra al revés.
- `ordenamiento_burbuja.c`: ordena 20 números con burbuja.
- `busqueda_secuencial_binaria.c`: búsqueda secuencial y binaria.

### 05-matrices
- `horas_analistas_proyectos.c`: horas por analista y proyecto con una matriz.

### 06-funciones
- `ordenamientos_menu.c`: ordenamientos con menú y funciones.
- `horas_analistas_funciones.c`: versión con funciones del ejercicio de analistas.

## Temas que cubre

- Condicionales (`if`, `else if`, `switch`) y validación de datos
- Bucles (`for`, `while`, `do-while`) y valores centinela
- Acumuladores, contadores y promedios
- Arreglos y matrices
- Algoritmos de ordenamiento (burbuja y QuickSort) y de búsqueda (secuencial y binaria)
- Funciones y paso de arreglos como parámetros

## Cómo compilar y ejecutar

1. Tener instalado un compilador de C, como GCC.
2. Compilar: `gcc nombre_del_archivo.c -o programa`
3. Ejecutar: `./programa` (en Windows: `programa.exe`)

Algunos programas declaran variables dentro del `for`, por lo que conviene compilar con `gcc -std=c99 nombre_del_archivo.c -o programa`. En la consola de Windows, las tildes pueden verse mal según la configuración.

## Próximos pasos

- Estructuras (`struct`), cadenas de caracteres y archivos.
- Pasar estos mismos ejercicios a Python y analizarlos con pandas.

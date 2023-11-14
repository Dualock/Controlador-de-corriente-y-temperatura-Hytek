## Interfaces de de visualización de temperatura y corriente
#### objetivos

- Crear una interfaz utilizando Arduino donde se pueda leer el valor de temperatura del diodo láser a partir del valor resistivo del termistor.
- Crear una interfaz utilizando Arduino donde se pueda leer el valor de corriente del diodo láser, utilizando un sensor ACS712



## Interfaz para control de `temperatura`

Se realizó inicialmente una simulación en TinkerCAD, donde se plantea una serie de pasos para lograr el objetivo final

+ ####Paso 1 `Conexión con pantalla LCD`

    
+ #### Paso 2  `Lectura del valor resistivo del termistor`

+ #### Paso 3  `Conversion de resistencia a temperatura`
Normalmente para un termistor NTC se utilizan dos algoritmos

    * ##### Ecuación de Steinhart-Hart:
		Consiste en tomar 3 valores de resistencia del termistor y la temperatura medida, en este proyecto se utiliza la tabla de resistencia vs temperatura que provee la hoja de datos Hy5640, se trata de tomar las medidas que se observan más claras para mayor precisión.
		![Gráfica de variación de la resistencia respecto a la temperatura 10k dale termistor](Figuras/RvsTemp.PNG)
| Valores medidos | R k$\Omega$ | T $C^o$ |
|-----------------|:-----------:|--------:|
| R1 \| T1        |      10     |      25 |
| R2 \| T2        |      25     |       5 |
| R3 \| T3        |     100     |     -20 |
		Luego se calculan los parametros A, B y C de la ecuación de Steinhart-Hart
		$1/T = A + Bln(R)+C[ln(R)^3]$
    * ##### Ecuación del parámetro beta
        * df_hora_asignacion : Un `dataframe` con los datos de consumo de potencia de una hora específica durante todo el año.
		  $1/T = 1/T_0 + 1/\betaln(\frac{R_T}{R_0})$
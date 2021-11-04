


//como encender un bit de una variable?

//si queremos cambiar el estado de solo un bit debemos utilira una mascara booleana

a = a | 0x 10; // 0x es hexadecimal que seria 0001 0000

//si me apoyo en el operador desplazamiento eria

a= a | (1<<5); // donde estara poniendo un 1 en el bit 5

//ahora podemos hacer una macro general para encender un bit

#define setBit (variable, bit) variable= variable | (1<<bit);


//como apagar un bit de una variable?

//si queremos cambiar el estado de solo un bit debemos utilira una mascara booleana

a = a & 0x 11101111; // 0x es hexadecimal que seria E F

//si me apoyo en el operador desplazamiento eria

a= a & ~(1<<5); // donde estara poniendo un 1 en el bit 5

//ahora podemos hacer una macro general para encender un bit

#define setBit (variable, bit) variable= variable | (1<<bit);




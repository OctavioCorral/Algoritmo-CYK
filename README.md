# Algoritmo-CYK

Algorimo CYK en lenguaje C++ para hacer la prueba de membresía de cadenas, para Lenguajes Libres de Contexto

La gramática tiene reglas las cuales deben de seguirse para que la cadena sea aceptada, para verificar si una cadena aceptada se trabaja con la gramática cuando está en el proceso de eliminar símbolos no alcanzables. Ya que se está en esa parte de la gramática se tiene que empezar con la producción de “M” donde se elige a la “A” para poder continuar, los caracteres de “A” son las reglas a seguir, donde elegimos el generador  “V” y empezamos con un terminal suyo y luego con el terminal “:”, seguido la cadena tiene que contener lo que contenga “Q” tanto un generador que lleve a otro terminal o directamente un terminal de “Q”, terminando se agrega el terminal “;”. Si se cumple con esa regla la cadena deberá de ser aceptada.

(Gramática utilizada en forma normal de chomsky)

M → MA | V:Q;

A → V:Q ;

Q → P ?Q :Q | P|T | T&F | (Q) | !F | p | q | r | 0| 1

P → P|T | T&F | (Q) | !F | p | q | r | 0| 1

T → T&F | (Q) | !F | p | q | r | 0| 1

F → (Q) | !F | p | q | r | 0| 1

V →  p | q | r 


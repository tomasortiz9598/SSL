#include "parser.h"

bool parser(){
	Estado stateParser = P_INIT;
	Token token;
	bool resultado;
	while ((token = GetNextToken()) != T_EOF){
		printf("[Parser] Parser: %d\n",token);
		switch (stateParser){
			case P_INIT:
				switch (token){
					case T_CONSTANTE:
						stateParser = P_CONSTANTE;
						resultado = true;
						break;
					case T_IDENTIFICADOR:
						stateParser = P_IDENTIFICADOR;
						resultado = true;
						break;
					default:
						stateParser = P_INVALIDO;
						resultado = false;
						break;
				}
				break;
			case P_IDENTIFICADOR:
			case P_CONSTANTE:
				switch (token){
					case T_SUMA:
					case T_MULTIPLICADOR:
						stateParser = P_OPERADOR;
						resultado = true;
						break;
					default:
						stateParser = P_INVALIDO;
						resultado = false;
						break;
				}
				break;
			case P_OPERADOR:
				switch (token){
					case T_CONSTANTE:
						stateParser = P_CONSTANTE;
						resultado = true;
						break;
					case T_IDENTIFICADOR:
						stateParser = P_IDENTIFICADOR;
						resultado = true;
						break;
					default:
						resultado = false;
						stateParser = P_INVALIDO;
						break;
				}
				break;

			default:
				break;
			}

	}
	return resultado;
}
#include <jni.h>
/*
 * Class:     ejemplomaxjni_lib_JavaDiscretas
 * Method:    calculardiscretas
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_ejemplomaxjni_lib_JavaDiscretas_calculardiscretas
  (JNIEnv * env1, jobject obj1, jint int1, jint int2){

     int num1 = int1;
     int num2 = int2;
     int aux, resOriginal,mult= 0, sum, resultado, indi = 0, iteraciones = 1;

     if(num1>num2) {
        resultado = num1;

        }
        else {resultado = num2;
        num2 = num1;
        }

    aux = num2;
    resOriginal = resultado;

    do{

        mult = resultado / num2;
        sum = resultado - (mult*num2);


        resultado = num2;
        num2 = sum;

        iteraciones++;

        if(sum == 0){
          indi = 1;
        }

    }while (indi == 0);

    jintArray jDatos = (*env1)->NewIntArray(env1, iteraciones * 4);
    jint datos[iteraciones * 4];

    resultado = resOriginal;
    num2 = aux;
    int posicion = 0;

    for(int i = 0 ; i < iteraciones-1; i++){

        mult = resultado / num2;
        sum = resultado - (mult*num2);


        datos[posicion] = resultado;
        posicion++;
        datos[posicion] = mult;
        posicion++;
        datos[posicion] = num2;
        posicion++;
        datos[posicion] = sum;
        posicion++;

        resultado = num2;
        num2 = sum;

    }

    (*env1)->SetIntArrayRegion(env1, jDatos, 0, iteraciones * 4, datos);

    return jDatos;
}

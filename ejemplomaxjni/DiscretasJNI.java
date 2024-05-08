package ejemplomaxjni;
import ejemplomaxjni.lib.JavaDiscretas;
import java.util.ArrayList;

public class DiscretasJNI {

    static {
        System.loadLibrary("javadiscretas");
    }

    public DiscretasJNI() {
        JavaDiscretas dis = new JavaDiscretas();
        int num1 = 512, num2 = 100;
        ArrayList<Integer> datos = new ArrayList<>();

        // Obtener el array de int devuelto por calculardiscretas()
        int[] resultado = dis.calculardiscretas(num1, num2);

        // Iterar sobre el array y agregar cada elemento a datos
        for (int valor : resultado) {
            datos.add(valor);
        }

        int posicion = 0;
        int inter = datos.size() / 4;

        for (int i = 0; i < inter; i++) {
            System.out.println(
                datos.get(posicion) + " " + 
                datos.get(posicion + 1) + " " + 
                datos.get(posicion + 2) + " " + 
                datos.get(posicion + 3)
            );
            posicion += 4;
        }
    }

    public static void main(String[] argumentos) {
        new DiscretasJNI();
    }
}


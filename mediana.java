import java.util.*;

public class HuxleyCode {
  public static void partition(int[] lista, int inicio, int fim) {
		int meio = (inicio + fim) / 2;
		int indiceMediana = getMedianaDeTres(lista, inicio, meio, fim); 
		trocar(lista, indiceMediana, fim); 
		System.out.println(lista[fim]);
		int pivo = lista[fim];
		int i = inicio;
		for (int j = inicio; j < fim; j++) {
			if (lista[j] <= pivo) {
				int aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
				i++;
			}
		}
		int aux = lista[i];
		lista[i] = lista[fim];
		lista[fim] = aux;

	}

	public static int getMedianaDeTres(int[] list, int inicio, int meio, int fim) {

		int[] elementos = { list[inicio], list[meio], list[fim] };
		for (int i = 0; i < elementos.length; i++) {
			for (int j = 1; j < elementos.length; j++) {
				if (elementos[j - 1] > elementos[j]) {
					int aux = elementos[j - 1];
					elementos[j - 1] = elementos[j];
					elementos[j] = aux;
				}
			}
		}
		int mediana = elementos[1]; 
		for (int indice = 0; indice < list.length; indice++) { 
			if (list[indice] == mediana) {
				return indice;
			}
		}
		System.out.println("Nao achou"); 
		return 0;
	}

	public static void trocar(int[] list, int indiceMediana, int fim) { 
		int aux = list[fim];
		list[fim] = list[indiceMediana];
		list[indiceMediana] = aux;
	}
	public static int[] converteForInt(String[] word) {
		int vect_numeros[] = new int[word.length];
		for(int i = 0; i < word.length;i++) {
			vect_numeros[i] = Integer.parseInt(word[i]);
		}
		return vect_numeros;
	}
	public static void printSaida(int[] saida) {
		for(int numero: saida) {
			System.out.print(numero);
			if(numero == saida[saida.length-1]) {
				continue;
			}else {
				System.out.print(" ");
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			String txtNumeros = sc.nextLine();
			String[] arrayTxtNumeros = txtNumeros.split(" ");
			int[] numeros = converteForInt(arrayTxtNumeros);
			partition(numeros, 0, numeros.length - 1);
			printSaida(numeros);
		}

        sc.close();
	}
}

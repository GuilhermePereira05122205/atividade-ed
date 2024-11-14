import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class App {

    public static void main(String[] args) {
        try {
            int[][] matrizTriangular = lerMatrizDeArquivo("entrada.txt");
            GrafoCompletar(matrizTriangular.length, matrizTriangular);

            for (int i = 0; i < matrizTriangular.length; i++) {
                for (int j = 0; j < matrizTriangular.length; j++) {
                    System.out.print(matrizTriangular[i][j] + " ");
                }
                System.out.println();
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }

    public static int[][] lerMatrizDeArquivo(String caminhoArquivo) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(caminhoArquivo));
        int n = Integer.parseInt(reader.readLine().trim());
        int[][] matriz = new int[n][n];

        for (int i = 0; i < n; i++) {
            String[] linha = reader.readLine().trim().split(" ");
            for (int j = 0; j <= i; j++) {
                matriz[i][j] = Integer.parseInt(linha[j]);
            }
        }
        reader.close();
        return matriz;
    }

    public static void GrafoCompletar(int n, int[][] matriz) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                matriz[j][i] = matriz[i][j];
            }
        }
    }
}

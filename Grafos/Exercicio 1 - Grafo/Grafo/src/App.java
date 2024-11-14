public class App {
    public static void main(String[] args) throws Exception {
       boolean[][] matriz = {
            {false, true, true, false},
            {true, false, true, false},
            {true, true, false, false},
            {true, false, false, false}
        };

            Grafo grafo = new Grafo();

            grafo.grafo = matriz;

            System.out.println("Numero de arestas:" + grafo.getArestas());

            System.out.println("Digrafo: " + grafo.ehDigrafo());

            int[] grauVertice = grafo.grauVertice();

            for(int i = 0; i < matriz.length; i++){
                System.out.println("Grau da vertice " + i + " " + grauVertice[i]);
            }

            System.out.println("Conexo: " + grafo.ehConexo());

            System.out.println("Ciclo: " + grafo.ehCiclo(0, 0, 0));

            int[][] lista = grafo.listaAdjacencias();

            for (int i = 0; i < grafo.listaAdjacencias().length; i++) {
                for (int j = 0; j < grafo.listaAdjacencias().length; j++) {
                    System.out.print(lista[i][j] + ",");
                }
                System.out.println("");
            }

    }
}

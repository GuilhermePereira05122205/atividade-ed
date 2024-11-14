public class Grafo {
    boolean grafo[][];

    int getArestas(){
        int arestas = 0;

        for (int i = 0; i < grafo.length; i++) {
            for (int j = 0; j < grafo.length; j++) {
                if(grafo[i][j] == true){
                    arestas = arestas + 1;
                }
            }
        }

        return arestas;
    }

    boolean ehDigrafo(){
        for (int i = 0; i < grafo.length; i++) {
            for (int j = 0; j < grafo.length; j++) {
                if(grafo[i][j] == true && grafo[j][i] == false){
                    return true;
                }
            }
        }

        return false;
    }

    int[] grauVertice(){
        int[] v = new int[5];
        for (int i = 0; i < grafo.length; i++) {
            int grau = 0;
            for (int j = 0; j < grafo.length; j++) {
                if(grafo[i][j] == true && i != j){
                    grau = grau + 1;
                }
                if(grafo[j][i] == true && i != j){
                    grau = grau + 1;
                }
            }
            v[i] = grau;
        }

        return v;
    }

    boolean ehConexo(){
        int[] posicao = new int[grafo.length];
        for(int i = 0; i < grafo.length; i++){
            for(int j = 0; j < grafo.length; j++){
                if(grafo[i][j] == true && i != j){
                    posicao[i] += 1;
                    posicao[j] += 1;
                }
            }
        }

        for(int i = 0; i < posicao.length; i++){
            if(posicao[i] == 0){
                return false;
            }
        }

        return true;
    }

    boolean ehCiclo(int vertice, int ciclo, int anterior){
        
        for(int i = 0; i < grafo.length; i++){
            if(grafo[vertice][ciclo] == true && anterior != ciclo){
                return true;
            }

            if(grafo[vertice][i] == true && i != vertice && i != anterior){
                return ehCiclo(i, ciclo, vertice);
            }
        }

        if(ciclo < grafo.length){
            ehCiclo(0, ciclo + 1, 0);
        }
        
        return false;
    }

    int[][] listaAdjacencias(){
        int[][] lista = new int[grafo.length][grafo.length];
        for (int i = 0; i < grafo.length; i++) {
            int cont = 0;
            int[] adj = new int[grafo.length];
            for (int j = 0; j < grafo.length; j++) {
                if(grafo[i][j] == true){
                    adj[cont] = j;
                    cont++;
                }
            }
            lista[i] = adj;
        }

        return lista;

    }


}

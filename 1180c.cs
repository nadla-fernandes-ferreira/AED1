using System; 

class URI {

static void Main(string[] args) { 

int N = int.Parse(Console.ReadLine());
string[] valores = Console.ReadLine().Split(' ');
        
int[] X = new int[N];
for(int i = 0; i < N; i++) {
X[i] = int.Parse(valores[i]);
}
int menorValor = X[0];
int posicao = 0;
for (int i = 1; i < N; i++) {
if (X[i] < menorValor)  {
menorValor = X[i];
posicao = i;
}  
}
Console.WriteLine("Menor valor: " + menorValor);
Console.WriteLine("Posicao: " + posicao);
}
}

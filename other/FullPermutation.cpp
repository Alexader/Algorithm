#include<stdio.h>
const int maxn = 13;
int n;
int P[maxn], hashTable[maxn] = {false};
void generateP(int index) {
  if(index > n) {
    for(int i=1;i<=n;i++) {
      printf("%d ", P[i]);
    }
    printf("\n");
    return;
  }
  for(int x=1;x<=n;x++) {
    if(hashTable[x] == false) {
      P[index] = x;
      hashTable[x] = true;
      generateP(index+1);
      // 试了一种可能性后，要还原到没试的状态
      hashTable[x] = false;
    }
  }
}

int main() {
  scanf("%d", &n);
  generateP(1);
  return 0;
}

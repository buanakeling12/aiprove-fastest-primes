#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pitab.h" /* pitab[k] = pi(k*1000), k=0..5000 */
static int sieve_pi(int n){ if(n<2) return 0; int m=(n+1)/2; unsigned char*c=calloc(m,1); if(!c) return -1; for(int i=3;(long long)i*i<=n;i+=2) if(!c[i>>1]) for(long long j=(long long)i*i;j<=n;j+=2LL*i) c[j>>1]=1; int k=1; for(int i=1;i<m;i++) if(!c[i]) k++; free(c); return k; }
int main(void){int n; if(scanf("%d",&n)!=1) return 0; if(n<2){puts("0");return 0;}
  if(n>5000000){printf("%d\n",sieve_pi(n));return 0;}
  int base=(n/1000)*1000, cnt=pitab[n/1000], len=n-base;
  if(len==0){printf("%d\n",cnt);return 0;}
  int sq=1; while((long long)(sq+1)*(sq+1)<=n) sq++;
  static unsigned char small[2237]; static unsigned char comp[1000];
  for(int i=2;(long long)i*i<=sq;i++) if(!small[i]) for(int j=i*i;j<=sq;j+=i) small[j]=1;
  memset(comp,0,len); if(base==0) comp[0]=1;
  for(int p=2;p<=sq;p++) if(!small[p]){ long long start=(long long)p*p, first=((long long)(base/p)+1)*p; if(first<start) first=start; for(long long m=first;m<=n;m+=p) comp[m-base-1]=1; }
  for(int i=0;i<len;i++) if(!comp[i]) cnt++;
  printf("%d\n",cnt); return 0;}

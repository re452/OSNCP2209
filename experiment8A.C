#include<stdio.h>

int main() {
    int ms, bs, nob, ef,n,
    mp[10],tif=0; int i,p=0;

    printf("Enter the total memory available (in Bytes) -- ");
     scanf("%d",&ms); //we chose 1000
    printf("Enter the block size (in Bytes) -- ");
     scanf("%d", &bs); //we chose 300
      nob=ms/bs;  //1000/300 = there are 3 blocks available in memory
      ef=ms - nob*bs; //1000 - 3*300 = 100 bytes of external fragmentation
    printf("\nEnter the number of processes -- ");
     scanf("%d",&n); //5 processes

    for(i=0;i<n;i++) {
        printf("Enter memory required for process %d (in Bytes)-- ",i+1);
         scanf("%d",&mp[i]); 
    }
        printf("\nNo. of Blocks available in memory--%d",nob);
        printf("\n\nPROCESS\tMEMORYREQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for(i=0;i<n && p<nob;i++) {
        printf("\n %d\t\t%d",i+1,mp[i]); //process number and memory required
        if(mp[i] > bs)
            printf("\t\tNO\t\t---"); //if memory required is greater than block size it cant be allocated
        else {
            printf("\t\tYES\t%d",bs-mp[i]); //otherwise it can be allocated, tif = block size - memory required
            tif = tif + bs-mp[i]; //tif is total internal fragmentation
            p++;
        }
    }

if(i<n)
    printf("\nMemory is Full, Remaining Processes cannot be accomodated");
    printf("\n\nTotal Internal Fragmentation is %d",tif);
    printf("\nTotal External Fragmentation is %d",ef);
}

#include<stdio.h> 

int main() { 
    int ms,mp[10],i, temp,n=0; char ch = 'y'; 

    printf("\nEnter the total memory available (in Bytes)-- "); 
     scanf("%d",&ms); 
    temp=ms; //temp is used to keep track of remaining memory after allocation

    for(i=0;ch=='y';i++,n++) {
        printf("\nEnter memory required for process %d (in Bytes) -- ",i+1); 
         scanf("%d",&mp[i]); 
    if(mp[i]<=temp) { //if memory required is less than or equal to remaining memory it can be allocated
        printf("\nMemory is allocated for Process %d ",i+1); 
    temp = temp - mp[i]; //after allocation, remaining memory is updated
        } 
    else { 
        printf("\nMemory is Full"); //if memory required is greater than remaining memory, then nono allocation
        break; 
    }
    printf("\nDo you want to continue(y/n) -- ");
     scanf(" %c", &ch); 
} 
    printf("\n\nTotal Memory Available -- %d", ms); 
    printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED "); 
    for(i=0;i<n;i++) 
        printf("\n \t%d\t\t%d",i+1,mp[i]); 
    printf("\n\nTotal Memory Allocated is %d",ms-temp); 
    printf("\nTotal External Fragmentation is %d",temp);  
}


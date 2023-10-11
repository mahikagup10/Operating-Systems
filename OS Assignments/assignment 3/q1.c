#include<stdio.h>


int phy_addr(int phy_mem_size, int log_mem_size, int frame_size, int logical_addr, int base, int offset);

int main()
{
    int pmem,lmem,fs,l_ad,b,o,res;
    int ch;

    
        printf("Enter the physical memory size: ");
        scanf("%d",&pmem);
        printf("\nEnter the logical memory size: ");
        scanf("%d",&lmem);
        if(pmem>lmem)
        {
            printf("Logical memory size should be greater than physical memory size");
            return 0;
        }
        printf("\nEnter the frame size: ");
        scanf("%d",&fs);
        printf("\nEnter the logical address: ");
        scanf("%d",&l_ad);
        printf("\nEnter the base: ");
        scanf("%d",&b);
        printf("\nEnter the offset: ");
        scanf("%d",&o);

        res = phy_addr(pmem,lmem,fs,l_ad,b,o);
        printf("\nThe physical address is: %d", res);
   
    
    

    return 0;
}

int phy_addr(int phy_mem_size, int log_mem_size, int frame_size, int logical_addr, int base, int offset)
{
    //numner of frames: phy mem size/page size 
    //number of pages: log mem size/page size
    int res;
    int no_of_pages, frame_num;
    no_of_pages = log_mem_size/frame_size;
    int p[no_of_pages];     //page table - gives the frame number
    int no_of_frames;
   // no_of_frames = phy_mem_size/frame_size;
   // int phy_mem[no_of_frames];
    frame_num = logical_addr/frame_size;
    for(int i=0; i<no_of_pages; i++)
    {
        printf("enter the frame number for page %d: ", i);
        scanf("%d",&p[i]);
    }

    printf("\nPage table: ");
    for(int i=0; i<no_of_pages; i++)
    {
        printf("%d\t",p[i]);

    }
    
    res = base+(frame_size*p[frame_num])+offset;
    return res;
}

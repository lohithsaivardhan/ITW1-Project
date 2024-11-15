// Online C compiler to run C program online
#include <stdio.h>
int menu(int arr[], int size);
int ins(int arr[], int size);
int dis(int arr[], int size);
int del(int arr[], int size);

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("----------------------------\n");
    printf("Your array is: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("----------------------------\n");
    menu(arr,size);
}

int dis(int arr[], int size){
    printf("Your array is: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("----------------------------\n");
    menu(arr,size);
}

int ins(int arr[], int size){
    int pos, elem;
    printf("Where do you want to insert element?\n");
    printf("Type: \n1.End of array\n2.Specify position\n::");
    scanf("%d", &pos);
    if(pos == 1){
        size = size+1;
        printf("Enter element to be inserted: ");
        scanf("%d", &elem);
        for(int i = 0; i < size; i++){
            if(i==size-1){
                arr[i] = elem;
            }
        }
    }
    else if(pos == 2){
        int pos2;
        size = size+1;
        printf("Enter position: ");
        scanf("%d", &pos2);
        printf("Enter element to be enterred: ");
        scanf("%d", &elem);
        int temp = arr[pos2-1];
        for(int i = size-1; i >= pos2-1; i--){
            arr[i] = arr[i-1];
            if(i == pos2){
                arr[pos2] = temp;
            }
            arr[pos2-1] = elem;
        }
    }
    else{
        printf("Invalid Input!\n");
        ins(arr,size);
    }
    
    printf("Element has been inserted!\n");
    int yon;
    printf("Do you want to display array? (0/1): ");
    scanf("%d", &yon);
    if(yon == 1){
        dis(arr,size);
    }else if(yon == 0){
        printf("You are being redirected to menu!\n");
        printf("----------------------------\n");
        menu(arr,size);
    }
    else{
        printf("Enter valid value!");
    }
}

int del(int arr[], int size){
    int posd;
    printf("Enter position of element to be deleted: ");
    scanf("%d", &posd);
    for (int i = posd-1; i < size - 1; i++)
        arr[i] = arr[i + 1];
    
    size = size-1;    
    printf("Element has been deleted!\n");
    int yon;
    printf("Do you want to display array? (0/1): ");
    scanf("%d", &yon);
    if(yon == 1){
        dis(arr,size);
    }else if(yon == 0){
        printf("You are being redirected to menu!\n");
        printf("----------------------------\n");
        menu(arr,size);
    }
    else{
        printf("Enter valid value!");
    }
}

int menu(int arr[], int size){
    int opt;
    printf("Menu: \n");
    printf("1. Insert element to end or specific position of array.\n2. Removing element from specified position of array.\n3. Display array.\n4. End program!\n");
    printf("::");
    scanf("%d", &opt);
    if(opt == 1){
        ins(arr,size);
    }else if(opt == 2){
        del(arr,size);
    }else if(opt == 3){
        dis(arr,size);
    }else if(opt == 4){
        printf("Program End!");
    }else{
        printf("Invalid input!\nProgram reinitialized.");
        main();
    }
}

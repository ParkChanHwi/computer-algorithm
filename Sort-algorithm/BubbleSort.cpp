#include <iostream> 



void BubbleSort(int DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < Length - 1; i++)
    {
        for (j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}

int main(void)
{
 
    
    int n = 0;

    printf("�Է��� ���� ���� : ");
    scanf("%d", &n);
   
    int* DataSet = (int*)malloc(sizeof(int) * n);
   
    for (int i = 0; i < n; i++) {
        printf("%d", i+1); 
        printf(" ��° �� �Է� : ");
        scanf("%d", &DataSet[i]);
    }

    BubbleSort(DataSet, n);
    printf("������ �� ��� \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n",DataSet[i]);
    }
    
    free(DataSet);
    return 0;
}

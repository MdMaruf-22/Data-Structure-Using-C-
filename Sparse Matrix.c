#include <stdio.h>

int main()
{
    int col, row;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter coloumn: ");
    scanf("%d", &col);
    int arr[row][col];
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter [%d][%d] elements: ", i, j);
            scanf("%d", &arr[i][j]);
            printf("\n");
            if (arr[i][j] == 0)
                cnt++;
        }
    }
    // printf("%d",cnt);
    if(cnt==(row*col)/2) printf("No.It is not sparse Matrix\n");
    else if (cnt > ((row * col) / 3))
    {
        printf("Yes.It is sparse matrix\n");
        if (row * col == cnt)
        {
            printf("It has all zero(0) elements.");
            return 0;
        }
        int size = ((row * col) - cnt);
        int table[3][size];
        int x = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] != 0)
                {
                    table[x][0] = i;
                    table[x][1] = j;
                    table[x][2] = arr[i][j];
                    x++;
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d\t", table[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("No.It is not sparse Matrix\n");
    return 0;
}
